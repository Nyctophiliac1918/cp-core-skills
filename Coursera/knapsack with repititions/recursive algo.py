T = dict()

def knapsack(w, v, u):
    if u not in T:
        T[u] = 0

        for i in range(len(w)):
            if w[i] <= u:
                T[u] = max(T[u], knapsack(w, v, u - w[i]) + v[i])

    return T[u]


print(knapsack(w=[6, 3, 4, 2], v=[30, 14, 16, 9], u=10))
