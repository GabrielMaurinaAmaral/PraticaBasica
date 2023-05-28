import cv2

# cria o objeto que esta captando imagem
obj_webcam = cv2.VideoCapture(0) 
# le oque aparece na camera e grava na variavel frame
validacao,  frame = obj_webcam.read() 
# grava o que voi armazenado na variavel frame num .png
cv2.imwrite("C:\CODE\PraticaBasica\Python\OpenCV\Meus_code\Foto_frame.png", frame)

obj_webcam.release()
cv2.destroyAllWindows()

