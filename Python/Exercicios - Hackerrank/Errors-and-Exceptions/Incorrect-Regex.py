import re

tam = int(input())
for _ in range(tam):
    try:
        re.compile(input())
        resposta = True
    except re.error:
        resposta = False
    print(resposta)
