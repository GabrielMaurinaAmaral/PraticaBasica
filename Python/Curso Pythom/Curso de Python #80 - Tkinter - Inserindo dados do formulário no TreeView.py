from tkinter import *
from tkinter import ttk
from tkinter import messagebox


def inserir():
    if variavel_id.get() == "" or variavel_nome.get() == "" or variavel_fone.get() == "":
        messagebox.showinfo(title="ERRO", message="Digite todos os dados")
        return
    tv.insert("", "end", values=(variavel_id.get(),variavel_nome.get(), variavel_fone.get()))
    variavel_id.delete(0,END)
    variavel_nome.delete(0,END)
    variavel_fone.delete(0,END)
    variavel_id.focus()
    
def deletar():
    print()


def obter():
    print()


app = Tk()
app.title("TreeView")
app.geometry("500x300")

label_id = Label(app, text="ID", anchor=W)
label_nome = Label(app, text="Nome", anchor=W)
label_fone = Label(app, text="Fone", anchor=W)
variavel_id = Entry(app)
variavel_nome = Entry(app)
variavel_fone = Entry(app)

tv = ttk.Treeview(app, columns=('id', 'nome', 'fone'), show='headings')
tv.column('id', minwidth=0, width=50)
tv.column('nome', minwidth=0, width=200)
tv.column('fone', minwidth=0, width=200)
tv.heading('id', text='ID')
tv.heading('nome', text='NOME')
tv.heading('fone', text='TELEFONE')
tv.grid(column=0, row=3, columnspan=3, pady=5)

button_inserir = Button(app, text="Inserir", command=inserir)
button_deletar = Button(app, text="Deletar", command=deletar)
button_obter = Button(app, text="Obter", command=obter)
button_inserir.grid(column=0, row=4, sticky='w')
button_deletar.grid(column=1, row=4, sticky='w')
button_obter.grid(column=2, row=4, sticky='w')

label_id.grid(column=0, row=0, sticky='w')
label_nome.grid(column=1, row=0, sticky='w')
label_fone.grid(column=2, row=0, sticky='w')
variavel_id.grid(column=0, row=1)
variavel_nome.grid(column=1, row=1)
variavel_fone.grid(column=2, row=1)

app.mainloop()
