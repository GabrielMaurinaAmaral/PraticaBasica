sentence=str(input("enter a sentence"))
print(sentence.count('a'))
print("posicao do primeiro a {}".format(sentence.find('a')+1))
print("posicao do primeiro a {}".format(sentence.rfind('a')+1))