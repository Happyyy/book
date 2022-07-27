#!/usr/bin/python3

def fib(max):
	i,a,b = 0,0,1
	while i < max:
#print(b)
		yield b #generator
		a,b = b,a+b
		i = i+1
	return "done"
for i in fib(6):
	print(i)
