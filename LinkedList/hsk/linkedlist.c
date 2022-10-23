#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    struct NODE *next;
    int data;
}NODE;

void swapNodeData(NODE *node1, NODE *node2){
    int temp;
    temp = node1 -> data;
    node1 ->data = node2 -> data;
    node2 ->data = temp;
}

void bubbleSort(NODE *start, int check_data){
    NODE *curr = malloc(sizeof(NODE));;
    curr = start;

    curr -> data = 0;
    curr = curr -> next;

    for (int i = 0; i< check_data; i++){
        if(curr->next == NULL)break;
        for (int j =0; j < check_data-1-i; j++){
            if(curr -> data > curr -> next -> data){
                swapNodeData(curr, curr -> next);
            }
            curr = curr -> next;
        }
        curr = start -> next;
    }
}

void popleft(NODE *target){
    NODE *temp = malloc(sizeof(NODE));
    temp = target -> next;
    target->next = temp -> next;
}

void addNode(NODE *target, int newData){
    NODE *newNode = malloc(sizeof(NODE));
    newNode -> next = target -> next;      
    newNode -> data = newData;   
    target -> next = newNode;        
}  

int main(){
    int num01, num02, num03, num04, num05, i; //입력 받을을 사용할 변수 
    char start[5] = "temp";                    //처음 헤더 위치를 표현 할 문구 
    
    NODE *head = malloc(sizeof(NODE)); // 초기세팅(노드 빵개)
    head -> next = NULL;                                
    
    scanf("%d%d%d%d%d", &num01, &num02, &num03, &num04, &num05); // 입력 받는 곳
    int* arr[] = {&num01, &num02, &num03, &num04, &num05};
    printf("--------------------\n");

    for(i = 0; i <= 4; i++){            // 노드 생성(입력받은 순서대로)
        addNode(head, *arr[i]);
    }

    printf("%s\n", start);             // 0포인트 표시

    bubbleSort(head, head -> data);

    popleft(head);                       //삭제

    NODE *hong = head -> next;
    while (hong != NULL){
        printf("|\n");
        printf("%d \n", hong -> data);
        
        hong = hong -> next;
    }

    hong = head -> next;
    while (hong !=NULL){
        NODE *next = hong -> next;
        free(hong);
        hong = next;
    }

    return 0;
}
