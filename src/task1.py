class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Stack:
    def __init__(self):
        self.head = Node('head')
        self.size = 0

    def __str__(self):
        current = self.head.next
        out = ""

        while current:
            out += str(current.data)
            current = current.next
        return out[:-2]

    def isEmpty(self):
        return self.size == 0;

    def top(self):
        if self.isEmpty():
            print("The Stack is empty")
        return self.head.data

    def push(self, data):
        node = Node(data)
        node.next = self.head.next
        self.head.next = node
        self.size += 1

    def pop(self):
        if self.isEmpty():
            print("The Stack is empty")
        popp = self.head.next
        self.head.next = self.head.next.next
        self.size -= 1
        return popp.data


stack = Stack()
for i in range(1, 11):
    stack.push(i)
print(f"Stack: {stack} ")

for _ in range(1, 6):
    remove = stack.pop()
    print(f"Pop: {remove}")
print(f"Stack: {stack}")
