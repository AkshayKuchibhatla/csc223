require_relative 'Tree'

tree = BinarySearchTree.new(10)

puts(tree.rootNode.left() == nil)
puts(tree.rootNode.right() == nil)
puts(tree.rootNode.to_s() == "10")
tree.rootNode.setLeft(3)
tree.rootNode.setRight(15)
puts(tree.rootNode.children.to_s)