


//���� 1
//���̰� �ִ� 100 �� ���ڿ��� �ϳ� �Է� �޾Ƽ� ���ڿ��� �������� ����ϴ� �Լ��� ��������. (���̵� : ��) ���� �� "abcde" �Է�-- > "edcba" ���


#include <iostream>
// ���� �Լ�
char reverse(char* str);
// ���� �Լ�
int char_length(char* str);

int main() {
	char str[100] = "abcdefg";
	reverse(str);
	return 0;
}

char reverse(char* str)
{
	for (int i = char_length(str); i >= 0; --i)
	{
		std::cout << str[i];
	}
	return 0;
}

int char_length(char* str)
{
	int i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return i;
}
