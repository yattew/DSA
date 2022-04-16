data LList
  = Null
  | Node Int LList
  deriving (Show)

-- nodeVal (Node x _) = x
-- nextList (Node _ ll) = ll

appendLList :: LList -> Int -> LList
appendLList Null x = Node x Null
appendLList (Node val ll) x = Node val (appendLList ll x)

popLList :: LList -> LList
popLList Null = Null
popLList (Node _ Null) = Null
popLList (Node x ll) = Node x $ popLList ll


printLList :: LList -> IO ()
printLList Null = putStrLn "null"
printLList (Node val ll) = do
    putStr (show val ++ "->")
    printLList ll

makeLList :: Int -> Int -> LList
makeLList n m 
    | n == m = Null
    | otherwise = Node  n $ makeLList (n+1) m

main = print 10