def matrix_mult(m):
    n = len(m) - 1
    T = [[float("inf")] * (n + 1) for _ in range(n + 1)]

    for i in range(n):
        T[i][i + 1] = 0

    for s in range(2, n + 1):
        for i in range(n - s + 1):
            j = i + s
            for k in range(i + 1, j):
                T[i][j] = min(T[i][j], T[i][k] + T[k][j] + m[i] * m[j] * m[k])

    return T[0][n]

print(matrix_mult(m=[50, 20, 1, 10, 100]))
