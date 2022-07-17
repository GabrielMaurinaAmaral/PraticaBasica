from tkinter import *
from tkinter import ttk


app = Tk()
app.title("ComboBox")
app.geometry("500x300")

lista_esportes = ["Futebol", "Volei", "Basquete"]

label_esportes = Label(app, text="ESPORTES")
label_esportes.pack()

combo_box_esportes = ttk.Combobox(app, values=lista_esportes)
combo_box_esportes.set("Futebol")
combo_box_esportes.pack()

app.mainloop()
