#  a  =  '1'
#  b  =  '0'
#  print  int ( a )  /  int ( b )
#  ZeroDivisionError :  divisão inteira  ou módulo por zero

#  a  =  '1'
#  b  =  '#'
#  print  int ( a )  /  int ( b )
#  ValueError :  literal inválido  para int () com base 10 : '#'

##Code
# try :
#     print  1/0 exceto ZeroDivisionError as e : print "Error Code : " , e

tamanho = int(input())

for i in range(tamanho):
    try:
        a, b = input().split()
        print(int(a)//int(b))

    except ZeroDivisionError as erro:
        print("Error Code:", erro)
    except ValueError as erro:
        print("Error Code:", erro)
