package linkedlist

import (
	"reflect"
	"testing"
)

func TestListPushAndValues(t *testing.T) {
	var list List[int]

	list.PushBack(2)
	list.PushFront(1)
	list.PushBack(3)

	if got, want := list.Len(), 3; got != want {
		t.Fatalf("Len() = %d, want %d", got, want)
	}
	if got, want := list.Values(), []int{1, 2, 3}; !reflect.DeepEqual(got, want) {
		t.Fatalf("Values() = %v, want %v", got, want)
	}
}

func TestListPopFrontAndReuse(t *testing.T) {
	var list List[int]
	list.PushBack(1)
	list.PushBack(2)

	if got, ok := list.PopFront(); !ok || got != 1 {
		t.Fatalf("PopFront() = (%d, %t), want (1, true)", got, ok)
	}
	if got, ok := list.PopFront(); !ok || got != 2 {
		t.Fatalf("PopFront() = (%d, %t), want (2, true)", got, ok)
	}
	if got, want := list.Len(), 0; got != want {
		t.Fatalf("Len() after draining = %d, want %d", got, want)
	}

	list.PushBack(3)
	if got, want := list.Values(), []int{3}; !reflect.DeepEqual(got, want) {
		t.Fatalf("Values() after reuse = %v, want %v", got, want)
	}
}

func TestListPopFrontWhenEmpty(t *testing.T) {
	var list List[int]

	if got, ok := list.PopFront(); ok || got != 0 {
		t.Fatalf("PopFront() on empty list = (%d, %t), want (0, false)", got, ok)
	}
}
