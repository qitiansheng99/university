#include<stdio.h>
#include<windows.h>
int main()
{
	system("color 0c");
	float a, x, y;
	for (y = 1.5f; y > -1; y -= 0.1f)
	{
		for (x = -1.5f; x < 1.5f; x += .05f)
		{
			a = x * x + y * y - 1;
			putchar(a * a * a - x * x * y * y * y < 0.0f ? 'x' : ' ');
		}
		Sleep(15);
		putchar('\n');
	}
	printf("\n\t\t\t祝侯思瑶天天开心\n");
	return 0;
}