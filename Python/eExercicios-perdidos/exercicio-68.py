import random

result = 0
cont = 0

while result == 0:
    print("="*20)
    str1 = str(input("par ou impar(P/I): ")).upper().strip()

    if str1 == "I" or str1 == "P":
        
        player = int(input("Enter a number: "))
        print("="*20)
        computer = random.randrange(1, 10)
        soma = player+computer

        print("{} + {} = {}".format(player, computer, soma))

        if str1 == "I":
            if soma % 2 != 0:
                cont += 1
                print("you wins")
            else:
                print("you lose")
                result = 1
        else:
            if soma % 2 == 0:
                cont += 1
                print("you wins")
            else:
                print("you lose")
                result = 1

print("="*20)
print("you won {} times".format(cont))
print("="*20)
