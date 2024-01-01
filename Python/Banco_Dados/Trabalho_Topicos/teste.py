import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

# Conjunto de recursos contendo valores (x,y) de 25 dados conhecidos/de treinamento
trainData = np.random.randint(0,100,(25,2)).astype(np.float32)

# Conjunto de recursos contendo valores (x,y) de 25 dados conhecidos/de treinamento
responses = np.random.randint(0,2,(25,1)).astype(np.float32)

# Pegue os vizinhos vermelhos e trace-os
red = trainData[responses.ravel()==0]
plt.scatter(red[:,0],red[:,1],80,'r','^')

# Pegue os vizinhos azuis e trace-os
blue = trainData[responses.ravel()==1]
plt.scatter(blue[:,0],blue[:,1],80,'b','s')

newcomer = np.random.randint(0,100,(1,2)).astype(np.float32)
plt.scatter(newcomer[:,0],newcomer[:,1],80,'g','o')
knn = cv.ml.KNearest_create()
knn.train(trainData, cv.ml.ROW_SAMPLE, responses)
ret, results, neighbours ,dist = knn.findNearest(newcomer, 3)
print( "result: {}\n".format(results) )
print( "neighbours: {}\n".format(neighbours) )
print( "distance: {}\n".format(dist) )

newcomers = np.random.randint(0,100,(10,2)).astype(np.float32)
ret, results,neighbours,dist = knn.findNearest(newcomer, 3)

plt.show()