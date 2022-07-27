#position argument

def pow(x,n=2):
	sum =1
	while n>0:
		sum = x*sum
		n = n-1
	return sum

def cacl(*numbers):
	sum = 0
	for i in numbers:
		sum = sum + pow(i)
	return sum



#print(pow(3,3))
print(cacl(1,2,3,4,5))