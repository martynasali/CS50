def ask():
    # Get height
    height = input("Height: ")
    # check if its a number
    if height.isdigit():
        height = int(height)
    # check if input is within range
        if height > 8 or height < 1:
            ask()
        else:
            # print triangles
            l = height
            for i in range(height):
                for t in range(l-1):
                    print(" ", end="")
                for e in range(i+1):
                    print("#", end="")
                print("  ", end="")
                for e in range(i+1):
                    print("#", end="")
                print()

                l -= 1
    else:
        ask()


height = ask()

