/*
Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
1 2 3 4 5 6 7
4 5

Output:
2
*/
from collections import deque

# Node definition
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

# Build tree from level order
def buildTree(level_order):
    if not level_order or level_order[0] == -1:
        return None
    
    root = Node(level_order[0])
    q = deque([root])
    i = 1
    
    while q and i < len(level_order):
        curr = q.popleft()
        
        # Left child
        if level_order[i] != -1:
            curr.left = Node(level_order[i])
            q.append(curr.left)
        i += 1
        
        if i >= len(level_order): break
        
        # Right child
        if level_order[i] != -1:
            curr.right = Node(level_order[i])
            q.append(curr.right)
        i += 1
    
    return root

# LCA function
def findLCA(root, n1, n2):
    if root is None:
        return None
    if root.val == n1 or root.val == n2:
        return root
    
    left = findLCA(root.left, n1, n2)
    right = findLCA(root.right, n1, n2)
    
    if left and right:
        return root
    return left if left else right

# Driver
N = int(input().strip())
level_order = list(map(int, input().split()))
n1, n2 = map(int, input().split())

root = buildTree(level_order)
lca = findLCA(root, n1, n2)
print(lca.val if lca else -1)
