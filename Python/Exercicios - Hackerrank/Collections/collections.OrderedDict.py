from collections import OrderedDict
#
# ordinary_dictionary = {}
# ordinary_dictionary['a'] = 1
# ordinary_dictionary['b'] = 2
# ordinary_dictionary['c'] = 3
# ordinary_dictionary['d'] = 4
# ordinary_dictionary['e'] = 5
#
# print(ordinary_dictionary)
# # {'a': 1, 'c': 3, 'b': 2, 'e': 5, 'd': 4}
#
# ordered_dictionary = OrderedDict()
# ordered_dictionary['a'] = 1
# ordered_dictionary['b'] = 2
# ordered_dictionary['c'] = 3
# ordered_dictionary['d'] = 4
# ordered_dictionary['e'] = 5
#
# print(ordered_dictionary)
# # OrderedDict([('a', 1), ('b', 2), ('c', 3), ('d', 4), ('e', 5)])


tam = int(input())
d = OrderedDict()

for i in range(tam):
    itens = input().split()

    itemNumero = int(itens[-1])
    itemNome = " ".join(itens[:-1])

    if(d.get(itemNome)):
        d[itemNome] += itemNumero
    else:
        d[itemNome] = itemNumero

for i in d.keys():
    print(i, d[i])
