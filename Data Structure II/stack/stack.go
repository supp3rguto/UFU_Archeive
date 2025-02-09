package main

import (
	"fmt"
)

type Stack struct {
	items []int
}

func (s *Stack) Push(item int) {
	s.items = append(s.items, item)
}

func (s *Stack) Pop() int {
	if len(s.items) == 0 {
		fmt.Println("Stack is empty.")
		return -1
	}
	popped := s.items[len(s.items)-1]
	s.items = s.items[:len(s.items)-1]
	return popped
}

func (s *Stack) Display() {
	if len(s.items) == 0 {
		fmt.Println("Stack is empty.")
	} else {
		fmt.Println("Stack:", s.items)
	}
}

func (s *Stack) Contains(item int) bool {
	for _, v := range s.items {
		if v == item {
			return true
		}
	}
	return false
}

func main() {
	s := Stack{}
	var choice, num int

	for {
		fmt.Println("\nStack Menu:")
		fmt.Println("1. Push")
		fmt.Println("2. Pop")
		fmt.Println("3. Display Stack")
		fmt.Println("4. Check if Number Exists")
		fmt.Println("5. Exit")
		fmt.Print("Enter choice: ")
		fmt.Scan(&choice)

		switch choice {
		case 1:
			fmt.Print("Enter number to push: ")
			fmt.Scan(&num)
			s.Push(num)
		case 2:
			fmt.Println("Popped:", s.Pop())
		case 3:
			s.Display()
		case 4:
			fmt.Print("Enter number to check: ")
			fmt.Scan(&num)
			if s.Contains(num) {
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
