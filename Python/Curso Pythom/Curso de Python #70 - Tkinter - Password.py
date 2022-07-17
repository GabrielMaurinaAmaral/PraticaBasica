from tkinter import *


def imprimir_senha():
    print("Senha digitada: "+variavel_senha.get())


app = Tk()
app.title("Checkbutton")
app.geometry("500x300")

variavel_senha = StringVar()

password_senha = Entry(app, textvariable=variavel_senha, show="*")
password_senha.pack()

button_mostrar_senha = Button(app, text="Imprimir Senha", command=imprimir_senha)
button_mostrar_senha.pack()

app.mainloop()