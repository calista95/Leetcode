#Description: remove element 
#Date: 4/5/2019

def remove(nums, val):
    temp=[]
    for x in nums:
        if x != val:
            temp.append(x)
    nums.clear()
    for x in temp:
        nums.append(x)

def remove2(nums, val):
    while(val in nums):
        nums.remove(val)
    print(nums)


def main():
    nums = [0,1,2,2,3,0,4,2]
    remove2(nums,2)

if __name__ == "__main__":
    main()