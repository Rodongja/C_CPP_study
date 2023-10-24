//문제 5
//도서 관리 프로그램을 만들어봅시다.프로그램에는 다음과 같은 기능들이 구현되어 있어야 합니다. (난이도 : 上)

//책을 새로 추가하는 기능(책의 총 개수는 100 권이라 하자.이 때, 각 책의 정보는 제목, 저자의 이름, 출판사로 한다)

//책의 제목을 검색하면 그 책의 정보가 나와야 한다.

//위와 마찬가지로 저자, 출판사 검색 기능이 있어야 한다.

//책을 빌리는 기능.

//책을 반납하는 기능

#include <iostream>
#include <string.h>

void library(int *idx, int *book_number, char(*name)[20], char (*author)[20], char (*publisher)[20], int* isBorrow);
void add_book(int *book_number, char(*name)[20], char(*author)[20], char(*publisher)[20], int* isBorrow);
void add(int *book_number, char(*name)[20], char(*author)[20], char(*publisher)[20], int* isBorrow);
void borrow_book(int *book_number, int* isBorrow);
void return_book(int *book_number, int* isBorrow);
void search_book(int *book_number, char(*name)[20], char(*author)[20], char(*publisher)[20], int* isBorrow);


int main() {
	int idx = -1;
	int book_number = 0;
	int isBorrow[100] = {-1}; //초기값 -1, 미대여 0, 대여 1
	char name[100][20] = {};
	char author[100][20] = {};
	char publisher[100][20] = {};

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
		library(&idx, &book_number, name, author, publisher, isBorrow);
	}
} 

void library(int* idx, int* book_number, char(*name)[20], char(*author)[20], char(*publisher)[20], int* isBorrow)
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

void add_book(int* book_number, char(*name)[20], char(*author)[20], char(*publisher)[20], int* isBorrow)
{
	std::cout << "추가할 책의 번호를 적어주세요 (0~99)" << std::endl;
	std::cin >> *book_number;

	if (name[*book_number][0] != 0)
	{
		// 같은 번호의 책이 있을때
		std::cout << "이미 같은 번호의 책이 있습니다. 기존 번호를 덮어 쓰시겠습니까? 1:YES/0:NO" << std::endl;
		int YoN = 0;
		std::cin >> YoN;
		if (1 == YoN)
		{
			add(book_number, name, author, publisher, isBorrow);
		}
		else if(0 == YoN)
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
		add(book_number, name, author, publisher, isBorrow);
	}
}

void add(int* book_number, char(*name)[20], char(*author)[20], char(*publisher)[20], int* isBorrow)
{
	if (*book_number >= 100) {
		std::cout << "100 이상의 번호로 책을 추가할 수 없습니다" << std::endl;
		return;
	}

	std::cout << "책의 이름을 입력하세요" << std::endl;
	std::cin.ignore(); // 이전에 남아있을지도 모르는 '\n' 문자를 지우기 위해
	std::cin.getline(name[*book_number], 20);

	std::cout << "책의 저자를 입력하세요" << std::endl;
	std::cin.getline(author[*book_number], 20);

	std::cout << "책의 출판사를 입력하세요" << std::endl;
	std::cin.getline(publisher[*book_number], 20);

	isBorrow[*book_number] = 0;

	std::cout << "입력이 완료되었습니다." << std::endl;

}


void borrow_book(int* book_number, int* isBorrow)
{
	std::cout << "빌리고 싶은 책의 번호를 입력하세요" << std::endl;
	std::cin >> *book_number;

	if (isBorrow[*book_number] == 1)
	{
		std::cout << "이미 대여중인 도서입니다" << std::endl;
	}
	else if (isBorrow[*book_number] == -1)
	{
		std::cout << "존재하지 않는 번호입니다" << std::endl;
	}
	else
	{
		isBorrow[*book_number] = 1;
		std::cout << "책이 정상적으로 대여되었습니다" << std::endl;
	}
}

void return_book(int* book_number, int* isBorrow)
{
	std::cout << "반납할 책의 번호를 입력하세요" << std::endl;
	std::cin >> *book_number;

	if (isBorrow[*book_number] == 0)
	{
		std::cout << "대여중이지 않은 도서입니다" << std::endl;
	}
	else if (isBorrow[*book_number] == -1)
	{
		std::cout << "존재하지 않는 번호입니다." << std::endl;
	}
	else
	{
		isBorrow[*book_number] = 0;
		std::cout << "정상적으로 반납되었습니다" << std::endl;
	}
}

void search_book(int* book_number, char(*name)[20], char(*author)[20], char(*publisher)[20], int* isBorrow)
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
		std::cin >> name_str;
		bool isHere = false;

		for (int i = 0; i < 100; ++i)
		{
			if (strstr(name[i], name_str) /*std::strcmp(name_str, name[i]) == 0*/)
			{
				if (isBorrow[i])
				{
					std::cout << "찾으시는 책의 이름은 " << name[i] << "이고 " << i << "번에 있으며 현재 대여중입니다" << std::endl;
					isHere = true;
				}
				else
				{
					std::cout << "찾으시는 책의 이름은 " << name[i] << "이고 " << i << "번에 있으며 현재 대여중이 아닙니다" << std::endl;
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
		std::cin >> author_str;
		bool isHere = false;

		for (int i = 0; i <= 100; ++i)
		{
			if (strstr(author[i], author_str) /*std::strcmp(author_str, author[i]) == 0*/)
			{
				if (isBorrow[i])
				{
					std::cout << "찾으시는 책의 이름은 " << name[i] << "이고 " << i << "번에 있으며 현재 대여중입니다" << std::endl;
					isHere = true;
				}
				else
				{
					std::cout << "찾으시는 책의 이름은 " << name[i] << "이고 " << i << "번에 있으며 현재 대여중이 아닙니다" << std::endl;
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
		std::cin >> publisher_str;
		bool isHere = false;

		for (int i = 0; i <= 100; ++i)
		{
			if (strstr(publisher[i], publisher_str) /*std::strcmp(publisher_str, publisher[i]) == 0*/)
			{
				if (isBorrow[i])
				{
					std::cout << "찾으시는 책의 이름은 " << name[i] << "이고 " << i << "번에 있으며 현재 대여중입니다" << std::endl;
					isHere = true;
				}
				else
				{
					std::cout << "찾으시는 책의 이름은 " << name[i] << "이고 " << i << "번에 있으며 현재 대여중이 아닙니다" << std::endl;
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
		search_book(book_number, name, author, publisher, isBorrow);
	}
}
