//���� 5
//���� ���¿��� ������� ���� ���� ���α׷��� ���� �Ҵ�� ����ü�� �̿��Ͽ� ��������(���̵� : ��)

#include <iostream>
#include <cstring>
#include <cmath>
#include "library.h"

book* head, * dummy;
int main() {
	head = (book*)malloc(sizeof(book)); // head �޸� �Ҵ�
	dummy = (book*)malloc(sizeof(book)); //����4 dummy �޸� �Ҵ�

	head->nextBook = dummy;
	head->prevBook = head;
	dummy->nextBook = dummy;
	dummy->prevBook = dummy;
	dummy->book_number = NULL;
	dummy->isBorrow = -1;
	head->book_number = NULL;

	int idx = -1;
	while (0 != idx)
	{
		std::cout << "���ϴ� ����� �����ϼ���" << std::endl;
		std::cout << "1 : ���ο� å �߰��ϱ�" << std::endl;
		std::cout << "2 : å ������" << std::endl;
		std::cout << "3 : å �ݳ��ϱ�" << std::endl;
		std::cout << "4 : å �˻��ϱ�" << std::endl;
		std::cout << "0 : ����" << std::endl;
		std::cin >> idx;
		if (0 == idx)
		{
			std::cout << "�����մϴ�";
			break;
		}
		else if (idx > 4 || idx < 0)
		{
			std::cout << "�߸��� ���� �Է��Ͽ� �����մϴ�";
			break;
		}
		library(&idx, head);
	}
}