import re
import os

nome = "texte.txt"
caminho = "C:/CODE/PraticaBasica/Python/"

#f = open(caminho+nome, "x")
#f.close

if os.path.exists(nome):
    print("arquivo existente")
else:
    f = open(nome, "x")

if os.path.exists("texte_1.txt"):
    os.remove("texte_1.txt")
else:
    print("arquivo inexistente")

f.close
