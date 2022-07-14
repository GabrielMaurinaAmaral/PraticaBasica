import random
import os
erros = 0
sorteado = random.randint(0, 100)
jogador = int(input("adivinha um numero de 0 a 100: "))
while(sorteado != jogador):
    os.system('cls')
    if(sorteado > jogador):
        print("Errou, o numero e maior")
    elif(sorteado < jogador):
        print("Errou, o numero e menor")
    erros += 1
    jogador = int(input("adivinha um numero de 0 a 100: "))

print(
    f"parabens vc acertou o numero era {sorteado} vc preciso de apenas {erros} tentativas")
