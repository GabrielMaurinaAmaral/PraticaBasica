from math import hypot

co = float(input("comprimento do co: "))
ca = float(input("comprimento do ca: "))
hip = hypot(co, ca)
print("a hipotenusa vai medir {:.2f}".format(hip))
