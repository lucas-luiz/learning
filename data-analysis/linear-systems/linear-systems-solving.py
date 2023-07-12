#Lucas Luiz da Silva
#2022008662
import numpy as np

i = j = k = n = l = 0
m = S = 0.0

print("\nEntre com a ordem da matriz")
n = int(input("\nn = "))

A = np.zeros((n, n))
B = np.zeros((n, n+1))
b = np.zeros(n)
x = np.zeros(n)
Laux = np.zeros(n)

print("\nEntre com as linhas")
for i in range(n):
    print("\n")
    for j in range(n):
        A[i][j] = float(input("A=[{}][{}] = ".format(i, j)))

print("\nEntre com os termos independentes")
for i in range(n):
    b[i] = float(input("b[{}] = ".format(i)))

B[:n, :n] = A

for i in range(n):
    B[i][n] = b[i]

print("\nMatriz.\n")
for i in range(n):
    print(B[i])

for k in range(n - 1):
    max_index = k
    max_value = abs(B[k][k])

    for i in range(k + 1, n):
        if abs(B[i][k]) > max_value:
            max_index = i
            max_value = abs(B[i][k])

    B[[k, max_index]] = B[[max_index, k]]

print("\nMatriz após pivoteamento.\n")
for i in range(n):
    print(B[i])

for k in range(n - 1):
    for i in range(k + 1, n):
        m = B[i][k] / B[k][k]
        B[i][k] = 0
        for j in range(k + 1, n + 1):
            B[i][j] = B[i][j] - (m * B[k][j])

print("\nMatriz escalonada.\n")
for i in range(n):
    print(B[i])

x[n - 1] = B[n - 1][n] / B[n - 1][n - 1]

for i in range(n - 2, -1, -1):
    S = 0
    for k in range(i + 1, n):
        S = S + B[i][k] * x[k]
    x[i] = (-S + B[i][n]) / B[i][i]

print("\nSolução do sistema.\n")
for i in range(n):
    print("x=[{}] = {}".format(i, x[i]))


