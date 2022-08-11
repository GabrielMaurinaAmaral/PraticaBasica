from collections import namedtuple

tam = int(input())
colunas = ','.join(input().split())
alunos = namedtuple('alunos', colunas)

soma = 0
for i in range(tam):
    linha = input().split()
    aluno = alunos(*linha)
    soma += int(aluno.MARKS)

print(soma/tam)
