import pandas
data_1 = pandas.read_csv('C:\CODE\PraticaBasica\Python\Topicos_Indormatica\Data-Science-main\_2_Organização_e_natureza_dos_dados\CompanhiaMB.csv')
"""
Exercício 1

A tabela apresentada no slide 15 ilustra o seguinte:
● Companhia MB
○ Um pesquisador está interessado em fazer um levantamento sobre alguns aspectos socioeconômicos dos empregados da seção de orçamentos da Companhia MB. 
Usando informações obtidas do departamento pessoal, ele elaborou a tabela descrita no arquivo CompanhiaMB.csv
○ Essa tabela está disponível no GitHub (link no moodle).
● Classifique as variáveis estado civil, grau de instrução, número de filhos, salário, idade, região. 
Que valores elas podem assumir?
"""

# informa as informaçoes de cada coluna com detalhe
data_1.info()

# Mostra todos os dados
print(data_1)

# Indorma o nome de cada coluna
print(data_1.columns)

# Variavel quantitativa discreto, podendo ir de 1 a 36
print(f"\n{data_1['funcionario']}")

# Variavel qualitativa nominal, podendo variar entre solteiro e casado
print(f"\n{data_1['estado_civil']}")

# Variavel qualitativa ordinais, podendo ser ensino_fundamental, ensino_medio ou superior
print(f"\n{data_1['instrucao']}")

# Variavel quantitativa discreto, podendo não possuir nem dados sobre,  ou 1, 2, 3...
print(f"\n{data_1['nfilhos']}")

# Variavel quantitativa continua
print(f"\n{data_1['salario']}")

# Variavel quantitativa discreto
print(f"\n{data_1['idade_anos']}")

# Variavel quantitativa discreto, podendo ir de 1 a 12
print(f"\n{data_1['idade_meses']}")

# Variavel qualitativa ordinais, podendo ser interior, capital ou outro
print(f"\n{data_1['regiao']}")

