#include <stdio.h>
#include <string.h>

#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

int empty() {
    return front == -1;
}

int size() {
    if (empty()) return 0;
    return rear - front + 1;
}

void push_front(int value) {
    if (front == -1) {
        front = rear = 0;
        deque[front] = value;
    } 
    else if (front > 0) {
        front--;
        deque[front] = value;
    } 
    else {
        printf("Deque Overflow\n");
    }
}

void push_back(int value) {
    if (rear == MAX - 1) {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1)
        front = rear = 0;
    else
        rear++;

    deque[rear] = value;
}

void pop_front() {
    if (empty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[front]);

    if (front == rear)
        front = rear = -1;
    else
        front++;
}

void pop_back() {
    if (empty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[rear]);

    if (front == rear)
        front = rear = -1;
    else
        rear--;
}

void get_front() {
    if (empty())
        printf("-1\n");
    else
        printf("%d\n", deque[front]);
}

void get_back() {
    if (empty())
        printf("-1\n");
    else
        printf("%d\n", deque[rear]);
}

void clear() {
    front = rear = -1;
}

void reverse() {
    if (empty()) return;

    int i = front, j = rear;
    while (i < j) {
        int temp = deque[i];
        deque[i] = deque[j];
        deque[j] = temp;
        i++;
        j--;
    }
}

void print_deque() {
    if (empty()) {
        printf("Deque Empty\n");
        return;
    }

    for (int i = front; i <= rear; i++)
        printf("%d ", deque[i]);

    printf("\n");
}

int main() {

    int n;
    char op[20];
    int value;

    scanf("%d", &n);

    while (n--) {

        scanf("%s", op);

        if (strcmp(op, "push_front") == 0) {
            scanf("%d", &value);
            push_front(value);
        }

        else if (strcmp(op, "push_back") == 0) {
            scanf("%d", &value);
            push_back(value);
        }

        else if (strcmp(op, "pop_front") == 0)
            pop_front();

        else if (strcmp(op, "pop_back") == 0)
            pop_back();

        else if (strcmp(op, "front") == 0)
            get_front();

        else if (strcmp(op, "back") == 0)
            get_back();

        else if (strcmp(op, "size") == 0)
            printf("%d\n", size());

        else if (strcmp(op, "empty") == 0)
            printf("%d\n", empty());

        else if (strcmp(op, "clear") == 0)
            clear();

        else if (strcmp(op, "reverse") == 0)
            reverse();
    }

    print_deque();

    return 0;
}