from tkinter import *  # importa tudo do tkinter/biblioteca

app = Tk()
app.title("Gabriel Maurina Amaral")  # Titulo do app
app.geometry("500x300")  # tamannho da janela
app.configure(background="#008")  # cor de funda da janela

txt1 = Label(app, text="Gabriel Mauirna Amaral",background="#008", foreground="#fff")
txt1.place(x=10, y=10, width=100, height=20)

vtxt = "Modulo Tkinter"
vbg = "#ff0"
vfg = "#000"
txt2 = Label(app, text=vtxt, background=vbg, foreground=vfg)
txt2.pack(ipadx=20, ipady=20, padx=10, pady=10, side="top", fill=Y, expand=True)# conteiner



app.mainloop()
