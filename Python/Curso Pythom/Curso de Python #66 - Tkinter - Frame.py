from tkinter import *
from tkinter import messagebox

def monstrar_mensagem(tipo_mensagem, variavel_mensagem):
    if(tipo_mensagem == "1"):
        messagebox.showinfo(title="INFO", message=variavel_mensagem)
    elif(tipo_mensagem == "2"):
        messagebox.showwarning(title="ARNING", message=variavel_mensagem)
    elif(tipo_mensagem == "3"):
        messagebox.showerror(title="ERRO", message=variavel_mensagem)


def resetar_test_box():
    resposta = messagebox.askokcancel("Resetar", "Resetar mesmo?")
    if resposta == True:
        test_box_numero.delete(0, END)


app = Tk()
app.title("Menssagebox")
app.geometry("500x300")

variavel_mensagem = "Vinland Saga é uma manga foda"
variavel_numero = StringVar()

#relief (flat, raised, sunken, solid)
frame=Frame(app, borderwidth=1, relief="solid", background="#345")
frame.place(x=10, y=10, width=300, height=100)

Label(frame, text="Tipo de caixa(1|2|3)").place(x=10, y=10, width=150, height=20)
test_box_numero = Entry(frame, textvariable=variavel_numero)
test_box_numero.place(x=10, y=30, width=150, height=20)
button_mensagem = Button(frame, text="Mostrar mensagem", command=lambda: monstrar_mensagem(variavel_numero.get(), variavel_mensagem))
button_mensagem.place(x=10, y=50, width=150, height=20)
button_resetar = Button(frame, text="Resetar mensagem", command=resetar_test_box)
button_resetar.place(x=10, y=70, width=150, height=20)


app.mainloop()
