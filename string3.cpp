


//문제 1
//길이가 최대 100 인 문자열을 하나 입력 받아서 문자열을 역순으로 출력하는 함수를 만들어보세요. (난이도 : 下) 예를 들어서 "abcde" 입력-- > "edcba" 출력


#include <iostream>
// 반전 함수
char reverse(char* str);
// 길이 함수
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
