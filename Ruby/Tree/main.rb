require_relative 'Tree'

def print_tree(node, left_accessor: nil, right_accessor: nil, value_accessor: nil, prefix: "", is_left: true)
  return if node.nil?

  left_accessor  ||= -> (n) { n.left }
  right_accessor ||= -> (n) { n.right }
  value_accessor ||= -> (n) { n.to_s }

  right_child = right_accessor.call(node)
  left_child  = left_accessor.call(node)
  
  print_tree(right_child, left_accessor: left_accessor, right_accessor: right_accessor,
             value_accessor: value_accessor,
             prefix: prefix + (is_left ? "│   " : "    "), is_left: false)

  puts prefix + (is_left ? "└── " : "┌── ") + value_accessor.call(node)

  print_tree(left_child, left_accessor: left_accessor, right_accessor: right_accessor,
             value_accessor: value_accessor,
             prefix: prefix + (is_left ? "    " : "│   "), is_left: true)
end

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
tree.insert(800)
tree.insert(801)
tree.insert(802)
tree.insert(803)
puts(tree.height)

puts
items = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
itemsPreorder = [8,4,2,1,3,6,5,7,12,10,9,11,14,13,15]
itemsPostorder = [1,3,2,5,7,6,4,9,11,10,13,15,14,12,8]

tree2 = BinarySearchTree.new

for i in 0..items.length - 1
  tree2.insert(items[i])
end

puts(tree2.pre_order_traversal == itemsPreorder)
puts(tree2.post_order_traversal == itemsPostorder)
puts
print("items: ")
puts(items.to_s)
puts("AVL tree:")

print_tree(
  tree2.rootNode,
  left_accessor: -> (n) { n.children[0] },
  right_accessor: -> (n) { n.children[1] },
  value_accessor: -> (n) { n.to_s }
)
