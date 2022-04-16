-- minimum of two elements
min_ab a b
    | a > b = b
    | b > a = a
    | otherwise = a

-- min element of a list
minim [] = 0
minim [x] = x
minim (x:xs) = min_ab x (minim xs)

-- delete element e from list
delete_list e (x:xs)
    | e == x = xs
    | otherwise = x : delete_list e xs

-- sorted (selection sort)
sorted [] = []
sorted [x] = [x]
sorted xs = 
    let x = minim xs
    in x : sorted (delete_list x xs)

main =
    let arr = [10, 5, 7, 15, 10, 19, 3, 3]
    in do
        putStr "the array :"
        print arr
        putStr "sorted array: "
        print (sorted arr)