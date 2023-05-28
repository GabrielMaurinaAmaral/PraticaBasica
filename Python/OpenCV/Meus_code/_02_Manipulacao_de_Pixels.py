import cv2

def show_Image(img):
    # img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    cv2.imshow('Imagem', img) 
    cv2.waitKey(0) 
    
def main():
    # acrscentando o zero em imread() elimina os canais de cor
    obj_img = cv2.imread("Python\OpenCV\Meus_code\imagem_teste.png")
    
    # dados de altura, largura e canais de cor
    print(obj_img.shape)
    altura, largura, canias_cor = obj_img.shape
    print(f" altura: {altura}\n largura: {largura}\n canias_cor: {canias_cor}")
        
    # Informção de cada pixel de cor [b g r] 
    for y in range(0, altura):
        for x in range(0, largura):
            # print(obj_img[y][x])   
            azul = obj_img.item(y, x, 0) 
            verde = obj_img.item(y, x, 1) 
            vermelhor = obj_img.item(y, x, 2) 
            # Imagem vai ficar toda azul
            # Anulando os canais verde e vermelhor
            obj_img.itemset((y, x, 1), 0)
            obj_img.itemset((y, x, 2), 0)

    show_Image(obj_img)            
    
main()