

//���� 4
//���ڿ��� �� �� �Է� �޾Ƽ� ���� �Է¹��� ���ڿ����� ���߿� �Է¹��� ���ڿ��� ��ġ�� �˻��ϴ� �Լ��� ��������.���� ���ٸ� - 1 �� �����ϰ� �ִٸ� �� ��ġ�� �����մϴ�. (���̵� : ��)

//���� ������ ó�� �Է��� ���� I_am_a_boy �̰�, ���߿� �Է��� ���� am �̿��ٸ� ��ǻ�ʹ� I_am_a_boy ���� am �� ��ġ�� ã�´�.�� ��쿡�� am �� ��ġ�� 2 (ó������ ����°) �̹Ƿ� 2 �� �����Ѵ�.���� am �̶�� ���ڿ��� ���ٸ� - 1 �� �����Ѵ�.

#include <iostream>
int search(char* str1, char* str2);
int char_length(char* str);

int main()
{
	int result = 0;
	char str1[100] = "I_am_a_boy";
	char str2[100] = "am";

	result = search(str1,str2);
	if (-1 == result)
	{
		std::cout << "ã�� ���ڿ��� �����ϴ�." << std::endl;
	}
	else
	{
		std::cout << "ã�� ���ڿ��� " << result << "���� �ֽ��ϴ�." << std::endl;
	}

	return 0;
}

int search(char* str1, char* str2)
{
	int cl1 = char_length(str1);
	int cl2 = char_length(str2);
	for (int i = 0; i <= cl1; ++i)
	{
		if (str1[i] == str2[0])
		{
			for (int j = 0; j <= cl2; ++j)
			{
				if (str1[i + j] == str2[j])
				{
					continue;
				}
				else if (str2[j] == NULL)
				{
					return i;
				}
				else
				{
					break;
				}
			}
		}
	}
	return -1;;
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