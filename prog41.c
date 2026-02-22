# Node class
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


# Linked List class
class LinkedList:
    def __init__(self):
        self.head = None

    # Insert at end
    def append(self, data):
        new_node = Node(data)

        # If list empty
        if self.head is None:
            self.head = new_node
            return

        # Traverse to last node
        temp = self.head
        while temp.next:
            temp = temp.next

        temp.next = new_node

    # Traverse and print
    def display(self):
        temp = self.head
        while temp:
            print(temp.data, end=" ")
            temp = temp.next


# ---- MAIN PROGRAM ----

# Input number of nodes
n = int(input())

# Input list of values
values = list(map(int, input().split()))

# Create linked list
ll = LinkedList()

# Insert elements
for val in values:
    ll.append(val)

# Print linked list
ll.display()