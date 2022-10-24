#include <stdio.h>
#include <stdlib.h>

typedef struct _RootNode
{
    int key;
    struct _RootNode *left;
    struct _RootNode *right;

} Node;

Node *search(Node *root, int key){
    if (root == NULL){
        printf("%d의 값이 존재하지 않습니다.", key);
        return root;
    }
    if (root->key == key){
        return root;
    }
    else if(root->key < key){
        search(root->right, key);
    }
    else {
        search(root->left, key);
    }
}

Node *insert(Node *root, int key){
    if (root == NULL){
        root = malloc(sizeof(Node));
        root -> key = key;
        root -> left = root -> right = NULL;
        return root;
    }
    else {
        if (root -> key > key) 
            root->left = insert(root -> left, key);
        else 
            root->right = insert(root -> right,key);
    }
    return root;
}

// 최댓값 노드를 찾는다.

Node* findMax(Node *root){
    // left node에서 최댓값을 찾는다.
    Node *max = root;
    while (root->right != NULL)
    {
        max = root-> right;
    }
    return max;
    
}
// Node *deleteNode(Node *root, int key){
//     Node *del_node = root;
//     Node *parent_node = NULL;
//     Node *tmp;

//     // 삭제하려는 노드를 찾기 위해 트리를 순회.
//     while (del_node != NULL){
//         if (del_node->key == key) break;

//         parent_node = del_node;
//         if (del_node->key <key) del_node = del_node->right;
//         else del_node = del_node -> left;
//     }

//     // 삭제하려는 노드를 찾지 못하면 print
//     if (del_node == NULL) {
//         printf("%d는 존재하지 않습니다.", key);
//         return root;
//     }
//     // 자식이 둘 다 없는 경우 == 차수 0
//     if (del_node->left == NULL && del_node->right == NULL){
//         // 부모노드가 없으면 트리에 노드 1개만 있는 것이므로 그냥 없애면 됨.
//         if (parent_node == NULL){
//             root ==  NULL;
//         }
//         // 부모노드와의 연결을 끊어버린다.
//         else{
//             if(parent_node->left == del_node) parent_node->left == NULL;
//             else parent_node->right == NULL;
//         }
//     }
    
//     // 자식이 두 개 있는 경우 == 차수 2
//     else if (del_node->left != NULL && del_node->right !=NULL)
//     {   
//         tmp = del_node->left;
//         if(tmp->right == NULL){
//             del_node->key = tmp->key;
//             del_node->left = tmp->left;
//             return root;
//         }
//         while(1){
//             if(tmp->right ==NULL){
//                 del_node->key = tmp->key;
//                 del_node->left = tmp->left;
//                 return root;
//             }
//             else {
//                 parent_node = tmp;
//                 tmp = tmp->right;
//             }
//         }
//         free(tmp);
//     }
    
//     // 자식이 1개 있는 경우 == 차수 1
//     else {
//         if (parent_node == NULL){
//             if (del_node -> left !=NULL) parent_node -> left = del_node -> left;
//             else parent_node -> right = del_node -> right;
//         } 
//         else {
//             if (del_node -> left != NULL) root = del_node -> left;
//             else root = del_node -> right;
//         }
//     }
//     return root;
// }

Node* Delete(Node* node, int key)
{   
    if(node == NULL) return NULL;
    
    // 일치하는 노드를 찾으면
    if(node->key == key)
    {   
        // 삭제하는 노드 주소 할당
        Node* deleteNode = node;

        // 자식 노드가 1개도 없으면
        if(node->left == NULL && node->right == NULL)
        {
            // 바로 없애버리기
            node = NULL;
        }
        // 자식노드가 1개만 있음 (왼쪽만)
        else if(node->left != NULL && node->right == NULL)
        {   
            // 왼쪽 노드로 대체
            node = node->left;
        }
        // 자식노드가 1개만 있음 (오른쪽만)
        else if(node->left == NULL && node->right != NULL)
        {
            // 오른쪽 노드만 대체
            node = node->right;
        }
        else
        {   
            // 직전노드를 찾는다.
            Node* maxNode = NULL;
            // 
            node->left = findMax(node->left);
            maxNode->left = deleteNode->left;
            maxNode->right = deleteNode->right;
            node = maxNode;
        }
        
        free(deleteNode);
        return node;
    }
    else
    {
        if(node->key > key)
        {
            node->left = Delete(node->left, key);
        }
        else
        {
            node->right = Delete(node->right, key);
        }
        
        return node;
    }
}

void preorder(Node *root){
    if(root == NULL){
        return;
    }
    printf("addr : %p\n", root);
    printf("key : %d\n", root->key);
    printf("left : %p\n", root->left);
    printf("right : %p\n", root->right);
    printf("=====================\n");
    preorder(root->left);
    preorder(root->right);
}

int main() {

    Node *root = NULL;
    Node *ptr = NULL;
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 60);
    root = insert(root, 50);
    root = insert(root, 10);
    root = insert(root, 35);
    root = insert(root, 5);
    ptr = search(root, 30);
    // printf("%p\n", ptr);
    root = Delete(root,20);
    preorder(root);
    return 0;
}