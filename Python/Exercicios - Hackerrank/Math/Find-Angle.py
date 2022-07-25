import math

AB = int(input())
BC = int(input())

H = math.sqrt(AB**2 + BC**2)
H = H/2.0
BC = BC/2.0

Output = int(round(math.degrees(math.acos(BC/H))))

Output = str(Output)

print(Output+"°")
