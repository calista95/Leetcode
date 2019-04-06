#Date: 4/5/2019

def lengthOfLastWord(s):
    if len(s) ==0:
        return 0
    else:
        count=0
        flag=False #assume that we have not yet seen the start of the last word yet   
        for x in reversed(range(len(s))):
            #print(x)
            if s[x] != " ":
                count+=1
                flag=True
            if s[x] == " " and flag==True:
                break
                
        return count
        
def lengthOfLastWord2(s):
    if not(not s or s.isspace()):
            words = s.split() 
            return len(words[-1])
    else: 
        return 0


print(lengthOfLastWord("a  "))