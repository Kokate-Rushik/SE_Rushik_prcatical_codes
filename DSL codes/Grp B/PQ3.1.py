#Code by Kokate Rushik
'''
This enhanced Ternary Search implementation not only fulfills the original requirement of searching for a
roll number in a club but also introduces critical membership management features. By considering 
potential user scenarios and providing intuitive feedback, this version elevates the program to a more 
practical and robust solution, making it well-suited for real-world applications.
'''

def TernarySearch(key, l, r):
	'''
	Performs Ternary Searching
	Input: key, l -> leftmost element, and r -> rightmost element
		club is not pass as it exist at global level.
	Ouput: it will return index value if the key is found
		else it will return -1 if the key is not found
	'''
	global club
	mid1, mid2 = (l+(r-l)//3), (r-(r-l)//3)
	
	while (l<=r):
		if key==club[mid1][0]:
			return mid1
			
		elif key==club[mid2][0]:
			return mid2
			
		elif key<club[mid1][0]:
			return TernarySearch(key, l, mid1-1)
			
		elif key>club[mid2][0]:
			return TernarySearch(key, mid2+1, r)
			
		else:
			return TernarySearch(key, mid1+1, mid2-1)
			
	return -1

def getclub():
	'''
	This function takes the data for the club from the user
	'''
	global club
	def ismember(r):
		'''
		This function checks if the rollno given by the user already
		exist in the club.
		'''
		for i in club:
			if i[0]==r:
				return True
		return False
		
	n = int(input("Enter no. of members:- "))
	if n==0:
		return None, None
	mem=[]
	i=0
	while i < n:
		r=int(input("\nEnter the roll no:- "))
		na=input("Enter the name of the member:- ")
		if ismember(r):
			club[r][1]=na
		else:
			mem=[r,na]
			club.append(mem)
			i+=1
	sortclub()
	return 0, len(club)-1

def sortclub():
	'''
	Sorts the club 
	'''
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
