class Queue
  def initialize
    @queue = []
  end

  def enqueue(item)
    @queue.push(item)
  end

  def dequeue
    return "Queue is empty." if @queue.empty?
    @queue.shift
  end

  def display
    return "Queue is empty." if @queue.empty?
    @queue
  end

  def contains?(item)
    @queue.include?(item)
  end
end

def menu
  q = Queue.new
  loop do
    puts "\nQueue Menu:"
    puts "1. Enqueue"
    puts "2. Dequeue"
    puts "3. Display Queue"
    puts "4. Check if Number Exists"
    puts "5. Exit"
    print "Enter choice: "
    choice = gets.chomp.to_i

    case choice
    when 1
      print "Enter number to enqueue: "
      num = gets.chomp.to_i
      q.enqueue(num)
    when 2
      puts "Dequeued: #{q.dequeue}"
    when 3
      puts "Queue: #{q.display}"
    when 4
      print "Enter number to check: "
      num = gets.chomp.to_i
      puts q.contains?(num) ? "Exists" : "Does not exist"
    when 5
      break
    else
      puts "Invalid choice, try again."
    end
  end
end

menu
