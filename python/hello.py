
grade = { "happy":95, "grace":100, "Aron":93}
print(grade)
grade["liang"] = 90
print(grade)

#justice
if "Sonic" in grade:
	print("sonic is in our class")
else:
	print("sonic is not in our class")

print(grade.get("grace"))
print('\n')

grade.pop("grace")
print(grade)

set1 = set([1,2,3,4,5])
set2 = set([1,2,3,4])
print(type(set1))
set1.add(33)
print(set1)
set1.remove(2)
print(set1)

print(set1 & set2)

print(set1 | set2)