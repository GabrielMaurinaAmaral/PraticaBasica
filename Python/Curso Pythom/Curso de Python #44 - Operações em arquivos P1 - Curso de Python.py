# r = read = abrir para leitura
# a = append = anexar no arquivo no final
# w = write = limpa o arquivo e escreve
# x = create = cria um arquivo
# t = texto
# b = binario

nome = "texte.txt"

#f1 = open("C:\CODE\PraticaBasica\Python\Curso Pythom\Curso de Python #44 - Operações em arquivos P1 - Curso de Python/")

f2 = open(nome, "w")
f2.write(str(input("escrever no arquivo texte.text: ")))
f2.close()

f3 = open("texte_1.txt", "a")
f3.write(str(input("escrever no arquivo texte.text: "))) + "\n"
f3.close()

f4 = open("texte_2.txt", "wt")
f4.write(str(input("escrever no arquivo texte.text: ")) + "\n")
f4.close()
