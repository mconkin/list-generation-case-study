package linkedlist

type node[T any] struct {
	value T
	next  *node[T]
}

// List is a singly linked list of values.
type List[T any] struct {
	head   *node[T]
	tail   *node[T]
	length int
}

// Len returns the number of values in the list.
func (l *List[T]) Len() int {
	return l.length
}

// PushFront adds value to the beginning of the list.
func (l *List[T]) PushFront(value T) {
	first := &node[T]{value: value, next: l.head}
	l.head = first
	if l.tail == nil {
		l.tail = first
	}
	l.length++
}

// PushBack adds value to the end of the list.
func (l *List[T]) PushBack(value T) {
	last := &node[T]{value: value}
	if l.tail == nil {
		l.head = last
	} else {
		l.tail.next = last
	}
	l.tail = last
	l.length++
}

// PopFront removes and returns the first value. The boolean is false if empty.
func (l *List[T]) PopFront() (T, bool) {
	if l.head == nil {
		var zero T
		return zero, false
	}

	first := l.head
	l.head = first.next
	l.length--
	if l.head == nil {
		l.tail = nil
	}
	return first.value, true
}

// Values returns the list's values in order.
func (l *List[T]) Values() []T {
	values := make([]T, 0, l.length)
	for current := l.head; current != nil; current = current.next {
		values = append(values, current.value)
	}
	return values
}
