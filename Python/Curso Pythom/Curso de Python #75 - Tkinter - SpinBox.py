from tkinter import *

app = Tk()
app.title("SpinBox")
app.geometry("500x300")

spinbox_valores = Spinbox(app, from_=0, to=10)
spinbox_valores.pack()

app.mainloop()
