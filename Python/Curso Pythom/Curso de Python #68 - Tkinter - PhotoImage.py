from tkinter import *
import os
from tkinter.tix import TList

pasta_app = os.path.dirname(__file__)

app = Tk()
app.title("PhotoImage")
app.geometry("500x300")

img = PhotoImage(file=pasta_app+"\\logo.gif")
label_logo = Label(app, image=img)
label_logo.place(x=10, y=10)

app.mainloop()
