#include <stdio.h>
#include <stdlib.h>

struct StackNode {
    int data;
    struct StackNode* next;
};

struct StackNode* createNode(int data) {
    struct StackNode* new_node = (struct StackNode*)malloc(sizeof(struct StackNode));
    if (new_node == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    } else {
        new_node->data = data;
        new_node->next = NULL;
        return new_node;
    }
}

// Função para verificar se a pilha está vazia
int isEmpty(struct StackNode* top) {
    if (top == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void push(struct StackNode** top_ref, int data) {
    struct StackNode* new_node = createNode(data);
    if (*top_ref == NULL) {
        *top_ref = new_node;
    } else {
        new_node->next = *top_ref;
        *top_ref = new_node;
    }
}

int pop(struct StackNode** top_ref) {
    if (isEmpty(*top_ref)) {
        printf("Pilha vazia! Não é possível desempilhar.\n");
        exit(1);
    } else {
        struct StackNode* temp = *top_ref;
        int popped = temp->data;
        *top_ref = temp->next;
        free(temp);
        return popped;
    }
}

void reverseStack(struct StackNode** top_ref) {
    struct StackNode* temp_stack = NULL;
    while (!isEmpty(*top_ref)) {
        int data = pop(top_ref);
        push(&temp_stack, data);
    }

    if (isEmpty(temp_stack)) {
        printf("Erro: a pilha temporária está vazia!\n");
    } else {
        *top_ref = temp_stack;
    }
}

void printStack(struct StackNode* top) {
    if (isEmpty(top)) {
        printf("A pilha está vazia.\n");
    } else {
        struct StackNode* temp = top;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct StackNode* stack = NULL;

    int values[] = {10, 20, 30, 40};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        push(&stack, values[i]);
    }

    printf("Pilha original: ");
    printStack(stack);

    reverseStack(&stack);

    printf("Pilha invertida: ");
    printStack(stack);

    return 0;
}