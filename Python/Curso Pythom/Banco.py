import sqlite3
from sqlite3 import Error
import os

pastaApp = os.path.dirname(__file__)
nomeBanco = pastaApp+"\\Curso Python - Nomes.db"


def conexaoBanco():
    conexao = None
    try:
        conexao = sqlite3.connect(nomeBanco)
    except Error as erro:
        print(erro)
    return conexao


def dql(query):
    variavel_conexao = conexaoBanco()
    c = variavel_conexao.cursor()
    c.execute(query)
    resultado = c.fetchall()
    variavel_conexao.close()
    return resultado


def dml(query):
    try:
        variavel_conexao = conexaoBanco()
        c = variavel_conexao.cursor()
        c.execute(query)
        variavel_conexao.commit()
        variavel_conexao.close()
    except Error as erro:
        print(erro)
