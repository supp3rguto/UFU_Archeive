class Node:
    def __init__(self, data):
        self.data = data
        self.left = self.right = None

class BST:
    def __init__(self):
        self.root = None

    def insert(self, data):
        self.root = self._insert(self.root, data)

    def _insert(self, node, data):
        if node is None:
            return Node(data)
        if data < node.data:
            node.left = self._insert(node.left, data)
        else:
            node.right = self._insert(node.right, data)
        return node

    def remove(self, data):
        self.root = self._remove(self.root, data)

    def _remove(self, node, data):
        if node is None:
            return node
        if data < node.data:
            node.left = self._remove(node.left, data)
        elif data > node.data:
            node.right = self._remove(node.right, data)
        else:
            if node.left is None:
                return node.right
            if node.right is None:
                return node.left
            temp = self._min_value_node(node.right)
            node.data = temp.data
            node.right = self._remove(node.right, temp.data)
        return node

    def _min_value_node(self, node):
        while node.left:
            node = node.left
        return node

    def contains(self, data):
        return self._contains(self.root, data)

    def _contains(self, node, data):
        if node is None:
            return False
        if data == node.data:
            return True
        return self._contains(node.left, data) if data < node.data else self._contains(node.right, data)

    def traverse(self, order="in"):
        if order == "pre":
            return self._pre_order(self.root, [])
        elif order == "post":
            return self._post_order(self.root, [])
        else:
            return self._in_order(self.root, [])

    def _in_order(self, node, result):
        if node:
            self._in_order(node.left, result)
            result.append(node.data)
            self._in_order(node.right, result)
        return result

    def _pre_order(self, node, result):
        if node:
            result.append(node.data)
            self._pre_order(node.left, result)
            self._pre_order(node.right, result)
        return result

    def _post_order(self, node, result):
        if node:
            self._post_order(node.left, result)
            self._post_order(node.right, result)
            result.append(node.data)
        return result

def menu():
    bst = BST()
    order = "in"

    while True:
        print("\nBinary Search Tree Menu:")
        print("1. Insert")
        print("2. Remove")
        print("3. Display Tree")
        print("4. Check if Number Exists")
        print("5. Change Display Order (Pre, In, Post)")
        print("6. Exit")
        choice = input("Enter choice: ")

        if choice == "1":
            num = int(input("Enter number to insert: "))
            bst.insert(num)
        elif choice == "2":
            num = int(input("Enter number to remove: "))
            bst.remove(num)
        elif choice == "3":
            print("Tree:", bst.traverse(order))
        elif choice == "4":
            num = int(input("Enter number to check: "))
            print("Exists" if bst.contains(num) else "Does not exist")
        elif choice == "5":
            order = input("Enter order (pre, in, post): ").strip().lower()
        elif choice == "6":
            break
        else:
            print("Invalid choice, try again.")

if __name__ == "__main__":
    menu()
