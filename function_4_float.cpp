//���� 4
//���⸦ ��������.����ڰ� 1 �� ������ + , 2 �� ������ - �� ���� ������� �ؼ� ����� �˴ϴ�.
//���� ������ ��� ����� ��� �����Ǿ�� �ϰ�, ����� ��ɵ� �־�� �մϴ�. (���� �ϳ��� �Լ��� �����ϴ� ���� �ƴ϶� �������� �Լ��� �����ؼ� �����߰��� ? ) (���̵� : ��)

#include <iostream>

void calculator(float a, float b, int sign);

int main()
{
	int sign = 0; // +1 -2 *3 /4 %5 ����0
	float a,b = 0.00f; //����

	std::cout << "��ȣ �ڵ带 �Է��ϼ���" << std::endl << "1 = +" << std::endl << "2 = -" << std::endl << "3 = *" << std::endl << "4 = /" << std::endl;
	std::cin >> sign;
	std::cout << "������ ���ڸ� �Է��ϼ���" << std::endl << "�Ҽ����� ���ڸ� ���� ǥ�õ˴ϴ�. " << std::endl;
	std::cin >> a >> b;

	calculator(a, b, sign);

	return 0;
}

void calculator(float a, float b, int sign)
{
	float value = 0.00f; //��
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
	}
	std::cout << std::fixed;
	std::cout.precision(4);
	std::cout << "���� " << value << "�Դϴ�." << std::endl;

	std::cout << "����� �̾ �Ͻ÷��� ��ȣ�ڵ�� ���� �Է����ּ���"
		<< std::endl << "���� �Ͻ÷��� 0�� �Է����ּ���" << std::endl;
	std::cin >> sign;

	if (0 != sign)
	{
		a = value;
		std::cin >> b;
		calculator(a, b, sign);
	}
}