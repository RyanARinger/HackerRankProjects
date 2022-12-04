class Node:
    def __init__(self, info):
        self.info = info  
        self.left = None  
        self.right = None 
        self.level = None 

    def __str__(self):
        return str(self.info) 

def preOrder(root):
    if root == None:
        return
    print (root.info, end=" ")
    preOrder(root.left)
    preOrder(root.right)
    
class BinarySearchTree:
    def __init__(self): 
        self.root = None

#Node is defined as
#self.left (the left child of the node)
#self.right (the right child of the node)
#self.info (the value of the node)

    def insert(self, val):
        #Enter you code here.
        node = Node(val)
        
        if self.root is None:
            self.root = node
            return self.root
        else:
            current = self.root
            while True:
                if node.info < current.info:
                    if current.left is None:
                        current.left = node
                        return self.root
                    current = current.left
                else:
                    if current.right is None:
                        current.right = node
                        return self.root
                    current = current.right
            
            
            
            
            

tree = BinarySearchTree()