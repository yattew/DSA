class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

    def __repr__(self):
        return f"node<{str(self.data)}>"

    def __str__(self):
        return str(self.data)


class LinkedList:
    def __init__(self):
        self.head = None
    def append(self, data):
        if self.head:
            itr = self.head
            while itr.next:
                itr = itr.next
            itr.next = Node(data)
            return
        self.head = Node(data)

    def insert(self, idx, data):
        if idx < 0:
            raise IndexError("the index cannot be negative")
        if not self.head and idx > 0:
            raise IndexError("index is out of range")
        if not self.head:
            self.head = Node(data)
            return
        itr = self.head
        try:
            while idx > 1:
                idx -= 1
                itr = itr.next
        except:
            raise IndexError("index is out of range")
        itr_temp = itr.next
        itr.next = Node(data)
        itr.next.next = itr_temp
    def __repr__(self):
        res = ""
        itr = self.head
        while itr:
            res += str(itr) + "->"
            itr = itr.next
        res += str(Node(None))
        return res
    def __len__(self):
        l = 0
        itr = self.head
        while itr:
            l+=1
            itr = itr.next
        return l


l = LinkedList()
l.insert(0, 1)
l.insert(1,2)
l.insert(1,3)
l.insert(3,4)
l.insert(2,100)
print(l)
print(len(l))
# for i in range(1,11):
#     l.append(i)
# print (l)
# l.insert(-1,1)
