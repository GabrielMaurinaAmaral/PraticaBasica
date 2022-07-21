palavras = ("aprender", "programar", "linguagem", "python", "curso")

for p in palavras:
    print("\npalavra {} tem ".format(p), end='')
    for letra in p:
        if letra.lower() in "aeiou":
            print(letra)
