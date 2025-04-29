class BinarySearchTree
  attr_accessor :rootNode

  def initialize(rootVal)
    @rootNode = BinaryNode.new(rootVal)
  end

  def insert(val, node)
    if val < node.cargo

    end
  end
end

class BinaryNode
  attr_accessor :children, :cargo
  
  def initialize(value)
    @children = []
    @cargo = value
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