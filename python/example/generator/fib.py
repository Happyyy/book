#!/usr/bin/python3

def fib(max):
	i,a,b = 0,0,1
	while i < max:
		print(b)
		a,b = b,a+b
		i = i+1
	return "done"

l = fib(6)
print(l)
