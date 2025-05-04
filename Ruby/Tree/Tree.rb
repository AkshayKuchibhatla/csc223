class BinarySearchTree
  attr_accessor :rootNode

  def initialize
    @rootNode = nil
  end

  # Outside function for insertion of node
  def insert(insValue)
    @rootNode = insertInNode(insValue, @rootNode)
  end

  # Outside function for deletion of node
  def delete(delValue)
    @rootNode = deleteFromNode(delValue, @rootNode)
  end

  # Outside function for inorder traversal
  def in_order_traversal
    inorderList = []
    inorder(@rootNode, inorderList)
    return inorderList
  end

  # Outside function for preorder traversal
  def pre_order_traversal
    preorderList = []
    preorder(@rootNode, preorderList)
    return preorderList
  end

  # Outside function for postorder traversal
  def post_order_traversal
    postorderList = []
    postorder(@rootNode, postorderList)
    return postorderList
  end

  def min
    tempNode = @rootNode
    while (tempNode != nil and tempNode.children[0] != nil)
      tempNode = tempNode.children[0]
    end
    return tempNode.cargo
  end

  def max
    tempNode = @rootNode
    while (tempNode != nil and tempNode.children[1] != nil)
      tempNode = tempNode.children[1]
    end
    return tempNode.cargo
  end

  def height
    return heightFromNode(@rootNode)
  end

  def empty
    return @rootNode == nil
  end

  private

  def heightFromNode(node)
    if node == nil
      return -1
    end

    leftHeight = heightFromNode(node.children[0])
    rightHeight = heightFromNode(node.children[1])

    if (leftHeight >= rightHeight)
      return leftHeight + 1
    else
      return rightHeight + 1
    end
  end

  # Helper function with inorder traversal
  def inorder(root, arr)
    if root == nil
      return nil
    end

    inorder(root.children[0], arr)
    arr.append(root.cargo)
    inorder(root.children[1], arr)
  end

  def preorder(root, arr)
    if root == nil
      return nil
    end

    arr.append(root.cargo)
    preorder(root.children[0], arr)
    preorder(root.children[1], arr)
  end

  def postorder(root, arr)
    if root == nil
      return nil
    end

    postorder(root.children[0], arr)
    postorder(root.children[1], arr)
    arr.append(root.cargo)
  end

  # Helper function for insertion of node
  def insertInNode(val, node)
    if node == nil
      return BinaryNode.new(val)
    end
    
    # If val is greater, insert on the right (second
    # in the children array)
    if node.cargo < val
      node.children[1] = insertInNode(val, node.children[1])
    end

    # If val is less, insert on the left (first
    # in the children array)
    if node.cargo > val
      node.children[0] = insertInNode(val, node.children[0])
    end

    return node
  end

  # Helper function for deletion of node (recursive)
  def deleteFromNode(x, node) 
    if node == nil
      return node
    end

    if node.cargo > x
      node.children[0] = deleteFromNode(x, node.children[0])
    elsif node.cargo < x
      node.children[1] = deleteFromNode(x, node.children[1])
    else
      if node.children[0] == nil
        node = node.children[1]
        return node
      end

      if node.children[1] == nil
        node = node.children[0]
        return node
      end

      successor = getInorderSuccessor(node)
      node.cargo = successor.cargo
      node.children[1] = deleteFromNode(successor.cargo, node.children[1])
    end
    return node
  end

  # Helper function for node deletion
  def getInorderSuccessor(currNode)
    currNode = currNode.children[1]
    while (currNode != nil and currNode.children[0] != nil)
      currNode = currNode.children[0]
    end
    return currNode
  end
end

class BinaryNode
  attr_accessor :children, :cargo
  
  def initialize(value)
    @children = []
    @cargo = value
    @children.append(nil, nil)
  end
  
  def to_s
    @cargo.to_s
  end
end