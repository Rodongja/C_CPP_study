//문제 5
//이전 강좌에서 만들었던 도서 관리 프로그램을 동적 할당과 구조체를 이용하여 만들어보세요(난이도 : 中)

#include <iostream>
#include <cstring>
#include <cmath>
#include "library.h"

book* head, * dummy;
int main() {
	head = (book*)malloc(sizeof(book)); // head 메모리 할당
	dummy = (book*)malloc(sizeof(book)); //문제4 dummy 메모리 할당

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
		library(&idx, head);
	}
}