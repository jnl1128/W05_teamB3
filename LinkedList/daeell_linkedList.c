#include <stdio.h>
#include <stdlib.h>

typedef struct Node { // 연결 리스트의 노드 구조체
    struct Node *next; // 다음 노드의 주소를 저장할 포인터
    int data; // 데이터 저장
}Node ;

Node *head;

void add_first(int data){
    Node *newNode = malloc(sizeof(Node));
    newNode -> next = head -> next;
    newNode -> data = data;
    head -> next = newNode;
}

// linked list는 마지막 요소가 어디있는지 한 번에 알 수 없다. head에서 출발해서 next 멤버가 NULL인 요소를 찾아야한다.
void append(int data){
    Node *curr = head;
    while (curr->next !=NULL){
        curr = curr ->next;
        // 마지막 노드를 찾기 위해 순회한다.
    }
    curr -> next = malloc(sizeof(Node));
    // 추가할 노드의 주소를 할당한다.
    curr -> next -> next = NULL;
    // 추가할 노드의 next멤버에 다음 주소를 할당한다.
    curr -> next -> data = data;
    // 추가할 노드의 data멤버에 data를 저장한다.
}

void remove_first(){
    Node *removeStruct = head -> next;
    head -> next = head -> next -> next;
    free(removeStruct);
}

void remove_Node(int data){
    Node *curr, *prev;
    curr = prev = head;

    curr = head -> next;
    while (curr != NULL)
    {
        if (curr -> data == data){
            prev -> next = curr -> next;
            free(curr);
            return; 
        } 
        prev = curr;
        curr = curr -> next;
    }
    printf("%d is not in list!\n", data);
    return;
}

int main()
{
    head = malloc(sizeof(struct Node));
    // head 포인터 노드에 메모리를 할당한다.
    head -> next = NULL;
    add_first(20);
    add_first(40);
    add_first(10);
    add_first(60);

    append(70);
    append(50);
    
    remove_first();

    remove_Node(40);
    remove_Node(15);
    // 배열을 순회하면서 노드를 출력
    Node *curr = head -> next;
    while (curr != NULL)
    {
        printf("%d\n", curr->data);
        curr = curr -> next;
    }

    curr = head -> next;
    // 노드들에 할당된 메모리를 해제
    while (curr != NULL)
    {
        Node *next = curr -> next;
        free(curr);
        curr = next;
    }

    free(head);   
}