import numpy as np
import cv2
import time

ESC = 27

def on_Change(value):
    #print("valor alterado", value)
    pass

def main():
    imagem = cv2.imread("C:\CODE\PraticaBasica\Python\OpenCV\Meus_code\imagem_teste.png")
    window_Title= "ajuste de Bilho e Contraste"
    
    # cria janela
    cv2.namedWindow(window_Title)
    
    # cria trackbar
    # parametros: nome da barra, janela que vai estar 
    cv2.createTrackbar("contraste", window_Title, 0, 100, on_Change)
   
    
    before_contrast = 0
    update_contrast = False
    counter_time = 0
   
    # loop pra que saia da janela só quando presscionar ESC
    while True:
        # le a barra
        current_contrast = cv2.getTrackbarPos("contraste", window_Title)
        
        #valor de contraste do trackbar foi alterado pelo usuário
        if before_contrast != current_contrast:
            update_contrast = True
            counter_time = time.time()
            # atulaiza
            before_contrast = current_contrast
       
        #se tiver passado 1 segundo desde que o usuário mexeu em algum trackbar
        if time.time() - counter_time > 1:
            #se tiver sido marcado que é pra atualizar contraste ou brilho
            if update_contrast == True:
                copy_img = imagem.copy()
                height, width, channels = imagem.shape
    
                #para cada informação de cor, de cada pixel, atualizamos o contraste
                for y in range(height):
                    for x in range(width):
                        for c in range(channels):
                            copy_img[y][x][c] *= current_contrast/100
                # copy_img = cv2.convertScaleAbs(imagem, alpha=current_contrast / 100) 
                update_contrast = False
                
        cv2.imshow(window_Title, copy_img)    
        # le o tecla precionada
        teclado = cv2.waitKey(0)
        if teclado == ESC:
            break
    
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()