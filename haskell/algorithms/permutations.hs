
-- combine an element with the permutations of all other elements
combinePerms :: a -> [[a]] -> [[a]]
combinePerms y [] = []
combinePerms y [x] = [y : x]
combinePerms y (x : xs) = (y : x) : combinePerms y xs


-- returns a list of all possible permutations of the given list
getPerms :: Eq a => [a] -> [[a]]
getPerms [] = []
getPerms [x] = [[x]]
getPerms xs =
  foldl
    ( \acc x ->
        --filter -> make a list of all elements except x
        --send it to getPerms recursively
        --call combinePerms with the current element x and the result of getPerms
        --finally add it to the accumulator acc
        acc ++ combinePerms x (getPerms $ filter (/= x) xs)
    )
    []
    xs