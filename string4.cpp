
//���� 2
//���̰� �ִ� 100 �� ���ڿ��� �Է� �޾Ƽ� �ҹ��ڴ� �빮�ڷ�, �빮�ڴ� �ҹ��ڷ� ����ϴ� �Լ��� ��������. (���̵� : ��) ���� �� "aBcDE" �Է�-- > "AbCde" ���

#include <iostream>
void change(char* str);
int char_length(char* str);
void cout(char* str);

int main() {
	char str[100] = "aBcDE";
	change(str);

	return 0;
}

void change(char* str)
{
	for (int i = 0; i < char_length(str); ++i)
	{
		if (str[i] > 96)
		{
			str[i] -= 32;
		}
		else
		{
			str[i] += 32;
		}
	}
	cout(str);
	return ;
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

void cout(char* str)
{
	for (int i = 0; i < char_length(str); ++i)
	{
		std::cout << str[i];
	}
}