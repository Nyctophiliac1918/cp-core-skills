def lis(A):
    T = [None] * len(A)
    prev = [None] * len(A)

    for i in range(len(A)):
        T[i] = 1
        prev[i] = -1
        for j in range(i):
            if A[j] < A[i] and T[i] < T[j] + 1:
                T[i] = T[j] + 1
                prev[i] = j

    last = 0
    for i in range(1, len(A)):
        if T[i] > T[last]:
            last = i

    lis= []
    current = last
    while current >= 0:
        lis.append(current)
        current = prev[current]
    lis.reverse()
    return [A[i] for i in lis]

print(lis([7, 2, 1, 3, 8, 4, 9, 1, 2, 6, 5, 9, 3, 8, 1]))
