#include"list.h"

void test1()
{
	LTNode* plist= LTNodeInit();
	LTNodePushBack(plist,1);
	LTNodePushBack(plist,2);
	LTNodePushBack(plist,3);
	LTNodePushBack(plist,4);
	LTNodePrint(plist);
	LTNodePopBack(plist);
	LTNodePrint(plist);
}

int main()
{
	test1();
	return 0;
}