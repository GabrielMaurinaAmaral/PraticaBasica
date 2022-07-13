import json

carros_dictionary = {"marca": "honda", "modelo": "HB20", "cor": "prata"}
#dictionary -> objeto json

carros_list = ["honda", "HB20", "gol", "palio"]
#list _> array json

carros_tupla = ("honda", "HB20", "gol", "palio")
#tupla -> array json

carros_j = json.dumps(carros_dictionary, indent=4,
                      separators=(":", "="), sort_keys=True)
print(carros_j)
carros_j = json.dumps(carros_list)
print(carros_j)
carros_j = json.dumps(carros_tupla)
print(carros_j)


pessoa = {
    "nome": "gabriel",
    "sobrenome": "maurina",
    "vivo": True,
    "idade": 19,
    "amigos": ["sara", "erison", "kaue", "teo", "marco"],
    "aeronaves": [
        {"tipo": "transporte", "habilidade": 80},
        {"tipo": "ataque", "habilidade": 100},
        {"tipo": "defesa", "habilidade": 60}
    ]
}
