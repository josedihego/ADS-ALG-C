import random

class Node:
    def __init__(self, key):
        self.key =  key
        self.next = None
        self.prev = None
    def __str__(self) -> str:
        return "Key: "+ self.key;

class List:
    def __init__(self):
        self.tail = None
        self.head = None
    def add(self,x):
        if(self.head == None):
            self.head = x
            self.tail = x
        else:
            x.next = self.head
            self.head.prev = x
            self.head = x
    def delete(self, x):
        if(x.prev != None):
            x.prev.next = x.next
        else:
            self.head = x.next
        if(x.next != None):
            x.next.prev = x.prev
        else:
            self.tail =  x.prev
    def search(self, key):
        x = self.head
        while(x != None and x.key != key):
            x = x.next
        return x
    def print(self):
        x = self.head
        while(x!=None):
            print(x)
            x = x.next

def generateString(size):
    letters = 'abcdefghijklmnopqrstuvwxyz'
    ret = ''
    for i in range(size):
        n = random.randint(0,25)
        ret = ret + letters[n]
    return ret[0].upper()+ret[1:]

turma  = List()
for i in range(10):
    a = Node(generateString(5))
    turma.add(a)
turma.print()
