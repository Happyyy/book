def person(name,age,**kw):
	print('name:',name,"age:",age,"other:",kw)

person("Bob",25,city="Beijing")

other={'city':'Beijing','job':'IT'}
person('Bob',25,**other)