#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode* next;
}SLTNode;

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    int countA = 0, countB = 0;
    struct ListNode* tailA = headA, * tailB = headB;
    while (tailA->next)
    {
        countA++;
        tailA = tailA->next;
    }
    while (tailB->next)
    {
        countB++;
        tailB = tailB->next;
    }
    if (tailA != tailB)
    {
        return NULL;
    }
    if (countA > countB)
    {
        int step = countA - countB;
        while (step)
        {
            headA = headA->next;
            step--;
        }
        while (headA)
        {
            if (headA == headB)
            {
                break;
            }
            else
            {
                headA = headA->next;
                headB = headB->next;
            }
        }
    }
    else
    {
        int step = countB - countA;
        while (step)
        {
            headB = headB->next;
            step--;
        }
        while (headB)
        {
            if (headA == headB)
            {
                break;
            }
            else
            {
                headA = headA->next;
                headB = headB->next;
            }
        }
    }
    return headA;
}


int main()
{
    SLTNode* plist1 = NULL;
    SLTNode* plist2 = NULL;
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
    plist1 = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;
    struct ListNode* pos = getIntersectionNode(plist1, plist2);
    printf("%p\n", pos);
    return 0;
}