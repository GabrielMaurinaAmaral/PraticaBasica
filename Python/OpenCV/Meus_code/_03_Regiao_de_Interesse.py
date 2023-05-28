import cv2

def show_Image(img):
    cv2.namedWindow("Imagem", cv2.WINDOW_NORMAL)  
    cv2.imshow("Imagem", img)
    cv2.waitKey(0)  
    cv2.destroyAllWindows()


    
def main():
    obj_img = cv2.imread("Python\OpenCV\Meus_code\imagem_teste.png")
    
    # [posição_inicial_y:posição _final_y, posição_inicial_x:posição_final_x]
    corte_img = obj_img[50:50+400, 50:50+300]
    cv2.imwrite("Python\OpenCV\Meus_code\imagem_teste_corte.png", corte_img)
    
    show_Image(corte_img)            


main()
