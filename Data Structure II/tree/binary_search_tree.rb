class Node
  attr_accessor :data, :left, :right

  def initialize(data)
    @data = data
    @left = @right = nil
  end
end

class BST
  def initialize
    @root = nil
  end

  def insert(data)
    @root = insert_node(@root, data)
  end

  def insert_node(node, data)
    return Node.new(data) if node.nil?

    if data < node.data
      node.left = insert_node(node.left, data)
    else
      node.right = insert_node(node.right, data)
    end
    node
  end

  def traverse(order)
    case order
    when 'pre'
      pre_order(@root)
    when 'post'
      post_order(@root)
    else
      in_order(@root)
    end
    puts
  end

  private

  def in_order(node)
    return if node.nil?

    in_order(node.left)
    print "#{node.data} "
    in_order(node.right)
  end

  def pre_order(node)
    return if node.nil?

    print "#{node.data} "
    pre_order(node.left)
    pre_order(node.right)
  end

  def post_order(node)
    return if node.nil?

    post_order(node.left)
    post_order(node.right)
    print "#{node.data} "
  end
end
