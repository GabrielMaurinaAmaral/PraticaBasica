import string


def print_rangoli(size):

    alfabeto = string.ascii_lowercase
    L = []

    for i in range(n):
        s = "-".join(alfabeto[i:n])
        L.append((s[::-1]+s[1:]).center(4*n-3, "-"))

    print('\n'.join(L[:0:-1]+L))


if __name__ == '__main__':
    n = int(input())
    print_rangoli(n)
