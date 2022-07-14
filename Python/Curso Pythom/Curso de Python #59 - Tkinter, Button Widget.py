from tkinter import *
import os

c = os.path.dirname(__file__)
nome_arquivo = c+"\\nomes.txt"


def imprimir_dados():
    arquivo = open(nome_arquivo, "a")
    arquivo.write("Nome....: %s \n" % nome.get())
    arquivo.write("Telefone: %s \n" % telefone.get())
    arquivo.write("Email...: %s \n" % email.get())# inicio do texto até o final
    arquivo.write("Obs.....: %s \n" % obs.get("1.0", END))
    arquivo.close()

app = Tk()
app.title("gabriel maurina amral")
app.geometry("500x300")
app.configure(background="#dde")

Label(app, text="Nome", background="#fff", foreground="#009",
      anchor=W).place(x=10, y=10, width=60, height=20)
nome = Entry(app)
nome.place(x=10, y=30, width=200, height=20)

Label(app, text="Telefone", background="#fff", foreground="#009",
      anchor=W).place(x=10, y=60, width=60, height=20)
telefone = Entry(app)
telefone.place(x=10, y=80, width=100, height=20)

Label(app, text="Email", background="#fff", foreground="#009",
      anchor=W).place(x=10, y=110, width=60, height=20)
email = Entry(app)
email.place(x=10, y=130, width=300, height=20)

Label(app, text="OBS", background="#fff", foreground="#009",
      anchor=W).place(x=10, y=160, width=60, height=20)
obs = Text(app)
obs.place(x=10, y=180, width=300, height=80)

Button(app, text="Gravar", command=imprimir_dados).place(
    x=10, y=270, width=100, height=20)


app.mainloop()
