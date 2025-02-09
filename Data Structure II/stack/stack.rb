class Stack
  def initialize
    @stack = []
  end

  def push(item)
    @stack.push(item)
  end

  def pop
    return "Stack is empty." if @stack.empty?
    @stack.pop
  end

  def display
    return "Stack is empty." if @stack.empty?
    @stack
  end

  def contains?(item)
    @stack.include?(item)
  end
end

def menu
  s = Stack.new
  loop do
    puts "\nStack Menu:"
    puts "1. Push"
    puts "2. Pop"
    puts "3. Display Stack"
    puts "4. Check if Number Exists"
    puts "5. Exit"
    print "Enter choice: "
    choice = gets.chomp.to_i

    case choice
    when 1
      print "Enter number to push: "
      num = gets.chomp.to_i
      s.push(num)
    when 2
      puts "Popped: #{s.pop}"
    when 3
      puts "Stack: #{s.display}"
    when 4
      print "Enter number to check: "
      num = gets.chomp.to_i
      puts s.contains?(num) ? "Exists" : "Does not exist"
    when 5
      break
    else
      puts "Invalid choice, try again."
    end
  end
end

menu
