data Tree a
  = Empty
  | Node (Tree a) a (Tree a)
  deriving (Show, Read, Eq)

treeInsert :: (Ord a) => a -> Tree a -> Tree a
treeInsert x Empty = Node Empty x Empty
treeInsert x (Node l v r)
  | x == v = Node l v r
  | x < v = Node (treeInsert x l) v r
  | x > v = Node l v (treeInsert x r)
  | otherwise = undefined

treeElem :: (Ord a) => a -> Tree a -> Bool
treeElem x Empty = False
treeElem x (Node l v r)
  | x == v = True
  | x < v = treeElem x l
  | x > v = treeElem x r
  | otherwise = undefined

treeInorder :: Tree a -> [a]
treeInorder Empty = []
treeInorder (Node l v r) = treeInorder l ++ [v] ++ treeInorder r