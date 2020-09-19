def lis(A, seq_len, last_index):
    if last_index == -1:
        last_element = float("-inf")
    else:
        last_element = A[last_index]

    result = seq_len

    for i in range(last_index + 1, len(A)):
        if A[i] > last_element:
            result = max(result, lis(A, seq_len + 1, i))

    return result

print(lis([3, 2, 7, 8, 9, 5, 8], 0, -1))
