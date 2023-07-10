import numpy as np

def main():
    A = np.zeros((10, 10))
    B = np.zeros((10, 11))
    b = np.zeros(10)
    x = np.zeros(10)
    Laux = np.zeros(10)
    i = j = k = n = l = 0
    m = S = 0.0

    # leitura da ordem da matriz
    print("\nEntre com a ordem da matriz de coeficientes do sistema linear.")
    n = int(input("\nn = "))

    # leitura dos dados da matriz
    print("\nEntre com os elementos da matriz de coeficientes do sistema linear.")
    print("\nEntre com as linhas.")
    for i in range(n):
        print("\n")
        for j in range(n):
            A[i][j] = float(input("A=[{}][{}] = ".format(i, j)))

    # leitura do vetor
    print("\nEntre com os elementos dos termos independentes de cada equação.")
    for i in range(n):
        b[i] = float(input("b[{}] = ".format(i)))

    # Montando a matriz expandida
    B[:n, :n] = A

    for i in range(n):
        B[i][n] = b[i]

    # impressão da matriz expandida
    print("\n")
    for i in range(n):
        print("\n")
        for j in range(n + 1):
            print("B=[{}][{}] = {:2.5f}".format(i, j, B[i][j]))

    # escalonamento da matriz expandida
    for k in range(n - 1):
        for i in range(k + 1, n):
            m = B[i][k] / B[k][k]
            B[i][k] = 0
            for j in range(k + 1, n + 1):
                B[i][j] = B[i][j] - (m * B[k][j])

    # Impressão Matriz escalonada
    print("\nMatriz escalonada.\n")
    for i in range(n):
        print("\n")
        for j in range(n + 1):
            print("B=[{}][{}] = {:2.5f}".format(i, j, B[i][j]))

    # Resolução do sistema triangular
    x[n - 1] = B[n - 1][n] / B[n - 1][n - 1]

    for i in range(n - 2, -1, -1):
        S = 0
        for k in range(i + 1, n):
            S = S + B[i][k] * x[k]
        x[i] = (-S + B[i][n]) / B[i][i]

    # Impressão da solução
    print("\nSolução do sistema.\n")
    for i in range(n):
        print("x=[{}] = {}".format(i, x[i]))


if __name__ == "__main__":
    main()
