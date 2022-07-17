from tkinter import *


def imprimir():
    print(list_box_esportes.get(ACTIVE))


def novo():
    list_box_esportes.insert(END, novo_esporte.get())


app = Tk()
app.title("ComboBox")
app.geometry("500x300")

lista_esportes = ["futbol", "volei", "basquete"]

list_box_esportes = Listbox(app)
for esportes in lista_esportes:
    list_box_esportes.insert(END, esportes)
list_box_esportes.pack()

button_esporte = Button(app, text="imprimir esporte", command=imprimir)
button_esporte.pack()

novo_esporte = Entry(app)
novo_esporte.pack()

button_novo = Button(app, text="inserir esporte", command=novo)
button_novo.pack()

app.mainloop()
