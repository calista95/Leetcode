#Date: 4/8/2019
#Important thing to note: need to have the criteria "if indexM >=0" in the if statement 



def merge(nums1, m, nums2, n):
    
    print(nums1)
    print(nums2)
    
    size = m+n-1
    indexM = m-1
    indexN = n-1
    while indexN >=0:
        if indexM >=0 and nums1[indexM] >= nums2[indexN]: #first array has larger number 
            print("nums1 bigger")
            nums1[size] = nums1[indexM]
            indexM-=1
  
        else:
            print("nums2 bigger")
            nums1[size] = nums2[indexN]
            indexN-=1
        size-=1
        print(nums1)
    

nums1=[None]*6
nums2=[None]*3
for x in range(3):
    nums1[x] = x+3
    nums2[x] = x+1
merge(nums1,3,nums2,3)

