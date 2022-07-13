curso = "Gabriel Maurina Amaral"

print(curso)
print(curso[2:7])
print(curso[1])
print("Tamanho: " + str(len(curso)))

"""as funçôes para strings
   strip = retira os espaços
   lower = transforma em minusculos
   upper = transforma em maiusculo
   replace = substitui strings ou char
   split = vai cortas determinado char da string

"""
rest = "Gabriel" not in curso
print(rest)
rest = "Gabriel" in curso
print(rest)

s1 = "mama"
s2 = " mia"
contatenar = s1+s2
print(contatenar)

cidade = "foz do jorssao"
dia = 30
mes = "marco"
ano = 2003
data = "{}, {} de {} de {}"
print(data.format(cidade, dia, mes, ano))

data = f"{cidade}, {dia} de {mes} de {ano}"
print(data)

#\n \r \t \b
