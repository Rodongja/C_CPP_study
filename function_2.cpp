//���� 2
//��Ŭ���� ȣ������ �̿��ؼ� N ���� ������ �ִ������� ���ϴ� �Լ��� ��������.��Ŭ���� ȣ������ �������� �𸣽Ŵٸ�, ���ͳ� �˻��� Ȱ���ϴ� ���� ��õ�մϴ�. (����� �޾Ƶ� �ſ�) (���̵� : ��߾)

#include <iostream>
#include <vector>
#include <algorithm>

// ������ ��� ����Լ�
int MOD(int x, int y);
int e_algorithm(std::vector<int> vec, int number_count);



int main() {

	int number_count = 0;// ���� ����
	int g_divisor; //�ִ�����

	std::cout << "���� ������ �Է��ϼ��� : " << std::endl;
	std::cin >> number_count;

	// ���� �����迭�� vector ����
	std::vector<int> euclid;

	
	for (int i = 0; i < number_count; ++i)
	{
		int number;
		std::cout << "���� �Է��ϼ��� : " << std::endl;
		// �Է��� �� number
		std::cin >> number;
		// euclid �迭�� number �Է�
		// ��������ڸ� �������� �ʾ� push_back���� ������ ����
		euclid.emplace_back(number);
	}

	// ��Ȱ�� ����� ���� ������ �� ����
	std::sort(euclid.rbegin(), euclid.rend());

	g_divisor = e_algorithm(euclid,number_count);

	std::cout << "�ִ����� : " << g_divisor << std::endl;


	
	return 0;
}

int MOD(int x, int y)
{
	int temp; //������
	int g_divisor; //�ִ�����
	temp = x % y;

	if (x % y != 0)
	{
		x = y;
		y = temp;
		//����Լ�
		MOD(x, y);
	}
	else {
		g_divisor = y;
		return g_divisor;
	}
}

int e_algorithm(std::vector<int> euclid, int number_count)
{
	// ��Ŭ���� ȣ����
	for (int i = 0; i < number_count-1; ++i)
	{
		int x, y;
		x = euclid[i];
		y = euclid[i + 1];

		MOD(x, y);
		int g_diviosr = MOD(x, y);
		return g_diviosr;
	}
}