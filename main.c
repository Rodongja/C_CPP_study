#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define max_line 256

struct BOOK {
    char book_name[30];
    char auth_name[30];
    char publ_name[30];
    int borrowed;
};
typedef struct BOOK BOOK;

char compare(char* str1, char* str2);
int register_book(BOOK* book_list, int* nth);
int search_book(BOOK* book_list, int total_num_book);
int borrow_book(BOOK* book_list);
int return_book(BOOK* book_list);
int print_book_list(BOOK* book_list, int total_num_book, int list_total_book);

int main() {
    int user_choice;        /* ������ ������ �޴� */
    int list_total_book;    /* �ִ� ���� �弭 �� */
    int num_total_book = 0; /* ���� å�� �� */

    char buf[20];
    char c;

    BOOK* book_list;
    FILE* fp;
    fopen_s(&fp,"C:\\Users\\legoh\\OneDrive\\���� ȭ��\\library\\book_list.txt", "r");


    if (fp == NULL) {
        //����Ʈ�� �������� ������ ���� ����
        printf("�������� �ִ� ���� �弭 ���� �������ּ��� : ");
        scanf_s("%d", &list_total_book, sizeof(list_total_book));
        getchar();//�Է¹��� ����;
        book_list = (BOOK*)malloc(sizeof(BOOK) * list_total_book);
        print_book_list(book_list, num_total_book, list_total_book);
    }
    else
    {
        char line[max_line];
        const char* cindex = " / ";
        int i = 0;
        //����Ʈ�� �����ϸ� ���� �ҷ�����
        printf("���� ������ �ҷ��ɴϴ�.\n");
        fgets(buf, 20, fp);
        list_total_book = atoi(buf);
        fgets(buf, 20, fp);
        num_total_book = atoi(buf);
        printf("�ִ� ���� �弭 �� : %d\n", list_total_book);
        book_list = (BOOK*)malloc(sizeof(BOOK) * list_total_book);
        printf("���� ���� �弭 �� : %d\n", num_total_book);
        
        for (i = 0; i < num_total_book; ++i)
        {
            fgets(book_list[i].book_name, max_line, fp);
            book_list[i].book_name[strlen(book_list[i].book_name) - 1] = '\0';//���๮�� ����
            fgets(book_list[i].auth_name, max_line, fp);
            book_list[i].auth_name[strlen(book_list[i].auth_name) - 1] = '\0';//���๮�� ����
            fgets(book_list[i].publ_name, 20, fp);
            book_list[i].publ_name[strlen(book_list[i].publ_name) - 1] = '\0';//���๮�� ����
            c = fgetc(fp);
            book_list[i].borrowed = c - 48;
            fgets(buf, max_line, fp);
        }

        fclose(fp);
    }

    while (1) {
        printf("���� ���� ���α׷� \n");
        printf("�޴��� �����ϼ��� \n");
        printf("1. å�� ���� �߰��ϱ� \n");
        printf("2. å�� �˻��ϱ� \n");
        printf("3. å�� ������ \n");
        printf("4. å�� �ݳ��ϱ� \n");
        printf("5. ���α׷� ���� \n");
        printf("6. å���� ������ book_list.txt �� ��� \n");

        printf("����� ������ : ");
        scanf_s("%d", &user_choice, sizeof(user_choice));
        getchar();//�Է¹��� ����;

        if (user_choice == 1) {
            /* å�� ���� �߰��ϴ� �Լ� ȣ�� */
            register_book(book_list, &num_total_book);
        }
        else if (user_choice == 2) {
            /* å�� �˻��ϴ� �Լ� ȣ�� */
            search_book(book_list, num_total_book);
        }
        else if (user_choice == 3) {
            /* å�� ������ �Լ� ȣ�� */
            borrow_book(book_list);
        }
        else if (user_choice == 4) {
            /* å�� �ݳ��ϴ� �Լ� ȣ�� */
            return_book(book_list);
        }
        else if (user_choice == 5) {
            /* ���α׷��� �����Ѵ�. */
            break;
        }
        else if (user_choice == 6) {
            print_book_list(book_list, num_total_book, list_total_book);
        }
    }

    free(book_list);
    return 0;
}

int print_book_list(BOOK* book_list, int total_num_book, int list_total_book) {
    FILE* fp;
    fopen_s(&fp, "C:\\Users\\legoh\\OneDrive\\���� ȭ��\\library\\book_list.txt", "w");
    int i;

    if (fp == NULL) {
        printf("��� ���� ! \n");
        return -1;
    }

    //�ִ� ���� �弭 ��
    fprintf(fp, "%d\n", list_total_book);
    //���� ���� �弭 ��
    fprintf(fp, "%d\n", total_num_book);
    //"å �̸�/���� �̸�/���ǻ�/�ݳ� ����"
    for (i = 0; i < total_num_book; i++) {
        fprintf(fp, "%s\n%s\n%s\n", book_list[i].book_name, book_list[i].auth_name, book_list[i].publ_name);
        if (book_list[i].borrowed == 0)
            fprintf(fp, "0\n");
        else
            fprintf(fp, "1\n");
    }

    fclose(fp);
}

