set_A = set(map(int, input().split()))

for i in range(int(input())):
    set_B = set(map(int, input().split()))
    result = set_B.issubset(set_A)
    
    if result == False:
        print(result)
        break
    
if result == True:
    print(result)
