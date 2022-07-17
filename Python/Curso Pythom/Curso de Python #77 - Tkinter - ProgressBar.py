from tkinter import *
from tkinter import ttk


def valor_barra(m):
    cont = 0
    etapas = m/100
    while cont < etapas:
        cont += 1
        i = 0
        while i < 1000000:
            i += 1
        variavel_barra.set(cont)
        app.update()


app = Tk()
app.title("ProgressBar")
app.geometry("500x300")

variavel_barra = DoubleVar()
variavel_barra.set(0)

progress_bar = ttk.Progressbar(app, variable=variavel_barra, maximum=100)
progress_bar.place(x=10, y=10, width=300, height=20)

button = Button(app, text="Definir barra", command=lambda: valor_barra(10000))
button.place(x=10, y=30, width=100, height=20)


app.mainloop()
