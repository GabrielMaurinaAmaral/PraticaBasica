from collections import deque

#d = deque()
#
#d.append(1)
#d.appendleft(2)
#d.clear()
#d.extend('1')
#d.extendleft('234')
#d.count('1')
#d.pop()
#d.popleft()
#d.extend('7896')
#d.remove('2')
#d.reverse()
#d.rotate(3)
#
#print(d)

d = deque()
tam = int(input())

for _ in range(tam):
    funcao = list(input().split())

    if('append' == funcao[0]):
        d.append(int(funcao[1]))
    elif('appendleft' == funcao[0]):
        d.appendleft(int(funcao[1]))
    elif('pop' == funcao[0]):
        d.pop()
    elif('popleft' == funcao[0]):
        d.popleft()

for i in d:
    print(i,end=" ")