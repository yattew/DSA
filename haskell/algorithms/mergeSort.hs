merge :: Ord a => [a] -> [a] -> [a]
merge [] xs = xs
merge xs [] = xs
merge (x1 : xs1) (x2 : xs2)
  | x1 < x2 = x1 : merge xs1 (x2 : xs2)
  | otherwise = x2 : merge xs2 (x1 : xs1)

mergeSort :: Ord a => [a] -> [a]
mergeSort [] = []
mergeSort [x] = [x]
mergeSort xs = merge l r
  where
    lr = splitAt (length xs `div` 2) xs
    l = mergeSort $ fst lr
    r = mergeSort $ snd lr

main :: IO ()
main = do
  let a = [1,2,0,5]
      b = mergeSort a
  print b
