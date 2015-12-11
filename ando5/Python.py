yes = 0
no = 0
for i in range(5) :
	s = input()
	if s == "yes" :
		yes += 1
	else :
		no += 1
if yes > no :
	print ("yes")
else :
	print ("no")