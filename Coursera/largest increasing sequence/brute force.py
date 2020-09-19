def lis(A, seq):
    result = len(seq)

    if len(seq) == 0:
        last_index = -1
        last_element = float("-inf")
    else:
        last_index = seq[-1]
        last_element = A[last_index]

    for i in range(last_index + 1, len(A)):
        if A[i] > last_element:
            result = max(result, lis(A, seq + [i]))

    return result

print(lis(A=[7, 2, 1, 3, 8, 4, 9], seq=[]))
