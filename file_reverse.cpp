#include <stdio.h>
#include <iostream>

int main()
{
	FILE* a;
	FILE* b;
	fopen_s(&a, "a.text", "r");
	char buf[20];  // ������ �Է¹��� ��
	if (a == NULL) {
		printf("READ ERROR !! \n");
		return 0;
	}
	fgets(buf, 20, a);
	printf("�Է¹޴� ���� : %s \n", buf);
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