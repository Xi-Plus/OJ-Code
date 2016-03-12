import random
import string
def random_string(size, chars=string.ascii_lowercase):
	return ''.join(random.choice(chars) for _ in range(size))

for t in range(1,2):
	n = 100
	ds = []
	name = []
	name.append("");

	for i in range(n+1):
		ds.append(i)
		name.append(random_string(6))
	def find(i):
		if(ds[i]==i): return i
		else:
			ds[i] = find(ds[i])
			return ds[i]
	def unite(a,b):
		ds[find(a)]=find(b)

	mn = random.randint(100,100)
	m = 0
	edge = []
	cnt = n
	while cnt!=1 or m<mn:
		a = random.randint(1,n)
		b = random.randint(1,n)
		if a==b: continue
		edge.append((name[a],name[b]))
		if find(a)!=find(b):
			cnt -= 1
		unite(a,b)
		m+=1
	print("%d"%n)
	for i in range(1,n+1):
		print("%s"%name[i])
	print("%d"%m)
	for i in edge:
		print("%s %s"%i)
	print("")
print("0")