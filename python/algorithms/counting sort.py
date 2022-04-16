def counting_sort(arr):
    arr_map = [None for _ in range(max(arr)+1)]
    for i in arr:
        if arr_map[i] == None:
            arr_map[i] = 1
            continue
        arr_map[i]+=1
    arr = []
    for i,j in enumerate(arr_map):
        if j !=None:
            arr.extend([i]*j)
    return arr
arr = [1,4,5,9,4,5,10,8,8,11,23,45,12,0,0,0]
print(counting_sort(arr))
    