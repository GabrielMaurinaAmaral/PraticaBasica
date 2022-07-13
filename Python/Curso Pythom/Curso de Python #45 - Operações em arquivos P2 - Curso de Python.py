import re
f = open("texte.txt", "rt")
print(f.read()+"\n")
f.close()

f1 = open("texte_1.txt", "rt")
print(f1.readline()+"\n")
f1.close()

f2 = open("texte_2.txt", "rt")
for l in f2:
    print(l)
f2.close()

f = open("texte.txt", "wt")
f.write(str(input("escrever no arquivo texte.text: ")))
resposta = (str(input("escrever algo pra substituir: ")))
f.close()

f = open("texte.txt", "rt")
texto_substituido = re.sub(" ", resposta, f.readline())
f.close()

f = open("texte.txt", "at")
f.write(texto_substituido+"\n")
f.close()
