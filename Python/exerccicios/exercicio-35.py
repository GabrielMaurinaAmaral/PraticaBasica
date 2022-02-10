side1 = int(input("fist side: "))
side2 = int(input("second side: "))
side3 = int(input("third side: "))

if side1 < side2+side3 and side2 < side1+side3 and side3 < side1+side2:
    print("it's a triangle")
else:
    print("it's not a triangle")
