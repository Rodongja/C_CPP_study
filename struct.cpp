//(������ ����)���� ���� ���α׷��������, ����ü�� �̿��� ���ô�.���� register_book �� ���� �Լ��� �̿��Ͽ� å�� ����غ��ô�. (���̵� : ��)

#include <iostream>
#include <cstring>

void library(int* idx, struct book_list *pbook);
void set_book(struct book_list* pbook,int i);
void add_book(struct book_list* pbook);
void add(struct book_list* pbook);
void borrow_book(struct book_list* pbook);
void return_book(struct book_list* pbook);
void search_book(struct book_list* pbook);

struct book_list {
	int book_number;
	int isBorrow;
	char name[20];
	char author[20];
	char publisher[20];
};

int main() {
	int idx = -1;
	struct book_list book[100];
	struct book_list* pbook[100];
	for (int i = 0; i < 100; ++i)
	{
		pbook[i] = &book[i];
		set_book(*pbook, i);
	}
	

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
		library(&idx, *pbook);
	}
}

void library(int* idx, struct book_list *pbook)
{
	switch (*idx)
	{
	case 1:
		add_book(pbook);
		break;
	case 2:
		borrow_book(pbook);
		break;
	case 3:
		return_book(pbook);
		break;
	case 4:
		search_book(pbook);
		break;
	}
}

void set_book(struct book_list* pbook,int i)
{
	pbook[i].isBorrow = -1;
	strcpy_s(pbook[i].name, "");
}

void add_book(struct book_list* pbook)
{
	int i;
	std::cout << "�߰��� å�� ��ȣ�� �����ּ��� (0~99)" << std::endl;
	std::cin >> i;
	pbook[i].book_number = i;
	if (pbook[i].isBorrow != -1) {
		// �̹� ���� ��ȣ�� å�� ������
		std::cout << "�̹� ���� ��ȣ�� å�� �ֽ��ϴ�. ���� ��ȣ�� ���� ���ðڽ��ϱ�? 1:YES/0:NO" << std::endl;
		int YoN = 0;
		std::cin >> YoN;
		if (1 == YoN) {
			add(&pbook[i]);
		}
		else if (0 == YoN) {
			std::cout << "���� �ܰ�� ���ư��ϴ�." << std::endl;
		}
		else {
			std::cout << "�߸��� ���� �Է��Ͽ� ���� �ܰ�� ���ư��ϴ�." << std::endl;
		}
	}
	// �ߺ� üũ

	else {
		add(&pbook[i]);
	}
}

void add(struct book_list* pbook)
{
	if (pbook->book_number >= 100) {
		std::cout << "100 �̻��� ��ȣ�� å�� �߰��� �� �����ϴ�" << std::endl;
		return;
	}
	else if (pbook->book_number < 0)
	{
		std::cout << "0 ������ ��ȣ�� å�� �߰��� �� �����ϴ�" << std::endl;
		return;
	}

	std::cout << "å�� �̸��� �Է��ϼ���" << std::endl;
	std::cin.ignore(); // ������ ������������ �𸣴� '\n' ���ڸ� ����� ����
	std::cin.getline(pbook->name, 20);

	std::cout << "å�� ���ڸ� �Է��ϼ���" << std::endl;
	std::cin.getline(pbook->author, 20);

	std::cout << "å�� ���ǻ縦 �Է��ϼ���" << std::endl;
	std::cin.getline(pbook->publisher, 20);

	pbook->isBorrow = 0;

	std::cout << "�Է��� �Ϸ�Ǿ����ϴ�." << std::endl;

}


void borrow_book(struct book_list* pbook)
{
	int i;
	std::cout << "������ ���� å�� ��ȣ�� �Է��ϼ���" << std::endl;
	std::cin >> i;

	if (pbook[i].isBorrow == -1)
	{
		std::cout << "�������� �ʴ� ��ȣ�Դϴ�" << std::endl;
	}
	else if (pbook[i].isBorrow == 1)
	{
		std::cout << "�̹� �뿩���� �����Դϴ�" << std::endl;
	}
	else
	{
		pbook[i].isBorrow = 1;
		std::cout << "å�� ���������� �뿩�Ǿ����ϴ�" << std::endl;
	}
}

