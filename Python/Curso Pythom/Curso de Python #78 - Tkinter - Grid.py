from tkinter import *


app = Tk()
app.title("Grid")
app.geometry("500x300")

label_nome = Label(app, text="gabriel maurina")
label_cidade = Label(app, text="digite um nome: ")
label_pais = Label(app, text="digite sua idade: ")

cidade = Entry(app)
pais = Entry(app)

button = Button(app, text="UIIIIIII")

label_nome.grid(column=0, row=0, columnspan=2, pady=15)
label_cidade.grid(column=0, row=1)
cidade.grid(column=1, row=1)
label_pais.grid(column=0, row=2, sticky='e')  # n, s, e, w
pais.grid(column=1, row=2)

app.mainloop()
