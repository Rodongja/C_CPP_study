
//문제 2
//길이가 최대 100 인 문자열을 입력 받아서 소문자는 대문자로, 대문자는 소문자로 출력하는 함수를 만들어보세요. (난이도 : 下) 예를 들어서 "aBcDE" 입력-- > "AbCde" 출력

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