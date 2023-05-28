# Impotando a biblioteca
import cv2 
# Cria o objeto para capturar o vídeo da webcam
webcam = cv2.VideoCapture(0) 

while webcam.isOpened():
    validacao, frame = webcam.read()
    
    if not validacao:
        break
    
    cv2.imshow('Webcam', frame)
    key = cv2.waitKey(5)
    if  key == (ord('q') or ord('Q')):
        
        break

print(webcam)
print(validacao)
print(frame)
cv2.imwrite("Foto_ultimo_frame.png", frame)

webcam.release()
cv2.destroyAllWindows()
