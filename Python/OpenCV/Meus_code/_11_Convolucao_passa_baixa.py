from matplotlib import pyplot as plt
import numpy as np
import cv2

def showSingleImage(img, title, size):
    fig, axis = plt.subplots(figsize = size)

    axis.imshow(img, 'gray')
    axis.set_title(title, fontdict = {'fontsize': 22, 'fontweight': 'medium'})
    plt.show()
    
def show_Multiple_Images(imgsArray, titlesArray, size, x, y):
    if(x < 1 or y < 1):
        print("ERRO: X e Y não podem ser zero ou abaixo de zero!")
        return
    elif(x == 1 and y == 1):
        showSingleImage(imgsArray, titlesArray)
    elif(x == 1):
        fig, axis = plt.subplots(y, figsize = size)
        yId = 0
        for img in imgsArray:
            axis[yId].imshow(img, 'gray')
            axis[yId].set_anchor('NW')
            axis[yId].set_title(titlesArray[yId], fontdict = {'fontsize': 18, 'fontweight': 'medium'}, pad = 10)

            yId += 1
    elif(y == 1):
        fig, axis = plt.subplots(1, x, figsize = size)
        fig.suptitle(titlesArray)
        xId = 0
        for img in imgsArray:
            axis[xId].imshow(img, 'gray')
            axis[xId].set_anchor('NW')
            axis[xId].set_title(titlesArray[xId], fontdict = {'fontsize': 18, 'fontweight': 'medium'}, pad = 10)

            xId += 1
    else:
        fig, axis = plt.subplots(y, x, figsize = size)
        xId, yId, titleId = 0, 0, 0
        for img in imgsArray:
            axis[yId, xId].set_title(titlesArray[titleId], fontdict = {'fontsize': 18, 'fontweight': 'medium'}, pad = 10)
            axis[yId, xId].set_anchor('NW')
            axis[yId, xId].imshow(img, 'gray')
            if(len(titlesArray[titleId]) == 0):
                axis[yId, xId].axis('off')

            titleId += 1
            xId += 1
            if xId == x:
                xId = 0
                yId += 1
    plt.show()

img = cv2.imread("Python\OpenCV\Meus_code\imagem_teste.png")
img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

# FILTRAGEM PASSA BAIXA
mean_img = cv2.blur(img, (5, 5))
median_img = cv2.medianBlur(img, 5)
gaussian_img = cv2.GaussianBlur(img, (5, 5), 0)
bil_gaussian_img = cv2.bilateralFilter(img, 15, 100, 100)
bil_gaussian_img2 = cv2.bilateralFilter(img, 9, 75, 1000)

imgsArray = [img, mean_img, median_img, gaussian_img, bil_gaussian_img, bil_gaussian_img2]
titlesArray = ['Original', 'Mean', 'Median', 'Gaussian', 'Bilateral Gaussian', 'Bilateral Gaussian 2']
show_Multiple_Images(imgsArray, titlesArray, (9, 9), 3, 2)
                   