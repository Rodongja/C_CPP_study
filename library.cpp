#include <iostream>
#include <cstring>
#include <cmath>
#include "library.h"


struct book* insertBook(int data) 
{
	book* newBook = (book*)malloc(sizeof(book));
	newBook->book_number = data; // data���� �ʱ�ȭ
	newBook->isBorrow = false; // isBurrow���� �ʱ�ȭ

	book* cur;
	cur = head->nextBook;
	while (cur->book_number != NULL)
	{
		cur = cur->nextBook;
	}

	book* prevBook = cur->prevBook;

	prevBook->nextBook = newBook;
	newBook->prevBook = prevBook;
	cur->prevBook = newBook;
	newBook->nextBook = cur;
	return newBook;
}

void removeBook(int iDestroy, struct book* head)
{
	struct book* destroy;
	destroy = findBook(head, iDestroy);
	/* ���� ��带 ����ų ������*/
	struct book* next = head;
	/* head �� �ı��Ϸ� �Ѵٸ� */
	if (iDestroy == head->book_number)
	{
		free(destroy);
		return;
	}/* ���� next->book_number �� NULL �̸� ���� */
	while (next->book_number)
	{ /* ���� next ���� ��尡 destroy ��� next �� destory �� ���*/
		if (next->nextBook == destroy)
		{ /* ���� next �� ���� ���� destory ���ƴ϶� destroy �� ���� ��尡 �ȴ�. */
			// next ����� ������ �����ϸ�
			if (next->nextBook->nextBook)
			{
				//������(���� next->nextBook �۾��� ���̶� next�� ���� ��带 ����Ŵ)�� �ּҸ� next�� �����ּ��� prevNode�� ����
				next->nextBook->prevBook = next;
			}
			next->nextBook = destroy->nextBook;
		} /* next �� ���� ��带 ����Ų��. */
		next = next->nextBook;
	}
	free(destroy);
}

struct book* findBook(book* head, int target) 
{
	book* current = dummy->nextBook;
	while (current->book_number > 0) 
	{
		if (current->book_number == target) 
		{
			return current;
		}
		current = current->nextBook;
	}
	if (current->book_number = 0)
	{
		return nullptr; // ã�� ���� ���
	}
}

int search_list(int data) {
	book* ptr;
	for (ptr = head; ptr; ptr = ptr->nextBook) {
		if (ptr->book_number == data) {    // data �߰�  
			return 1;
		}
	}
	return -1; // ������ �� �߰� 
}

void library(int* idx, struct book* head)
{
	switch (*idx)
	{
	case 1:
		add_book(head);
		break;
	case 2:
		borrow_book(head);
		break;
	case 3:
		return_book(head);
		break;
	case 4:
		search_book(head);
		break;
	}
}

void add_book(struct book* head)
{
	int i;
	std::cout << "�߰��� å�� ��ȣ�� �����ּ���" << std::endl;
	std::cin >> i;
	if (std::cin.fail()) {
		std::cout << "���ڷ� �Է����ּ���" << std::endl;
		std::cin.clear(); // �÷��׵��� �ʱ�ȭ �ϰ�
		std::cin.ignore(100, '\n'); // ���๮�ڰ� ���� �� ���� �����Ѵ�
		return;
	}
	if (i <= 0)
	{
		std::cout << "0 ������ ��ȣ�� å�� �߰��� �� �����ϴ�" << std::endl;
		return;
	}

	//ã�� ��ȣ�� �����ϸ�
	if (head = findBook(head, i))
	{
		std::cout << "�̹� ���� ��ȣ�� å�� �ֽ��ϴ�. ���� ��ȣ�� ���� ���ðڽ��ϱ�? 1:YES/0:NO" << std::endl;
		int YoN = 0;
		std::cin >> YoN;
		if (1 == YoN) 
		{
			add(head,i);
		}
		else if (0 == YoN) 
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
		add(head,i);
	}
}


void add(struct book* book, int i)
{
	book = insertBook(i);
	std::cout << "å�� �̸��� �Է��ϼ���" << std::endl;
	std::cin.ignore(); // ������ ������������ �𸣴� '\n' ���ڸ� ����� ����
	std::cin.getline(book->name, 20);

	std::cout << "å�� ���ڸ� �Է��ϼ���" << std::endl;
	std::cin.getline(book->author, 20);

	std::cout << "å�� ���ǻ縦 �Է��ϼ���" << std::endl;
	std::cin.getline(book->publisher, 20);

	std::cout << "�Է��� �Ϸ�Ǿ����ϴ�." << std::endl;

}


