//문제 6
//에라토스테네스의 체를 이용해서 1 부터 N 까지의 소수를 구하는 프로그램을 만들어보세요. (난이도 : 中)

//먼저, 2부터 시작하여 원하는 범위 내의 모든 자연수를 나열합니다.
//
//아직 처리되지 않은 가장 작은 수를 선택하고, 이 수는 소수입니다.이 소수의 배수를 모두 지우는 작업을 시작합니다.
//
//선택한 소수의 배수를 모두 지우기 위해, 해당 소수의 배수 위치에 있는 수를 표시하거나 지웁니다. (예를 들어, 2를 선택하면 2의 배수를 모두 제거)
//
//아직 처리되지 않은 다음으로 작은 수를 선택하고, 이 수가 소수인지 확인합니다.이 소수의 배수를 모두 지우는 작업을 반복합니다.
//
//이 과정을 반복하여 모든 소수를 찾을 때까지 계속합니다.범위 내의 모든 수가 처리될 때까지 진행하면, 남아있는 수들은 모두 소수입니다.

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<bool> eratosthenes(int num, std::vector<bool> prime_vec);
void fcout(std::vector<bool> prime_vec);

int main()
{
	int num = 0;
	std::cout << "숫자를 입력하세요" << std::endl;
	std::cin >> num;
	
	// bool vector 생성
	// 0은 소수가 아님 1은 소수임
	std::vector<bool> prime_vec = {};

	prime_vec = eratosthenes(num, prime_vec);
	fcout(prime_vec);
	

	return 0;
}

std::vector<bool> eratosthenes(int num, std::vector<bool> prime_vec)
{

	//1. N까지 모든 수를 써놓는다.
	for (int i = 0; i <= num; ++i)
	{
		prime_vec.push_back(1);
	}
	//1.5 0과 1은 소수가 아니므로 0처리한다.
	prime_vec[0] = 0;
	prime_vec[1] = 0;

	//2. 아직 지워지지않은 수 중에서 가장 작은수를 찾는다.
	//2.5 제곱근을 이용하여 계산하면 절반의 계산으로 가능하다.
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (prime_vec[i])
		{
			//2,3,5,7 등 첫 수는소수이기 때문에 j = i * 2를 하여 넘겨줌
			for (int j = i * 2; j <= num; j += i)
			{
				prime_vec[j] = 0;
			}
		}
	}
	return prime_vec;
}

//출력 함수
void fcout(std::vector<bool> prime_vec)
{
	std::cout << "소수 출력 : ";
	for (int i = 0; i < prime_vec.size(); ++i)
	{
		if (1 == prime_vec[i])
		{
			std::cout << i << " ";
		}
	}
}