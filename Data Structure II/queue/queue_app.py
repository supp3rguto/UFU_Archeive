class Queue:
    def __init__(self):
        self.queue = []

    def enqueue(self, item):
        self.queue.append(item)

    def dequeue(self):
        if not self.is_empty():
            return self.queue.pop(0)
        return "Queue is empty."

    def is_empty(self):
        return len(self.queue) == 0

    def display(self):
        return self.queue if not self.is_empty() else "Queue is empty."

    def contains(self, item):
        return item in self.queue

def menu():
    q = Queue()
    while True:
        print("\nQueue Menu:")
        print("1. Enqueue")
        print("2. Dequeue")
        print("3. Display Queue")
        print("4. Check if Number Exists")
        print("5. Exit")
        choice = input("Enter choice: ")

        if choice == "1":
            num = int(input("Enter number to enqueue: "))
            q.enqueue(num)
        elif choice == "2":
            print("Dequeued:", q.dequeue())
        elif choice == "3":
            print("Queue:", q.display())
        elif choice == "4":
            num = int(input("Enter number to check: "))
            print("Exists:" if q.contains(num) else "Does not exist")
        elif choice == "5":
            break
        else:
            print("Invalid choice, try again.")

if __name__ == "__main__":
    menu()
