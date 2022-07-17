from tkinter import *


def imprimir_Esporte():
    ve = variavel_esporte.get()
    print(ve)


app = Tk()
app.title("Radio Button")
app.geometry("500x300")

lista_esportes = ["Futebol", "Volei", "Baquete"]

variavel_esporte = StringVar()
variavel_esporte.set(lista_esportes[0])  # valor padrão

option_esporte = OptionMenu(app, variavel_esporte, *lista_esportes)
option_esporte.pack()

button_esporte = Button(app, text="Esporte selecionado",command=imprimir_Esporte)
button_esporte.pack()


app.mainloop()
