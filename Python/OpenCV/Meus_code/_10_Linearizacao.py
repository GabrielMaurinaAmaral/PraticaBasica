from matplotlib import pyplot as plt
import cv2
import glob
import time

ESCAPE_KEY_ASCII = 27

folder = 'C:\CODE\Exemplos_Curso_OPENCV\Python_OpenCV4\_base_mama/*'
image_files_list = glob.glob(folder)
def onChange(value):
    pass

def show_Single_Image(img, title, size):
    fig, axis = plt.subplots(figsize = size)

    axis.imshow(img, 'gray')
    axis.set_title(title, fontdict = {'fontsize': 22, 'fontweight': 'medium'})
    plt.show()
    
def show_Multiple_Images(imgs_Array, titles_Array, size, x, y):
    if(x < 1 or y < 1):
        print("ERRO: X e Y não podem ser zero ou abaixo de zero!")
        return
    elif(x == 1 and y == 1):
        show_Single_Image(imgs_Array, titles_Array)
    elif(x == 1):
        fig, axis = plt.subplots(y, figsize = size)
        y_Id = 0
        for img in imgs_Array:
            axis[y_Id].imshow(img, 'gray')
            axis[y_Id].set_anchor('NW')
            axis[y_Id].set_title(titles_Array[y_Id], fontdict = {'fontsize': 18, 'fontweight': 'medium'}, pad = 10)

            y_Id += 1
    elif(y == 1):
        fig, axis = plt.subplots(1, x, figsize = size)
        fig.suptitle(titles_Array)
        x_Id = 0
        for img in imgs_Array:
            axis[x_Id].imshow(img, 'gray')
            axis[x_Id].set_anchor('NW')
            axis[x_Id].set_title(titles_Array[x_Id], fontdict = {'fontsize': 18, 'fontweight': 'medium'}, pad = 10)

            x_Id += 1
    else:
        fig, axis = plt.subplots(y, x, figsize = size)
        x_Id, y_Id, titleId = 0, 0, 0
        for img in imgs_Array:
            axis[y_Id, x_Id].set_title(titles_Array[titleId], fontdict = {'fontsize': 18, 'fontweight': 'medium'}, pad = 10)
            axis[y_Id, x_Id].set_anchor('NW')
            axis[y_Id, x_Id].imshow(img, 'gray')
            if(len(titles_Array[titleId]) == 0):
                axis[y_Id, x_Id].axis('off')

            titleId += 1
            x_Id += 1
            if x_Id == x:
                x_Id = 0
                y_Id += 1
    plt.show()
    
# exemplo 1
img_filename = image_files_list[2]
img = cv2.imread(img_filename)
show_Single_Image(img, "Mama", (5, 5))

# exemlo 2
#cv2.THRESH_BINARY
img = cv2.imread(img_filename)
thresh, img_thresh = cv2.threshold(img, 230, 255, cv2.THRESH_BINARY)
show_Single_Image(img_thresh, "Limiarização cv2.THRESH_BINARY", (5, 5))

# exemplo4 
limiar = 240
imgOriginal = cv2.imread(img_filename)
_, imgBinary = cv2.threshold(imgOriginal, limiar, 255, cv2.THRESH_BINARY)
_, imgBinaryInv = cv2.threshold(imgOriginal, limiar, 255, cv2.THRESH_BINARY_INV)
_, imgTrunc = cv2.threshold(imgOriginal, limiar, 255, cv2.THRESH_TRUNC)
_, imgToZero = cv2.threshold(imgOriginal, limiar, 255, cv2.THRESH_TOZERO)
_, imgToZeroInv = cv2.threshold(imgOriginal, limiar, 255, cv2.THRESH_TOZERO_INV)

imgs_Array = [imgOriginal, imgBinary, imgBinaryInv, imgTrunc, imgToZero, imgToZeroInv]
titles_Array = ['Original', 'THRESH_BINARY', 'THRESH_BINARY_INV', 'THRESH_TRUNC', 'THRESH_TOZERO', 'THRESH_TOZERO_INV']
show_Multiple_Images(imgs_Array, titles_Array, (12, 8), 3, 2)

# exemplo 4

#imagem carregada e sua cópia
img = cv2.imread(image_files_list[0])
copyimg = img.copy()

#cria janela gráfica para inserir a imagem
windowTitle = "Ajuste de Limiarizacao"
cv2.namedWindow(windowTitle)

#cria trackbar
cv2.createTrackbar("limiarizacao", windowTitle, 0, 255, onChange)

before_thresh = 0
update_thresh = False
counter_time = 0

while True:
    current_thresh = cv2.getTrackbarPos("limiarizacao", windowTitle)
    
    #valor de limiarização do trackbar foi alterado pelo usuário? (sim)
    if before_thresh != current_thresh:
        update_thresh = True
        counter_time = time.time()
        before_thresh = current_thresh
        
    #se tiver passado 1 segundo desde que o usuário mexeu em algum trackbar
    if time.time() - counter_time > 1:
        #se tiver sido marcado que é pra atualizar limiarização
        if update_thresh == True:
            
            #fazemos uma cópia da imagem original
            _, copyimg = cv2.threshold(img, current_thresh, 255, cv2.THRESH_BINARY)

            update_thresh = False
        
    cv2.imshow(windowTitle, copyimg)
    
    keyPressed = cv2.waitKey(1) & 0xFF
    if keyPressed == ESCAPE_KEY_ASCII:
        break
        
cv2.destroyAllWindows()