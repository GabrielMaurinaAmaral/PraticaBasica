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


def consultar_banco(conexao, sql):
    c = conexao.cursor()
    c.execute(sql)
    resultado = c.fetchall()
    return resultado


#vsql = "SELECT * FROM tabela_contatos WHERE T_NOME_CONTATO LiKE 'B%'"
vsql = "SELECT * FROM tabela_contatos"
res = consultar_banco(vconexao, vsql)

for r in res:
    print(r)