/* å�� �߰��ϴ� �Լ�*/
int register_book(BOOK* book_list, int* nth) {
    printf("å�� �̸� : ");
    gets(book_list[*nth].book_name);
    printf("å�� ���� : ");
    gets(book_list[*nth].auth_name);
    printf("å�� ���ǻ� : ");
    gets(book_list[*nth].publ_name);
    book_list[*nth].borrowed = 0;
    (*nth)++;
    return 0;
}

/* å�� �˻��ϴ� �Լ� */
int search_book(BOOK* book_list, int total_num_book) {
    int user_input = 0; /* ������� �Է��� �޴´�. */
    int i;
    char user_search[30];
    printf("��� ������ �˻� �� ���ΰ���? \n");
    printf("1. å ���� �˻� \n");
    printf("2. ������ �˻� \n");
    printf("3. ���ǻ� �˻� \n");
    scanf_s("%d",&user_input,sizeof(user_input));
    getchar();//�Է¹��� ����;
    printf("�˻��� �ܾ �Է����ּ��� : ");
    scanf_s("%[^\n]s", &user_search, sizeof(user_search));//���� ���� �Է��� ���� %[^\n]s ���
    getchar();//�Է¹��� ����;
    printf("�˻� ��� \n");
    if (user_input == 1) {
        /* i �� 0 ���� num_total_book ���� ���鼭 ������ å ������ ����ڰ� �Է���
         * �˻���� ���ϰ� �ִ�. */
        for (i = 0; i < total_num_book; i++) {
            if (compare(book_list[i].book_name, user_search)) {
                printf("��ȣ : %d // å �̸� : %s // ������ : %s // ���ǻ� : %s \n", i,
                    book_list[i].book_name, book_list[i].auth_name,
                    book_list[i].publ_name);
            }
        }
    }
    else if (user_input == 2) {
        /* i �� 0 ���� num_total_book ���� ���鼭 ������ ������ �̸��� ����ڰ�
         * �Է��� �˻���� ���ϰ� �ִ�. */
        for (i = 0; i < total_num_book; i++) {
            if (compare(book_list[i].auth_name, user_search)) {
                printf("��ȣ : %d // å �̸� : %s // ������ : %s // ���ǻ� : %s \n", i,
                    book_list[i].book_name, book_list[i].auth_name,
                    book_list[i].publ_name);
            }
        }
    }
    else if (user_input == 3) {
        /* i �� 0 ���� num_total_book ���� ���鼭 ������ ���ǻ縦 ����ڰ� �Է���
         * �˻���� ���ϰ� �ִ�. */
        for (i = 0; i < total_num_book; i++) {
            if (compare(book_list[i].publ_name, user_search)) {
                printf("��ȣ : %d // å �̸� : %s // ������ : %s // ���ǻ� : %s \n", i,
                    book_list[i].book_name, book_list[i].auth_name,
                    book_list[i].publ_name);
            }
        }
    }
    return 0;
}

int borrow_book(BOOK* book_list) { /* ����ڷ� ���� å ��ȣ�� ���� ���� */
    int book_num = 0;
    printf("���� å�� ��ȣ�� �����ּ��� \n");
    printf("å ��ȣ : ");
    scanf_s("%d", &book_num, sizeof(book_num));
    getchar();//�Է¹��� ����;
    if (book_list[book_num].borrowed == 1) {
        printf("�̹� ����� å�Դϴ�! \n");
    }
    else if(book_list[book_num].borrowed == 0) {
        printf("å�� ���������� ����Ǿ����ϴ�. \n");
        book_list[book_num].borrowed = 1;
    }
    else//å�� ������
    {
        printf("�������� �ʴ� ��ȣ�Դϴ�.\n");
    }
    return 0;
}

int return_book(BOOK* book_list) { /* �ݳ��� å�� ��ȣ */
    int num_book = 0;
    printf("�ݳ��� å�� ��ȣ�� ���ּ��� \n");
    printf("å ��ȣ : ");
    scanf_s("%d", &num_book, sizeof(num_book));
    getchar();//�Է¹��� ����;
    if (book_list[num_book].borrowed == 0) {
        printf("�̹� �ݳ��Ǿ� �ִ� �����Դϴ�\n");
    }
    else if(book_list[num_book].borrowed == 1) {
        book_list[num_book].borrowed = 0;
        printf("���������� �ݳ��Ǿ����ϴ�\n");
    }
    else
    {
        printf("�������� �ʴ� ��ȣ�Դϴ�.\n");
    }
    return 0;
}
char compare(char* str1, char* str2) {
    while (*str1) {
        if (*str1 != *str2) {
            return 0;
        }
        str1++;
        str2++;
    }
    if (*str2 == '\0') return 1;
    return 0;
}