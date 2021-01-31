import cs50

# Improvised do-while loop for users input
h = cs50.get_int("Height: ")

while h < 1 or h > 8:
    h = cs50.get_int("Height: ")


# While loop for printing two opposing pyramids with a gap in between of them
h2 = h

while h2 != 0:
    i = h2 - 1
    print(" " * i + "#" * (h - i) + "  " + "#" * (h - i))
    h2 -= 1
