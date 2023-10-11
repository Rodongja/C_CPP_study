//문제 2
//유클리도 호제법을 이용해서 N 개의 수들의 최대공약수를 구하는 함수를 만들어보세요.유클리드 호제법이 무엇인지 모르신다면, 인터넷 검색을 활용하는 것을 추천합니다. (댓글을 달아도 돼요) (난이도 : 中上)

#include <iostream>
#include <vector>
#include <algorithm>

// 나머지 계산 재귀함수
int MOD(int x, int y);
int e_algorithm(std::vector<int> vec, int number_count);



int main() {

	int number_count = 0;// 수의 개수
	int g_divisor; //최대공약수

	std::cout << "수의 개수를 입력하세요 : " << std::endl;
	std::cin >> number_count;

	// 수의 가변배열을 vector 생성
	std::vector<int> euclid;

	
	for (int i = 0; i < number_count; ++i)
	{
		int number;
		std::cout << "수를 입력하세요 : " << std::endl;
		// 입력할 수 number
		std::cin >> number;
		// euclid 배열에 number 입력
		// 복사생성자를 생성하지 않아 push_back보다 성능이 좋음
		euclid.emplace_back(number);
	}

	// 원활한 계산을 위해 내림차 순 정렬
	std::sort(euclid.rbegin(), euclid.rend());

	g_divisor = e_algorithm(euclid,number_count);

	std::cout << "최대공약수 : " << g_divisor << std::endl;


	
	return 0;
}

int MOD(int x, int y)
{
	int temp; //나머지
	int g_divisor; //최대공약수
	temp = x % y;

	if (x % y != 0)
	{
		x = y;
		y = temp;
		//재귀함수
		MOD(x, y);
	}
	else {
		g_divisor = y;
		return g_divisor;
	}
}

int e_algorithm(std::vector<int> euclid, int number_count)
{
	// 유클리드 호제법
	for (int i = 0; i < number_count-1; ++i)
	{
		int x, y;
		x = euclid[i];
		y = euclid[i + 1];

		MOD(x, y);
		int g_diviosr = MOD(x, y);
		return g_diviosr;
	}
}