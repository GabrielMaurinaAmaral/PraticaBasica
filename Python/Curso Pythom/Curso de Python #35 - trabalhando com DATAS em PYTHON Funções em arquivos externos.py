import datetime

data = datetime.datetime.now()
nascimento = datetime.datetime(2003, 3, 31)

# %a = texto dia da semana abreviado
# %A = texto dia da semana
# %w = numero dia do mes
# %d = numero dia da semana
# %b = texto nome do mes abreviado
# %B = texto mes
# %m = numero do mes
# %y ano com dois digitos
# %Y ano com quatro digitos
# %H hora de 00 a 23
# %I hora de 00 a 12
# %p AM/PM1
# %M minutos
# %s segundos
# %f microsegundos
# %j dia do ano 1 a 365


print(f"{data.day} / {data.month} / {data.year}")
print(nascimento)
print(nascimento.strftime("%Y"))

op = int(input("Deseja saber o dia da semana que você nasceu?\nDigite 1 se a resposta for sim\nDigite 2 se a resposta for não\n"))
if op == 1:
    dia = int(input("Digite o dia em que você nasceu "))
    mes = int(input("Digite o número do mês em que você nasceu "))
    ano = int(input("Digite o ano em que você nasceu "))
    dt = datetime.datetime(ano, mes, dia)
    res = dt.strftime("%A").upper()
    if res == "SUNDAY":
        res = "DOMINGO"
    elif res == "MONDAY":
        res = "SEGUNDA-FEIRA"
    elif res == "TUESDAY":
        res = "TERÇA-FEIRA"
    elif res == "WENDSDAY":
        res = "QUARTA-FEIRA"
    elif res == "THURSDAY":
        res = "QUINTA-FEIRA"
    elif res == "FRIDAY":
        res = "SEXTA"
    elif res == "SATURDAY":
        res = "SÁBADO"
    print("O dia da semana é ", res)
else:
    print("Sem problemas...")
