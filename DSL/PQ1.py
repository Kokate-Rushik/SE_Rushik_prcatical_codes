def common(L1, L2):
    return [x for x in L1 if x in L2]

def either(L1, L2):
    return [x for x in (L1+L2) if (x in L1 or x in L2) and x not in common(L1,L2)]

def neither(L1, L2, allstudent):
    return [x for x in allstudent if x not in (L1+L2)]

def exceptbadmi(Clist, Flist, Blist):
    cir_n_foot = common(Clist, Flist)
    return [x for x in cir_n_foot if x not in Blist]

cir = ["Alice", "Bob", "Charlie", "David"]
foot = ["Bob", "Eve", "Frank"]
badmi = ["Charlie", "George", "Alice"]

allstudent = list(set(cir+foot+badmi))

Q1 = common(cir, badmi)
Q2 = either(cir, badmi)
Q3 = neither(cir, badmi, allstudent)
Q4 = exceptbadmi(cir, foot, badmi)

print("Circket list:- ", cir)
print("Football list:- ", foot)
print("Badminton list:- ", badmi)

print("\nStudents who play both cricket and badminton:- ")
print(Q1)
print("\nStudents who play either cricket or badminton but not both:- ")
print(Q2)
print("\nNumber of students who play neither cricket nor badminton:- ")
print(Q3)
print("\nNumber of students who play cricket and football but not badminton:- ")
print(Q4)
