def knapsack(W, w, v, items):
    weight = sum(w[i] for i in items)
    value = sum(v[i] for i in items)

    for i in range(len(w)):
        if weight + w[i] <= W:
            value = max(value, knapsack(W, w, v, items + [i]))

    return value

print(knapsack(W=10, w=[6, 3, 4, 2], v=[30, 14, 16, 9], items=[]))
