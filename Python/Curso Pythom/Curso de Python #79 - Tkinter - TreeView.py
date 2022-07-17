from tkinter import *
from tkinter import ttk

app = Tk()
app.title("TreeView")
app.geometry("500x300")

lista_nomes = [['0', 'Breno', '9876'], ['1', 'Gabriel', '1234'], ['2', 'Lucio', '6342']]

tv = ttk.Treeview(app, columns=('id', 'nome', 'fone'), show='headings')
tv.column('id', minwidth=0, width=50)
tv.column('nome', minwidth=0, width=200)
tv.column('fone', minwidth=0, width=200)
tv.heading('id', text='ID')
tv.heading('nome', text='NOME')
tv.heading('fone', text='TELEFONE')
tv.pack()

for (i, n, f) in lista_nomes:
    tv.insert("", "end", values=(i, n, f))

app.mainloop()
