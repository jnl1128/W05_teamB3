#include <stdio.h>
#include <stdlib.h>

typedef struct NodeStruct {
    struct NodeStruct *leftChild;
    struct NodeStruct *rightChild;
    int data;
}NODE;

NODE *root;

NODE *insert(NODE *root, int data){
    if (root == NULL){
        root = malloc(sizeof(NODE));
        root -> leftChild = root -> rightChild = NULL;
        root -> data = data;
        return root;
    }else{
        if (data < root -> data){
            root -> leftChild = insert(root->leftChild, data);
        }else{
            root -> rightChild = insert(root->rightChild, data);
        }
    }
    return root;
}

NODE *findMin(NODE *root){
    NODE *tmp = root;
    while(tmp->leftChild != NULL){
        tmp = tmp -> leftChild;
    }
    return tmp;
}

NODE *delete(NODE *root, int data){
    NODE *tempNode = NULL;
    if (root == NULL){
        return NULL;
    }

    if (root->data > data){                                  // 같은 값이 있는 노드가 있을때까지 찾음
        root->leftChild = delete(root->leftChild, data);
    }else if (root->data < data){                               
        root->rightChild = delete(root->rightChild, data);
    }else{                                                          // 같다면
        if (root->leftChild != NULL && root->rightChild != NULL){   // 양쪽의 노드가 모두 있을때
            tempNode = findMin(root->rightChild);                   
            root->data = tempNode->data;
            root->rightChild = delete(root->rightChild, tempNode->data);
        }else{
            tempNode = (root->leftChild == NULL) ? root->rightChild : root-> leftChild;
            free(root);
            return tempNode;
        }
    }
    return root;

}

void preorder(NODE *root){
    if (root == NULL){
        return;
    }
    printf("값: %d, 노드주소:  %p\n", root->data, root);
    printf("--------\n");
    preorder(root->leftChild);
    preorder(root->rightChild);
}

void inorder(NODE *root){
    if (root == NULL){
        return;
    }
    inorder(root->leftChild);
    printf("값: %d, 노드주소:  %p\n", root->data, root);
    printf("--------\n");
    inorder(root->rightChild);
}

void postorder(NODE *root){
    if (root == NULL){
        return;
    }
    postorder(root->leftChild);
    postorder(root->rightChild);
    printf("값: %d, 노드주소:  %p\n", root->data, root);
    printf("--------\n");
}

int main(){
    root = insert(root, 7);
    root = insert(root, 3);
    root = insert(root, 9);
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 5);
    root = insert(root, 8);

    root = delete(root, 7);
 
    printf("<preorder>\n");
    preorder(root);

    printf("<inorder>\n");
    inorder(root);

    printf("<postorder>\n");
    postorder(root);

}
