num = int(input("car speed in km/h: "))

if num > 80:
   penalty = (num-80)*7
   print("penalty de U$ {}".format(penalty))
else:
    print("within the speed limit")
