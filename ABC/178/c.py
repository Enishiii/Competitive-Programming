n = int(input())
mod = 10 ** 9 + 7
ans = pow(10, n, mod)
ans -= pow(9, n, mod) * 2
ans += pow(8, n, mod)
print(ans % mod)
