valores = [2, 5, 3, 6]


def somar(num):
    r = 0
    for n in num:
        r += n
    return r


print(f"{valores}: soma= {somar(valores)}")
