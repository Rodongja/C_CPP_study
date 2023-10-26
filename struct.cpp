//(이전에 만든)도서 관리 프로그램을만들되, 구조체를 이용해 봅시다.또한 register_book 과 같은 함수를 이용하여 책을 등록해봅시다. (난이도 : 下)

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

		std::cout << "원하는 기능을 선택하세요" << std::endl;
		std::cout << "1 : 새로운 책 추가하기" << std::endl;
		std::cout << "2 : 책 빌리기" << std::endl;
		std::cout << "3 : 책 반납하기" << std::endl;
		std::cout << "4 : 책 검색하기" << std::endl;
		std::cout << "0 : 종료" << std::endl;
		std::cin >> idx;
		if (0 == idx)
		{
			std::cout << "종료합니다";
			break;
		}
		else if (idx > 4 || idx < 0)
		{
			std::cout << "잘못된 값을 입력하여 종료합니다";
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
	std::cout << "추가할 책의 번호를 적어주세요 (0~99)" << std::endl;
	std::cin >> i;
	pbook[i].book_number = i;
	if (pbook[i].isBorrow != -1) {
		// 이미 같은 번호의 책이 존재함
		std::cout << "이미 같은 번호의 책이 있습니다. 기존 번호를 덮어 쓰시겠습니까? 1:YES/0:NO" << std::endl;
		int YoN = 0;
		std::cin >> YoN;
		if (1 == YoN) {
			add(&pbook[i]);
		}
		else if (0 == YoN) {
			std::cout << "이전 단계로 돌아갑니다." << std::endl;
		}
		else {
			std::cout << "잘못된 값을 입력하여 이전 단계로 돌아갑니다." << std::endl;
		}
	}
	// 중복 체크

	else {
		add(&pbook[i]);
	}
}

void add(struct book_list* pbook)
{
	if (pbook->book_number >= 100) {
		std::cout << "100 이상의 번호로 책을 추가할 수 없습니다" << std::endl;
		return;
	}
	else if (pbook->book_number < 0)
	{
		std::cout << "0 이하의 번호로 책을 추가할 수 없습니다" << std::endl;
		return;
	}

	std::cout << "책의 이름을 입력하세요" << std::endl;
	std::cin.ignore(); // 이전에 남아있을지도 모르는 '\n' 문자를 지우기 위해
	std::cin.getline(pbook->name, 20);

	std::cout << "책의 저자를 입력하세요" << std::endl;
	std::cin.getline(pbook->author, 20);

	std::cout << "책의 출판사를 입력하세요" << std::endl;
	std::cin.getline(pbook->publisher, 20);

	pbook->isBorrow = 0;

	std::cout << "입력이 완료되었습니다." << std::endl;

}


void borrow_book(struct book_list* pbook)
{
	int i;
	std::cout << "빌리고 싶은 책의 번호를 입력하세요" << std::endl;
	std::cin >> i;

	if (pbook[i].isBorrow == -1)
	{
		std::cout << "존재하지 않는 번호입니다" << std::endl;
	}
	else if (pbook[i].isBorrow == 1)
	{
		std::cout << "이미 대여중인 도서입니다" << std::endl;
	}
	else
	{
		pbook[i].isBorrow = 1;
		std::cout << "책이 정상적으로 대여되었습니다" << std::endl;
	}
}

void return_book(struct book_list* pbook)
{
	int i;
	std::cout << "반납할 책의 번호를 입력하세요" << std::endl;
	std::cin >> i;

	if (pbook[i].isBorrow == -1)
	{
		std::cout << "존재하지 않는 번호입니다." << std::endl;
	}
	else if (pbook[i].isBorrow == 0)
	{
		std::cout << "대여중이지 않은 도서입니다" << std::endl;
	}
	else
	{
		pbook[i].isBorrow = 0;
		std::cout << "정상적으로 반납되었습니다" << std::endl;
	}
}

void search_book(struct book_list* pbook)
{
	int idx = 0;
	std::cout << "찾으려는 범주를 선택하세요" << std::endl;
	std::cout << "1 : 책 제목으로 찾기" << std::endl;
	std::cout << "2 : 작가 이름으로 찾기" << std::endl;
	std::cout << "3 : 출판사 이름으로 찾기" << std::endl;
	std::cin >> idx;
	if (idx == 1)
	{
		char name_str[20] = {};
		std::cout << "찾고싶은 책의 제목을 입력하세요" << std::endl;
		std::cin.ignore();
		std::cin.getline(name_str,20);
		bool isHere = false;

		for (int i = 0; i < 100; ++i)
		{
			if (strstr(pbook[i].name, name_str) /*std::strcmp(name_str, name[i]) == 0*/)
			{
				if (pbook[i].isBorrow)
				{
					std::cout << "찾으시는 책의 이름은 " << pbook[i].name << "이고 " << i << "번에 있으며 현재 대여중입니다" << std::endl;
					isHere = true;
				}
				else
				{
					std::cout << "찾으시는 책의 이름은 " << pbook[i].name << "이고 " << i << "번에 있으며 현재 대여중이 아닙니다" << std::endl;
					isHere = true;
				}
			}
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

		for (int i = 0; i <= 100; ++i)
		{
			if (strstr(pbook[i].author, author_str) /*std::strcmp(author_str, author[i]) == 0*/)
			{
				if (pbook[i].isBorrow)
				{
					std::cout << "찾으시는 책의 이름은 " << pbook[i].name << "이고 " << i << "번에 있으며 현재 대여중입니다" << std::endl;
					isHere = true;
				}
				else
				{
					std::cout << "찾으시는 책의 이름은 " << pbook[i].name << "이고 " << i << "번에 있으며 현재 대여중이 아닙니다" << std::endl;
					isHere = true;
				}
			}
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

		for (int i = 0; i <= 100; ++i)
		{
			if (strstr(pbook[i].publisher, publisher_str) /*std::strcmp(publisher_str, publisher[i]) == 0*/)
			{
				if (pbook[i].isBorrow)
				{
					std::cout << "찾으시는 책의 이름은 " << pbook[i].name << "이고 " << i << "번에 있으며 현재 대여중입니다" << std::endl;
					isHere = true;
				}
				else
				{
					std::cout << "찾으시는 책의 이름은 " << pbook[i].name << "이고 " << i << "번에 있으며 현재 대여중이 아닙니다" << std::endl;
					isHere = true;
				}
			}
		}
		if (isHere == false)
		{
			std::cout << "찾으시는 책이 없습니다" << std::endl;
		}
	}

	else
	{
		std::cout << "잘못된 값을 입력하셨습니다" << std::endl;
		search_book(pbook);
	}
}

