import numpy as np
import pandas as pd

lista = [['brasil', 'brasil', 'brasil', 'argentina', 'argentina',
          'argentina'], [2017, 2018, 2019, 2017, 2018, 2019]]
tuplas = zip(*lista)

print("\n",lista)
print("\n",tuplas)

tuplas = list(tuplas)

print("\n",tuplas)

multi = pd.MultiIndex.from_tuples(tuplas)
print("\n",tuplas)

data_frame_1=pd.DataFrame(data = np.random.randn(6,2), index=multi, columns=['EXP TRIGO', 'EXP ARROZ'])
print(data_frame_1)

data_frame_1.index.names = ['PAÍ','ANO']
print('\n',data_frame_1)

print('\n',data_frame_1['EXP ARROZ'])
print('\n',data_frame_1.loc['brasil'])
print('\n',data_frame_1.xs(2017, level=1))
print('\n',data_frame_1.unstack())


