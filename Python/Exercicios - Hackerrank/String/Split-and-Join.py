def split_and_join(line):
    string = line.split(" ")
    string = "-".join(string)
    return string


if __name__ == '__main__':
    line = input()
    result = split_and_join(line)
    print(result)
