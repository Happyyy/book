#!/usr/bin/python
import math
#a = float(raw_input("Enter a= "))
#b = float(raw_input("Enter b= "))
#c = float(raw_input("Enter c= "))
def quadratic(a,b,c):
	if a==0:
		if b != 0:
			return "x= " + (-b/c)
		else:
			return "no solution"
	else:
		delta = b**2 - 4*a*c
		if delta >= 0:
			x1 = (-b + math.sqrt(delta)) / (2*a)
			x2 = (-b - math.sqrt(delta)) / (2*a)
			return x1,x2
		else:
			return "no solution"


print(quadratic(a,b,c))


