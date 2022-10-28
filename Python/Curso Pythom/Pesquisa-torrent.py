from urllib.request import Request, urlopen
import os
import sys
import subprocess
provedor_1 = "https://solidtorrents.to/search?q="


def formatar_link(termo_busaca, provedor_link):
    """ recebe um termo e um provedor para formatar link """
    termo_mais = termo_busaca.replace(" ", "+")
    # link = provedor_link+termo busca
    link = provedor_link.replace("BUSCAR_MAIS", termo_mais)

    return link


def fazer_requisicoes(termo_busca: str, provedor: str) -> list:
    """
    recebe um provedor 
    """
    link = formatar_link(termo_busca, provedor)
    lista_magnets = []
    contador = 0

    try:
        requisicao = Request(link)                   # faz a requisição
        # le o HTML da pagina na qual é feita a requisição
        webpage = urlopen(requisicao).read()

        texto_pagina = webpage.decode("ISO-8859-1")  # muda parra o ISO
        # sempre que ver um " separar em um item de uma lista
        items = texto_pagina.split('"')

        for item in items:
            if "magnet.?" in item:
                item = item.replace("&#", "=")
                item = item.replace("x3d", "")
                item = item.replace("amp", "")

                if item not in lista_magnets and contador <= 10:
                    lista_magnets.append(item)
                    contador += 1
    except:
        print("ERRO em fazer a requisição com o provedor: " + provedor)

    return lista_magnets


def pegar_torrentes_metadados(lista_magnets) -> list:
    lista_metadado: list = []

    for magnet in lista_magnets:
        nome_torrent = magnet[0]
        nome_torrent = nome_torrent.replace("Bitsearch.to", "")
        nome_torrent = nome_torrent.replace("%5D", "")
        nome_torrent = nome_torrent.replace("%5B", "")

        lista_metadado.append([nome_torrent, magnet[1]])

    return lista_metadado


def main():
    pesquisar = str(input("oque vc quer baixar: "))

    torrents = fazer_requisicoes(pesquisar, provedor_1)
    metadados = pegar_torrentes_metadados(torrents)

    for index in range(0, len(metadados)):
        print(f"{index} - {metadados[index][0]}")

    baixar = int(input("qual torrent deseja baixar: "))
    numero_baixar = metadados[baixar][1]

    # verificar se o sitema opercional é winnão linux
    if sys.platform.startswith('win32'):
        os.startfile(numero_baixar)
    elif sys.platform.startswith('win32'):
        subprocess.Popen(['xdg-open'], numero_baixar, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    return
