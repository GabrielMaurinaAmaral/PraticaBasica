frase = str(input("digite uma frese: ")).strip().upper()
palavras = frase.split()
junto = ''.join(palavras)
inverso=''
for letra in range(len(junto)-1,-1,-1):
    inverso+=junto[letra]

if inverso==junto:
    print(junto, inverso)
    print("palintromo")

else:
    print(junto, inverso)
    print("mao palintromo")
