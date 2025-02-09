package main

import (
	"fmt"
)

type Node struct {
	data  int
	left  *Node
	right *Node
}

type BST struct {
	root *Node
}

func (bst *BST) Insert(data int) {
	bst.root = insertNode(bst.root, data)
}

func insertNode(node *Node, data int) *Node {
	if node == nil {
		return &Node{data: data}
	}
	if data < node.data {
		node.left = insertNode(node.left, data)
	} else {
		node.right = insertNode(node.right, data)
	}
	return node
}

func (bst *BST) Contains(data int) bool {
	return containsNode(bst.root, data)
}

func containsNode(node *Node, data int) bool {
	if node == nil {
		return false
	}
	if data == node.data {
		return true
	}
	if data < node.data {
		return containsNode(node.left, data)
	}
	return containsNode(node.right, data)
}

func (bst *BST) Traverse(order string) {
	switch order {
	case "pre":
		preOrder(bst.root)
	case "post":
		postOrder(bst.root)
	default:
		inOrder(bst.root)
	}
	fmt.Println()
}

func inOrder(node *Node) {
	if node != nil {
		inOrder(node.left)
		fmt.Print(node.data, " ")
		inOrder(node.right)
	}
}

func preOrder(node *Node) {
	if node != nil {
		fmt.Print(node.data, " ")
		preOrder(node.left)
		preOrder(node.right)
	}
}

func postOrder(node *Node) {
	if node != nil {
		postOrder(node.left)
		postOrder(node.right)
		fmt.Print(node.data, " ")
	}
}

func main() {
	bst := BST{}
	var choice, num int
	order := "in"

	for {
		fmt.Println("\nBinary Search Tree Menu:")
		fmt.Println("1. Insert")
		fmt.Println("2. Display Tree")
		fmt.Println("3. Check if Number Exists")
		fmt.Println("4. Change Display Order (Pre, In, Post)")
		fmt.Println("5. Exit")
		fmt.Print("Enter choice: ")
		fmt.Scan(&choice)

		switch choice {
		case 1:
			fmt.Print("Enter number to insert: ")
			fmt.Scan(&num)
			bst.Insert(num)
		case 2:
			bst.Traverse(order)
		case 3:
			fmt.Print("Enter number to check: ")
			fmt.Scan(&num)
			if bst.Contains(num) {
				fmt.Println("Exists")
			} else {
				fmt.Println("Does not exist")
			}
		case 4:
			fmt.Print("Enter order (pre, in, post): ")
			fmt.Scan(&order)
		case 5:
			return
		default:
			fmt.Println("Invalid choice, try again.")
		}
	}
}
