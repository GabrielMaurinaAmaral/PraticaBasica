def average(array):
    soma_array = float(sum(set(array)))
    tam_array = len(set(array))
    return soma_array/tam_array

    
if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    result = average(arr)
    print(result)