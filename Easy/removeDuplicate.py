#Date: 4/3/2019
#Description: Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

def removeDup(arr):
        prev = ''
        curr = ''
        temp=[]
        for x in arr:
                prev = curr
                curr = x
                if (prev != curr):
                        temp.append(curr)

        arr.clear() # <------------pay attention, important for passing by value 
        for x in temp:
                arr.append(x)





def main():
    array = [0,0,0,1,1,1,1,2,2,2,2,2,3,3]
    removeDup(array)
    print(array)

if __name__ == "__main__":
    main()