
//���� 1
//����ڷ� ���� 5 ���� �л��� ����, ����, ���� ������ �Է� �޾Ƽ� ����� ���� ���� ��� ���� ����� ���� ���� ������� ���ĵǾ� ����ϵ��� �ϼ���.
//Ư��, ����� �������� ��� �̻��� ��� ������ '�հ�', �ƴ� ����� '���հ�' �� ����ϰ� �غ�����(���̵� : ��߾).

#include <iostream>

void func(int (*arr)[3]);

int main() {


	int arr[5][3] = {};

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << "������ �Է��ϼ��� : " << std::endl;
			std::cin >> arr[i][j];
			if (arr[i][j] > 100 || arr[i][j] < 0)
			{
				std::cout << "������ �ٽ� �Է��ϼ���" << std::endl;
				j--;
			}
		}
	}

	func(arr);

	return 0;
}

void func(int (*arr)[3])
{
	int class_avg = 0;
	int row_avg = 0;
	int student_avg[5] = {};
	int top = 0;

	// �л� ������ ���
	for (int i = 0; i < 5; ++i)
	{
		int sum_arr = 0;
		for (int j = 0; j < 3; ++j)
		{
			sum_arr += arr[i][j];
		}
		student_avg[i] = (sum_arr/3);
	}	

	// �� ��ü�� ���
	for (int i = 0; i < 5; ++i)
	{
		class_avg += student_avg[i];
	}
	class_avg /= 5;

	// �������� ����
	int temp = 0;
	int j = 0;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = i + 1; j < 5; ++j)
		{
			if (student_avg[i] < student_avg[j])
			{
				temp = student_avg[j];
				student_avg[j] = student_avg[i];
				student_avg[i] = temp;
			}
		}
	}

	std::cout << "�� ��� : " << class_avg << "��" << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		if (class_avg < student_avg[i])
			std::cout << i+1 << "�� �л��� ��� : " << student_avg[i] << "�հ�" << std::endl;
		else
			std::cout << i+1 << "�� �л��� ��� : " << student_avg[i] << "���հ�" << std::endl;
	}
}