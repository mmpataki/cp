t=int(input())
for tt in range(t):
    n, k = [int(i) for i in input().split(" ")]
    print('abc' * (n//3) + 'abc'[:n%3])