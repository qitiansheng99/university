#include"SList.h"
int main()
{
	SLTNode* plist=NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTprintf(plist);
	return 0;
}