from tkinter import *


def imprimir_Esporte():
    ve = variavel_esporte.get()
    print(ve)


def imprimir_Cor():
    vc = variavel_cor.get()
    print(vc)


app = Tk()
app.title("Radio Button")
app.geometry("500x300")

variavel_esporte = StringVar()
variavel_cor = StringVar()

#radio button esporte
bola_esportes = Label(app, text="Esportes")
bola_esportes.pack()

radio_button_futebol = Radiobutton(
    app, text="Futebol", value="f", variable=variavel_esporte)
radio_button_futebol.pack()

radio_button_volei = Radiobutton(
    app, text="Volei", value="v", variable=variavel_esporte)
radio_button_volei.pack()

radio_button_basquete = Radiobutton(
    app, text="Basquete", value="b", variable=variavel_esporte)
radio_button_basquete.pack()

button_esporte = Button(app, text="Esporte selecionado",
                        command=imprimir_Esporte)
button_esporte.pack()

#radio button cor
radio_button_vermelho = Radiobutton(
    app, text="Vermelho", value="#f00", variable=variavel_cor)
radio_button_vermelho.pack()

radio_button_verde = Radiobutton(
    app, text="Verde", value="#0F0", variable=variavel_cor)
radio_button_verde.pack()

button_cor = Button(app, text="Cor selecionado", command=imprimir_Cor)
button_cor.pack()

app.mainloop()
