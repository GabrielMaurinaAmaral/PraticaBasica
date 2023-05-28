import cv2

BLACK = (0, 0, 0)
WHITE = (255, 255, 255)

RED = (0, 0, 255)
GREEN =(0, 255, 0)
BLUE = (255, 0, 0)

# mostrando imagem pelo plt
def show_Image(img):
    from matplotlib import pyplot as plt
    img =  cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    plt.imshow(img)
    plt.show()
    
# crinado imagem usando numpy
def new_Image():
    import numpy as np
    # dtype = np.uint8, pois imagem no opnenCV é um inteiro sem sinal
    # u=sem sinal, int=tipo, 8=bits(0=preto a 255=branco)
    # parametros: (y, x, rgb), tipo de dados
    img = np.zeros((400,400, 3), dtype = np.uint8)
    return img

# salva imagem na pasta
def save_Image(img):
    cv2.imwrite("Python\OpenCV\Meus_code\Foto_Salva.png", img)

# criando circulo todo preenchido
def draw_Circle(img, color):
    center_Coordinates = (200, 200)
    radius = 25
    # parametros: imagem, ponto central(x,y), raio, cores, traço
    cv2.circle(img, center_Coordinates, radius, color, -1)
    
# criando elipse com padrão de ponto central e largura
def draw_Ellipse(img, angle_Ellipse, angle_Start, angle_End, color, thickness):
    center_Coordinates = (200, 200)
    axes_Length = (200, 50)
    # parametros: imagem, ponto central(x,y), largura(x,y), angulo° rotação, angulo abertura, angulo fechamento, cores, traço
    cv2.ellipse(img, center_Coordinates, axes_Length, angle_Ellipse, angle_Start, angle_End, color, thickness)

# ANIMAÇÃO DOS ELETRONS
def animetion_Eletrons(img):
    # define como o video vai ser codificado, no caso é o XVID
    fourcc = cv2.VideoWriter_fourcc('X', 'V', 'I', 'D')
    # escrevendo um arquico de video
    # parametro: nome do arquivo, , qudaros por segundo, dimenções(x,y)
    video_Output = cv2.VideoWriter('Python\OpenCV\Meus_code\_atomo.avi', fourcc, 20.0, (400, 400))
    # quantidade de frame
    frames = 0
    # angulo onde cada eletron vai andar pela elipse
    angle_Electron1 = 0
    angle_Electron2 = 40
    angle_Electron3 = 80
    # geral uma animação onde o eletron da 3 volta
    while angle_Electron1 < 1080:
        # cria uma copia da imagem do atomo
        atom_Image_Copy = img.copy()
        # frame que vai mudando para gerana animação
        draw_Ellipse(atom_Image_Copy, 45, angle_Electron1, angle_Electron1 + 5, WHITE, 15)
        draw_Ellipse(atom_Image_Copy, 90, angle_Electron2, angle_Electron2 + 5, WHITE, 15)
        draw_Ellipse(atom_Image_Copy, 135, angle_Electron3, angle_Electron3 + 5, WHITE, 15)
        # frame a freme vai gerando a animação
        # show_Image(atom_Image_Copy)
        # para que no proximo frame o eletro esteja um pouco na frente que antes
        angle_Electron1 += 10
        angle_Electron2 += 10
        angle_Electron3 += 10
        # salva frame no .ive
        video_Output.write(atom_Image_Copy)
        frames += 1
    video_Output.release()
      
def convert_Gif():
    import os
    os.system("ffmpeg -i Python\OpenCV\Meus_code\_atomo.avi Python\OpenCV\Meus_code\_atomo.gif")
          
def main():
    imagem = new_Image()
    show_Image(imagem)
    # cv2.ellipse(imagem, (200, 200), (200, 50), 0, 0, 360, BLUE, 5)
    draw_Ellipse(imagem, 0, 0, 360, BLUE, 5)
    show_Image(imagem)
    draw_Ellipse(imagem, 45, 0, 360, BLUE, 5)
    show_Image(imagem)
    draw_Ellipse(imagem, 90, 0, 360, BLUE, 5)
    show_Image(imagem)
    draw_Ellipse(imagem, -45, 0, 360, BLUE, 5)
    show_Image(imagem)
    # criando nucleo
    draw_Circle(imagem, RED)
    show_Image(imagem)    
    # salvar a imagem do atomo
    save_Image(imagem)
    # criando a animação
    animetion_Eletrons(imagem)    
    # converter de .ive para gif
    convert_Gif()
    
if __name__ == "__main__":
    main()

