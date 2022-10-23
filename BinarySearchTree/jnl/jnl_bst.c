//이진탐색 트리
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key;
    struct Node *parent;
    struct Node *left;
    struct Node *right;
} Node;

void insertNode(Node* cur, int data){
    if (cur->key > data)
    {
        if (cur->left != NULL){
            insertNode(cur->left, data);
        }
        else{
            cur->left = (Node *)malloc(sizeof(Node));
            cur->left->key = data;
            cur->left->parent = cur;
            cur->left->left = NULL;
            cur->left->right = NULL;
        }
    }
    else
    {
        if (cur->right != NULL){
            insertNode(cur->right, data);
        }else{
            cur->right = (Node *)malloc(sizeof(Node));
            cur->right->key = data;
            cur->right->parent = cur;
            cur->right->left = NULL;
            cur->right->right = NULL;
        }
    }
}

// 루트 기준으로 왼쪽으로만 쭉~~~내려가면 가장 작은 값
Node * minValueNode(Node* root){
    Node *cur = root;
    while (cur && cur->left != NULL)
        cur = cur->left;
    return cur;
}

Node* deleteNode(Node* cur, int data){
    if(cur== NULL)
        return cur;
    if (data < cur->key)
    {
        cur->left = deleteNode(cur->left, data);
    }
    else if(data > cur->key){
        cur->right = deleteNode(cur->right, data);
    }else{
        if (cur->left == NULL){
            Node *tmp = cur->right;
            free(cur);
            return tmp;
        }else if (cur->right == NULL){
            Node *tmp = cur->left;
            free(cur);
            return tmp;
        }

        Node *tmp = minValueNode(cur->right);
        cur->key = tmp->key;
        cur->right = deleteNode(cur->right, tmp->key);
    }
    return cur;
}

void showNode(Node *n){
    if (n != NULL){
        printf("key: %d\n", n->key);
        printf("self: %p\n", n);
        printf("left: %p\n", n->left);
        printf("right: %p\n", n->right);
        printf("-------------------------------------\n");
        showNode(n->left);
        showNode(n->right);
    }
}

void init(Node **nn_head, int data){
    *nn_head = (Node *)malloc(sizeof(Node));
    Node *n = *nn_head;
    n->key = data;
    n->parent = NULL;
    n->left = NULL;
    n->right = NULL;
}

int main(){
    Node *head;
    init(&head, 10); // 10
    insertNode(head, 11);
    insertNode(head, 9);
    insertNode(head, 20);
    insertNode(head, 21);
    showNode(head);
    deleteNode(head, 11);
    showNode(head);
}