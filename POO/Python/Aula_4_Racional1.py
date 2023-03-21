from Aula_4_Racional import Fracao

f1 = Fracao()
f2 = Fracao(3)
f3 = Fracao(3, 9)
f4 = Fracao(12, 24)

f1.imprimirFracao()
f2.imprimirFracao()
f3.imprimirFracao()
f4.imprimirFracao()

print("\n SOMA -------------------------")
f1.somar(f2)
f3.somar(f4)
f1.imprimirFracao()
f3.imprimirFracao()

print("\n SUBTRAIR-------------------------")
f2.subtrair(f1)
f4.subtrair(f3)
f2.imprimirFracao()
f4.imprimirFracao()

print("\n MULTIPLICAR-------------------------")
f1.multiplicar(f3)
f2.multiplicar(f4)
f1.imprimirFracao()
f2.imprimirFracao()

print("\n DIVIDIR-------------------------")
f3.dividir(f1)
f4.dividir(f2)
f3.imprimirFracao()
f4.imprimirFracao()

print("\n-------------------------")
f1.imprimirNumerico(0)
f2.imprimirNumerico(1)
f3.imprimirNumerico(2)
f4.imprimirNumerico(3)
