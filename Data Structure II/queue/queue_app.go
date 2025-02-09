package main

import (
	"fmt"
)

type Queue struct {
	items []int
}

func (q *Queue) Enqueue(item int) {
	q.items = append(q.items, item)
}

func (q *Queue) Dequeue() int {
	if len(q.items) == 0 {
		fmt.Println("Queue is empty.")
		return -1
	}
	dequeued := q.items[0]
	q.items = q.items[1:]
	return dequeued
}

func (q *Queue) Display() {
	if len(q.items) == 0 {
		fmt.Println("Queue is empty.")
	} else {
		fmt.Println("Queue:", q.items)
	}
}

func (q *Queue) Contains(item int) bool {
	for _, v := range q.items {
		if v == item {
			return true
		}
	}
	return false
}

func main() {
	q := Queue{}
	var choice, num int

	for {
		fmt.Println("\nQueue Menu:")
		fmt.Println("1. Enqueue")
		fmt.Println("2. Dequeue")
		fmt.Println("3. Display Queue")
		fmt.Println("4. Check if Number Exists")
		fmt.Println("5. Exit")
		fmt.Print("Enter choice: ")
		fmt.Scan(&choice)

		switch choice {
		case 1:
			fmt.Print("Enter number to enqueue: ")
			fmt.Scan(&num)
			q.Enqueue(num)
		case 2:
			fmt.Println("Dequeued:", q.Dequeue())
		case 3:
			q.Display()
		case 4:
			fmt.Print("Enter number to check: ")
			fmt.Scan(&num)
			if q.Contains(num) {
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
