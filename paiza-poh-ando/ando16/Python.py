n=int(input())
m1=int(input())
x=input().split()
x.sort()
m2=int(input())
y=input().split()
ans=[]
for t in y:
	if t not in x:
		ans.append(int(t))
if len(ans)==0:
	print("None")
else :
	ans.sort()
	print(" ".join(str(x) for x in ans))
