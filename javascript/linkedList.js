class Node {
  constructor(value) {
    this.value = value;
    this.next = null;
  }
}

class LinkedList {
  constructor() {
    this.head = null;
    this.tail = null;
    this._length = 0;
  }

  get length() {
    return this._length;
  }

  pushFront(value) {
    const first = new Node(value);
    first.next = this.head;
    this.head = first;
    if (this.tail === null) {
      this.tail = first;
    }
    this._length += 1;
  }

  pushBack(value) {
    const last = new Node(value);
    if (this.tail === null) {
      this.head = last;
    } else {
      this.tail.next = last;
    }
    this.tail = last;
    this._length += 1;
  }

  popFront() {
    if (this.head === null) {
      throw new RangeError("Cannot pop from an empty linked list");
    }

    const first = this.head;
    this.head = first.next;
    this._length -= 1;
    if (this.head === null) {
      this.tail = null;
    }
    return first.value;
  }

  values() {
    const result = [];
    for (let current = this.head; current !== null; current = current.next) {
      result.push(current.value);
    }
    return result;
  }
}

module.exports = { LinkedList };
