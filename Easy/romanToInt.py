
#Title: Roman to Int
#Date: 4/5/2019

rome = {"I":1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000}

def getInt(s):
    stack=[]
    sum=0
    for char in s:
        if len(stack) ==0:
            stack.append(char)
            sum+=rome[char]
        else:
            if rome[stack[-1]] >= rome[char]:
                sum+=rome[char] 
            else:
                sum-=rome[stack[-1]] 
                sum+=rome[char] - rome[stack[-1]]
            stack.append(char)

    return sum

 


def main():
    s='MCMXCIV'
    print(str(getInt(s)))

if __name__ == "__main__":
    main()