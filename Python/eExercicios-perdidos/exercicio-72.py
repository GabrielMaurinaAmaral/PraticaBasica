number=("zero","um","dois","tres","quadro","cinco","seis","sete","oito","nove","dez","onze","doze","treze","catorze","quinze","dezesseis","dezoito","dezenove","vinte")
while True:
    i=int(input("write a number between 0 to 20: "))
    if 0<=i<=20:
        break
    print("try again") 

print("number: {}".format(number[i]))