from collections import defaultdict

# d = defaultdict(list)
# d['python'].append("awesome")
# d['something-else'].append("not relevant")
# d['python'].append("language")
# for i in d.items():
#     print i

d = defaultdict(list)
tam_1, tam_2 = map(int, input().split())

for i in range(tam_1):
    d[input()].append(i+1)

for i in range(tam_2):
    key = input()

    if len(d[key]) > 0:
        print(" ".join(str(j) for j in d[key]))
    else:
        print(-1)
