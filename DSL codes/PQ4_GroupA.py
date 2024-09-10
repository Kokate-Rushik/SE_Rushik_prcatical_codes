def checkBalance(fromthis):
    bal=0
    for i in fromthis:
        if i[0]=='D':
            bal+=i[1]
        else:
            bal-=i[1]
    if bal<=0:
        return False
    else:
        return bal

def Withdraw():
    global record
    if checkBalance(record)==False:
        print("Insufficient Balance")
        return
    amt = int(input("Enter amount to withdraw:- "))
    log=('W', amt)
    record.append(log)
    print("Withdrawn successfull!")
    return

def Deposit():
    global record
    amt = int(input("Enter amount to deposit:- "))
    log=('D', amt)
    record.append(log)
    return

def showBalance():
    global record
    bal = checkBalance(record)
    if bal==False:
        print("Insufficient Balance!")
        return
    else:
        print("Your balance is:-", bal)
        return

def showRecord():
    global record
    print(record)
    return

def EXIT():
    print("Exiting the program. Thank you!")
    return

def main():
    global record
    print("What you want to do?\n"
      "1. Withdraw.\n"
      "2. Deposite.\n"
      "3. Show Balance.\n"
      "4. Show transaction history.\n"
      "5. EXIT.\n"
      "Enter no. 1-5 to choose:- ",end='')

    while True:
        choice=int(input())
        if choice==1:
            Withdraw()
            break
        elif choice==2:
            Deposit()
            break
        elif choice==3:
            showBalance()
            break
        elif choice==4:
            showRecord()
            break
        elif choice==5:
            EXIT()
            break
        else:
            print("Wrong input\nEnter again ",end='')

record=[]

if __name__ == "__main__":

    if len(record)==0:
        log=('D',1000)
        record.append(log)
    main()
