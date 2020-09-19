def knapsack(W, w, v, items, last):
    weight = sum(w[i] for i in items)

    if last == len(w) - 1:
        return sum(v[i] for i in items)

    value = knapsack(W, w, v, items, last + 1)
    if weight + w[last + 1] <= W:
        value = max(value, knapsack(W, w, v, items + [last + 1], last + 1))

    return value

print(knapsack(W=10, w=[6, 3, 4, 2], v=[30, 14, 16, 9], items=[], last=-1))
