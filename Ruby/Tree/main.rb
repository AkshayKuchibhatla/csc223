require_relative 'Tree'

tree = BinarySearchTree.new

tree.insert(100)
tree.insert(50)
tree.insert(150)
tree.insert(50)
tree.insert(125)
tree.insert(175)
tree.insert(25)
tree.insert(75)
tree.inorder(tree.rootNode)
