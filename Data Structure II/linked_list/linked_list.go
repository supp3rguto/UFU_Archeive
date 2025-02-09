package main

import (
	"fmt"
)

type Node struct {
	data int
	next *Node
}

type LinkedList struct {
	head *Node
}

func (ll *LinkedList) Insert(data int) {
	newNode := &Node{data: data}
	if ll.head == nil {
		ll.head = newNode
	} else {
		temp := ll.head
		for temp.next != nil {
			temp = temp.next
		}
		temp.next = newNode
	}
}

func (ll *LinkedList) Remove(data int) string {
	if ll.head == nil {
		return "List is empty."
	}

	if ll.head.data == data {
		ll.head = ll.head.next
		return fmt.Sprintf("Removed %d", data)
	}

	temp := ll.head
	for temp.next != nil && temp.next.data != data {
		temp = temp.next
	}

	if temp.next != nil {
		temp.next = temp.next.next
		return fmt.Sprintf("Removed %d", data)
	}
	return "Number not found."
}

func (ll *LinkedList) Display() {
	if ll.head == nil {
		fmt.Println("List is empty.")
		return
	}

	temp := ll.head
	fmt.Print("List: ")
	for temp != nil {
		fmt.Print(temp.data, " ")
		temp = temp.next
	}
	fmt.Println()
}

func (ll *LinkedList) Contains(data int) bool {
	temp := ll.head
	for temp != nil {
		if temp.data == data {
			return true
		}
		temp = temp.next
	}
	return false
}

func main() {
	ll := LinkedList{}
	var choice, num int

	for {
		fmt.Println("\nLinked List Menu:")
		fmt.Println("1. Insert")
		fmt.Println("2. Remove")
		fmt.Println("3. Display List")
		fmt.Println("4. Check if Number Exists")
		fmt.Println("5. Exit")
		fmt.Print("Enter choice: ")
		fmt.Scan(&choice)

		switch choice {
		case 1:
			fmt.Print("Enter number to insert: ")
			fmt.Scan(&num)
			ll.Insert(num)
		case 2:
			fmt.Print("Enter number to remove: ")
			fmt.Scan(&num)
			fmt.Println(ll.Remove(num))
		case 3:
			ll.Display()
		case 4:
			fmt.Print("Enter number to check: ")
			fmt.Scan(&num)
			if ll.Contains(num) {
				fmt.Println("Exists")
			} else {
				fmt.Println("Does not exist")
			}
		case 5:
			return
		default:
			fmt.Println("Invalid choice, try again.")
		}
	}
}
