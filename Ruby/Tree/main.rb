require_relative 'Tree'

tree = BinarySearchTree.new

puts(tree.empty)

tree.insert(100)
puts(tree.empty)
puts
tree.insert(50)
tree.insert(150)
tree.insert(50)
tree.insert(125)
tree.insert(175)
tree.insert(25)
tree.insert(75)
print("inorder:  ")
puts(tree.in_order_traversal.to_s)
print("preorder:  ")
puts(tree.pre_order_traversal.to_s)
print("postorder:  ")
puts(tree.post_order_traversal.to_s)

puts
tree.delete(175)
print("inorder:  ")
puts(tree.in_order_traversal.to_s)
print("preorder:  ")
puts(tree.pre_order_traversal.to_s)
print("postorder:  ")
puts(tree.post_order_traversal.to_s)

puts
tree.delete(100)
print("inorder:  ")
puts(tree.in_order_traversal.to_s)
print("preorder:  ")
puts(tree.pre_order_traversal.to_s)
print("postorder:  ")
puts(tree.post_order_traversal.to_s)

puts(tree.min)
tree.delete(25)
puts(tree.min)

puts
puts(tree.max)
tree.delete(150)
puts(tree.max)

puts
puts(tree.height)
tree.insert(80)
puts(tree.height)