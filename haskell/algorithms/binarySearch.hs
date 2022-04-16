bSearchHelper :: [Int] -> Int -> Int -> Int -> Int
bSearchHelper ls x low high
  | low > high = -1
  | el == x = mid
  | el > x = bSearchHelper ls x low (mid -1)
  | el < x = bSearchHelper ls x (mid + 1) high
  | otherwise = -1
  where
    mid = low + (high - low) `div` 2
    el = ls !! mid

binarySearch :: [Int] -> Int -> Int
binarySearch ls el = bSearchHelper ls el 0 (length ls - 1)
