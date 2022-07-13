num1 = int(input())
num2 = int(input())


def soma():
    num3 = num1+num2
    print(f"a soma de {num1} + {num2} = {num3}\n")


def subtrair():
    num3 = num1-num2
    print(f"a subtracao de {num1} - {num2} = {num3}\n")


def multiplicar(n1, n2):
    num3 = n1*n2
    print(f"a multiplicacao de {n1} * {n2} = {num3}\n")


def texto(*t):
    print(t[0])
    print(t[1])
    print(t[2])


soma()
subtrair()
multiplicar(num1, num2)
multiplicar(5, 3)
texto("paulo", "joao", "rian")
