T = dict()

def fib(n):
    if n not in T:
        if n <= 1:
            T[n] = n
        else:
          T[n] = fib(n - 1) + fib(n - 2)
    
    return T[n]
    
print(fib(n)) #n=100
