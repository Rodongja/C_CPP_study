#pragma once
#include <iostream>
#include <cstring>
#include <cmath>

struct book* insertBook(int data);
void removeBook(int iDestroy, struct book* head);
struct book* findBook(book* head, int target);
void library(int* idx, struct book* head);
void add_book(struct book* book);
void add(struct book* book, int i);
void borrow_book(struct book* book);
void return_book(struct book* book);
void search_book(struct book* head);

struct book {
	struct book* nextBook; /* 다음 노드를 가리키는 부분 */
	struct book* prevBook; /* 이전 노드를 가리키는 부분 */
	char name[20];
	char author[20];
	char publisher[20];
	int book_number;
	int isBorrow;
};
extern book* head, * dummy;