#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
} *first = NULL;

void create(int a[], int n) {
    int i;
    struct node *t, *last;
    first = (struct node*)malloc(sizeof(struct node));
    first->data = a[0]; 
    first->next = NULL;
    last = first;//Initially it is pointing the same node, same node is first and last

    for (i = 1; i < n; i++) {     //here i = 0 is the first node created above 
        t = (struct node*)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

struct node* Lsearch(struct node* p, int key) {
    struct node* q = NULL;
    while (p != NULL) {
        if (key == p->data) {
            if (q != NULL) {
                q->next = p->next;
                p->next = first;
                first = p;
            }
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

struct node* Recursive_Lsearch(struct node* p, int key) {
    if (p == NULL) {
        return NULL;
    }
    if (key == p->data) {
        return p;
    }
    return Recursive_Lsearch(p->next, key);
}

int main() {
    struct node* temp;
    int n;
    printf("Enter size of the Linked list: ");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);
    create(a, n);
    temp = Lsearch(first, key);
    if (temp != NULL) {
        printf("Key found: %d\n", temp->data);
    } else {
        printf("Key not found.\n");
    }
    return 0;
}
