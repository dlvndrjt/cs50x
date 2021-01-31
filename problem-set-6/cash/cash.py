import cs50

# Improvised do-while loop for user's input
co = cs50.get_float("Change owed: ")

while co <= 0:
    co = cs50.get_float("Change owed: ")


# Rounding change owed & storing it into co2
co2 = int(co * 100)


# Simple division to get the number of specific coins usable and the remainder of change left
q1 = int(co2 / 25)
q2 = co2 % 25

d1 = int(q2 / 10)
d2 = q2 % 10

n1 = int(d2 / 5)
n2 = d2 % 5

p1 = int(n2 / 1)


# Adding coins used & printing it out
change = q1 + d1 + n1 + p1
print(change)
