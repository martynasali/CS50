import sys
import csv


def main():
    if len(sys.argv) != 3:
        print("missing command-line argument")
        sys.exit(1)
    # Open files and read
    file = open(sys.argv[1])
    reader = csv.reader(file)
    header = next(reader)
    nucleotide = []
    nucleotide = header[1:]
    people = []
    results = []
    for row in reader:
        people.append(row)

    file1 = open(sys.argv[2])
    reader1 = csv.reader(file1)
    # search for strands
    for line in reader1:
        sequence = line
    for o in range(len(nucleotide)):
        results.append(check(sequence, nucleotide[o]))
    i = 0
    count = 0
    numbers = len(people[0])-1
    is_awin = False
    # compare results
    for peeps in people:
        i += 1
        count = 0
        for number in range(len(peeps)-1):
            if int(people[i-1][number+1]) == results[number]:
                count += 1
                if count == numbers:
                    is_awin = True
                    winner = people[i-1][0]
    if is_awin:
        print(winner)
    else:
        print("No match")
    # close files
    file.close()
    file1.close()
    sys.exit(0)

 # search for strands


def check(sequence, nucleotide):
    counts = 4
    cuts = []
    fr = 0
    longest = 0
    current = []
    counter = 0
    countss = 0
    final = 0
    length = len(nucleotide)
    i = 0
    c = 0
    for d in range(len(sequence[0])+1):
        counts = length+d
        strs = sequence[0][d:counts]

        if strs == nucleotide:
            current.append(d)
    # filter trough
    for t in range(len(current)):
        if len(current)-1 == 0:
            countss += 1
            cuts.append(countss)
        elif t < len(current)-1:
            if current[t]-length == current[t-1] and (current[t]+length) == current[t+1] :
                countss += 1
                cuts.append(countss)
            elif (current[t]+length) == current[t+1]:
                countss = 0
                countss += 1
                cuts.append(countss)
            elif (current[t]-(length*2)) == current[t-2]:
                countss += 1
                cuts.append(countss)
            elif (current[t]-length) == current[t-1]:
                countss = 0
                countss += 1
                cuts.append(countss)
        elif t == len(current)-1:
            if (current[t]-length) == current[t-1]:
                countss += 1
                cuts.append(countss)

    cuts.sort(reverse=True)
    try:
        countss = cuts[0]
    except IndexError:
        countss = 0

    return countss


if __name__ == "__main__":
    main()