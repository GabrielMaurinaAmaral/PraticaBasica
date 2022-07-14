from tkinter import *
import os

pasta_App = os.path.dirname(__file__)
nome_Banco = pasta_App+"\\Curso Python - Agenda.db"


def novo_Contato():
    exec(open(pasta_App+"\\Novo_Contato.py").read())


def pesquisar_Contato():
    print()


def deletar_Contato():
    print()


def dados_Manutencao():
    print()


def gabrie_Maurina():
    print()


#criar a janela
app = Tk()
app.title("Agenda")
app.geometry("500x300")
app.configure(background="#dde")

#criar a barra de menu
barra_Menu = Menu(app)
#coluna contatos
menu_Contatos = Menu(barra_Menu, tearoff=0)
menu_Contatos.add_command(label="Novo", command=novo_Contato)
menu_Contatos.add_command(label="Pesquisar", command=pesquisar_Contato)
menu_Contatos.add_command(label="Deleter", command=deletar_Contato)
menu_Contatos.add_separator()  # vai separar os items com uma linha
# comanto para aparecer na janela
menu_Contatos.add_command(label="Fechar", command=app.quit())
barra_Menu.add_cascade(label="Contatos", menu=menu_Contatos)

#coluna manuteção
menu_Manutencao = Menu(barra_Menu, tearoff=0)
menu_Manutencao.add_command(label="Banco de Dados", command=dados_Manutencao())
barra_Menu.add_cascade(label="Manutenção", menu=menu_Manutencao)

#coluna manuteção
menu_Manutencao = Menu(barra_Menu, tearoff=0)
menu_Manutencao.add_command(label="Gabriel Maurina", command=gabrie_Maurina())
barra_Menu.add_cascade(label="Sobre", menu=menu_Manutencao)


app.config(menu=barra_Menu)  # para aparecer a barra de menu

app.mainloop()  # rodar em loop
