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


def atualizar_banco(conexao, sql):
    try:
        c = conexao.cursor()
        c.execute(sql)
        conexao.commit()
        print("atualizacao FEITA")
    except Error as erro:
        print(erro)


vsql = "UPDATE tabela_contatos SET T_NOME_CONTATO='Erison', T_TELEFONE_CONTATO='(46)3943-4432', T_EMAIL_CONTATO='gabrielzinho@gmail.com' WHERE N_CONTATOS=1"
atualizar_banco(vconexao, vsql)
