#!/usr/bin/python3

def fib(max):
	i,a,b = 0,0,1
	while i < max:
#print(b)
		yield b #generator
		a,b = b,a+b
		i = i+1
	return "done"

g = fib(6)
while True:
	try:
		x = next(g)
		print('g:',x)
	except StopIteration as e:
		print('Generator return value:',e.value)
		break

