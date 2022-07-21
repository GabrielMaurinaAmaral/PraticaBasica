from tkinter import *
from reportlab.pdfgen import canvas
from reportlab.lib.pagesizes import A4
import os

pastaApp = os.path.dirname(__file__)


def criar_pdf():
    cnv = canvas.Canvas(pastaApp+"\\teste-PDF.pdf", pagesize=A4)
    cnv.drawString(100, 100, "GABRIEL MAURINA AMARAL")
    cnv.save()

criar_pdf()