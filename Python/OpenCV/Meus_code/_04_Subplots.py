import numpy as np
import cv2
from matplotlib import pyplot as plt

# PLOTS
def plot_Single_Image():
    #criando grid com a imagem original apenas
    img_Original = cv2.imread("Python\OpenCV\Meus_code\imagem_teste.png")
    show_Image_Grid(img_Original, "Foto da Ada")

def plot_TwoImage_Vertical():
    img_Original = cv2.imread("Python\OpenCV\Meus_code\imagem_teste.png")
    img_Replicate = cv2.copyMakeBorder(img_Original, 200, 100, 50, 10, cv2.BORDER_REPLICATE)

    #criando grid com 2 imagens, a segunda com borda replicada
    imgs_Array = [img_Original, img_Replicate]
    title = 'Imagem Original e Imagem com Borda Replicada'
    show_Multiple_Image_Grid(imgs_Array, title, 1, 2)

def plot_Two_Image_Horizontal():
    img_Original = cv2.imread("Python\OpenCV\Meus_code\imagem_teste.png")
    img_Replicate = cv2.copyMakeBorder(img_Original, 200, 100, 50, 25, cv2.BORDER_REPLICATE)

    #criando grid com 2 imagens, a segunda com borda replicada
    imgs_Array = [img_Original, img_Replicate]
    title = 'Imagem Original e Imagem com Borda Replicada'
    show_Multiple_Image_Grid(imgs_Array, title, 2, 1)
    
def plot_Three_Images():
    img_Original = cv2.imread("Python\OpenCV\Meus_code\imagem_teste.png")
    img_Replicate = cv2.copyMakeBorder(img_Original, 100, 100, 100, 100, cv2.BORDER_REPLICATE)
    img_Reflect = cv2.copyMakeBorder(img_Original, 100, 100, 100, 100, cv2.BORDER_REFLECT)
    img_Transparent = np.ones((img_Original.shape[0], img_Original.shape[1], 4), np.uint8) * 255

    #criando grid com 3 imagens, a segunda com borda replicada e a terceira com borda de espelho
    #a ultima imagem é transparente
    imgs_Array = [img_Original, img_Replicate, img_Reflect, img_Transparent]
    titles_Array = ['Original', 'Borda Replicada', 'Borda de Espelho', '']
    show_Multiple_Image_Grid(imgs_Array, titles_Array, 2, 2)

def plot_FourImages():
    img_Original = cv2.imread("Python\OpenCV\Meus_code\imagem_teste.png")
    img_Replicate = cv2.copyMakeBorder(img_Original, 100, 100, 100, 100, cv2.BORDER_REPLICATE)
    img_Reflect = cv2.copyMakeBorder(img_Original, 100, 100, 100, 100, cv2.BORDER_REFLECT)
    img_Reflect101 = cv2.copyMakeBorder(img_Original, 100, 100, 100, 100, cv2.BORDER_REFLECT_101)

    #criando grid com 4 imagens, a segunda com borda replicada e a terceira e quarta com borda de espelho
    imgs_Array = [img_Original, img_Replicate, img_Reflect, img_Reflect101]
    titles_Array = ['Original', 'Borda Replicada', 'Borda de Espelho', 'Borda de Espelho 2']
    show_Multiple_Image_Grid(imgs_Array, titles_Array, 2, 2)

def plot_SixImages():
    img_Original = cv2.imread("Python\OpenCV\Meus_code\imagem_teste.png")
    img_Replicate = cv2.copyMakeBorder(img_Original, 100, 100, 100, 100, cv2.BORDER_REPLICATE)
    img_Reflect = cv2.copyMakeBorder(img_Original, 100, 100, 100, 100, cv2.BORDER_REFLECT)
    img_Reflect101 = cv2.copyMakeBorder(img_Original, 100, 100, 100, 100, cv2.BORDER_REFLECT_101)
    img_Wrap = cv2.copyMakeBorder(img_Original, 100, 100, 100, 100, cv2.BORDER_WRAP)

    BLUE = [255, 0, 0]
    imgConstant = cv2.copyMakeBorder(img_Original, 100, 100, 100, 100, cv2.BORDER_CONSTANT, value = BLUE)

    #criando grid com 6 imagens, a segunda com borda replicada e a terceira e quarta com borda de espelho
    #constant insere uma moldura e wrap só olhando pra entender =)
    imgs_Array = [img_Original, img_Replicate, img_Reflect, img_Reflect101, imgConstant, img_Wrap]
    titles_Array = ['Original', 'Borda Replicada', 'Borda de Espelho', 'Borda de Espelho 2', 'Moldura', 'Efeito Wrap']
    show_Multiple_Image_Grid(imgs_Array, titles_Array, 3, 2)

# SHOWS
def show_Image(img):
    img_MPLIB = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    plt.imshow(img_MPLIB)
    plt.show()

def show_Image_Grid(img, title):
    fig, axis = plt.subplots()
    img_MPLIB = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    axis.imshow(img_MPLIB)
    axis.set_title(title)
    plt.show()

def show_Multiple_Image_Grid(imgs_Array, titles_Array, x, y):
    if(x < 1 or y < 1):
        print("ERRO: X e Y não podem ser zero ou abaixo de zero!")
        return
    elif(x == 1 and y == 1):
        show_Image_Grid(imgs_Array, titles_Array)
    elif(x == 1):
        fig, axis = plt.subplots(y)
        fig.suptitle(titles_Array)
        y_Id = 0
        for img in imgs_Array:
            img_MPLIB = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
            axis[y_Id].imshow(img_MPLIB)

            y_Id += 1
    elif(y == 1):
        fig, axis = plt.subplots(1, x)
        fig.suptitle(titles_Array)
        x_Id = 0
        for img in imgs_Array:
            img_MPLIB = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
            axis[x_Id].imshow(img_MPLIB)

            x_Id += 1
    else:
        fig, axis = plt.subplots(y, x)
        x_Id, y_Id, titleId = 0, 0, 0
        for img in imgs_Array:
            img_MPLIB = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
            axis[y_Id, x_Id].set_title(titles_Array[titleId])
            axis[y_Id, x_Id].imshow(img_MPLIB)
            
            if(len(titles_Array[titleId]) == 0):
                axis[y_Id, x_Id].axis('off')

            titleId += 1
            x_Id += 1
            if x_Id == x:
                x_Id = 0
                y_Id += 1
                
        fig.tight_layout(pad=0.5)
    plt.show()


# main
def main():
    plot_Single_Image()
    plot_TwoImage_Vertical()
    plot_Two_Image_Horizontal()
    plot_Three_Images()
    plot_FourImages()
    plot_SixImages()

if __name__ == "__main__":
    main()