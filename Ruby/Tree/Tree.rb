class BinarySearchTree
  attr_accessor :rootNode

  def initialize
    @rootNode = nil
  end

  # Outside function for insertion of node
  def insert(insValue)
    @rootNode = insertInNode(insValue, @rootNode)
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

  def inorder(root)
    if root == nil
      return nil
    end

    inorder(root.children[0])
    printf("%d ", root.cargo)
    inorder(root.children[1])
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

  def left()
    if @children.length > 0
      return children[0]
    else
      return nil
    end
  end

  def right()
    if @children.length() > 1
      return children[1]
    else
      return nil
    end
  end

  def setLeft(number)
    if @children.length() > 0
      return nil
    end
    puts("setting left")
    @children << number
  end

  def setRight(number)
    puts("setting right")
    if @children.length() > 1
      return nil
    end
    puts("setting right")
    @children << number
  end

end