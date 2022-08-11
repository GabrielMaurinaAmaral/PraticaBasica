import math

class Points(object):
    def __init__(self, x, y, z):

    def __sub__(self, no):

    def dot(self, no):

    def cross(self, no):

    def absolute(self):
        return pow((self.x ** 2 + self.y ** 2 + self.z ** 2), 0.5)


if __name__ == '__main__':
    points = list()

    for i in range(4):
        pontos = list(map(float, input().split()))
        points.append(pontos)
        
    a = Points(*points[0])
    b = Points(*points[1])
    c = Points(*points[2])
    d = Points(*points[3])

    x = (b - a).cross(c - b)
    y = (c - b).cross(d - c)
    angle = math.acos(x.dot(y) / (x.absolute() * y.absolute()))

    print("%.2f" % math.degrees(angle))
