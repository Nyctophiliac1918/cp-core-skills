def fib(n):
    if n <= 1:
      return n

    previous, current = 0, 1
    for _ in range(n - 1):
        new_current = previous + current
        previous, current = current, new_current

    return current
    
print(fib(n)) #n=400
