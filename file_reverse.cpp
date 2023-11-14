#include <stdio.h>
#include <iostream>

int main()
{
	FILE* a;
	FILE* b;
	fopen_s(&a, "a.text", "r");
	char buf[20];  // 내용을 입력받을 곳
	if (a == NULL) {
		printf("READ ERROR !! \n");
		return 0;
	}
	fgets(buf, 20, a);
	printf("입력받는 내용 : %s \n", buf);
	fopen_s(&b, "b.text", "w");
	if (b == NULL)
	{
		printf("Write Error!!\n");
		return 0;
	}

	fputs(buf, b);
	fclose(a);
	fclose(b);

	return 0;
}