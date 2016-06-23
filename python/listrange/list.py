#!/usr/bin/python
L1 = ['HELLO','WORLD',18,'APPLE',None]

L2 = [l.lower() for l in L1 if isinstance(l,str)]
print(L2)

