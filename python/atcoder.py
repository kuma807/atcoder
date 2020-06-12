from fractions import Fraction
a, b = input().split()
a = int(a)
b = Fraction(b) * 100
ans = (a * b) // 100
print(ans)
