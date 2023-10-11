//문제 4
//계산기를 만들어보세요.사용자가 1 을 누르면 + , 2 를 누르면 - 와 같은 방식으로 해서 만들면 됩니다.
//물론 이전의 계산 결과는 계속 누적되어야 하고, 지우기 기능도 있어야 합니다. (물론 하나의 함수에 구현하는 것이 아니라 여러개의 함수로 분할해서 만들어야겠죠 ? ) (난이도 : 中)

#include <iostream>

void calculator(int a, int b, int sign);

int main()
{
	int sign = 0; // +1 -2 *3 /4 %5 종료0
	int a,b; //숫자
	int value; //값

	std::cout << "부호 코드를 입력하세요" << std::endl << "1 = +" << std::endl << "2 = -" << std::endl << "3 = *" << std::endl << "4 = /" << std::endl << "5 = %" << std::endl;
	std::cin >> sign;
	std::cout << "연산할 숫자를 입력하세요" << std::endl;
	std::cin >> a >> b;

	calculator(a, b, sign);

	return 0;
}

void calculator(int a, int b, int sign)
{
	int value = 0;
	switch (sign)
	{
	case 1: value = a + b;
		break;
	case 2: value = a - b;
		break;
	case 3: value = a * b;
		break;
	case 4: value = a / b;
		break;
	case 5: value = a % b;
		break;
	}
	std::cout << "값은 " << value << "입니다." << std::endl;

	std::cout << "계산을 이어서 하시려면 부호코드와 값을 입력해주세요"
		<< std::endl << "종료 하시려면 0을 입력해주세요" << std::endl;
	std::cin >> sign;

	if (0 != sign)
	{
		a = value;
		std::cin >> b;
		calculator(a, b, sign);
	}
}