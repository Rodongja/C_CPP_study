#include <stdio.h>
#include <stdlib.h>
struct Node* InsertNode(struct Node* current, int data);
struct Node* DummyNode();
void DestroyNode(struct Node* destroy, struct Node* head, Node* tail);
void PrintNodeFrom(struct Node* from);
int CountNode(Node* head);
bool HasNode(Node* head, Node* tail, struct Node* search);

struct Node {
        struct Node* nextNode; /* 다음 노드를 가리키는 부분 */
        struct Node* prevNode; /* 이전 노드를 가리키는 부분 */
        int data;              /* 데이터 */
};

Node* head, * dummy, * tail;

int main() {
    head = (Node*)malloc(sizeof(Node)); // head 메모리 할당
    dummy = (Node*)malloc(sizeof(Node)); //문제4 dummy 메모리 할당
    tail = (Node*)malloc(sizeof(Node)); // tail 메모리 할당

    head->nextNode = dummy;
    head->prevNode = head;
    dummy->nextNode = dummy;
    dummy->prevNode = dummy;
    dummy->data = NULL;
    tail->nextNode = tail;
    tail->prevNode = dummy;

    int count = 0;
    bool search = false;
    struct Node* Node1 = InsertNode(dummy,100);
    struct Node* Node2 = InsertNode(Node1, 200);
    struct Node* Node3 = InsertNode(Node2, 300);
    /* Node 2 뒤에 Node4 넣기 */
    struct Node* Node4 = InsertNode(Node2, 400);
    count = CountNode(Node1);
    PrintNodeFrom(Node1);
    
    //문제1
    printf("node의 총 개수는 %d입니다. \n", count);

    //문제2
    search = HasNode(Node1, Node4, Node2);
    if (true == search)
    {
        printf("찾는 data가 존재합니다. \n");
    }
    else
    {
        printf("찾는 data가 존재하지 않습니다. \n");
    }

    //문제3
    DestroyNode(Node2, Node1, Node4);
    PrintNodeFrom(Node1);
    return 0;
}



void PrintNodeFrom(struct Node* from) {
    /* from 이 NULL 일 때 까지,
       즉 끝 부분에 도달할 때 까지 출력 */
    while (from->data != NULL) {
        printf("노드의 데이터 : %d \n", from->data);
        from = from->nextNode;
    }
}
/* current 라는 노드 뒤에 노드를 새로 만들어 넣는 함수 */
struct Node* InsertNode(struct Node* current, int data) {
    /* current 노드가 가리키고 있던 다음 노드가 after 이다 */
    struct Node* after = current->nextNode;

    /* 새로운 노드를 생성한다 */
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    /* 새 노드에 값을 넣어준다. */
    newNode->data = data;
    newNode->nextNode = after;
    newNode->prevNode = current;

    /* current 는 이제 newNode 를 가리키게 된다 */
    current->nextNode = newNode;

    return newNode;
} /* 선택된 노드를 파괴하는 함수 */
Node* DummyNode()
{
    return nullptr;
}
void DestroyNode(struct Node* destroy, struct Node* head, struct Node* tail)
{ 
    /* 다음 노드를 가리킬 포인터*/
    struct Node* next = head;
    /* head 를 파괴하려 한다면 */
    if (destroy == head) 
    {
        free(destroy);
        return;
    }/* 만일 next->data 가 NULL 이면 종료 */
    while (next->data) 
    { /* 만일 next 다음 노드가 destroy 라면 next 가 destory 앞 노드*/
        if (next->nextNode == destroy) 
        { /* 따라서 next 의 다음 노드는 destory 가아니라 destroy 의 다음 노드가 된다. */
            // next 노드의 다음이 존재하면
            if (next->nextNode->nextNode)
            {
                //현재노드(아직 next->nextNode 작업이 전이라 next는 현재 노드를 가리킴)의 주소를 next의 다음주소의 prevNode에 전달
                next->nextNode->prevNode = next;
            }
            next->nextNode = destroy->nextNode;
        } /* next 는 다음 노드를 가리킨다. */
        next = next->nextNode;
    }
    free(destroy);
}

//문제 1
//head 가 주어질 때 전체 노드의 개수를 세는 int CountNode(Node * head) 함수를 작성하시오(난이도 : 下)

//노드의 개수를 세는 함수
int CountNode(struct Node* head) {
    int count = 0;
    while (head->data != NULL) {
        count++;
        head = head->nextNode;
    }
    return count;
}

//문제 2
//head 와 원하는 노드가 주어질 때 특정 data 를 가지는 노드가 존재하는지 확인하는 bool HasNode(Node * head) 함수를 작성하세요.
bool HasNode(struct Node* head, struct Node* tail, struct Node* search)
{
    while (head) {
        if (head->data == search->data)
        {
            return true;
        }
        else
        {
            head = head->nextNode;
        }
    }
}

//문제 3
//앞서 구현하였던 Node 의 단점으로 '이 노드를 가리키는 노드' 를 쉽게 알 수 없다는 점이다.이를 보완하기 위해
//struct Node {
//    int data;              /* 데이터 */
//    struct Node* nextNode; /* 다음 노드를 가리키는 부분 */
//    struct Node* prevNode; /* 이전 노드를 가리키는 부분 */
//};
//형식으로 노드를 만들어보고 앞서 작성했던 모든 함수들을 다시 작성해보시오(난이도 : 中)

//문제 4
//위와 같은 형식의 노드를 개량하여 head 가 맨 마지막 노드인 tail 을 prevNode 로 가리키는 원형의 노드를 만들어보시오.
//다시 말해 노드의 처음과 끝이 없다고 볼 수 있다.이러한 형태의 노드를 이용하여 앞서 구현하였던 모든 함수를 구현해보시오(난이도 : 中上)