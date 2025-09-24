#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int pow;
    struct Node* next;
} Node;

Node* createNode(int c, int p) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->coeff = c;
    temp->pow = p;
    temp->next = NULL;
    return temp;
}

void insert(Node** head, int c, int p) {
    Node* temp = createNode(c, p);
    if (*head == NULL) {
        *head = temp;
    } else {
        Node* t = *head;
        while (t->next) t = t->next;
        t->next = temp;
    }
}

Node* addPoly(Node* p1, Node* p2) {
    Node* result = NULL;
    while (p1 && p2) {
        if (p1->pow > p2->pow) {
            insert(&result, p1->coeff, p1->pow);
            p1 = p1->next;
        } else if (p1->pow < p2->pow) {
            insert(&result, p2->coeff, p2->pow);
            p2 = p2->next;
        } else {
            int sum = p1->coeff + p2->coeff;
            if (sum != 0)
                insert(&result, sum, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1) {
        insert(&result, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    while (p2) {
        insert(&result, p2->coeff, p2->pow);
        p2 = p2->next;
    }
    return result;
}

void printPoly(Node* poly) {
    while (poly) {
        printf("%dx^%d", poly->coeff, poly->pow);
        poly = poly->next;
        if (poly) printf(" + ");
    }
    printf("\n");
}

void inputPoly(Node** poly) {
    int n, coeff, pow;
    printf("Enter the total number of terms: ");
    scanf("%d", &n);

   
    for (int i = 0; i < n; i++) {
        printf(" Enter the Coefficient of Term %d : ", i + 1);
        scanf("%d", &coeff);
        printf(" enter the exponent of Term %d:", i + 1);
        scanf("%d", &pow);
        insert(poly, coeff, pow);
    }
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    printf("first polynomial:\n");
    inputPoly(&poly1);

    printf(" second polynomial:\n");
    inputPoly(&poly2);

    printf("Polynomial 1: ");
    printPoly(poly1);

    printf("Polynomial 2: ");
    printPoly(poly2);

    Node* sum = addPoly(poly1, poly2);
    printf("Results polynomial after addition \n");
    printPoly(sum);

    return 0;
}
