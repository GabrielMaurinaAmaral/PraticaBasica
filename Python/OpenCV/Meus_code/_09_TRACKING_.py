import cv2
import numpy as np

ESC_KEY = 27
trackbar_Window = "trackbar window"

def onChange(val):
        return
       
def set_Limits_Of_Trackbar():
    # lendo matiz
    mat = {}
    mat["min"] = cv2.getTrackbarPos("Min Matiz", trackbar_Window)
    mat["max"] = cv2.getTrackbarPos("Max Matiz", trackbar_Window)
    # verificando
    if mat["min"] > mat["max"]:
        # define o valor do maximo igual ao minimo
        cv2.setTrackbarPos("Max Matiz", trackbar_Window, mat["min"]+1)
        # define recebe o novo valor
        mat["max"] = cv2.getTrackbarPos("Max Matiz", trackbar_Window)
    
    sat = {}
    sat["min"] = cv2.getTrackbarPos("Min Saturacao", trackbar_Window)
    sat["max"] = cv2.getTrackbarPos("Max Saturacao", trackbar_Window)
    
    if sat["min"] > sat["max"]:
        cv2.setTrackbarPos("Max Saturacao", trackbar_Window, sat["min"]+1)
        sat["max"] = cv2.getTrackbarPos("Max Saturacao", trackbar_Window)

    val = {}
    val["min"] = cv2.getTrackbarPos("Min Valor", trackbar_Window)
    val["max"] = cv2.getTrackbarPos("Max Valor", trackbar_Window)

    if val["min"] > val["max"]:
        cv2.setTrackbarPos("Max Valor", trackbar_Window, val["min"]+1)
        val["max"] = cv2.getTrackbarPos("Max Valor", trackbar_Window)

    return mat, sat, val

def compute_Tracking(frame, mat, sat, val):
    #transforma a imagem de RGB para HSV
    hsvImage = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    
    #definir os intervalos de cores que vão aparecer na imagem final
    lowerColor = np.array([mat['min'], sat["min"], val["min"]])
    upperColor = np.array([mat['max'], sat["max"], val["max"]])
    
    #marcador pra saber se o pixel pertence ao intervalo ou não
    mask = cv2.inRange(hsvImage, lowerColor, upperColor)
    cv2.imshow("mascara", mask)
    
    #aplica máscara que "deixa passar" pixels pertencentes ao intervalo, como filtro
    result = cv2.bitwise_and(frame, frame, mask = mask)
    cv2.imshow("result", result)
    
    #aplica limiarização
    gray = cv2.cvtColor(result, cv2.COLOR_BGR2GRAY)
    _,gray = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY | cv2.THRESH_OTSU)
    
    #encontra pontos que circundam regiões conexas (contour)
    contours, hierarchy = cv2.findContours(gray, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
    
    #se existir contornos    
    if contours:
        #retornando a área do primeiro grupo de pixels brancos
        maxArea = cv2.contourArea(contours[0])
        contourMaxAreaId = 0
        i = 0
        
        #para cada grupo de pixels branco existente
        for cnt in contours:
            #procura o grupo com a maior área
            if maxArea < cv2.contourArea(cnt):
                maxArea = cv2.contourArea(cnt)
                contourMaxAreaId = i
            i += 1
            
        #achei o contorno com maior área em pixels
        cntMaxArea = contours[contourMaxAreaId]
        
        #retorna um retângulo que envolve o contorno em questão
        xRect, yRect, wRect, hRect = cv2.boundingRect(cntMaxArea)
        
        #desenha caixa envolvente com espessura 3
        cv2.rectangle(frame, (xRect, yRect), (xRect + wRect, yRect + hRect), (0, 0, 255), 2)
    
    return frame, gray


def main():
    # nome da janela grafica
    trackbar_Window = "trackbar window"
    cv2.namedWindow(trackbar_Window)
       
    # criando a trackbar na janela grafica
    cv2.createTrackbar("Min Matiz", trackbar_Window, 0, 255, onChange)
    cv2.createTrackbar("Max Matiz", trackbar_Window, 255, 255, onChange)
    cv2.createTrackbar("Min Saturacao", trackbar_Window, 0, 255, onChange)
    cv2.createTrackbar("Max Saturacao", trackbar_Window, 255, 255, onChange)
    cv2.createTrackbar("Min Valor", trackbar_Window, 0, 255, onChange)
    cv2.createTrackbar("Max Valor", trackbar_Window, 255, 255, onChange)
    
    webcam = cv2.VideoCapture(0)
    while True:
        validacao, frame = webcam.read()
    
        if validacao:
            # le verificar para que o minumo não seja maior que o maximo em cada caso
            mat, sat, val = set_Limits_Of_Trackbar()
            
            #transforma a imagem de RGB para cinza
            frame_cinza = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
           
            # limiarização
            frame, gray = compute_Tracking(frame, mat, sat, val)
            
            cv2.imshow("webcam preto e branco", frame_cinza)
            cv2.imshow("webcam linearizada", gray)
            cv2.imshow("webcam", frame)
           
            # se prescionar "esq" o ou "q" ele fecha a janela
            if cv2.waitKey(1) & 0xFF == ord('q') or 0xFF == ESC_KEY:
                break
        else:
            break
    webcam.release()
    cv2.destroyAllWindows()

main()        
