bSearchHelper :: [Int] -> Int -> Int -> Int -> Int
bSearchHelper ls x low high
    | low > high = -1
    | otherwise = 
        if el == x 
                then mid
            else 
                if el > x 
                    then bSearchHelper ls x low $ mid - 1
                    else bSearchHelper ls x (mid + 1) high
        where 
            mid = low + (high - low) `div` 2
            el = ls !! mid

binarySearch :: [Int] -> Int->Int
binarySearch ls el = bSearchHelper ls el 0 (length ls -1)   


