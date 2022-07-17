from tkinter import *

app = Tk()
app.title("ComboBox")
app.geometry("500x300")

label_frame = LabelFrame(app, text="Esportes", borderwidth=1, relief="solid")
label_frame.place(x=10, y=10, width=300, height=100)

app.mainloop()
