def lis(A, last_index):
    if last_index == -1:
        last_element = float("-inf")
    else:
        last_element = A[last_index]

    result = 0

    for i in range(last_index + 1, len(A)):
        if A[i] > last_element:
            result = max(result, 1 + lis(A, i))

    return result

print(lis([8, 2, 3, 4, 5, 6, 7], -1))
