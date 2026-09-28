import unittest

from linked_list import LinkedList


class LinkedListTests(unittest.TestCase):
    def test_push_and_values(self):
        linked_list = LinkedList()

        linked_list.push_back(2)
        linked_list.push_front(1)
        linked_list.push_back(3)

        self.assertEqual(len(linked_list), 3)
        self.assertEqual(linked_list.values(), [1, 2, 3])

    def test_pop_front_and_reuse(self):
        linked_list = LinkedList()
        linked_list.push_back(1)
        linked_list.push_back(2)

        self.assertEqual(linked_list.pop_front(), 1)
        self.assertEqual(linked_list.pop_front(), 2)
        self.assertEqual(len(linked_list), 0)

        linked_list.push_back(3)
        self.assertEqual(linked_list.values(), [3])

    def test_pop_front_when_empty(self):
        linked_list = LinkedList()

        with self.assertRaises(IndexError):
            linked_list.pop_front()

        self.assertEqual(len(linked_list), 0)


if __name__ == "__main__":
    unittest.main()
