import json


pessoa_j = '{"nome": "gabriel","sobrenome": "maurina","vivo": True,"idade": 19,"amigos": ["sara", "erison", "kaue", "teo", "marco"],"aeronaves": [{"tipo": "transporte", "habilidade": 80},{"tipo": "ataque", "habilidade": 100},{"tipo": "defesa", "habilidade": 60}]}'

pessoa = json.loads(pessoa_j)

for c in pessoa:
    print(c)

for i in pessoa.items():
    print(i)
