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

nome = input("digite um nome: ")
telefone = input("digite um telefone: ")
email = input("digite um email: ")

#vsql = "INSERT INTO tabela_contatos (T_NOME_CONTATO,T_TELEFONE_CONTATO,T_EMAIL_CONTATO)VALUES('teste_nome','teste_telefone','teste_email')"
vsql = "INSERT INTO tabela_contatos (T_NOME_CONTATO,T_TELEFONE_CONTATO,T_EMAIL_CONTATO)VALUES('" + \
    nome+"','"+telefone+"','"+email+"')"


def inserir_banco(conexao, sql):
    try:
        c = conexao.cursor()
        c.execute(sql)
        conexao.commit()
        print("INSERSAO FEITA")
    except Error as erro:
        print(erro)


inserir_banco(vconexao, vsql)
