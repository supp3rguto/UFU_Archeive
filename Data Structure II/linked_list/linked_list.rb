class Node
  attr_accessor :data, :next

  def initialize(data)
    @data = data
    @next = nil
  end
end

class LinkedList
  def initialize
    @head = nil
  end

  def insert(data)
    new_node = Node.new(data)
    if @head.nil?
      @head = new_node
    else
      temp = @head
      temp = temp.next while temp.next
      temp.next = new_node
    end
  end

  def remove(data)
    return "List is empty." if @head.nil?

    if @head.data == data
      @head = @head.next
      return "Removed #{data}"
    end

    temp = @head
    while temp.next && temp.next.data != data
      temp = temp.next
    end

    if temp.next
      temp.next = temp.next.next
      return "Removed #{data}"
    end
    "Number not found."
  end

  def display
    return "List is empty." if @head.nil?

    elements = []
    temp = @head
    while temp
      elements << temp.data
      temp = temp.next
    end
    elements
  end

  def contains?(data)
    temp = @head
    while temp
      return true if temp.data == data
      temp = temp.next
    end
    false
  end
end

def menu
  ll = LinkedList.new
  loop do
    puts "\nLinked List Menu:"
    puts "1. Insert"
    puts "2. Remove"
    puts "3. Display List"
    puts "4. Check if Number Exists"
    puts "5. Exit"
    print "Enter choice: "
    choice = gets.chomp.to_i

    case choice
    when 1
      print "Enter number to insert: "
      num = gets.chomp.to_i
      ll.insert(num)
    when 2
      print "Enter number to remove: "
      num = gets.chomp.to_i
      puts ll.remove(num)
    when 3
      puts "List: #{ll.display}"
    when 4
      print "Enter number to check: "
      num = gets.chomp.to_i
      puts ll.contains?(num) ? "Exists" : "Does not exist"
    when 5
      break
    else
      puts "Invalid choice, try again."
    end
  end
end

menu
