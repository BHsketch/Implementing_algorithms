def quicksort(nums):
    pivot=[]
    #pivot.append(nums.pop(0))
    lesser=[]
    greater=[]
    i=0
    if len(nums) < 2:
        result=nums
    elif len(nums) >= 2:
        pivot.append(nums.pop(0))
        for x in nums:
            if x < pivot[0]:
                lesser.append(x)
            elif x >= pivot[0]:
                greater.append(x)
        #print("lesser array for this iteration: ", lesser)
        #print("greater array for this iteration: ", greater)

        result=  quicksort(lesser) + pivot + quicksort(greater)
    
    return result

n=int(input("enter the number of elements in the list to be sorted: "))
nums1=[]
print("Enter the elements of the list: ")
for j in range(n):
    nums1.append(int(input()))
    #print(nums[j])

print("This list before sorting is:", nums1)
print("This list after sorting is:", quicksort(nums1))
