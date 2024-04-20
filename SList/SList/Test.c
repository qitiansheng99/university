#include"SList.h"
int main()
{
	SLTNode* plist=NULL;
	SLTPushBack(&plist, 5);
	SLTPushBack(&plist, 6);
	SLTPushBack(&plist, 7);
	SLTPushBack(&plist, 8);
	SLTPushFront(&plist,4);
	SLTPushFront(&plist,3);
	SLTPushFront(&plist,2);
	SLTPushFront(&plist,1);
	SLTprintf(plist);
	SLTNode* pos = SLTFind(plist, 4);
	SLTErase(&plist, pos);
	SLTprintf(plist);
	SLTDestory(&plist);
	return 0;
}