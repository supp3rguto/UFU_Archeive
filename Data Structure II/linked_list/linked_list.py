class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def insert(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
        else:
            temp = self.head
            while temp.next:
                temp = temp.next
            temp.next = new_node

    def remove(self, data):
        temp = self.head
        if not temp:
            return "List is empty."
        
        if temp.data == data:
            self.head = temp.next
            return f"Removed {data}"

        while temp.next and temp.next.data != data:
            temp = temp.next

        if temp.next:
            temp.next = temp.next.next
            return f"Removed {data}"
        return "Number not found."

    def display(self):
        elements = []
        temp = self.head
        while temp:
            elements.append(temp.data)
            temp = temp.next
        return elements if elements else "List is empty."

    def contains(self, data):
        temp = self.head
        while temp:
            if temp.data == data:
                return True
            temp = temp.next
        return False

def menu():
    ll = LinkedList()
    while True:
        print("\nLinked List Menu:")
        print("1. Insert")
        print("2. Remove")
        print("3. Display List")
        print("4. Check if Number Exists")
        print("5. Exit")
        choice = input("Enter choice: ")

        if choice == "1":
            num = int(input("Enter number to insert: "))
            ll.insert(num)
        elif choice == "2":
            num = int(input("Enter number to remove: "))
            print(ll.remove(num))
        elif choice == "3":
            print("List:", ll.display())
        elif choice == "4":
            num = int(input("Enter number to check: "))
            print("Exists" if ll.contains(num) else "Does not exist")
        elif choice == "5":
            break
        else:
            print("Invalid choice, try again.")

if __name__ == "__main__":
    menu()
