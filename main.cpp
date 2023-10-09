#include <stdio.h>
#include <iostream>

int magic_box(int num) {
    return num+4;
}
int slave(int num1, int num2) {
    int total_money = num1 + num2;
    int today_money = num2;
    return total_money;
}
int factorial(int fac) {
    int sum = 0;
    for (; fac >= 1; --fac)
    {
        sum += fac;
    }
    return sum;
}
int prime_count(int N)
{
    int total_prime = 0;
    for (int i =2; i <= N; ++i)
    {
        int count = 0;
        for (int j = 1; j <= i; ++j)
        {
            if (i % j == 0)
            {
                count++;
            }
        }
        if (count == 2)
        {
            total_prime++;
        }
    }
    return total_prime;
}
void factorize(int N) { 
    //for (int i = 2; i <= N; i++)
    int i = 2;
    while(i <= N)
    {
        if (N % i == 0)
        {
            N = N / i;
            std::cout << i;
            if (N != 1)
            {
                std::cout << " X ";
            }
        }
        else
            ++i;
    }
}
int max(int* data);
void max2(int* data);
void arr2d(int (*data)[3]);

 int main() {
     int i;
     int j;
     int master1 = 100000;
     int master2;
     int fac;
     int prime;
     int facto;
     int maxint[10];
     int maxint2[10];
     int arr[2][3];

     //모두의 코드 (https://modoocode.com/) C언어 문제 연습

     ////입력한 수에 4를 더해주는 함수
     //std::cin >> i;
     //std::cout << magic_box(i) << std::endl;


     ////종합 수익과 오늘 수익을 출력하는 함수
     //std::cin >> master2;
     //std::cout << "total_money : " << slave(master1, master2) << std::endl;
     //std::cout << "today_money : " << master2 << std::endl;


     ////팩토리얼 함수
     //std::cin >> fac;
     //std::cout << factorial(fac) << std::endl;
     

     ////입력한 수보다 작은 수 중 소수가 몇개 있는지 찾아주는 함수
     //std::cin >> prime;
     //std::cout << prime_count(prime) << std::endl;


     ////소인수분해 함수
     //std::cin >> facto;
     //factorize(facto);


     ////길이 10의 배열에서 가장 큰 수를 찾아주는 함수
     /*for (i = 0; i < 10; i++)
     {
         std::cin >> maxint2[i];
     }*/

     //std::cout << "최대값 : " << max(maxint) << std::endl;
     //max2(maxint2);


     //// 2차원배열의 각 원소에 1을 더하는 함수
     //for (i = 0; i < 2; i++)
     //{
     //    for (j = 0; j < 3; j++)
     //    {
     //        std::cin >> arr[i][j];
     //    }
     //}

     //arr2d(arr);

    return 0;
}

 int max(int* data) {
     int max = data[0];
     for (int i = 0; i < 10; i++)
     {
         if (max < data[i])
         {
             max = data[i];
         }
     }
     return max;
 }
 void max2(int* data)
 {
     int max = data[0];
     for (int i = 0; i < 10; i++)
     {
         if (max < data[i])
         {
             max = data[i];
         }
     }
     std::cout << "최대값 : " << max << std::endl;
 }
 void arr2d(int (*data)[3])
 {
     int x = 0;
     int idata = 0;
     for (; x < 2; x++)
     {
         int y = 0;
         for (; y < 3; y++)
         {
             idata = data[x][y];
             idata++;
             std::cout << x << "열" << y << "행" << "값 : " << idata << std::endl;
         }
     }
 }