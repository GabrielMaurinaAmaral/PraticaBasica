from tkinter import *
from xml.sax import make_parser
from reportlab.pdfgen import canvas
from reportlab.lib.pagesizes import A4
import os

pastaApp = os.path.dirname(__file__)


def criar_pdf():
    cnv = canvas.Canvas(pastaApp+"\\teste-PDF.pdf", pagesize=A4)
    cnv.drawString(100, 100, "GABRIEL MAURINA AMARAL")
    cnv.drawImage(pastaApp+"\\logo.jpg", mp(0), mp(207))
    cnv.circle(mp(100), mp(100), mp(25))
    cnv.save()


criar_pdf()
