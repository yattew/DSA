#insertion sort
#incase the comparisons are expensive, do binary search for finding where 
#to insert in the left sorted part of the array
arr = [5,2,4,6,1,3]

def insertion_sort(arr):
    if len(arr)<=1:
        return 
    key = 1
    while key<len(arr):
        pointer = key
        while pointer!=0 and arr[pointer]<arr[pointer-1]:
            temp = arr[pointer-1]
            arr[pointer-1] = arr[pointer]
            arr[pointer] = temp
            pointer-=1
        key+=1
# insertion_sort(arr)
# print(arr)
    


