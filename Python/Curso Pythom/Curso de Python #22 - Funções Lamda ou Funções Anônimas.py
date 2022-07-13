soma=lambda a,b:a+b
print(soma(int(input()), int(input())))

print()

multplicacao=lambda a,b,c:(a+b)*c
print(multplicacao(int(input()), int(input()), int(input())))

print()

print((lambda a,b:a+b)(3,2))

print()

r=lambda x,funcao:x+funcao(x)
print(r(2, lambda x:x*x))

