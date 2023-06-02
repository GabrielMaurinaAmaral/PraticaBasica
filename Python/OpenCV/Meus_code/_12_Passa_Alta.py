import numpy as np
import cv2
from matplotlib import pyplot as plt

def showSingleImage(img, title, size, mincolor=0, maxcolor=255):
    fig, axis = plt.subplots(figsize = size)
    axis.imshow(img, cmap='gray', vmin=mincolor, vmax=maxcolor)
    axis.set_title(title, fontdict = {'fontsize': 22, 'fontweight': 'medium'})
    plt.show()
    
def showMultipleImages(imgsArray, titlesArray, size, x, y, mincolor=0, maxcolor=255):
    if(x < 1 or y < 1):
        print("ERRO: X e Y não podem ser zero ou abaixo de zero!")
        return
    elif(x == 1 and y == 1):
        showSingleImage(imgsArray, titlesArray)
    elif(x == 1):
        fig, axis = plt.subplots(y, figsize = size)
        yId = 0
        for img in imgsArray:
            axis[yId].imshow(img, cmap='gray', vmin=mincolor, vmax=maxcolor)
            axis[yId].set_anchor('NW')
            axis[yId].set_title(titlesArray[yId], fontdict = {'fontsize': 18, 'fontweight': 'medium'}, pad = 10)

            yId += 1
    elif(y == 1):
        fig, axis = plt.subplots(1, x, figsize = size)
        fig.suptitle(titlesArray)
        xId = 0
        for img in imgsArray:
            axis[xId].imshow(img, cmap='gray', vmin=mincolor, vmax=maxcolor)
            axis[xId].set_anchor('NW')
            axis[xId].set_title(titlesArray[xId], fontdict = {'fontsize': 18, 'fontweight': 'medium'}, pad = 10)

            xId += 1
    else:
        fig, axis = plt.subplots(y, x, figsize = size)
        xId, yId, titleId = 0, 0, 0
        for img in imgsArray:
            axis[yId, xId].set_title(titlesArray[titleId], fontdict = {'fontsize': 18, 'fontweight': 'medium'}, pad = 10)
            axis[yId, xId].set_anchor('NW')
            axis[yId, xId].imshow(img, cmap='gray', vmin=mincolor, vmax=maxcolor)
            if(len(titlesArray[titleId]) == 0):
                axis[yId, xId].axis('off')

            titleId += 1
            xId += 1
            if xId == x:
                xId = 0
                yId += 1
    plt.show()
    
img_tij = cv2.imread("Python\OpenCV\Meus_code\_tijolo.jpg")
img_tij = cv2.cvtColor(img_tij, cv2.COLOR_BGR2RGB)
img_gray_tij = cv2.cvtColor(img_tij, cv2.COLOR_RGB2GRAY)

img_sudoku = cv2.imread("Python\OpenCV\Meus_code\sudoku.jpg")
img_sudoku = cv2.cvtColor(img_sudoku, cv2.COLOR_BGR2RGB)
img_gray_sud = cv2.cvtColor(img_sudoku, cv2.COLOR_RGB2GRAY)    

# FILTROS PASSA ALTA
# filtro Sobel
img_sobelx = cv2.Sobel(src=img_gray_tij, ddepth=cv2.CV_64F, dx=1, dy=0, ksize=3)
img_sobely = cv2.Sobel(src=img_gray_tij, ddepth=cv2.CV_64F, dx=0, dy=1, ksize=3)
img_sobelxy = cv2.addWeighted(img_sobelx, 0.5, img_sobely, 0.5, 0) #melhor usar assim

imgsArray = [img_tij, img_sobelx, img_sobely, img_sobelxy]
titlesArray = ['Original', 'Sobel X', 'Sobel Y', 'Sobel XY']
showMultipleImages(imgsArray, titlesArray, (12, 8), 2, 2)

