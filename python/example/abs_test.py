#!/usr/bin/python
def my_abs(x):
	if not isinstance(x,(int,float)):
		return "Bad operand error"
	if x >= 0:
		return x
	else:
		return -x