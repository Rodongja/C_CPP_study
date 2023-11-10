#include <stdio.h>
#include <stdlib.h>
struct Node* InsertNode(struct Node* current, int data);
struct Node* DummyNode();
void DestroyNode(struct Node* destroy, struct Node* head, Node* tail);
void PrintNodeFrom(struct Node* from);
int CountNode(Node* head);
bool HasNode(Node* head, Node* tail, struct Node* search);

struct Node {
        struct Node* nextNode; /* ���� ��带 ����Ű�� �κ� */
        struct Node* prevNode; /* ���� ��带 ����Ű�� �κ� */
        int data;              /* ������ */
};

Node* head, * dummy, * tail;

int main() {
    head = (Node*)malloc(sizeof(Node)); // head �޸� �Ҵ�
    dummy = (Node*)malloc(sizeof(Node)); //����4 dummy �޸� �Ҵ�
    tail = (Node*)malloc(sizeof(Node)); // tail �޸� �Ҵ�

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
    /* Node 2 �ڿ� Node4 �ֱ� */
    struct Node* Node4 = InsertNode(Node2, 400);
    count = CountNode(Node1);
    PrintNodeFrom(Node1);
    
    //����1
    printf("node�� �� ������ %d�Դϴ�. \n", count);

    //����2
    search = HasNode(Node1, Node4, Node2);
    if (true == search)
    {
        printf("ã�� data�� �����մϴ�. \n");
    }
    else
    {
        printf("ã�� data�� �������� �ʽ��ϴ�. \n");
    }

    //����3
    DestroyNode(Node2, Node1, Node4);
    PrintNodeFrom(Node1);
    return 0;
}



void PrintNodeFrom(struct Node* from) {
    /* from �� NULL �� �� ����,
       �� �� �κп� ������ �� ���� ��� */
    while (from->data != NULL) {
        printf("����� ������ : %d \n", from->data);
        from = from->nextNode;
    }
}
/* current ��� ��� �ڿ� ��带 ���� ����� �ִ� �Լ� */
struct Node* InsertNode(struct Node* current, int data) {
    /* current ��尡 ����Ű�� �ִ� ���� ��尡 after �̴� */
    struct Node* after = current->nextNode;

    /* ���ο� ��带 �����Ѵ� */
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    /* �� ��忡 ���� �־��ش�. */
    newNode->data = data;
    newNode->nextNode = after;
    newNode->prevNode = current;

    /* current �� ���� newNode �� ����Ű�� �ȴ� */
    current->nextNode = newNode;

    return newNode;
} /* ���õ� ��带 �ı��ϴ� �Լ� */
Node* DummyNode()
{
    return nullptr;
}
void DestroyNode(struct Node* destroy, struct Node* head, struct Node* tail)
{ 
    /* ���� ��带 ����ų ������*/
    struct Node* next = head;
    /* head �� �ı��Ϸ� �Ѵٸ� */
    if (destroy == head) 
    {
        free(destroy);
        return;
    }/* ���� next->data �� NULL �̸� ���� */
    while (next->data) 
    { /* ���� next ���� ��尡 destroy ��� next �� destory �� ���*/
        if (next->nextNode == destroy) 
        { /* ���� next �� ���� ���� destory ���ƴ϶� destroy �� ���� ��尡 �ȴ�. */
            // next ����� ������ �����ϸ�
            if (next->nextNode->nextNode)
            {
                //������(���� next->nextNode �۾��� ���̶� next�� ���� ��带 ����Ŵ)�� �ּҸ� next�� �����ּ��� prevNode�� ����
                next->nextNode->prevNode = next;
            }
            next->nextNode = destroy->nextNode;
        } /* next �� ���� ��带 ����Ų��. */
        next = next->nextNode;
    }
    free(destroy);
}

//���� 1
//head �� �־��� �� ��ü ����� ������ ���� int CountNode(Node * head) �Լ��� �ۼ��Ͻÿ�(���̵� : ��)

//����� ������ ���� �Լ�
int CountNode(struct Node* head) {
    int count = 0;
    while (head->data != NULL) {
        count++;
        head = head->nextNode;
    }
    return count;
}

//���� 2
//head �� ���ϴ� ��尡 �־��� �� Ư�� data �� ������ ��尡 �����ϴ��� Ȯ���ϴ� bool HasNode(Node * head) �Լ��� �ۼ��ϼ���.
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

//���� 3
//�ռ� �����Ͽ��� Node �� �������� '�� ��带 ����Ű�� ���' �� ���� �� �� ���ٴ� ���̴�.�̸� �����ϱ� ����
//struct Node {
//    int data;              /* ������ */
//    struct Node* nextNode; /* ���� ��带 ����Ű�� �κ� */
//    struct Node* prevNode; /* ���� ��带 ����Ű�� �κ� */
//};
//�������� ��带 ������ �ռ� �ۼ��ߴ� ��� �Լ����� �ٽ� �ۼ��غ��ÿ�(���̵� : ��)

//���� 4
//���� ���� ������ ��带 �����Ͽ� head �� �� ������ ����� tail �� prevNode �� ����Ű�� ������ ��带 �����ÿ�.
//�ٽ� ���� ����� ó���� ���� ���ٰ� �� �� �ִ�.�̷��� ������ ��带 �̿��Ͽ� �ռ� �����Ͽ��� ��� �Լ��� �����غ��ÿ�(���̵� : ��߾)