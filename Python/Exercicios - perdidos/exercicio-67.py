i=0

while i>=0:
    i=int(input("enter a number: "))
    print("="*30)
    
    for j in range(0,11):
        print("{} x {} = {}".format(i,j,i*j))
    
    print("="*30)

print("the end")