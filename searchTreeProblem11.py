import sys

class Node(object):
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
class Tree(object):
    def __init__(self):
        self.root = None

def insert(node, data):
    if node is None:
        return Node(data)
    if data < node.key:
        node.left = insert(node.left, data)
    elif data > node.key:
        node.right = insert(node.right, data)
    return node
def preOrderTraversal(node, out):
    if node is None:
        return
    out.write(str(node.key) + '\n')
    preOrderTraversal(node.left, out)
    preOrderTraversal(node.right, out)
def deleteRecursively(node, data):
    if node is None:
        return None

    if data < node.key:
        node.left = deleteRecursively(node.left, data)
        return node
    elif data > node.key:
        node.right = deleteRecursively(node.right, data)
        return node
    if node.left is None:
        return node.right
    elif node.right is None:
        return node.left
    else:
        minKey = findMin(node.right).key
        node.key = minKey
        node.right = deleteRecursively(node.right, minKey)
        return node
def findMin(node):
    if node.left is not None:
        return findMin(node.left)
    else:
        return node

# Solution task
nodeMaxHeight = 0
rootDeleted = False
root = 0
def height(node):
    if node is None or node.left is None and node.right is None:
        return 0
    else:
        return max(height(node.left), height(node.right)) + 1
def msl(node):
    if node is None or node.left is None and node.right is None:
        return 0
    h = height(node.left) + height(node.right)
    if node.left is None or node.right is None:
        return h + 1
    else:
        return h + 2
def postOrderTraversal(node):
    if node is None:
        return
    postOrderTraversal(node.left)
    postOrderTraversal(node.right)
    global nodeMaxHeight
    m = msl(node)
    if nodeMaxHeight < m:
        nodeMaxHeight = m
def inOrderTraversal(node):
    if node is None:
        return
    inOrderTraversal(node.left)
    global nodeMaxHeight
    global rootDeleted
    global root
    if rootDeleted is False:
        if msl(node) == nodeMaxHeight:
            rootDeleted = True
            root = node.key
    inOrderTraversal(node.right)

tree = Tree()
f = open("in.txt","r")
out = open("out.txt","w")
sys.setrecursionlimit(2000)
for data in f:
    tree.root = insert(tree.root, int(data))
postOrderTraversal(tree.root)
inOrderTraversal(tree.root)
tree.root = deleteRecursively(tree.root, root)
preOrderTraversal(tree.root, out)
f.close()
out.close()
