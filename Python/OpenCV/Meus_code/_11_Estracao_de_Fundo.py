import cv2
import numpy as np

# Carrega a imagem
imagem = cv2.imread('Python\OpenCV\Meus_code\IMG_20230913_194800245.jpg')

# Converte a imagem para tons de cinza
imagem_em_tons_de_cinza = cv2.cvtColor(imagem, cv2.COLOR_BGR2GRAY)

# Aplica uma técnica de segmentação, como um limiar simples
limiar, imagem_binaria = cv2.threshold(imagem_em_tons_de_cinza, 200, 255, cv2.THRESH_BINARY)

# Inverte a imagem binária (para que o objeto em primeiro plano seja branco)
imagem_binaria_invertida = cv2.bitwise_not(imagem_binaria)

# Aplica a máscara de segmentação para isolar o objeto em primeiro plano
imagem_objeto_em_primeiro_plano = cv2.bitwise_and(imagem, imagem, mask=imagem_binaria_invertida)

# Exibe a imagem do objeto em primeiro plano
cv2.imshow('Objeto em Primeiro Plano', imagem_objeto_em_primeiro_plano)

# Aguarda até que uma tecla seja pressionada e fecha a janela
cv2.waitKey(0)
cv2.destroyAllWindows()