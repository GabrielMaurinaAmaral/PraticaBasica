from tkinter import *
from tkinter import ttk
app = Tk()
app.title("abas notebbok")
app.geometry("500x300")

note = ttk.Notebook(app)
note.place(x=10, y=10, width=300, height=100)

tabela_1=Frame(note)
note.add(tabela_1, text="oloco")

tabela_2=Frame(note)
note.add(tabela_2, text="uiiii")

app.mainloop()
