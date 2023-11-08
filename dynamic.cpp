/* 2 차원 배열 동적 할당의 활용 */
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
int main(int argc, char** argv) {
    int i, j, input, sum = 0;
    int subject, students, ave;
    int** arr;
    int* average;
    int* rank;
    // 우리는 arr[subject][students] 배열을 만들 것이다.

    printf("과목 수 : ");
    scanf_s("%d", &subject);

    printf("학생의 수 : ");
    scanf_s("%d", &students);

    arr = (int**)malloc(sizeof(int*) * subject);
    average = (int*)malloc(sizeof(int) * students);
    rank = (int*)malloc(sizeof(int) * students);
    for (i = 0; i < subject; i++) {
        arr[i] = (int*)malloc(sizeof(int) * students);
    }

    for (i = 0; i < subject; i++) {
        printf("과목 %d 점수 --------- \n", i);

        for (j = 0; j < students; j++) {
            printf("학생 %d 점수 입력 : ", j);
            scanf_s("%d", &input);

            arr[i][j] = input;
        }
    }

    for (i = 0; i < subject; i++) {
        sum = 0;
        for (j = 0; j < students; j++) {
            sum += arr[i][j];
        }
        printf("과목 %d 평균 점수 : %d \n", i, sum / students);
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
        printf("%d 학생의 평균 점수 : %d \n", j, average[j]);
        printf("%d 학생의 등수 : %d \n", j, rank[j]);
    }

    for (i = 0; i < subject; i++) {
        free(arr[i]);
    }

    free(average);
    free(rank);
    free(arr);

    return 0;
}