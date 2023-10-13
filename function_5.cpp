//문제 5
//N 진법에서 M 진법으로 변환하는 프로그램을 만들어보세요. (난이도 : 中)

#include <iostream>
#include <string>
#include <sstream>
#include <math.h> 
#include <vector>
#include <algorithm>

int decimal_func(std::string num, int n);
std::stringstream vec_to_str(std::vector<int> vector);
std::vector<int> trans_func(std::vector<int> value, int decimal, int m);

int main() {

	//n진법을 10진법으로 변환
	int n; //변환전 n진법
	std::string num; //입력값
	int decimal = 0; //10진법 변환값

	std::cout << "변환할 수의 진법을 입력하세요" << std::endl;
	std::cin >> n;
	std::cout << "변환할 수를 입력하세요" << std:: endl;
	std::cin >> num;

	//n진법을 10진법으로 변환
	decimal = decimal_func(num, n);
	std::cout << "10진법 변환 값 : " << decimal << std::endl;

	int m; //m진법 변환값

	std::cout << "변환할 진법을 입력하세요" << std::endl;
	std::cin >> m;

	std::vector<int> value;

	//10진법을 m진법으로 변환
	value = trans_func(value, decimal, m);

	//vector 값 반전
	std::reverse(value.begin(), value.end());

	//vector를 sstr로
	std::stringstream sstr(vec_to_str(value));

	//sstr을 str로
	std::string str = sstr.str();

	//출력
	std::cout << m << "진법 변환 값 : ";
	for (int i = 0; i < str.length(); ++i)
	{
		char temp = str[i];
		std::cout  << temp;
	}

	return 0;
}

//n진법을 10진법으로 변환
int decimal_func(std::string num, int n)
{
	int decimal = 0; //10진법 변환값
	int a, b;

	for (int i = num.length() - 1; i >= 0; --i)
	{
		if (num[i] <= 57)
		{
			//숫자가 0~9면
			a = (num[i] - 48);
		}
		else
		{
			//숫자가 10을 넘어가면(10진수보다 클때)
			a = (num[i] - 87);
		}
		int c = num.length() - i - 1;
		b = pow(n, c);
		decimal += a * b;
	}
	return decimal;
}

//vector를 string으로 변환
std::stringstream vec_to_str(std::vector<int> vector)
{
	int temp;
	std::stringstream ss;
	for (size_t i = 0; i < vector.size(); i++) {
		if (vector[i] > 10)//10진법 초과할때 9이상의 수 표기 (a,b,c,d,e,f...)
		{
			temp = vector[i] + 87;
			ss << (char)temp; //아스키코드 소문자를 이용해 입력
		}
		else //10진법 이하의 수 표기(0,1,2,3...9)
		{
			ss << vector[i];
		}
	}
	return ss;
}

// m진법 계산
std::vector<int> trans_func(std::vector<int> value ,int decimal, int m)
{	
	// m진법 계산
	while (0 != decimal)
	{
		if (decimal >= m)
		{
			value.push_back(decimal % m);
			decimal /= m;
		}
		else
		{
			value.push_back(decimal);
			decimal /= m;
		}
	}
	return value;
}