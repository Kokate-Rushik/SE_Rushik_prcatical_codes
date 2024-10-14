#Code by Kokate Rushik

def switch(choice):
    global phonebook
    name = input("Enter the name you want to search:- ")
    output = -1
    while (True):
        if choice==1:
            output = Binary_Search_1(phonebook, name)
            break
        elif choice==2:
            output = Binary_Search_1(phonebook, name)
            break
        elif choice==3:
            output = Fibonacci_Search(phonebook, name)
            break
        else:
            print("Wrong input")
            break
    return output, name

def Binary_Search_1(arr, key, low=0, high=None):
    if high==None:
        high=len(arr)-1

    mid = low+(high-low)//2
    
    while (low<=high):
        if (arr[mid][0]<key):
            return Binary_Search_1(arr, key, mid+1, high)

        elif (arr[mid][0]>key):
            return Binary_Search_2(arr, key, low, mid-1)

        else:
            return mid
    return -1
    
    
def Binary_Search_2(arr, key, low=0, high=None):
    if high==None:
        high=len(arr)-1

    mid = low+(high-low)//2

    while (low<=high):
        if (arr[mid][0]<key):
            low= mid+1
            mid= low+(high-low)//2
            continue
        
        elif (arr[mid][0]>key):
            high = mid-1
            mid= low+(high-low)//2
            continue
        
        else:
            return mid
    return -1
    
def Fibonacci_Search(arr, key):
    fib_2 = 0
    fib_1 = 1
    fib_m = fib_2 + fib_1

    while (fib_m < len(arr)):
        fib_2=fib_1
        fib_1=fib_m
        fib_m=fib_2+fib_1

    offset = -1

    while (fib_m > 1):
        i = min(offset+fib_2, len(arr)-1)

        if (arr[i][0] < key):
            fib_m=fib_1
            fib_1=fib_2
            fib_2=fib_m-fib_1
            offset=i
            
        elif (arr[i][0] > key):
            fib_m = fib_2
            fib_1 = fib_1-fib_2
            fib_2 = fib_m-fib_1
            
        else:
            return i

    if (fib_m and arr[len(arr)-1] == key):
        return (len(arr)-1)

    return -1

        
def main():
    Choice = int(input("Choose the method of searching.\
    \n1. Recursive Binary Search.\
    \n2. Non-Recursive Binary Search.\
    \n3. Fibonacci Search.\nChoice:- "))

    Answer,name = switch(Choice)

    if (Answer != -1):
        print(name+" found at",Answer)
        print(phonebook[Answer])
    else:
        print(name+" not found in phonebook.")
        yesno = input("DO you want to add the name (Y/N):- ")
        if(yesno.lower()=='y'):
            phno = input("Enter the phone no.:-")
            phonebook.append((name, phno))
            print("Number added sucessfully.")
        else:
            print("Number not added.")            

phonebook = [
    ("Aarav", "9876543210"),
    ("Ishita", "9123456789"),
    ("Rahul", "9871234567"),
    ("Ananya", "9823456789"),
    ("Rohan", "9812345678"),
    ("Sanya", "9123456780"),
    ("Arjun", "9876541234"),
    ("Neha", "9812348765"),
    ("Kunal", "9876548765"),
    ("Priya", "9123454321"),
    ("Riya", "9876545678"),
    ("Rushik", "9123457890"),
    ("Sneha", "9876542345"),
    ("Devansh", "9812345432"),
    ("Meera", "9123451234")
]

if __name__ == "__main__":
    main()
