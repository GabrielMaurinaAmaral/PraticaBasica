from tkinter import *
from tkinter import ttk
from tkinter import messagebox
import Banco


def popular():
    tv.delete(*tv.get_children())
    variavel_query = "SELECT * FROM tabela_nomes order by ID"
    linhas = Banco.dql(variavel_query)
    for i in linhas:
        tv.insert("", "end", values=i)


def inserir():
    if variavel_nome.get() == "" or variavel_fone.get() == "":
        messagebox.showinfo(title="ERRO", message="digite todos os dados")
        return
    try:
        variavel_query = "INSERT INTO tabela_nomes (nome, fone) VALUES('" +\
            variavel_nome.get()+"','"+variavel_fone.get()+"')"
        Banco.dml(variavel_query)
    except:
        messagebox.showinfo(title="ERRO", message="erro ao inserir")
        return
    popular()
    variavel_nome.delete(0, END)
    variavel_fone.delete(0, END)
    variavel_nome.focus()


def deletar():
    variavel_id -= 1
    item_selecionado = tv.selection()[0]
    valores = tv.item(item_selecionado, "values")
    variavel_id = valores[0]
    try:
        variavel_query = "DELETE FROM tabela_nomes WHERE id="+variavel_id
        Banco.dml(variavel_query)
    except:
        messagebox.showinfo(title="ERRO", message="erro ao deletar")
        return
    tv.delete(item_selecionado)


def pesquisar():
    tv.delete(*tv.get_children())
    variavel_query = "SELECT * FROM tabela_nomes WHERE nome LIKE '%" + \
        variavel_nome_pesquisar.get()+"%' order by ID"
    linhas = Banco.dql(variavel_query)
    for i in linhas:
        tv.insert("", "end", values=i)


app = Tk()
app.title("TreeView com Banco de Dados")
app.geometry("700x500")

quadro_grid = LabelFrame(app, text="Contatos")
quadro_grid.pack(fill="both", expand="yes", padx=10, pady=10)

tv = ttk.Treeview(quadro_grid, columns=('id', 'nome', 'fone'), show='headings')
tv.column('id', minwidth=0, width=50)
tv.column('nome', minwidth=0, width=250)
tv.column('fone', minwidth=0, width=100)
tv.heading('id', text='ID')
tv.heading('nome', text='NOME')
tv.heading('fone', text='TELEFONE')
tv.pack()
popular()

quadro_inserir = LabelFrame(app, text="Inserir Novos Contatos")
quadro_inserir.pack(fill="both", expand="yes", padx=10, pady=10)

label_nome = Label(quadro_inserir, text="Nome")
label_nome.pack(side="left")
variavel_nome = Entry(quadro_inserir)
variavel_nome.pack(side="left", padx=10)

label_fone = Label(quadro_inserir, text="Fone")
label_fone.pack(side="left")
variavel_fone = Entry(quadro_inserir)
variavel_fone.pack(side="left", padx=10)

button_inserir = Button(quadro_inserir, text="Inserir", command=inserir)
button_inserir.pack(side="left", padx=10)

quadro_pesquisar = LabelFrame(app, text="Pesquisar Contatos")
quadro_pesquisar.pack(fill="both", expand="yes", padx=10, pady=10)

label_id = Label(quadro_pesquisar, text="Nome")
label_id.pack(side="left")
variavel_nome_pesquisar = Entry(quadro_pesquisar)
variavel_nome_pesquisar.pacWk(side="left", padx=10)

button_pesquisar = Button(quadro_pesquisar, text="Pesquisar", command=pesquisar)
button_pesquisar.pack(side="left", padx=10)

button_todos = Button(quadro_pesquisar, text="Mostrar Todos", command=popular)
button_todos.pack(side="left", padx=10)

app.mainloop()
