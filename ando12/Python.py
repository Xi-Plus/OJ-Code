n = [int(i) for i in input().split(" ")]
(x, y, z, q) = n
xl = [0, x]
yl = [0, y]
for i in range(q) :
	n = [int(i) for i in input().split(" ")]
	if n[0] == 0 :
		xl.append(n[1])
	else :
		yl.append(n[1])
xl.sort()
yl.sort()
xmin = 100000000
for i in range(len(xl)-1) :
	xmin = min(xmin,xl[i+1]-xl[i])
ymin = 100000000
for i in range(len(yl)-1) :
	ymin = min(ymin,yl[i+1]-yl[i])
print (xmin*ymin*z)