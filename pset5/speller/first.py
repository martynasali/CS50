
import cs50

    x = 12
    phrase = 'this is cs50'

    if y < 43 or z == 15:
        # code goes here
    else:
        # code goes here


    if coursenum == 50:
        # code goes here
    elif not coursenum == 51:
        # code goes here


    letters_only = True if input().isalpha() else False

    counter = 0
    while counter < 100:
        print(counter)
        counter += 1


    for x in range(0, 100):
        print(x)

    nums = [1, 2, 3, 4];
    nums.append(5)
    nums.insert(4, 5)
    nums[len(nums):] = [5];

    nums = [x for x in range(500)]

    presidents = [
        ("George Washington", 1789),
        ("John Adams", 1801),
        ("James Madison", 1809)
        ]

    for prez, year in presidents:
        print("In {1}, {0} took office".format(prez, year))

    pizzas = {
        "cheese": 9,
        "peperoni": 10,
        "su ananasais": 11
    }

    pizzas["cheese"] = 8

    if pizza["vegetables"] < 12:
        # do something

    pizzas["bacon"] = 14

    for pie in pizzas:
        # use pie in here as a stand-in for i
        print(pie)

    for pie, price in pizzas.items():
        print(price)

    for pie, price in pizzas.items():
        print("A whole {} pizza costs ${}" .format(pie, price))

    print("A whole"+ pie +" pizza costs $" + str(price))

    def square(x):
        return x ** x


    class Student():

        def __init__(self, name, id)
            self.name = name
            self.id = id

        def changeID(self, id):
            self.id = id

        def print(self):
            print("{} - {}".format(self.name, self.id))
            
            
        jane = Student ("Jane", 10)
        jane.print()
        jane.changeID(11)
        jane.print()