void borrow_book(struct book* head)
{
	int i;
	std::cout << "������ ���� å�� ��ȣ�� �Է��ϼ���" << std::endl;
	std::cin >> i;

	struct book* borbook;
	borbook = findBook(head, i);

	if (borbook == nullptr)
	{
		std::cout << "�������� �ʴ� ��ȣ�Դϴ�" << std::endl;
	}
	else if (borbook->isBorrow == 1)
	{
		std::cout << "�̹� �뿩���� �����Դϴ�" << std::endl;
	}
	else
	{
		borbook->isBorrow = 1;
		std::cout << "å�� ���������� �뿩�Ǿ����ϴ�" << std::endl;
	}
}

void return_book(struct book* head)
{
	int i;
	std::cout << "�ݳ��� å�� ��ȣ�� �Է��ϼ���" << std::endl;
	std::cin >> i;

	struct book* retbook;
	retbook = findBook(head, i);

	if (retbook == nullptr)
	{
		std::cout << "�������� �ʴ� ��ȣ�Դϴ�." << std::endl;
	}
	else if (retbook->isBorrow == 0)
	{
		std::cout << "�뿩������ ���� �����Դϴ�" << std::endl;
	}
	else
	{
		retbook->isBorrow = 0;
		std::cout << "���������� �ݳ��Ǿ����ϴ�" << std::endl;
	}
}

void search_book(struct book* head)
{
	int idx = 0;
	std::cout << "ã������ ���ָ� �����ϼ���" << std::endl;
	std::cout << "1 : å �������� ã��" << std::endl;
	std::cout << "2 : �۰� �̸����� ã��" << std::endl;
	std::cout << "3 : ���ǻ� �̸����� ã��" << std::endl;
	std::cin >> idx;
	
	struct book* current;
		/* from �� NULL �� �� ����, �� �� �κп� ������ �� ���� ��� */
	current = dummy->nextBook;
	if (idx == 1)
	{
		char name_str[20] = {};
		std::cout << "ã����� å�� ������ �Է��ϼ���" << std::endl;
		std::cin.ignore();
		std::cin.getline(name_str, 20);
		bool isHere = false;
		while (current->isBorrow != -1)
		{
			if (strstr(current->name, name_str) /*std::strcmp(name_str, name[i]) == 0*/)
			{
				if (current->isBorrow)
				{
					std::cout << "ã���ô� å�� �̸��� " << current->name << "�̰� " << current->book_number << "���� ������ ���� �뿩���Դϴ�" << std::endl;
					isHere = true;
				}
				else
				{
					std::cout << "ã���ô� å�� �̸��� " << current->name << "�̰� " << current->book_number << "���� ������ ���� �뿩���� �ƴմϴ�" << std::endl;
					isHere = true;
				}
			}
			current = current->nextBook;
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

		while (current->isBorrow != -1)
		{
			if (strstr(current->author, author_str) /*std::strcmp(author_str, author[i]) == 0*/)
			{
				if (current->isBorrow)
				{
					std::cout << "ã���ô� å�� �̸��� " << current->name << "�̰� " << current->book_number << "���� ������ ���� �뿩���Դϴ�" << std::endl;
					isHere = true;
				}
				else
				{
					std::cout << "ã���ô� å�� �̸��� " << current->name << "�̰� " << current->book_number << "���� ������ ���� �뿩���� �ƴմϴ�" << std::endl;
					isHere = true;
				}
			}
			current = current->nextBook;
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

		while (current->isBorrow != -1)
		{
			if (strstr(current->publisher, publisher_str) /*std::strcmp(publisher_str, publisher[i]) == 0*/)
			{
				if (current->isBorrow)
				{
					std::cout << "ã���ô� å�� �̸��� " << current->name << "�̰� " << current->book_number << "���� ������ ���� �뿩���Դϴ�" << std::endl;
					isHere = true;
				}
				else
				{
					std::cout << "ã���ô� å�� �̸��� " << current->name << "�̰� " << current->book_number << "���� ������ ���� �뿩���� �ƴմϴ�" << std::endl;
					isHere = true;
				}
			}
			current = current->nextBook;
		}
		if (isHere == false)
		{
			std::cout << "ã���ô� å�� �����ϴ�" << std::endl;
		}
	}
	else
	{
		std::cout << "�߸��� ���� �Է��ϼ̽��ϴ�" << std::endl;
		search_book(head);
	}
}
