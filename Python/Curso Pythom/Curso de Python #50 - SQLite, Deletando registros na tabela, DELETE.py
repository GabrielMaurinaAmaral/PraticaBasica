import sqlite3
from sqlite3 import Error


def criar_conexaoBanco(caminho):
    conexao = None
    try:
        conexao = sqlite3.connect(caminho)
    except Error as erro:
        print(erro)
    return conexao


caminho = "C:/SQlite/Curso Python/Curso Python - Agenda.db"
vconexao = criar_conexaoBanco(caminho)


def remover_banco(conexao, sql):
    try:
        c = conexao.cursor()
        c.execute(sql)
        conexao.commit()
        print("remocao FEITA")
    except Error as erro:
        print(erro)


vsql = "DELETE FROM tabela_contatos WHERE N_CONTATOS=1"
remover_banco(vconexao, vsql)
