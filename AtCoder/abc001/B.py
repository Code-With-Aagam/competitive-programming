n = int(input())
ans = int(0)
if n < 100:
	ans = 0
elif n <= 5000:
	ans = n * 10
	ans /= 1000
elif n <= 30000:
	ans = (n / 1000) + 50;
elif n <= 70000:
	ans = (((n / 1000) - 30) / 5) + 80;
else:
	ans = 89
if ans < 10:
	print(0, end = '')
print(int(ans))