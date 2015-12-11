n = int(input())
q = []
for i in range(n) :
	q.append(input().split(" "))
m = int(input())
p = []
for i in range(m) :
	p.append(input().split(" "))
for i in range(n-m+1) :
	find = True;
	for j in range(n-m+1) :
		find = True;
		for k in range(m) :
			for l in range(m) :
				if q[i+k][j+l] != p[k][l] :
					find = False;
					break
			if find == False :
				break
		if find == True :
			print (i,j)
			break
	if find == True :
		break