import cv2
import numpy as np

ESC_KEY = 27
trackbar_Window = "trackbar window"

def onChange(vermelho):
        return
       
def set_Limits_Of_Trackbar():
    azul = {}
    azul["min"] = cv2.getTrackbarPos("min azul", trackbar_Window)
    azul["max"] = cv2.getTrackbarPos("max azul", trackbar_Window)
    if azul["min"] > azul["max"]:
        cv2.setTrackbarPos("max azul", trackbar_Window, azul["min"]+1)
        azul["max"] = cv2.getTrackbarPos("max azul", trackbar_Window)
    
    verde = {}
    verde["min"] = cv2.getTrackbarPos("min verde", trackbar_Window)
    verde["max"] = cv2.getTrackbarPos("max verde", trackbar_Window)
    
    if verde["min"] > verde["max"]:
        cv2.setTrackbarPos("max verde", trackbar_Window, verde["min"]+1)
        verde["max"] = cv2.getTrackbarPos("max verde", trackbar_Window)

    vermelho = {}
    vermelho["min"] = cv2.getTrackbarPos("min vermelho", trackbar_Window)
    vermelho["max"] = cv2.getTrackbarPos("max vermelho", trackbar_Window)

    if vermelho["min"] > vermelho["max"]:
        cv2.setTrackbarPos("max vermelho", trackbar_Window, vermelho["min"]+1)
        vermelho["max"] = cv2.getTrackbarPos("max vermelho", trackbar_Window)

    return azul, verde, vermelho

def compute_Tracking(frame, azul, verde, vermelho):    
    lowerColor = np.array([azul['min'], verde["min"], vermelho["min"]])
    upperColor = np.array([azul['max'], verde["max"], vermelho["max"]])
    
    mask = cv2.inRange(frame, lowerColor, upperColor)    
    result = cv2.bitwise_and(frame, frame, mask = mask)
    cv2.imshow("fame - mascara", result)
    
    gray = cv2.cvtColor(result, cv2.COLOR_BGR2GRAY)
    _,gray = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY | cv2.THRESH_OTSU)
    
    contours, hierarchy = cv2.findContours(gray, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
    
    if contours:
        maxArea = cv2.contourArea(contours[0])
        contourMaxAreaId = 0
        i = 0
        
        for cnt in contours:
            if maxArea < cv2.contourArea(cnt):
                maxArea = cv2.contourArea(cnt)
                contourMaxAreaId = i
            i += 1
            
        cntMaxArea = contours[contourMaxAreaId]
        xRect, yRect, wRect, hRect = cv2.boundingRect(cntMaxArea)
        
        cv2.rectangle(frame, (xRect, yRect), (xRect + wRect, yRect + hRect), (0, 0, 255), 2)
    
    return frame, gray


def main():
    trackbar_Window = "trackbar window"
    cv2.namedWindow(trackbar_Window)
       
    cv2.createTrackbar("min azul", trackbar_Window, 0, 255, onChange)
    cv2.createTrackbar("max azul", trackbar_Window, 255, 255, onChange)
    cv2.createTrackbar("min verde", trackbar_Window, 0, 255, onChange)
    cv2.createTrackbar("max verde", trackbar_Window, 255, 255, onChange)
    cv2.createTrackbar("min vermelho", trackbar_Window, 0, 255, onChange)
    cv2.createTrackbar("max vermelho", trackbar_Window, 255, 255, onChange)
    
    webcam = cv2.VideoCapture(0)
    while True:
        validacao, frame = webcam.read()
    
        if validacao:
            azul, verde, vermelho = set_Limits_Of_Trackbar()
            
           
            frame, gray = compute_Tracking(frame, azul, verde, vermelho)            
            cv2.imshow("webcam linearizada", gray)
            cv2.imshow("webcam", frame)
           
            if cv2.waitKey(1) & 0xFF == ord('q') or 0xFF == ESC_KEY:
                break
        else:
            break
    webcam.release()
    cv2.destroyAllWindows()

main()        
