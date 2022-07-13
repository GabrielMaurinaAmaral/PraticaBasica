import sqlite3
from sqlite3 import Error

caminho = "C:/SQlite/Curso Python/Curso Python - Agenda.db"


def criar_conexaoBanco(caminho):
    conexao = None
    try:
        conexao = sqlite3.connect(caminho)
    except Error as erro:
        print(erro)
    return conexao
vconexao = criar_conexaoBanco(caminho)


vsql = "CREATE TABLE tabela_contatos(N_CONTATOS INTEGER PRIMARY KEY AUTOINCREMENT,T_NOME_CONTATO VARCHAR(30),T_TELEFONE_CONTATO VARCHAR(14),T_EMAIL_CONTATO VARCHAR(30))"


def criar_tabelaBanco(conexao, sql):
    try:
        c = conexao.cursor()
        c.execute(sql)
        print("tabela criada")
    except Error as erro:
        print(erro)


criar_tabelaBanco(vconexao, vsql)

vconexao.close()
