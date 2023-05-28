import numpy as np
import cv2
from matplotlib import pyplot as plt

# PLOTS
def plot_Added_Images():
    img_Circle = cv2.imread('Python\OpenCV\Meus_code\Circle.png')
    img_Rectangle = cv2.imread('Python\OpenCV\Meus_code\Rectangle.png')
    # juntando/somando duas imagems
    add_Image = cv2.add(img_Circle, img_Rectangle) # fist_Image + second_Image
    soma_Image = img_Circle + img_Rectangle
    add_Weighted_Image = cv2.addWeighted(img_Circle, 0.7, img_Rectangle, 0.3, 0)
    # salvar imagem 
    cv2.imwrite("Python\OpenCV\Meus_code\Foto_Salva.png", add_Image)
    # criando grid com 4 imagens
    imgs_Array = [img_Circle, img_Circle, add_Image, add_Weighted_Image]
    titles_Array = ['Primeira Imagem', 'Segunda Imagem', 'Add', 'Add = %70 + %30']
    
    show_Multiple_Image_Grid(imgs_Array, titles_Array, 2, 2)
    show_Image_Grid(soma_Image, "soma")

# SHOWS
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

# EXEMPLO MEME
def resizeImage(image, scalePercent):
    width = int(image.shape[1] * scalePercent / 100)
    height = int(image.shape[0] * scalePercent / 100)
    image = cv2.resize(image, (width, height))

    return image

def addImageOverlay(background, foreground, translationForegroundW, translationForegroundH):
    backH, backW, _ = background.shape
    foreH, foreW, _ = foreground.shape
    remainingH, remainingW = backH - foreH, backW - foreW

    if translationForegroundH + foreH > backH:
        print("Erro: sobreposição com altura maior do que a permitida.")
        print("Posição final que altura do objeto da frente termina:", translationForegroundH + foreH)
        print("Altura do fundo:", backH)
        return

    if translationForegroundW + foreW > backW:
        print("Erro: sobreposição com largura maior do que a permitida.")
        print("Posição final que largura do objeto da frente termina:", translationForegroundW + foreW)
        print("Largura do fundo:", backW)
        return

    #parte do cenário do fundo em que a imagem será adicionada
    crop = background[translationForegroundH : foreH + translationForegroundH, translationForegroundW : foreW + translationForegroundW]

    #Transformamos o foreground em imagem com tons de cinza e criamos uma máscara binária da mesma com a binarização (cv2.threshold)
    foregroundGray = cv2.cvtColor(foreground, cv2.COLOR_BGR2GRAY)
    ret, maskFore = cv2.threshold(foregroundGray, 240, 255, cv2.THRESH_BINARY)

    #Agora aplicamos uma operação de AND binário na imagem recortada 'crop'. No caso, realizar a operação binária entre a mesma imagem não terá efeito. Só que, com a inclusão da máscara no terceiro parâmetro, os pixels pretos de maskFore serão ignorados e, portanto, ficarão escuros. Com isso temos a marcação em que vamos incluir o foreground posteriormente.
    backWithMask = cv2.bitwise_and(crop, crop, mask = maskFore)
    foreWithMask = cv2.bitwise_not(maskFore)
    foreWithMask = cv2.bitwise_and(foreground, foreground, mask = foreWithMask)

    #Faremos a composição entre 'frente' e 'fundo', compondo o foreground na imagem extraída do background.
    combinedImage = cv2.add(foreWithMask, backWithMask)

    #Adicionamos a imagem gerada no background final.
    copyImage = background.copy()
    copyImage[translationForegroundH:foreH + translationForegroundH, translationForegroundW:foreW + translationForegroundW] = combinedImage

    return copyImage

def addBlendingEffect(firstImage, secondImage, weight):
    firstImageGray = cv2.cvtColor(firstImage, cv2.COLOR_BGR2GRAY)
    secondImageGray = cv2.cvtColor(secondImage, cv2.COLOR_BGR2GRAY)

    mask = firstImageGray - secondImageGray
    ret, mask = cv2.threshold(mask, 0, 255, cv2.THRESH_BINARY)

    copyImg = firstImage.copy()
    altura, largura, = mask.shape
    for y in range(0, altura):
        for x in range(0, largura):
            if mask.item(y, x) == 255:
                blendingPixelBlue = firstImage.item(y, x, 0) * (1.0 - weight) + secondImage.item(y, x, 0) * weight
                blendingPixelGreen = firstImage.item(y, x, 1) * (1.0 - weight) + secondImage.item(y, x, 1) * weight
                blendingPixelRed = firstImage.item(y, x, 2) * (1.0 - weight) + secondImage.item(y, x, 2) * weight

                copyImg.itemset((y, x, 0), blendingPixelBlue)
                copyImg.itemset((y, x, 1), blendingPixelGreen)
                copyImg.itemset((y, x, 2), blendingPixelRed)

    return copyImg

def memeGeneratorWithBlending(fala1, imagem1, fala2, imagem2, fundo):
    background = cv2.imread(fundo)

    atilaFeliz = cv2.imread(imagem1)
    atilaFeliz = resizeImage(atilaFeliz, 250)
    finalImageUmAtila = addImageOverlay(background, atilaFeliz, 380, 465)

    atilaBravo = cv2.imread(imagem2)
    atilaBravo = resizeImage(atilaBravo, 250)
    finalImageDoisAtilas = addImageOverlay(finalImageUmAtila, atilaBravo, 930, 460)

    finalImage = addBlendingEffect(finalImageUmAtila, finalImageDoisAtilas, 0.4)

    finalImage = cv2.putText(finalImage, fala1, (210, 420), cv2.FONT_HERSHEY_SIMPLEX , 2.5, (0, 0, 0), 5, cv2.LINE_AA)
    finalImage = cv2.putText(finalImage, fala2, (1030, 1150), cv2.FONT_HERSHEY_SIMPLEX ,2.5, (0, 0, 0) , 5, cv2.LINE_AA)

    cv2.imwrite("memeatila.png", finalImage)

# main
def main():
    plot_Added_Images()
    #memeGeneratorWithBlending('Respeito seu argumento!', "src/atila_feliz.png", 'Burro pra caramba...', "src/atila_bravo.png", "src/fundo2.jpg")
    

if __name__ == "__main__":
    main()