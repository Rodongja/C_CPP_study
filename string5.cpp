



//���� 3
//�� ���� ���ڿ��� �Է� �޾Ƽ� ���ٸ� "����", �ٸ��� "�ٸ���" ��� ����ϴ� �Լ��� ��������. (���̵� : ��)

#include <iostream>

int compare(char* str1, char* str2);
int char_length(char* str);

int main()
{
	char str1[100] = "abcde";
	char str2[100] = "abcdef";

	if (compare(str1, str2) == 1)
	{
		std::cout << "����";
	}
	else
	{
		std::cout << "�ٸ���";
	}
	return 0;
}

int compare(char* str1, char* str2)
{
	if (char_length(str1) == char_length(str2))
	{
		for (int i = 0; i < char_length(str1); ++i)
		{
			if (str1[i] != str2[i])
			{
				return 0;
			}
		}
		return 1;
	}
	else
	{
		return 0;
	}

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