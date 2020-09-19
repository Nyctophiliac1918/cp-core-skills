def fib(n):
    if n <= 1:
        return n
    return fib(n - 1) + fib(n - 2)
    
print(fib(n)) #could tell easily till n=10
