import urllib.request

pagina = urllib.request.urlopen("https://www.google.com.br")
texto = pagina.read().decode("")
print(texto)
