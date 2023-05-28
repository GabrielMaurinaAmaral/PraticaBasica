import cv2

# cria um objeto que lê e armazena na variável
obj_img = cv2.imread("C:\CODE\PraticaBasica\Python\OpenCV\Meus_code\Foto_frame.png")

# verifica se a leitura da imagem foi bem sucedida
if obj_img is not None:
    # Exibe a imagem na janela
    cv2.imshow('Imagem', obj_img)    
    # Aguarda uma tecla ser pressionada para fechar a janela
    cv2.waitKey(0)
    # Fecha a janela
    cv2.destroyAllWindows()
else:
    print("Não foi possível ler a imagem.")
    
