# Program to calculate the power set of a given set
elements=list(map(int, input("Enter Elements :: ").split()))
power_set=[]
ans=0
for i in range(1<<len(elements)):
	temp=[]
	for j in range(len(elements)):
		if i&(1<<j):
			temp.append(elements[j])
	power_set.append(temp)

print("The Sets are as Follows")
for sub_set in power_set:
	print(sub_set)
