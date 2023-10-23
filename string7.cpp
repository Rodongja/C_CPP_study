//���� 5
//���� ���� ���α׷��� �����ô�.���α׷����� ������ ���� ��ɵ��� �����Ǿ� �־�� �մϴ�. (���̵� : ߾)

//å�� ���� �߰��ϴ� ���(å�� �� ������ 100 ���̶� ����.�� ��, �� å�� ������ ����, ������ �̸�, ���ǻ�� �Ѵ�)

//å�� ������ �˻��ϸ� �� å�� ������ ���;� �Ѵ�.

//���� ���������� ����, ���ǻ� �˻� ����� �־�� �Ѵ�.

//å�� ������ ���.

//å�� �ݳ��ϴ� ���

#include <iostream>

void library(int *idx, int *book_number, char(*name)[20], char (*author)[20], char (*publisher)[20], bool* isBorrow);
void add_book(int *book_number, char(*name)[20], char(*author)[20], char(*publisher)[20], bool* isBorrow);
void add(int *book_number, char(*name)[20], char(*author)[20], char(*publisher)[20], bool* isBorrow);
void borrow_book(int *book_number, bool* isBorrow);
void return_book(int *book_number, bool* isBorrow);
void search_book(int *book_number, char(*name)[20], char(*author)[20], char(*publisher)[20], bool* isBorrow);


int main() {
	int idx = 1;
	int book_number = 0;
	bool isBorrow[100] = {false};
	char name[100][20] = {};
	char author[100][20] = {};
	char publisher[100][20] = {};

	while (idx != 0)
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
		library(&idx, &book_number, name, author, publisher, isBorrow);
	}
} 

void library(int* idx, int* book_number, char(*name)[20], char(*author)[20], char(*publisher)[20], bool* isBorrow)
{
	switch (*idx)
	{
	case 1 :
		add_book(book_number, name, author, publisher, isBorrow);
		break;
	case 2:
		borrow_book(book_number, isBorrow);
		break;
	case 3:
		return_book(book_number, isBorrow);
		break;
	case 4:
		search_book(book_number, name, author, publisher, isBorrow);
		break;
	}
}

void add_book(int* book_number, char(*name)[20], char(*author)[20], char(*publisher)[20], bool* isBorrow)
{
	std::cout << "�߰��� å�� ��ȣ�� �����ּ���" << std::endl;
	std::cin >> *book_number;

	if (name[*book_number][0] != 0)
	{
		// ���� ��ȣ�� å�� ������
		std::cout << "�̹� ���� ��ȣ�� å�� �ֽ��ϴ�. ���� ��ȣ�� ���� ���ðڽ��ϱ�? 1:YES/0:NO" << std::endl;
		int YoN = 0;
		std::cin >> YoN;
		if (1 == YoN)
		{
			add(book_number, name, author, publisher, isBorrow);
		}
		else if(0 == YoN)
		{
			std::cout << "���� �ܰ�� ���ư��ϴ�." << std::endl;
		}
		else
		{
			std::cout << "�߸��� ���� �Է��Ͽ� ���� �ܰ�� ���ư��ϴ�." << std::endl;
		}
	}
	else
	{
		add(book_number, name, author, publisher, isBorrow);
	}
}

void add(int* book_number, char(*name)[20], char(*author)[20], char(*publisher)[20], bool* isBorrow)
{
	if (*book_number >= 100) {
		std::cout << "�� �̻� å�� �߰��� �� �����ϴ�" << std::endl;
		return;
	}

	std::cout << "å�� �̸��� �Է��ϼ���" << std::endl;
	std::cin.ignore(); // ������ ������������ �𸣴� '\n' ���ڸ� ����� ����
	std::cin.getline(name[*book_number], 20);

	std::cout << "å�� ���ڸ� �Է��ϼ���" << std::endl;
	std::cin.getline(author[*book_number], 20);

	std::cout << "å�� ���ǻ縦 �Է��ϼ���" << std::endl;
	std::cin.getline(publisher[*book_number], 20);

	isBorrow[*book_number] = false;

	std::cout << "�Է��� �Ϸ�Ǿ����ϴ�." << std::endl;

}


void borrow_book(int* book_number, bool* isBorrow)
{
	std::cout << "������ ���� å�� ��ȣ�� �Է��ϼ���" << std::endl;
	std::cin >> *book_number;

	if (isBorrow[*book_number] == true)
	{
		std::cout << "�̹� �뿩���� �����Դϴ�" << std::endl;
	}
	else if (isBorrow[*book_number] == NULL)
	{
		std::cout << "�������� �ʴ� ��ȣ�Դϴ�" << std::endl;
	}
	else
	{
		isBorrow[*book_number = true];
		std::cout << "å�� ���������� �뿩�Ǿ����ϴ�" << std::endl;
	}
}

void return_book(int* book_number, bool* isBorrow)
{
	std::cout << "�ݳ��� å�� ��ȣ�� �Է��ϼ���" << std::endl;
	std::cin >> *book_number;

	if (isBorrow[*book_number] == false)
	{
		std::cout << "�뿩������ ���� �����Դϴ�" << std::endl;
	}
	else if (isBorrow[*book_number == NULL])
	{
		std::cout << "�������� �ʴ� ��ȣ�Դϴ�." << std::endl;
	}
	else
	{
		isBorrow[*book_number] = false;
		std::cout << "���������� �ݳ��Ǿ����ϴ�" << std::endl;
	}
}

void search_book(int* book_number, char(*name)[20], char(*author)[20], char(*publisher)[20], bool* isBorrow)
{
	char name_str[20] = {};
	std::cout << "ã����� å�� ������ �Է��ϼ���" << std::endl;
	std::cin >> name_str;
	bool isHere = false;
	for (int i = 0; i <= 100; ++i)
	{
		if (std::strcmp(name_str,name[i]) == 0)
		{
			if (isBorrow[i] == true)
			{
				std::cout << "ã���ô� å�� " << i << "���� �ְ� ���� �뿩���Դϴ�" << std::endl;
				isHere = true;
				break;
			}
			else
			{
				std::cout << "ã���ô� å�� " << i << "���� �ְ� ���� �뿩���� �ƴմϴ�" << std::endl;
				isHere = true;
				break;
			}
		}
	}
	if (isHere == false)
	{
		std::cout << "ã���ô� å�� �����ϴ�" << std::endl;
	}
}