//���� 6
//�����佺�׳׽��� ü�� �̿��ؼ� 1 ���� N ������ �Ҽ��� ���ϴ� ���α׷��� ��������. (���̵� : ��)

//����, 2���� �����Ͽ� ���ϴ� ���� ���� ��� �ڿ����� �����մϴ�.
//
//���� ó������ ���� ���� ���� ���� �����ϰ�, �� ���� �Ҽ��Դϴ�.�� �Ҽ��� ����� ��� ����� �۾��� �����մϴ�.
//
//������ �Ҽ��� ����� ��� ����� ����, �ش� �Ҽ��� ��� ��ġ�� �ִ� ���� ǥ���ϰų� ����ϴ�. (���� ���, 2�� �����ϸ� 2�� ����� ��� ����)
//
//���� ó������ ���� �������� ���� ���� �����ϰ�, �� ���� �Ҽ����� Ȯ���մϴ�.�� �Ҽ��� ����� ��� ����� �۾��� �ݺ��մϴ�.
//
//�� ������ �ݺ��Ͽ� ��� �Ҽ��� ã�� ������ ����մϴ�.���� ���� ��� ���� ó���� ������ �����ϸ�, �����ִ� ������ ��� �Ҽ��Դϴ�.

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<bool> eratosthenes(int num, std::vector<bool> prime_vec);
void fcout(std::vector<bool> prime_vec);

int main()
{
	int num = 0;
	std::cout << "���ڸ� �Է��ϼ���" << std::endl;
	std::cin >> num;
	
	// bool vector ����
	// 0�� �Ҽ��� �ƴ� 1�� �Ҽ���
	std::vector<bool> prime_vec = {};

	prime_vec = eratosthenes(num, prime_vec);
	fcout(prime_vec);
	

	return 0;
}

std::vector<bool> eratosthenes(int num, std::vector<bool> prime_vec)
{

	//1. N���� ��� ���� ����´�.
	for (int i = 0; i <= num; ++i)
	{
		prime_vec.push_back(1);
	}
	//1.5 0�� 1�� �Ҽ��� �ƴϹǷ� 0ó���Ѵ�.
	prime_vec[0] = 0;
	prime_vec[1] = 0;

	//2. ���� ������������ �� �߿��� ���� �������� ã�´�.
	//2.5 �������� �̿��Ͽ� ����ϸ� ������ ������� �����ϴ�.
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (prime_vec[i])
		{
			//2,3,5,7 �� ù ���¼Ҽ��̱� ������ j = i * 2�� �Ͽ� �Ѱ���
			for (int j = i * 2; j <= num; j += i)
			{
				prime_vec[j] = 0;
			}
		}
	}
	return prime_vec;
}

//��� �Լ�
void fcout(std::vector<bool> prime_vec)
{
	std::cout << "�Ҽ� ��� : ";
	for (int i = 0; i < prime_vec.size(); ++i)
	{
		if (1 == prime_vec[i])
		{
			std::cout << i << " ";
		}
	}
}