const assert = require("node:assert/strict");
const test = require("node:test");

const { LinkedList } = require("./linkedList");

test("pushes values at both ends and returns them in order", () => {
  const list = new LinkedList();

  list.pushBack(2);
  list.pushFront(1);
  list.pushBack(3);

  assert.equal(list.length, 3);
  assert.deepEqual(list.values(), [1, 2, 3]);
});

test("pops from the front and supports reuse", () => {
  const list = new LinkedList();
  list.pushBack(1);
  list.pushBack(2);

  assert.equal(list.popFront(), 1);
  assert.equal(list.popFront(), 2);
  assert.equal(list.length, 0);

  list.pushBack(3);
  assert.deepEqual(list.values(), [3]);
});

test("throws when popping from an empty list", () => {
  const list = new LinkedList();

  assert.throws(() => list.popFront(), RangeError);
  assert.equal(list.length, 0);
});
