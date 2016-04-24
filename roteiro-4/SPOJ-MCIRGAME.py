#/usr/bin/python

def solve():

    sol = [0] * 152
    sol[0] = sol[1] = 1

    for i in range (2, 151):
        j = 0
        while (j < i):
            sol[i] += sol[j] * sol[i - j - 1]
            j+=1

    n = 0
    while (True):
        x = [int(i) for i in input().split(' ')]
        if (x[0] == -1):
            break
        print (sol[x[0]])

solve()
