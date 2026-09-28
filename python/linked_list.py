class _Node:
    def __init__(self, value):
        self.value = value
        self.next = None


class LinkedList:
    """A singly linked list of values."""

    def __init__(self):
        self._head = None
        self._tail = None
        self._length = 0

    def __len__(self):
        return self._length

    def push_front(self, value):
        first = _Node(value)
        first.next = self._head
        self._head = first
        if self._tail is None:
            self._tail = first
        self._length += 1

    def push_back(self, value):
        last = _Node(value)
        if self._tail is None:
            self._head = last
        else:
            self._tail.next = last
        self._tail = last
        self._length += 1

    def pop_front(self):
        if self._head is None:
            raise IndexError("pop from empty linked list")

        first = self._head
        self._head = first.next
        self._length -= 1
        if self._head is None:
            self._tail = None
        return first.value

    def values(self):
        result = []
        current = self._head
        while current is not None:
            result.append(current.value)
            current = current.next
        return result
