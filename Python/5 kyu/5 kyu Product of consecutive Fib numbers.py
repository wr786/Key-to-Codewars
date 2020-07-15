def productFib(prod):
    fibs = [0] * 10000
    cur = 0
    def Fib(n): 
        fibs[n] = (n if n <= 1 else (Fib(n-1) + Fib(n-2) if fibs[n] == 0 else fibs[n]))
        return fibs[n] 
    while Fib(cur) * Fib(cur+1) < prod: cur += 1
    return [Fib(cur), Fib(cur+1), Fib(cur)*Fib(cur+1) == prod]