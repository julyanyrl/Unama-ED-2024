#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void initialize(struct Node** head_ref) {
    *head_ref = NULL;
}

struct Node* createNode(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insertInOrder(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);

    if (*head_ref == NULL || (*head_ref)->data >= new_data) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }

    struct Node* current = *head_ref;
    while (current->next != NULL && current->next->data < new_data) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head;
    initialize(&head);

    int n, value;
    printf("Quantos valores deseja inserir? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Digite o valor #%d: ", i + 1);
        scanf("%d", &value);
        insertInOrder(&head, value);
    }

    printf("Lista encadeada ordenada: ");
    printList(head);

    return 0;
}