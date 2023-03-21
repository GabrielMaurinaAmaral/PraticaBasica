from Aula_4_Complexo import Complexo

c1 = Complexo()
c2 = Complexo(4)
c3 = Complexo(6, 9)

c1.inicializarComplexo(2, 5)
c2.inicializarComplexo(2, 5)

c1.imprimirComplexo()
c2.imprimirComplexo()
c3.imprimirComplexo()

print(c1.elgual(c2))
print(c1.elgual(c3))

c1.soma(c2)
c1.imprimirComplexo()

c2.subtrai(c3)
c2.imprimirComplexo()

c1.multiplica(c2)
c1.imprimirComplexo()

c1.divide(c3)
c1.imprimirComplexo()
