class MinHeap:
    def __init__(self):
        self.heap = []

    # Heapify Up
    def heapify_up(self, index):
        while index > 0:
            parent = (index - 1) // 2
            if self.heap[parent] > self.heap[index]:
                self.heap[parent], self.heap[index] = self.heap[index], self.heap[parent]
                index = parent
            else:
                break

    # Heapify Down
    def heapify_down(self, index):
        size = len(self.heap)

        while True:
            left = 2 * index + 1
            right = 2 * index + 2
            smallest = index

            if left < size and self.heap[left] < self.heap[smallest]:
                smallest = left

            if right < size and self.heap[right] < self.heap[smallest]:
                smallest = right

            if smallest != index:
                self.heap[index], self.heap[smallest] = self.heap[smallest], self.heap[index]
                index = smallest
            else:
                break

    def insert(self, x):
        self.heap.append(x)
        self.heapify_up(len(self.heap) - 1)

    def extractMin(self):
        if not self.heap:
            print(-1)
            return

        min_val = self.heap[0]
        last = self.heap.pop()

        if self.heap:
            self.heap[0] = last
            self.heapify_down(0)

        print(min_val)

    def peek(self):
        if not self.heap:
            print(-1)
        else:
            print(self.heap[0])


# Driver Code
n = int(input())
heap = MinHeap()

for _ in range(n):
    command = input().split()

    if command[0] == "insert":
        heap.insert(int(command[1]))

    elif command[0] == "extractMin":
        heap.extractMin()

    elif command[0] == "peek":
        heap.peek()