void return_book(struct book_list* pbook)
{
	int i;
	std::cout << "�ݳ��� å�� ��ȣ�� �Է��ϼ���" << std::endl;
	std::cin >> i;

	if (pbook[i].isBorrow == -1)
	{
		std::cout << "�������� �ʴ� ��ȣ�Դϴ�." << std::endl;
	}
	else if (pbook[i].isBorrow == 0)
	{
		std::cout << "�뿩������ ���� �����Դϴ�" << std::endl;
	}
	else
	{
		pbook[i].isBorrow = 0;
		std::cout << "���������� �ݳ��Ǿ����ϴ�" << std::endl;
	}
}

void search_book(struct book_list* pbook)
{
	int idx = 0;
	std::cout << "ã������ ���ָ� �����ϼ���" << std::endl;
	std::cout << "1 : å �������� ã��" << std::endl;
	std::cout << "2 : �۰� �̸����� ã��" << std::endl;
	std::cout << "3 : ���ǻ� �̸����� ã��" << std::endl;
	std::cin >> idx;
	if (idx == 1)
	{
		char name_str[20] = {};
		std::cout << "ã����� å�� ������ �Է��ϼ���" << std::endl;
		std::cin.ignore();
		std::cin.getline(name_str,20);
		bool isHere = false;

		for (int i = 0; i < 100; ++i)
		{
			if (strstr(pbook[i].name, name_str) /*std::strcmp(name_str, name[i]) == 0*/)
			{
				if (pbook[i].isBorrow)
				{
					std::cout << "ã���ô� å�� �̸��� " << pbook[i].name << "�̰� " << i << "���� ������ ���� �뿩���Դϴ�" << std::endl;
					isHere = true;
				}
				else
				{
					std::cout << "ã���ô� å�� �̸��� " << pbook[i].name << "�̰� " << i << "���� ������ ���� �뿩���� �ƴմϴ�" << std::endl;
					isHere = true;
				}
			}
		}
		if (isHere == false)
		{
			std::cout << "ã���ô� å�� �����ϴ�" << std::endl;
		}
	}

	else if (idx == 2)
	{
		char author_str[20] = {};
		std::cout << "ã����� å�� �۰� �̸��� �Է��ϼ���" << std::endl;
		std::cin.ignore();
		std::cin.getline(author_str, 20);
		bool isHere = false;

		for (int i = 0; i <= 100; ++i)
		{
			if (strstr(pbook[i].author, author_str) /*std::strcmp(author_str, author[i]) == 0*/)
			{
				if (pbook[i].isBorrow)
				{
					std::cout << "ã���ô� å�� �̸��� " << pbook[i].name << "�̰� " << i << "���� ������ ���� �뿩���Դϴ�" << std::endl;
					isHere = true;
				}
				else
				{
					std::cout << "ã���ô� å�� �̸��� " << pbook[i].name << "�̰� " << i << "���� ������ ���� �뿩���� �ƴմϴ�" << std::endl;
					isHere = true;
				}
			}
		}
		if (isHere == false)
		{
			std::cout << "ã���ô� å�� �����ϴ�" << std::endl;
		}
	}

	else if (idx == 3)
	{
		char publisher_str[20] = {};
		std::cout << "ã����� å�� ���ǻ� �̸��� �Է��ϼ���" << std::endl;
		std::cin.ignore();
		std::cin.getline(publisher_str, 20);
		bool isHere = false;

		for (int i = 0; i <= 100; ++i)
		{
			if (strstr(pbook[i].publisher, publisher_str) /*std::strcmp(publisher_str, publisher[i]) == 0*/)
			{
				if (pbook[i].isBorrow)
				{
					std::cout << "ã���ô� å�� �̸��� " << pbook[i].name << "�̰� " << i << "���� ������ ���� �뿩���Դϴ�" << std::endl;
					isHere = true;
				}
				else
				{
					std::cout << "ã���ô� å�� �̸��� " << pbook[i].name << "�̰� " << i << "���� ������ ���� �뿩���� �ƴմϴ�" << std::endl;
					isHere = true;
				}
			}
		}
		if (isHere == false)
		{
			std::cout << "ã���ô� å�� �����ϴ�" << std::endl;
		}
	}

	else
	{
		std::cout << "�߸��� ���� �Է��ϼ̽��ϴ�" << std::endl;
		search_book(pbook);
	}
}

