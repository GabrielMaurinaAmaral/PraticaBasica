import re

texto = "gabriel@gmail.com"
texto = re.split("@", texto)
texto = re.split(".", texto[0])

print(texto)
