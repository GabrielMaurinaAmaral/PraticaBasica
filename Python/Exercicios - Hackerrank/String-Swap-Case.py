def swap_case(string):
    newstring = ''
    
    for s in string:
        if (s.isupper()) == True:
            newstring += (s.lower())
        elif (s.islower()) == True:
            newstring += (s.upper())
        else:
            newstring += s
    return newstring


if __name__ == '__main__':
    s = input()
    result = swap_case(s)
    print(result)