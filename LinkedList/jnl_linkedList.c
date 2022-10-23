#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key;
    struct Node *p_next;
} Node;

void appendNode(Node**, int);
void appendleftNode(Node **, int);
void insertNode(Node **, int, int);
void appendleftNode(Node **, int);
int popleftNode(Node **);
int popNode(Node **);
int deleteNode(Node **, int);
void dumpNode(Node **pphead);

void appendNode(Node **pp_head, int data){
    Node *p;
    if(*pp_head != NULL){
        p = *pp_head;
        while (p->p_next != NULL) p = p->p_next;
        p->p_next = (Node *)malloc(sizeof(Node));
        p = p->p_next;
    }else{
        *pp_head = (Node *)malloc(sizeof(Node));
        p = *pp_head;
    }
    p->key = data;
    p->p_next = NULL;
}

void insertNode(Node** pp_head, int data, int position){
    Node *cur;
    if (position == 0){
        appendleftNode(&cur, data);
        return;
    }
    if (*pp_head != NULL)
    {
        cur = *pp_head;
        Node *prev;
        for (int i = 0; i <= position; i++){
            if (cur->p_next != NULL){
                prev = cur;
                cur = cur->p_next;
            }
        }
        prev->p_next = (Node *)malloc(sizeof(Node));
        prev->p_next->key = data;
        prev->p_next->p_next = cur;
    }
}

void appendleftNode(Node** pp_head, int data){
    Node *p;
    Node *tmp = *pp_head;
    *pp_head = (Node *)malloc(sizeof(Node));
    p = *pp_head;
    p->key = data;
    p->p_next = tmp;
}

int popleftNode(Node** pp_head){
    Node *p;
    int result = -1;
    if (*pp_head != NULL)
    {
        p = *pp_head;
        result = p->key;
        *pp_head = p->p_next;
    }
    return result;
}

int popNode(Node** pp_head){
    Node *cur;
    int result = -1;
    if (*pp_head != NULL)
    {
        cur = *pp_head;
        Node *prev;
        while (cur->p_next != NULL)
        {
            prev = cur;
            cur = cur->p_next;
        }
        result = cur->key;
        prev->p_next = NULL;
    }
    return result;
}
int deleteNode(Node** pp_head, int position){
    Node *cur;
    int result = -1;
    if (position == 0){
        result = popleftNode(&cur);
    }
    else{
        Node *prev;
        cur = *pp_head;
        for (int i = 0; i < position; i++)
        {
            if (cur->p_next != NULL) {
                prev = cur;
                cur = cur->p_next;
            }
        }
        result = cur->key;
        prev->p_next = prev->p_next->p_next;
    }
    return result;
}

void dumpNode(Node **pp_head){
    Node *p;
    if (*pp_head != NULL){
        p = *pp_head;
        do{
            printf("%d\n", p->key);
            p = p->p_next;
        } while (p != NULL);
    }
}

int getLength(Node **pp_head){
    Node *p;
    if (*pp_head != NULL){
        int result = 1;
        p = *pp_head;
        while (p->p_next != NULL){
            result++;
            p = p->p_next;
        }
        return result;
    }
    return 0;
}

// void revSort(Node **pp_head){
//     Node *p;
//     if (*pp_head != NULL)
//     {
//         p = *pp_head;
//         Node *iter = *pp_head;
//         do {
//             while (iter != p){
//                 if (iter->key < p->key){
//                     Node *tmp = p->p_next;
//                     p->p_next = iter->p_next;
//                     iter->p_next = tmp;
//                     iter++;
//                 }
//             }
//             p = p->p_next;
// 
//         }while(p != NULL)
//     }
// }
int indexOf(Node **pp_head, int data){
    Node *p;
    if (*pp_head != NULL){
        int idx = 0;
        p = *pp_head;
        do
        {
            if (p->key == data)
                return idx;
            idx++;
            p = p->p_next;
        } while (p != NULL);
    }
    return -1;
}
int main(){
    Node *head = NULL;

    appendleftNode(&head, 11);
    appendleftNode(&head, 22);
    appendNode(&head, 15); // 22 11 15

    int a = popleftNode(&head); // 11 15
    printf("a:%d\n", a);

    appendleftNode(&head, 12); // 12 11 15
    appendNode(&head, 100); // 12 11 15 100
    int b = popNode(&head); // 12 11 15
    printf("b: %d\n", b);

    int d = deleteNode(&head, 1);
    printf("d: %d\n", d);

    insertNode(&head, 20, 1);

    int c = indexOf(&head, 20);
    printf("c: %d\n", c);
    int e = indexOf(&head, 1000);
    printf("e:%d\n", e);
    dumpNode(&head);

}