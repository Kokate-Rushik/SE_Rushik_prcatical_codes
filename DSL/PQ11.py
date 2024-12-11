def switch(choice):
    global arr1, arr2
    output = -1
    if (choice==1):
        n = len(arr2)
        choice_2 = int(input("Choose searching type\
\n1. Linear Search.\n2. Sentinel Search.\nChoice:- "))
        key = int(input("Enter Roll No:- "))
        if (choice_2==1):
            output = Linear_Search(arr1, n, key)
        elif (choice_2==2):
            output = Sentinel_Search(arr1, n, key)
        else:
            return "Invalid search type"
           
    elif (choice==2):
        n = len(arr2)
        choice_2 = int(input("Choose searching type\
\n1. Binary Search.\n2. Fibonacci Search.\nChoice:- "))
        key = int(input("Enter Roll No:- "))
        if (choice_2==1):
            output = Binary_Search(arr2, key)
        elif (choice_2==2):
            output = Fibonacci_Search(arr2, n, key)
        else:
            return "Invalid search type"
            
    else:
        return "Wrong input"
    return output

def Linear_Search(arr, n, key):
    i = 0
    while (i<n):
        if (arr[i]==key):
            return 'Found at ' + str(i)
        i+=1
    return 'Not Found!!'

def Sentinel_Search(arr, n, key):
    last = arr[n-1]
    arr[n-1] = key
    i = 0
    while (arr[i]!=key):
        i+=1
    arr[n-1] = last
    if (i<n-1 or arr[n-1]==key):
        return 'Found at '+ str(i)
    else:
        return 'Not Found!!'

def Binary_Search(arr, key, low=0, high=None):
    if high==None:
        high=len(arr)-1
    if low>high:
        return -1
    mid = low+(high-low)//2
    if (arr[mid]==key):
        return mid
    if (arr[mid]<key):
        return Binary_Search(arr, key, mid+1 , high)
    else:
        return Binary_Search(arr, key, low, mid-1)
    return -1

def Fibonacci_Search(arr, n, key):
    fib2=0
    fib1=1
    fibm=fib2+fib1

    while (fibm<n):
        fib2=fib1
        fib1=fibm
        fibm=fib2+fib1

    offset = -1

    while (fibm > 1):
        i= min(offset+fib2, n-1)

        if (arr[i]<key):
            fibm=fib1
            fib1=fib2
            fib2=fibm-fib1
            offset = i

        elif (arr[i]>key):
            fibm = fib2
            fib1 = fib1-fib2
            fib2 = fibm-fib1

        else:
            return i

    if (fibm and arr[n-1]==key):
        return n-1

    return -1

arr1 = [5, 10, 3, 13, 11, 2, 1, 17, 14, 6, 12, 8, 19, 4, 5]
arr2 = [1, 2, 3, 4, 5, 6, 8, 10, 11, 12, 13, 14, 15, 17, 19]

def main():
    choice_1 = int(input("Unsorted array for Sorted array (1 or 2)?"))
    
    index = switch(choice_1)
    if (isinstance(index, str)):
        print(index)
    elif (index==-1):
        print("Roll no. not found")
    else:
        print("Roll no. found at ", index)
    
if __name__ == '__main__':
    main()
