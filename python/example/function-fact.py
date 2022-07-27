'''def fact(n):
	if n == 1:
		return 1
	else:
		return fact(n-1)*n
'''
def fact_iter(n,sum):
	if n == 1:
		return sum
	else:
		return fact_iter(n-1, sum*n)
def fact(n):
	return fact_iter(n, 1)

#print(fact(100))
#print(fact(93))
print(fact(100)/fact(93))
