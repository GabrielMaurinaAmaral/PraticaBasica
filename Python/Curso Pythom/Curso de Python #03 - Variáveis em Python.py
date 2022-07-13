num1 = num2 = rest = 0
canal = "curso CFB"  # variavel global

def funcao():
    canal2 = "Gabriel"  # variavel local
    global canal3  # declara a variavel como global
    canal3 = "variavel global"
    print(canal)
    print(canal2)

funcao()
print(canal3)
