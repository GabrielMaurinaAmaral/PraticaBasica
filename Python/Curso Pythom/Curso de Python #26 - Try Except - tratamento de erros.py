try:
    print(x)
# except NameError:
#     print("ERROUUUUUUUUU")
except:
    print("erro no programa")
else:
    print("tudo certo")
finally:
    print("final do tratamento de erro")

num = 10
if num < 1:
    raise Exception("valor nao permitido")

a = "gabriel"

if not type(a) is int:
    raise Exception("somenre numeros permitidos")
else:
    print(str(num))
