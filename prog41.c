#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
int data;
struct Node* next;
};

// Head pointer
struct Node* head = NULL;

// Insert at end
void append(int data) {

```
// create new node
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = NULL;

// if list empty
if (head == NULL) {
    head = newNode;
    return;
}

// traverse to last node
struct Node* temp = head;
while (temp->next != NULL) {
    temp = temp->next;
}

temp->next = newNode;
```

}

// display linked list
void display() {
struct Node* temp = head;

```
while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
}
```

}

// main function
int main() {

```
int n, value;

// number of nodes
scanf("%d", &n);

// input values
for(int i = 0; i < n; i++) {
    scanf("%d", &value);
    append(value);
}

// print list
display();

return 0;
```

}
