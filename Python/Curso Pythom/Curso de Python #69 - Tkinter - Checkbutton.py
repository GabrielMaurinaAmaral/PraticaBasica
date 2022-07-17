from tkinter import *


def button_futebol():
    if (variavel_futbol.get() == "s"):
        print("FUTEBOL")


def button_volei():
    if (variavel_volei.get() == "s"):
        print("VOLEI")


def button_basquete():
    if (variavel_basquete.get() == "s"):
       print("BASQUETE")


app = Tk()
app.title("Checkbutton")
app.geometry("500x300")

variavel_futbol = StringVar()
variavel_volei = StringVar()
variavel_basquete = StringVar()

frame_quadro_1 = Frame(app, borderwidth=1, relief="solid")
frame_quadro_1.place(x=10, y=10, width=300, height=100)

checkbutton_futebol = Checkbutton(frame_quadro_1, text="Futebol",
                                  variable=variavel_futbol, onvalue="s", offvalue="n", command=button_futebol)
checkbutton_volei = Checkbutton(frame_quadro_1, text="Volei",
                                variable=variavel_volei, onvalue="s", offvalue="n", command=button_volei)
checkbutton_basquete = Checkbutton(frame_quadro_1, text="basquete",
                                   variable=variavel_basquete, onvalue="s", offvalue="n", command=button_basquete)
checkbutton_futebol.pack(side=LEFT)
checkbutton_volei.pack(side=LEFT)
checkbutton_basquete.pack(side=LEFT)

app.mainloop()
