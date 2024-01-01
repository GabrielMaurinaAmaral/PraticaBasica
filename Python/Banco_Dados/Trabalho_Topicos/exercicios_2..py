"""
1) Considere o dataset CompanhiaMB.csv. 
- Identifique os tipos de dados para cada variável (categórico, numérico...)
- Veja o catálogo From Data to Viz (https://www.data-to-viz.com/)
- Identifique qual mapeamento visual é o mais indicado para os seus dados e, se você julgar que aquele paradigma visual realmente é a melhor escolha, apresente seus dados com a visualização
- Descreva os insights que a visualização proporcionou para os seus dados
- Entrega no Moodle até 6/4. (Entregar o notebook .ipynb ou arquivo .py)
"""

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt 
import seaborn as sns

data = pd.read_csv("C:/Users/GABRIEL/OneDrive - alunos.utfpr.edu.br/Material-UTFPR/5° Periodo/Topicos em Informatica/Topicos_Indormatica/Data-Science-main/3_Visualizacao_de_dados/CompanhiaMB.csv")
print(data)

#funcionario, numerico int -> 1 a 36 
print('\n',data['funcionario'])
#estado_civil, categorica -> solteiro ou casado
print('\n',data['estado_civil'])
#instrucao, categorico -> ensino_fundamental, ensino_medio ou superior
print('\n',data['instrucao'] )
#nfilhos, numerico int -> 0 a 5
print('\n',data['nfilhos'] )
#salario, numerico float -> 4.00 a 23.30
print('\n',data['salario'])
#idade_anos, numerio int -> 23 a 48
print('\n',data['idade_anos'])
#idade_meses, numerio int -> 0 a 11
print('\n',data['idade_meses'])
#regiao,categorico -> outro, interior ou capital
print('\n',data['regiao'])

# Cria o gráfico de pizza
contagem = data['estado_civil'].value_counts()
plt.pie(contagem.values, labels=contagem.index, colors=['blue', 'green'], autopct='%1.1f%%', startangle=140)
plt.title('Porcentagem de Pessoas Solteiras e Casadas')
plt.show()

contagem = data['instrucao'].value_counts()
plt.pie(contagem.values, labels=contagem.index, colors=['blue', 'green', 'red'], autopct='%1.1f%%', startangle=140)
plt.title('Porcentagem de Pessoas Instruidas')
plt.show()

contagem = data['regiao'].value_counts()
plt.pie(contagem.values, labels=contagem.index, colors=['blue', 'green', 'red'], autopct='%1.1f%%', startangle=140)
plt.title('Porcentagem de Pessoas de Cada Regiao')
plt.show()

# noção de quantos solteiros ou casados tem em cada regiao e a idade
sns.violinplot(x='regiao', y='idade_anos', hue='estado_civil', data=data)
plt.title('Distribuição da solteiro e casados por regiao')
plt.legend()
plt.show()

sns.violinplot(x='regiao', y='nfilhos', hue='estado_civil', data=data)
plt.title('Distribuição da solteiro e casados por regiao')
plt.legend()
plt.show()

sns.countplot(x="regiao", hue="estado_civil", data=data)
plt.title("Distribuição de Estado Civil por Região")
plt.legend()
plt.show()