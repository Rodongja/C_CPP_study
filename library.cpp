#include <iostream>
#include <cstring>
#include <cmath>
#include "library.h"


struct book* insertBook(int data) 
{
	book* newBook = (book*)malloc(sizeof(book));
	newBook->book_number = data; // data값을 초기화
	newBook->isBorrow = false; // isBurrow값을 초기화

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
	/* 다음 노드를 가리킬 포인터*/
	struct book* next = head;
	/* head 를 파괴하려 한다면 */
	if (iDestroy == head->book_number)
	{
		free(destroy);
		return;
	}/* 만일 next->book_number 가 NULL 이면 종료 */
	while (next->book_number)
	{ /* 만일 next 다음 노드가 destroy 라면 next 가 destory 앞 노드*/
		if (next->nextBook == destroy)
		{ /* 따라서 next 의 다음 노드는 destory 가아니라 destroy 의 다음 노드가 된다. */
			// next 노드의 다음이 존재하면
			if (next->nextBook->nextBook)
			{
				//현재노드(아직 next->nextBook 작업이 전이라 next는 현재 노드를 가리킴)의 주소를 next의 다음주소의 prevNode에 전달
				next->nextBook->prevBook = next;
			}
			next->nextBook = destroy->nextBook;
		} /* next 는 다음 노드를 가리킨다. */
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
		return nullptr; // 찾지 못한 경우
	}
}

