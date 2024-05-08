#include"list.h"

void test1()
{
	LTNode* plist= LTNodeInit();
	ListPushBack(plist,1);
	ListPushBack(plist,2);
	ListPushBack(plist,3);
	ListPushBack(plist,4);
	LTNodePrint(plist);
	ListPopBack(plist);
	LTNodePrint(plist);
}

void test2()
{
	LTNode* plist = LTNodeInit();
	ListPushFront(plist,1);
	ListPushFront(plist,2);
	ListPushFront(plist,3);
	ListPushFront(plist,4);
	LTNodePrint(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	LTNodePrint(plist);
}

void test3()
{
	LTNode* plist = LTNodeInit();
	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);
	LTNodePrint(plist);
	LTNode* pos = ListFind(plist, 3);
	ListInsert(pos, 7);
	LTNodePrint(plist);
	pos = ListFind(plist, 4);
	ListErase(pos);
	LTNodePrint(plist);
	ListDestory(plist);
	plist = NULL;
}

int main()
{
	test3();
	return 0;
}