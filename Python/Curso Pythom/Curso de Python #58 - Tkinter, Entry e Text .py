import email
from tkinter import *

app = Tk()
app.title("gabriel maurina amral")
app.geometry("500x300")
app.configure(background="#dde")

# anchor=> N=norte, S=sul, E=leste, W=oeste
# anchor=> NE=NORDESTE, SE=suldeste, SW=sudoeste, NW=Noroeste
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
telefone = Text(app)
telefone.place(x=10, y=180, width=300, height=80)


app.mainloop()