int search_list(int data) {
	book* ptr;
	for (ptr = head; ptr; ptr = ptr->nextBook) {
		if (ptr->book_number == data) {    // data 발견  
			return 1;
		}
	}
	return -1; // 데이터 미 발견 
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
	std::cout << "추가할 책의 번호를 적어주세요" << std::endl;
	std::cin >> i;
	if (std::cin.fail()) {
		std::cout << "숫자로 입력해주세요" << std::endl;
		std::cin.clear(); // 플래그들을 초기화 하고
		std::cin.ignore(100, '\n'); // 개행문자가 나올 때 까지 무시한다
		return;
	}
	if (i <= 0)
	{
		std::cout << "0 이하의 번호로 책을 추가할 수 없습니다" << std::endl;
		return;
	}

	//찾는 번호가 존재하면
	if (head = findBook(head, i))
	{
		std::cout << "이미 같은 번호의 책이 있습니다. 기존 번호를 덮어 쓰시겠습니까? 1:YES/0:NO" << std::endl;
		int YoN = 0;
		std::cin >> YoN;
		if (1 == YoN) 
		{
			add(head,i);
		}
		else if (0 == YoN) 
		{
			std::cout << "이전 단계로 돌아갑니다." << std::endl;
		}
		else 
		{
			std::cout << "잘못된 값을 입력하여 이전 단계로 돌아갑니다." << std::endl;
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
	std::cout << "책의 이름을 입력하세요" << std::endl;
	std::cin.ignore(); // 이전에 남아있을지도 모르는 '\n' 문자를 지우기 위해
	std::cin.getline(book->name, 20);

	std::cout << "책의 저자를 입력하세요" << std::endl;
	std::cin.getline(book->author, 20);

	std::cout << "책의 출판사를 입력하세요" << std::endl;
	std::cin.getline(book->publisher, 20);

	std::cout << "입력이 완료되었습니다." << std::endl;

}


void borrow_book(struct book* head)
{
	int i;
	std::cout << "빌리고 싶은 책의 번호를 입력하세요" << std::endl;
	std::cin >> i;

	struct book* borbook;
	borbook = findBook(head, i);

	if (borbook == nullptr)
	{
		std::cout << "존재하지 않는 번호입니다" << std::endl;
	}
	else if (borbook->isBorrow == 1)
	{
		std::cout << "이미 대여중인 도서입니다" << std::endl;
	}
	else
	{
		borbook->isBorrow = 1;
		std::cout << "책이 정상적으로 대여되었습니다" << std::endl;
	}
}

void return_book(struct book* head)
{
	int i;
	std::cout << "반납할 책의 번호를 입력하세요" << std::endl;
	std::cin >> i;

	struct book* retbook;
	retbook = findBook(head, i);

	if (retbook == nullptr)
	{
		std::cout << "존재하지 않는 번호입니다." << std::endl;
	}
	else if (retbook->isBorrow == 0)
	{
		std::cout << "대여중이지 않은 도서입니다" << std::endl;
	}
	else
	{
		retbook->isBorrow = 0;
		std::cout << "정상적으로 반납되었습니다" << std::endl;
	}
}

void search_book(struct book* head)
{
	int idx = 0;
	std::cout << "찾으려는 범주를 선택하세요" << std::endl;
	std::cout << "1 : 책 제목으로 찾기" << std::endl;
	std::cout << "2 : 작가 이름으로 찾기" << std::endl;
	std::cout << "3 : 출판사 이름으로 찾기" << std::endl;
	std::cin >> idx;
	
	struct book* current;
		/* from 이 NULL 일 때 까지, 즉 끝 부분에 도달할 때 까지 출력 */
	current = dummy->nextBook;
	if (idx == 1)
	{
		char name_str[20] = {};
		std::cout << "찾고싶은 책의 제목을 입력하세요" << std::endl;
		std::cin.ignore();
		std::cin.getline(name_str, 20);
		bool isHere = false;
		while (current->isBorrow != -1)
		{
			if (strstr(current->name, name_str) /*std::strcmp(name_str, name[i]) == 0*/)
			{
				if (current->isBorrow)
				{
					std::cout << "찾으시는 책의 이름은 " << current->name << "이고 " << current->book_number << "번에 있으며 현재 대여중입니다" << std::endl;
					isHere = true;
				}
				else
				{
					std::cout << "찾으시는 책의 이름은 " << current->name << "이고 " << current->book_number << "번에 있으며 현재 대여중이 아닙니다" << std::endl;
					isHere = true;
				}
			}
			current = current->nextBook;
		}
		if (isHere == false)
		{
			std::cout << "찾으시는 책이 없습니다" << std::endl;
		}
	}

	else if (idx == 2)
	{
		char author_str[20] = {};
		std::cout << "찾고싶은 책의 작가 이름을 입력하세요" << std::endl;
		std::cin.ignore();
		std::cin.getline(author_str, 20);
		bool isHere = false;

		while (current->isBorrow != -1)
		{
			if (strstr(current->author, author_str) /*std::strcmp(author_str, author[i]) == 0*/)
			{
				if (current->isBorrow)
				{
					std::cout << "찾으시는 책의 이름은 " << current->name << "이고 " << current->book_number << "번에 있으며 현재 대여중입니다" << std::endl;
					isHere = true;
				}
				else
				{
					std::cout << "찾으시는 책의 이름은 " << current->name << "이고 " << current->book_number << "번에 있으며 현재 대여중이 아닙니다" << std::endl;
					isHere = true;
				}
			}
			current = current->nextBook;
		}
		if (isHere == false)
		{
			std::cout << "찾으시는 책이 없습니다" << std::endl;
		}
	}

	else if (idx == 3)
	{
		char publisher_str[20] = {};
		std::cout << "찾고싶은 책의 출판사 이름을 입력하세요" << std::endl;
		std::cin.ignore();
		std::cin.getline(publisher_str, 20);
		bool isHere = false;

		while (current->isBorrow != -1)
		{
			if (strstr(current->publisher, publisher_str) /*std::strcmp(publisher_str, publisher[i]) == 0*/)
			{
				if (current->isBorrow)
				{
					std::cout << "찾으시는 책의 이름은 " << current->name << "이고 " << current->book_number << "번에 있으며 현재 대여중입니다" << std::endl;
					isHere = true;
				}
				else
				{
					std::cout << "찾으시는 책의 이름은 " << current->name << "이고 " << current->book_number << "번에 있으며 현재 대여중이 아닙니다" << std::endl;
					isHere = true;
				}
			}
			current = current->nextBook;
		}
		if (isHere == false)
		{
			std::cout << "찾으시는 책이 없습니다" << std::endl;
		}
	}
	else
	{
		std::cout << "잘못된 값을 입력하셨습니다" << std::endl;
		search_book(head);
	}
}
