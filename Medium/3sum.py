#Date: 4/3/2019
#Description: 3sum

from itertools import permutations 

def isDup(sol, temp): #solution set and the set that is potentially added 
    perm = permutations(temp)
    tempArr=[]
    for i in perm:
        tempArr.append(list(i))
    for x in tempArr:
        for y in sol:
            if x == y:
                return True
    return False

def exists(nums, sum):
    count=0
    for x in nums:
        if x == sum:
            count+=1
    if count > 1:
        return True
    else:
        return False


def threesum(nums):
    sol = []

    for x in range(len(nums)):
        for y in range(len(nums)):
            if (x != y):
                sum = -1 * (nums[x] + nums[y]) #get the reciprocal of the sum 
                if sum in nums and exists(nums, sum) is True:
                    #print(iter)
                    temp=[]
                    temp.append(nums[x])
                    temp.append(nums[y])
                    temp.append(sum)
                    if isDup(sol, temp) is False:
                        sol.append(temp)
    return sol   


def main():
    nums = [-1, 0, 1, 2, -1, -4]
    print(threesum(nums))


if __name__ == "__main__":
    main()


