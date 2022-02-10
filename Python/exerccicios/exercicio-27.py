n = str(input("enter a sentence: ")).strip()
sentence = n.split()
print("fist name: {}".format(sentence[0]))
print("last name: {}".format(sentence[len(sentence)-1]))
