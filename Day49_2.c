/*
Insert into BST
*/
class Node:
   def __init__(self, key):
       self.key = key
       self.left = None
       self.right = None
def insert(node, key):
   # If the tree is empty, return a new node
   if node is None:
       return Node(key)
   # Otherwise, recur down the tree
   if key < node.key:
       node.left = insert(node.left, key)
   elif key > node.key:
       node.right = insert(node.right, key)
   # Return the (unchanged) node pointer
   return node
# Utility function to do inorder tree traversal
def inorder(root):
   if root:
       inorder(root.left)
       print(root.key, end=" ")
       inorder(root.right)
# Driver code
root = Node(50)
root = insert(root, 30)
root = insert(root, 20)
root = insert(root, 40)
root = insert(root, 70)
root = insert(root, 60)
root = insert(root, 80)
# Print inorder traversal of the BST
inorder(root)
