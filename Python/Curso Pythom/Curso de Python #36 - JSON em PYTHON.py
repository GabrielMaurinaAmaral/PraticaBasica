import json

carros_json = '{"marca":"honda","modelo":"HB20","cor":"prata"}'

carros = json.loads(carros_json)

print(carros)
print(carros["marca"])

for x in carros:
    print(x)

for y, x in carros.items():
    print(f"{y} - {x}")
