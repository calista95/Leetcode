    #Date: 4/5/2019
    
    def strStr(haystack, needle):
        if needle in haystack:
            return haystack.find(needle)
            
        else:
            return -1
    


    haystack = "aaaaaabcd"
    needle = "bcd"
    print(str(strStr(haystack,needle)))