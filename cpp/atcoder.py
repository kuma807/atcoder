a, b = map(int, input().split())

ans = 1
for i in range(N):
    ans *= A[i]
if ans > pow(10, 18):
    ans = -1
print(ans)
