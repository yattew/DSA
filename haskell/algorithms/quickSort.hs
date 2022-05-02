quickSort :: Ord a => [a] -> [a]
quickSort [] = []
quickSort (x : xs) = l ++ [x] ++ r
  where
    l = quickSort $ filter (< x) xs
    r = quickSort $ filter (>= x) xs