import sqlite3
from sqlite3 import Error
import os

pasta_App = os.path.dirname(__file__)
nome_Banco = pasta_App+"\\Curso Python - Agenda.db"


def criar_Conexao_Banco():
    conexao = None
    try:
        conexao = sqlite3.connect(nome_Banco)
    except Error as erro:
        print(erro)
    return conexao


def dql(query):  # select
    variavel_connexao = criar_Conexao_Banco()
    cursor = variavel_connexao.cursor()
    cursor.execute(query)
    resultado = cursor.fetchall()
    variavel_connexao.close()
    return resultado


def dml(query):  # insert, update, delete
    try:
        variavel_connexao = criar_Conexao_Banco()
        cursor = variavel_connexao.cursor()
        cursor.execute(query)
        variavel_connexao.commit()
        variavel_connexao.close()
    except Error as erro:
        print(erro)
