from tkinter import *
from tkinter import messagebox

#messagebox.showinfo(title="ERRO", message="vc é muito burro pra usar esse codigo")


def monstrar_mensagem(tipo_mensagem, variavel_mensagem):
    if(tipo_mensagem == "1"):
        messagebox.showinfo(title="INFO", message=variavel_mensagem)
    elif(tipo_mensagem == "2"):
        messagebox.showwarning(title="ARNING", message=variavel_mensagem)
    elif(tipo_mensagem == "3"):
        messagebox.showerror(title="ERRO", message=variavel_mensagem)


def resetar_test_box():
    #askyesno/askquestion - SIM ou NÂO - (True ou False)
    #askokcancel - OK ou  CANCELAR - (True ou False)
    #askretrycancel - REPETIR ou  CANCELAR - (True ou False)
    #askyesnocancel - SIM, NAO ou  CANCELAR - (True, False ou None)
    resposta = messagebox.askokcancel("Resetar", "Resetar mesmo?")
    if resposta == True:
        test_box_numero.delete(0, END)


app = Tk()
app.title("Menssagebox")
app.geometry("500x300")

variavel_mensagem = "Vinland Saga é uma manga foda"
variavel_numero = StringVar()

Label(app, text="Tipo de caixa(1|2|3)").pack()
# variavel_numero.set("1")
test_box_numero = Entry(app, textvariable=variavel_numero)
test_box_numero.pack()

button_mensagem = Button(app, text="Mostrar mensagem", command=lambda: monstrar_mensagem(variavel_numero.get(), variavel_mensagem))
button_mensagem.pack()
button_resetar = Button(app, text="Resetar mensagem", command=resetar_test_box)
button_resetar.pack()


app.mainloop()
