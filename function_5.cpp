//���� 5
//N �������� M �������� ��ȯ�ϴ� ���α׷��� ��������. (���̵� : ��)

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

	//n������ 10�������� ��ȯ
	int n; //��ȯ�� n����
	std::string num; //�Է°�
	int decimal = 0; //10���� ��ȯ��

	std::cout << "��ȯ�� ���� ������ �Է��ϼ���" << std::endl;
	std::cin >> n;
	std::cout << "��ȯ�� ���� �Է��ϼ���" << std:: endl;
	std::cin >> num;

	//n������ 10�������� ��ȯ
	decimal = decimal_func(num, n);
	std::cout << "10���� ��ȯ �� : " << decimal << std::endl;

	int m; //m���� ��ȯ��

	std::cout << "��ȯ�� ������ �Է��ϼ���" << std::endl;
	std::cin >> m;

	std::vector<int> value;

	//10������ m�������� ��ȯ
	value = trans_func(value, decimal, m);

	//vector �� ����
	std::reverse(value.begin(), value.end());

	//vector�� sstr��
	std::stringstream sstr(vec_to_str(value));

	//sstr�� str��
	std::string str = sstr.str();

	//���
	std::cout << m << "���� ��ȯ �� : ";
	for (int i = 0; i < str.length(); ++i)
	{
		char temp = str[i];
		std::cout  << temp;
	}

	return 0;
}

//n������ 10�������� ��ȯ
int decimal_func(std::string num, int n)
{
	int decimal = 0; //10���� ��ȯ��
	int a, b;

	for (int i = num.length() - 1; i >= 0; --i)
	{
		if (num[i] <= 57)
		{
			//���ڰ� 0~9��
			a = (num[i] - 48);
		}
		else
		{
			//���ڰ� 10�� �Ѿ��(10�������� Ŭ��)
			a = (num[i] - 87);
		}
		int c = num.length() - i - 1;
		b = pow(n, c);
		decimal += a * b;
	}
	return decimal;
}

//vector�� string���� ��ȯ
std::stringstream vec_to_str(std::vector<int> vector)
{
	int temp;
	std::stringstream ss;
	for (size_t i = 0; i < vector.size(); i++) {
		if (vector[i] > 10)//10���� �ʰ��Ҷ� 9�̻��� �� ǥ�� (a,b,c,d,e,f...)
		{
			temp = vector[i] + 87;
			ss << (char)temp; //�ƽ�Ű�ڵ� �ҹ��ڸ� �̿��� �Է�
		}
		else //10���� ������ �� ǥ��(0,1,2,3...9)
		{
			ss << vector[i];
		}
	}
	return ss;
}

// m���� ���
std::vector<int> trans_func(std::vector<int> value ,int decimal, int m)
{	
	// m���� ���
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