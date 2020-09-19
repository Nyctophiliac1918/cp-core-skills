def knapsack(W, w, v):
    T = [[None] * (len(w) + 1) for _ in range(W + 1)]

    for u in range(W + 1):
        T[u][0] = 0

    for i in range(1, len(w) + 1):
        for u in range(W + 1):
            T[u][i] = T[u][i - 1]
            if u >= w[i - 1]:
                T[u][i] = max(T[u][i], T[u - w[i - 1]][i - 1] + v[i - 1])

    return T[W][len(w)]


print(knapsack(W=10, w=[6, 3, 4, 2], v=[30, 14, 16, 9]))
