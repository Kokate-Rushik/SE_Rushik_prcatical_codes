#code by Kokate Rushik

def custom_split(string, delimit=' '):
    result=[]
    word=""
    for char in string:
        if char==delimit:
            if word:
                result.append(word)
                word=""
        else:
            word+=char
    if word:
        result.append(word)
    return result

def remove_spaces(string):
    result=''
    for char in string:
        if char!=' ':
            result+=char
        else:
            continue
    return result

def longest_word(string):
    str1=custom_split(string)
    check=0
    longword=''
    for word in str1:
        if len(word)>check:
            longword=word
        else:
            continue
    return longword

def word_count(word, string):
    str1=custom_split(string)
    count=0
    for i in str1:
        if i.lower()==word.lower():
            count+=1
    return count

def checkPalin(string):
    str1= remove_spaces(string.lower())
    str2= str1[::-1]
    if str1==str2:
        return True
    else:
        return False

def searchWord(word,string):
    str1=custom_split(string)
    index=-1
    for i in str1:
        if i.lower()!=word.lower():
            index+=len(i)
            index+=1
        else:
            index+=1
            break
    return index

def words_count(string):
    str1=custom_split(string)
    frequency={}
    for word in str1:
        if word in frequency:
            frequency[word]+=1
        else:
            frequency[word]=1

    return frequency

def main():
    s1="One one one one two two two three three four"
    s2="Level"
    print("Longest word in string'",s1,"' is",longest_word(s1))
    print("Frequency of word 'one' in '",s1,"' is",word_count('one',s1))
    print("If given string '",s2,"' is Palindrome:- ",checkPalin(s2))
    print("The word 'three' is at",searchWord('three',s1))
    print("Occurrence of each word in the string '", s1,"' is:-\n",words_count(s1))


if __name__=="__main__":
    main()
