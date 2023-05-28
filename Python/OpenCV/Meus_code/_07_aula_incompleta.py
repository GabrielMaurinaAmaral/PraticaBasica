import cv2
import numpy as np

BLACK = (0, 0, 0)

def show_Image(img):
    from matplotlib import pyplot as plt
    plt.imshow(img)
    plt.show()
    
def draw_Line(image, start_Point, end_Point, color = BLACK, thickness = 5):
    # imagem que vai desenha em cima
    # parametros: imagem, ponto inicial(x,y), ponto final(x,y), cor, traço
    cv2.line(image, start_Point, end_Point, color, thickness)
    
def draw_Board(): 
    Board = np.empty([400, 300, 3], dtype = np.uint8)
    # fill -> cor do fundo
    Board.fill(255)
    # senha as quatro linha do jogo da velha
    draw_Line(Board, (100, 100), (100, 300))
    draw_Line(Board, (200, 100), (200, 300))
    draw_Line(Board, (50, 150), (250, 150))
    draw_Line(Board, (50, 250), (250, 250))
    
    show_Image(Board)
    
def main():
    draw_Board()
    
if __name__ == "__main__":
    main()