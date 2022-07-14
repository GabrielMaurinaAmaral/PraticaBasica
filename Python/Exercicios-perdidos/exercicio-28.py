from random import randint
print("="*20)
print("tente adivinhar um numero entre 0 a 5")
print("="*20)

result = randint(0, 5)
print(result)
num = int(input("escolha um numero: "))

if num == result:
    print("ACERTOU")
else:
    print("ERROU")
