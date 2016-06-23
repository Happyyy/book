#!/usr/bin/python3

def triangles(max):
	n,L = 0,[1]
	while n < max:
		yield L
		L = [1] + [L[m]+L[m+1] for m in range(len(L)-1)] + [1]
		n = n+1
	return 'done'

g = triangles(10)
while True:
	try:
		x = next(g)
		print(x)
	except StopIteration as e:
		print('generator return value:',e.value)
		break
