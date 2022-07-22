def merge_the_tools(string, k):
    new_string = []
    len_new_string = 0

    for item in string:
        len_new_string += 1

        if item not in new_string:
            new_string.append(item)

        if len_new_string == k:
            print(''.join(new_string))
            new_string = []
            len_new_string = 0


if __name__ == '__main__':
    string, k = input(), int(input())
    merge_the_tools(string, k)
