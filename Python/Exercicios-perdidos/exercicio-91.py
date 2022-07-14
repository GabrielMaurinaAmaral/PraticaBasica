aluno=dict()
aluno['nome']=str(input('nome: '))
aluno['media']=float(input('media: '))

if aluno['media']>=7:
    aluno['situação']='aprovado'
elif 7>aluno['media']>=5:
    aluno['situação']='recuperação'
else:
    aluno['situação']='reprovado'

for k, v in aluno.items():
    print("{} e igual a {}".format(k, v))
