import os
import sqlite3
from sqlite3 import Error


def conexao_agenda_banco():
    caminho = "C:/SQlite/Curso Python/Curso Python - Agenda.db"
    conexao = None
    try:
        conexao = sqlite3.connect(caminho)
    except Error as erro:
        print(erro)
    return conexao


vconexao = conexao_agenda_banco()


def menu_principal():
    os.system("cls")
    print("1 - inserir novo registro")
    print("2 - deletar registro")
    print("3 - atualizar registro")
    print("4 - consultar registro por ID registro")
    print("5 - consultar registro por nome registro")
    print("6 - sair")


def query(conexao, sql):
    try:
        c = conexao.cursor()
        c.execute(sql)
        conexao.commit()
    except Error as erro:
        print(erro)
    finally:
        print("operacao realizada com sucesso")
        #conexao.close()


def consultar(conexao, sql):
    c = conexao.cursor()
    c.execute(sql)
    resultado = c.fetchall()
    #conexao.close()
    return resultado


def menu_inserir():
    os.system("cls")
    nome = input("digite o nome: ")
    telefone = input("digite o telefone: ")
    email = input("digite o email: ")
    vsql = "INSERT INTO tabela_contatos (T_NOME_CONTATO,T_TELEFONE_CONTATO, T_EMAIL_CONTATO) VALUES('"+nome+"','"+telefone+"','"+email+"')"
    query(vconexao, vsql)


def menu_remover():
    os.system("cls")
    id = input("Digite o ID do registro a ser deletado: ")
    vsql = "DELETE FROM tabela_contatos WHERE N_CONTATOS="+id
    query(vconexao, vsql)


def menu_atualizar():
    os.system("cls")
    id = input("Digite o ID do registro a ser deletado: ")
    r = consultar(vconexao, "SELECT * FROM tabela_contatos WHERE N_CONTATOS="+id)
    rNome = r[0][1]
    rTelefone = r[0][2]
    rEmail = r[0][3]
    nome = input("digite o nome: ")
    telefone = input("digite o telefone: ")
    email = input("digite o email: ")
    if(len(nome) == 0):
        nome = rNome
    if(len(telefone) == 0):
        nome = rTelefone
    if(len(email) == 0):
        nome = rEmail
    vsql = "UPDETE tabela_contatos SET T_NOME_CONTATO='"+nome+"',T_TELEFONE_CONTATO='"+telefone+"', T_EMAIL_CONTATO='"+email+"' WHERE N_CONTATOS="+id
    query(vconexao, vsql)


def menu_consultar_id():
    vsql = "SELECT * FROM tabela_contatos"
    resultado = consultar(vconexao, vsql)
    limite = 10
    cont = 0
    for r in resultado:
        print("ID: {0:_<3} - Nome:{1:_<30} - Telefone:{2:_<14} - Email:{3:_<30}".format(r[0], r[1], r[2]))
        cont += 1
        if(cont >= limite):
            cont = 0
            os.system("pause")
            os.system("cls")
    print("Fim da lista")
    os.system("pause")


def menu_consultar_nome():
    nome = input("Digite o nome: ")
    vsql = "SELECT * FROM tabela_contatos WHERE T_NOME_CONTATO LIKE '%"+nome+"%'"
    resultado = consultar(vconexao, vsql)
    limite = 10
    cont = 0
    for r in resultado:
        print("ID: {0:_<3} - Nome:{1:_<30} - Telefone:{2:_<14} - Email:{3:_<30}".format(r[0], r[1], r[2]))
        cont += 1
        if(cont >= limite):
            cont = 0
            os.system("pause")
            os.system("cls")
    print("Fim da lista")
    os.system("pause")


opcao = 0
while opcao != 6:
    menu_principal()
    opcao = int(input("Digite sua opcao: "))
    if opcao == 1:
        menu_inserir()
    elif opcao == 2:
        menu_remover()
    elif opcao == 3:
        menu_atualizar()
    elif opcao == 4:
        menu_consultar_id()
    elif opcao == 5:
        menu_consultar_nome()
    elif opcao == 6:
        os.system("cls")
        print("programa finalizado")
        os.system("pause")

vconexao.close()
os.system("pause")
