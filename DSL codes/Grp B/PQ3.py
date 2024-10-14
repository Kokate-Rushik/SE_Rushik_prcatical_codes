#Code by Kokate Rushik

def TernarySearch(key, l, r):
	global club
	mid1, mid2 = (l+(r-l)//3), (r-(r-l)//3)
	
	while (l<=r):
		if (key==club[mid1][0]):
			return mid1
		elif (key==club[mid2][0]):
			return mid2
		elif (key<club[mid1][0]):
			return TernarySearch(key, l, mid1-1)
		elif (key>club[mid2][0]):
			return TernarySearch(key, mid2+1, r)
		else:
			return TernarySearch(key, mid1+1, mid2-1)
	return -1

def getclub():
	global club	
	n = int(input("Enter no. of members:- "))
	if n==0:
		return None, None
	mem=()
	for i in range(0,n):
		r=int(input("\nEnter the roll no:- "))
		na=input("Enter the name of the member:- ")
		mem=(r,na)
		club.append(mem)
	sortclub()
	return 0, len(club)-1

def sortclub():
	global club
	return club.sort(key=lambda member : member[0])

club = []

if __name__=='__main__':
	l, r = getclub()
	if r!=None:
		key=int(input("\nEnter roll no to search:- "))
	
		output = TernarySearch(key, l, r)
		if output==-1:
			print(f"\nRollno {key} is not the member of the club.")
		else:
			print(f"\nRollno {key} is the {output+1}th member of the club.")
	else:
		print("End of the program")	
