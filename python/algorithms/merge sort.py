def merge_sort(arr):
    if len(arr)>1:
        mid = len(arr)//2
        l = arr[:mid]
        r = arr[mid:]
        merge_sort(l)
        merge_sort(r)
        i,j,k = 0,0,0
        while i < len(l) and j<len(r):
            if l[i]<r[j]:
                arr[k] = l[i]
                i+=1
            else:
                arr[k] = r[j]
                j+=1
            k+=1
        while i<len(l):
            arr[k] = l[i]
            k+=1
            i+=1
        while j<len(r):
            arr[k] = r[j]
            k+=1
            j+=1
arr = [5,2,4,6,1,3]
merge_sort(arr)
print(arr)