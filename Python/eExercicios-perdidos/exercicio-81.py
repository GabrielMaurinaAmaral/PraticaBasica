vector = []
while True:
    vector.append(input("enter a nember: "))
    opc = str(input("continue? "))

    if opc in "Nn":
        break

print("vector size ", len(vector))
vector.sort(reverse=True)
print("vector is ", vector)
## vetor.sort() arruma os vetor de forma cressente
## vetor.sort(reverse=True) arruma os vetor de forma cressente
if 5 in vector:
   print("yes")
else:
    print("no")
