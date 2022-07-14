from tkinter import *
import os
import Banco


def gravar_dados():
    if tb_nome.get() != "":
        variavel_nome = tb_nome.get()
        variavel_telefone = tb_telefone.get()
        variavel_email = tb_email.get()
        variavel_obs = tb_obs.get("1.0", END)
        variavel_query = "INSERT INTO tabela_contatos (T_NOME_CONTATO, T_TELEFONE_CONTATO, T_EMAIL_CONTATO, T_OBS_CONTATO) VALUES('" +\
            variavel_nome+"','"+variavel_telefone+"','"+variavel_email+"','"+variavel_obs+"')"
        Banco.dml(variavel_query)
        tb_nome.delete(0, END)
        tb_telefone.delete(0, END)
        tb_email.delete(0, END)
        tb_obs.delete("1.0", END)

        print("Dados Gravados")
    else:
        print("Erro")


app = Tk()
app.title("gabriel maurina amral")
app.geometry("500x300")
app.configure(background="#dde")

Label(app, text="Nome", background="#fff", foreground="#009",
      anchor=W).place(x=10, y=10, width=60, height=20)
tb_nome = Entry(app)
tb_nome.place(x=10, y=30, width=200, height=20)

Label(app, text="Telefone", background="#fff", foreground="#009",
      anchor=W).place(x=10, y=60, width=60, height=20)
tb_telefone = Entry(app)
tb_telefone.place(x=10, y=80, width=100, height=20)

Label(app, text="Email", background="#fff", foreground="#009",
      anchor=W).place(x=10, y=110, width=60, height=20)
tb_email = Entry(app)
tb_email.place(x=10, y=130, width=300, height=20)

Label(app, text="OBS", background="#fff", foreground="#009",
      anchor=W).place(x=10, y=160, width=60, height=20)
tb_obs = Text(app)
tb_obs.place(x=10, y=180, width=300, height=80)

Button(app, text="Gravar", command=gravar_dados).place(
    x=10, y=270, width=100, height=20)


app.mainloop()
