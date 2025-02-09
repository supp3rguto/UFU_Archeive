class Stack:
    def __init__(self):
        self.stack = []

    def push(self, item):
        self.stack.append(item)

    def pop(self):
        if not self.is_empty():
            return self.stack.pop()
        return "Stack is empty."

    def is_empty(self):
        return len(self.stack) == 0

    def display(self):
        return self.stack if not self.is_empty() else "Stack is empty."

    def contains(self, item):
        return item in self.stack

def menu():
    s = Stack()
    while True:
        print("\nStack Menu:")
        print("1. Push")
        print("2. Pop")
        print("3. Display Stack")
        print("4. Check if Number Exists")
        print("5. Exit")
        choice = input("Enter choice: ")

        if choice == "1":
            num = int(input("Enter number to push: "))
            s.push(num)
        elif choice == "2":
            print("Popped:", s.pop())
        elif choice == "3":
            print("Stack:", s.display())
        elif choice == "4":
            num = int(input("Enter number to check: "))
            print("Exists" if s.contains(num) else "Does not exist")
        elif choice == "5":
            break
        else:
            print("Invalid choice, try again.")

if __name__ == "__main__":
    menu()
