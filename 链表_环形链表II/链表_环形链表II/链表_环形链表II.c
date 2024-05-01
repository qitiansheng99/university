#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode* next;
}SLTNode;

//第二种方法，在快慢指针的相遇点将链表断开，使得问题变为求相交链表的交点


//第一种方法，运用数学知识，一个指针在快慢指针相遇点开始，一个指针在头结点开始，当两个指针相遇时，即使环形链表的头
struct ListNode* detectCycle(SLTNode* head)
{
    SLTNode* fast = head, * slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            SLTNode* meet = head;
            while (meet != slow)
            {
                meet = meet->next;
                slow = slow->next;
            }
            return meet;
        }
    }
    return NULL;
}


int main()
{
    SLTNode* plist = NULL;
    SLTNode* n1 = (SLTNode*)malloc(sizeof(SLTNode));
    SLTNode* n2 = (SLTNode*)malloc(sizeof(SLTNode));
    SLTNode* n3 = (SLTNode*)malloc(sizeof(SLTNode));
    SLTNode* n4 = (SLTNode*)malloc(sizeof(SLTNode));
    SLTNode* n5 = (SLTNode*)malloc(sizeof(SLTNode));
    n1->data = 1;
    n2->data = 2;
    n3->data = 3;
    n4->data = 4;
    n5->data = 5;
    plist = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;
    struct ListNode* pos = detectCycle(plist);
    printf("%p\n", pos);
    return 0;
}