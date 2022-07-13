from random import choice
n1 = str(input("firt student "))
n2 = str(input("second student "))
n3 = str(input("third student "))
n4 = str(input("quarto student "))
students = [n1, n2, n3, n4]
chosen = choice(students)
print("the chosen students was {}".format(chosen))
