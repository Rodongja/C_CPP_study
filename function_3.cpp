//���� 3
//�ڱ� �ڽ��� ȣ���ϴ� �Լ��� �̿��ؼ� 1 ���� Ư���� �������� ���� ���ϴ� ���α׷��� ��������. (���̵� : ��)

#include <iostream>
#include <vector>

// i i+1 i+2 i+3 i+4

int mul(int num, int count, int imul);

int main()
{
	int num;//�Է��� ����
	int count = 0;//���� ����
	int imul = 1;//���� ��
	std::vector<int> mulvec = {};

	std::cout << "���� �Է��ϼ���" << std::endl;
	std::cin >> num;

	imul = mul(num,count,imul);
	std::cout << "�� : " << imul << std::endl;
	return 0;
}

int mul(int num, int count, int imul)
{
	if (num != count)
	{
		imul *= (count + 1);
		++count;
		mul(num, count,imul);
	}
	else {
		return imul;
	}
}