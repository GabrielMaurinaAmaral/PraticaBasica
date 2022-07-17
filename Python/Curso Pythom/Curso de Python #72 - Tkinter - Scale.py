from tkinter import *
from tkinter import ttk


app = Tk()
app.title("ComboBox")
app.geometry("500x300")

label_valor = Label(app, text="valor")
label_valor.pack()

scale_escala = Scale(app, from_=0,to=100,orient=HORIZONTAL)
scale_escala.pack()

app.mainloop()