img_sobelx = cv2.Sobel(src=img_gray_sud, ddepth=cv2.CV_64F, dx=1, dy=0, ksize=3)
img_sobely = cv2.Sobel(src=img_gray_sud, ddepth=cv2.CV_64F, dx=0, dy=1, ksize=3)
img_sobelxy = cv2.addWeighted(img_sobelx, 0.5, img_sobely, 0.5, 0) #melhor usar assim

imgsArray = [img_sudoku, img_sobelx, img_sobely, img_sobelxy]
titlesArray = ['Original', 'Sobel X', 'Sobel Y', 'Sobel XY']
showMultipleImages(imgsArray, titlesArray, (12, 8), 2, 2)


# filtro Scharr
img_scharrx = cv2.Scharr(src=img_gray_tij, ddepth=cv2.CV_64F, dx=1, dy=0)
img_scharry = cv2.Scharr(src=img_gray_tij, ddepth=cv2.CV_64F, dx=0, dy=1)
img_scharrxy = cv2.addWeighted(img_scharrx, 0.5, img_scharry, 0.5, 0) #melhor usar assim

imgsArray = [img_tij, img_scharrx, img_scharry, img_scharrxy]
titlesArray = ['Original', 'Scharr X', 'Scharr Y', 'Scharr XY']
showMultipleImages(imgsArray, titlesArray, (12, 9), 2, 2)

img_blur_tij = cv2.GaussianBlur(img_gray_tij, (9, 9), 3, 3)
img_scharrx = cv2.Scharr(src=img_blur_tij, ddepth=cv2.CV_64F, dx=1, dy=0)
img_scharry = cv2.Scharr(src=img_blur_tij, ddepth=cv2.CV_64F, dx=0, dy=1)
img_scharrxy = cv2.addWeighted(img_scharrx, 0.5, img_scharry, 0.5, 0) #melhor usar assim

imgsArray = [img_tij, img_scharrx, img_scharry, img_scharrxy]
titlesArray = ['Original', 'Scharr X', 'Scharr Y', 'Scharr XY']
showMultipleImages(imgsArray, titlesArray, (12, 8), 2, 2)

# filtro Laplaciano
img_blur = cv2.GaussianBlur(img_gray_tij, (5, 5), 5, 5)

img_laplacian3 = cv2.Laplacian(img_gray_tij, cv2.CV_64F, ksize=3)
img_blur_laplacian3 = cv2.Laplacian(img_blur, cv2.CV_64F, ksize=3)
img_laplacian5 = cv2.Laplacian(img_gray_tij, cv2.CV_64F, ksize=5)
img_blur_laplacian5 = cv2.Laplacian(img_blur, cv2.CV_64F, ksize=5)

imgsArray = [img_tij, img_laplacian3, img_blur_laplacian3, img_laplacian5, img_blur_laplacian5]
titlesArray = ['Original', 'Laplacian k=3', 'Blur + Laplacian k=3', 'Laplacian k=5', 'Blur + Laplacian k=5']
showMultipleImages(imgsArray, titlesArray, (12, 6), 3, 2)

img_blur = cv2.GaussianBlur(img_gray_sud, (5, 5), 5, 5)

img_laplacian3 = cv2.Laplacian(img_gray_sud, cv2.CV_64F, ksize=3)
img_blur_laplacian3 = cv2.Laplacian(img_blur, cv2.CV_64F, ksize=3)
img_laplacian5 = cv2.Laplacian(img_gray_sud, cv2.CV_64F, ksize=5)
img_blur_laplacian5 = cv2.Laplacian(img_blur, cv2.CV_64F, ksize=5)

imgsArray = [img_sudoku, img_laplacian3, img_blur_laplacian3, img_laplacian5, img_blur_laplacian5]
titlesArray = ['Original', 'Laplacian k=3', 'Blur + Laplacian k=3', 'Laplacian k=5', 'Blur + Laplacian k=5']
showMultipleImages(imgsArray, titlesArray, (12, 6), 3, 2)