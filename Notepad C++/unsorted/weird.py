def solve(p):
    a = 10 % p
    r = 1
    while True:
        if a == 1:
            return r
        a = (a * 10) % p
        r += 1 

while True:
    p = int(input("Enter a prime p (not 2 or 5, -1 to quit):\n"))
    if p == -1:
        break
    print(solve(p))