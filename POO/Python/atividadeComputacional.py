import numpy as np 

def decomposicaoLU(A):

    n = len(A)
    b = [0 for i in range(n)]
    L = np.zeros((n, n))
    U = np.zeros((n, n))

    # Preparando a matrix L e U
    for i in range(0, n):
        L[i, i] = 1
        for j in range(0, n):
            U[i][j] = A[i][j]

    #Triangularizando e pegando coeficientes
    for i in range(0, n):
       
        for j in range(i + 1, n):
            coeficiente = -U[j][i]/float(U[i][i])
            L[j][i] = abs(coeficiente)
            for k in range(i, n):
                U[j][k] += U[i][k] * coeficiente
        
    return U, L

 
def substituicaoLU(U, L, b):
    # Descobrindo a matrix y
    n = len(U)
    y = np.zeros((n, 1))

    y[0] = b[0]/L[0, 0]

    for i in range(1, n):
        y[i] = (b[i] - np.dot(L[i, :i], y[:i])) / L[i, i]

    # Descobrindo a matrix x
    x = np.zeros((n, 1))

    x[-1] = y[-1]/U[-1, -1]

    for i in range(n-2, -1, -1):
        x[i] = (y[i] - np.dot(U[i,i:], x[i:]))/U[i,i]

    return x


def LU():
    A = np.array([[1, 1, 1], [2, 1, -1], [2, -1, 1]])

    b = np.array([[-2], [1], [3]])
    U = np.zeros(A.shape)
    L = np.zeros(A.shape)

    U, L = decomposicaoLU(A)

    return substituicaoLU(U, L, b)

print(LU())



