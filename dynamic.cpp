/* 2 ���� �迭 ���� �Ҵ��� Ȱ�� */
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
int main(int argc, char** argv) {
    int i, j, input, sum = 0;
    int subject, students, ave;
    int** arr;
    int* average;
    int* rank;
    // �츮�� arr[subject][students] �迭�� ���� ���̴�.

    printf("���� �� : ");
    scanf_s("%d", &subject);

    printf("�л��� �� : ");
    scanf_s("%d", &students);

    arr = (int**)malloc(sizeof(int*) * subject);
    average = (int*)malloc(sizeof(int) * students);
    rank = (int*)malloc(sizeof(int) * students);
    for (i = 0; i < subject; i++) {
        arr[i] = (int*)malloc(sizeof(int) * students);
    }

    for (i = 0; i < subject; i++) {
        printf("���� %d ���� --------- \n", i);

        for (j = 0; j < students; j++) {
            printf("�л� %d ���� �Է� : ", j);
            scanf_s("%d", &input);

            arr[i][j] = input;
        }
    }

    for (i = 0; i < subject; i++) {
        sum = 0;
        for (j = 0; j < students; j++) {
            sum += arr[i][j];
        }
        printf("���� %d ��� ���� : %d \n", i, sum / students);
    }

    for (j = 0; j < students; j++)
    {
        ave = 0;
        for (i = 0; i < subject; i++)
        {
            ave += arr[i][j];
        }
        average[j] = ave / subject;
        rank[j] = 1;
    }    
        
    for (j = 0; j < students; j++) 
    {
        for (int k = 0; k < students; k++)
        {
            if (average[j] < average[k])
            {
                rank[j] += 1;
            }
        }
    }

    for (j = 0; j < students; j++)
    {
        printf("%d �л��� ��� ���� : %d \n", j, average[j]);
        printf("%d �л��� ��� : %d \n", j, rank[j]);
    }

    for (i = 0; i < subject; i++) {
        free(arr[i]);
    }

    free(average);
    free(rank);
    free(arr);

    return 0;
}