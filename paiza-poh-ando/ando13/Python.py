n=int(input())
ans=1
while n>1:
	ans*=n
	while ans%10==0:
		ans//=10
	ans%=1000000000000
	n-=1
print(ans%1000000000)
