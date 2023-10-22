

//문제 4
//문자열을 두 개 입력 받아서 먼저 입력받은 문자열에서 나중에 입력받은 문자열의 위치를 검색하는 함수를 만들어보세요.만일 없다면 - 1 을 리턴하고 있다면 그 위치를 리턴합니다. (난이도 : 中)

//예를 들어먼저 처음 입력한 것이 I_am_a_boy 이고, 나중에 입력한 것이 am 이였다면 컴퓨터는 I_am_a_boy 에서 am 의 위치를 찾는다.이 경우에는 am 의 위치는 2 (처음에서 세번째) 이므로 2 를 리턴한다.만일 am 이라는 문자열이 없다면 - 1 을 리턴한다.

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
		std::cout << "찾는 문자열이 없습니다." << std::endl;
	}
	else
	{
		std::cout << "찾는 문자열은 " << result << "번에 있습니다." << std::endl;
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