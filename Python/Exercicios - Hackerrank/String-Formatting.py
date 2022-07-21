def print_formatted(number):
    
    tam = len(bin(number)[2:])

    for i in range(1, number+1):
        print(str(i).rjust(tam, ' '), end=" ")
        print(oct(i)[2:].rjust(tam, ' '), end=" ")
        print(((hex(i)[2:]).upper()).rjust(tam, ' '), end=" ")
        print(bin(i)[2:].rjust(tam, ' '))


if __name__ == '__main__':
    n = int(input())
    print_formatted(n)
