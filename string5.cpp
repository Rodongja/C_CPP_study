



//문제 3
//두 개의 문자열을 입력 받아서 같다면 "같다", 다르면 "다르다" 라고 출력하는 함수를 만들어보세요. (난이도 : 下)

#include <iostream>

int compare(char* str1, char* str2);
int char_length(char* str);

int main()
{
	char str1[100] = "abcde";
	char str2[100] = "abcdef";

	if (compare(str1, str2) == 1)
	{
		std::cout << "같다";
	}
	else
	{
		std::cout << "다르다";
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