"""
Considere os dados abaixo
[1] 0 0 1 1 2 2 4 6 8 8 8 9 9 10 11 11 11 12 12 12 13 13 13 13 13
[26] 14 14 14 15 15 16 16 16 16 17 17 18 18 18 19 19 19 20 21 21 22 28 34

a) Monte uma tabela construindo as classes conforme os critérios
apresentados.

b) Calcule as frequências: absoluta, relativa, percentual, acumulada
"""
data_2 = [0, 0, 1, 1, 2, 2, 4, 6, 8, 8, 8, 9, 9, 10, 11, 11, 11, 12, 12, 12, 13, 13, 13, 13, 13, 14, 14, 14, 15, 15, 16, 16, 16, 16, 17, 17, 18, 18, 18, 19, 19, 19, 20, 21, 21, 22, 28, 34]
data_frame = pandas.DataFrame(data_2, columns=['valor'])
# b)
frequencia_absoluta = data_frame['valor'].value_counts().sort_index()
frequencia_relativa = frequencia_absoluta / len(data_frame)
frequencia_percentual = frequencia_relativa * 100
frequencia_acumulada = frequencia_absoluta.cumsum()
# a)
tabela = pandas.DataFrame({
    'valor': frequencia_absoluta.index,
    'frequencia_absoluta': frequencia_absoluta.values,
    'frequencia_relativa': frequencia_relativa.values,
    'frequencia_percentual': frequencia_percentual.values,
    'frequencia_acumulada': frequencia_acumulada.values
})
print(tabela)
"""
    valor  frequencia_absoluta  frequencia_relativa  frequencia_percentual  frequencia_acumulada
0       0                    2             0.041667               4.166667                     2
1       1                    2             0.041667               4.166667                     4
2       2                    2             0.041667               4.166667                     6
3       4                    1             0.020833               2.083333                     7
4       6                    1             0.020833               2.083333                     8
5       8                    3             0.062500               6.250000                    11
6       9                    2             0.041667               4.166667                    13
7      10                    1             0.020833               2.083333                    14
8      11                    3             0.062500               6.250000                    17
9      12                    3             0.062500               6.250000                    20
10     13                    5             0.104167              10.416667                    25
11     14                    3             0.062500               6.250000                    28
12     15                    2             0.041667               4.166667                    30
13     16                    4             0.083333               8.333333                    34
14     17                    2             0.041667               4.166667                    36
15     18                    3             0.062500               6.250000                    39
16     19                    3             0.062500               6.250000                    42
17     20                    1             0.020833               2.083333                    43
18     21                    2             0.041667               4.166667                    45
19     22                    1             0.020833               2.083333                    46
20     28                    1             0.020833               2.083333                    47
21     34                    1             0.020833               2.083333                    48
"""
"""
Considere o arquivo CompanhiaMB.csv disponível no Github e realize as seguintes operações:
● faça a leitura do arquivo via pandas
● Verifique as informações dos dados
● Apresente um resumo estatístico
● Acesse os campos e defina quais são categóricos
● Renomeie o nome das colunas para que todos tenham a primeira letra maiúscula
● Para as variáveis nfilhos e idade_anos, apresente a média, moda, desvio padrão, mínimo
e máximo
● Encontre o índice do funcionário que possui a maior idade. Faça a localização (loc) e
mostre todos os dados dele.
● Faça um loc para apresentar se existem funcionários com idade maior de 40 anos.
"""
# leitura do arquivo 
data_3 = pandas.read_csv('C:\CODE\PraticaBasica\Python\Topicos_Indormatica\Data-Science-main\_2_Organização_e_natureza_dos_dados\CompanhiaMB.csv')
print(data_3)
# informações dos dados
print(data_3.info())
"""
 #   Column        Non-Null Count  Dtype
---  ------        --------------  -----
 0   funcionario   36 non-null     int64
 1   estado_civil  36 non-null     object
 2   instrucao     36 non-null     object
 3   nfilhos       20 non-null     float64
 4   salario       36 non-null     float64
 5   idade_anos    36 non-null     int64
 6   idade_meses   36 non-null     int64
 7   regiao        36 non-null     object
dtypes: float64(2), int64(3), object(3)
"""
# resumo estatístico
print(data_3.describe())
"""
       funcionario    nfilhos    salario  idade_anos  idade_meses
count    36.000000  20.000000  36.000000   36.000000    36.000000
mean     18.500000   1.650000  11.122222   34.583333     5.611111
std      10.535654   1.268028   4.587458    6.737422     3.288749
min       1.000000   0.000000   4.000000   20.000000     0.000000
25%       9.750000   1.000000   7.552500   30.000000     3.750000
50%      18.500000   2.000000  10.165000   34.500000     6.000000
75%      27.250000   2.000000  14.060000   40.000000     8.000000
max      36.000000   5.000000  23.300000   48.000000    11.000000
"""
# colunas com todos as primeira letra maiúscula
data_3.columns = data_3.columns.str.capitalize()
print(data_3.columns)
"""
Funcionario Estado_civil Instrucao Nfilhos Salario Idade_anos Idade_meses Regiao
"""
# Para as variáveis nfilhos e idade_anos, apresente a média, moda, desvio padrão, mínimo e máximo
print(data_3['Nfilhos'].mean())
print(data_3['Nfilhos'].mode().values[0])
print(data_3['Nfilhos'].std())
print(data_3['Nfilhos'].min())
print(data_3['Nfilhos'].max())
""" 
1.65
2.0
1.268027892769755
0.0
5.0
"""
print(data_3['Idade_anos'].mean())
print(data_3['Idade_anos'].mode().values[0])
print(data_3['Idade_anos'].std())
print(data_3['Idade_anos'].min())
print( data_3['Idade_anos'].max())
""" 
34.583333333333336
26
6.737422143732508
20
48
"""
# Encontre o índice do funcionário que possui a maior idade
id_maior_idade = data_3['Idade_anos'].idxmax()
print(id_maior_idade)
""" 
34
"""
# Faça a localização (loc) e mostre todos os dados dele
funcionario_maior_idade = data_3.loc[id_maior_idade]
print(funcionario_maior_idade)
""" 
Funcionario               35
Estado_civil          casado
Instrucao       ensino_medio
Nfilhos                  2.0
Salario                 19.4
Idade_anos                48
Idade_meses               11
Regiao               capital
Name: 34, dtype: object
"""

# Faça um loc para apresentar se existem funcionários com idade maior de 40 anos
funcionarios_mais_40 = data_3.loc[data_3['Idade_anos'] > 40]
print(funcionarios_mais_40)
""" 
    Funcionario Estado_civil           Instrucao  Nfilhos  Salario  Idade_anos  Idade_meses    Regiao
6             7     solteiro  ensino_fundamental      NaN     6.86          41            0  interior
7             8     solteiro  ensino_fundamental      NaN     7.39          43            4   capital
13           14       casado  ensino_fundamental      3.0     8.95          44            2     outro
22           23     solteiro  ensino_fundamental      NaN    12.00          41            0     outro
26           27     solteiro  ensino_fundamental      NaN    13.85          46            7     outro
32           33       casado            superior      3.0    17.26          43            7   capital
34           35       casado        ensino_medio      2.0    19.40          48           11   capital
35           36       casado            superior      3.0    23.30          42            2  interior
"""

# defina quais são categóricos
data_3['funcionario'] = data_3['funcionario'].astype('quantitativo_discreto')
data_3['estado_civil'] = data_3['estado_civil'].astype('qualitativa nominal')
data_3['instrucao'] = data_3['instrucao'].astype('qualitativa ordinais')
data_3['nfilhos'] = data_3['nfilhos'].astype('quantitativo_discreto')
data_3['salario'] = data_3['salario'].astype('quantitativo_continua')
data_3['idade_anos'] = data_3['idade_anos'].astype('quantitativo_discreto')
data_3['idade_meses'] = data_3['idade_meses'].astype('quantitativo_discreto')
data_3['idade_meses'] = data_3['idade_meses'].astype('quantitativo_discreto')