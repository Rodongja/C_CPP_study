//문제 3
//자기 자신을 호출하는 함수를 이용해서 1 부터 특정한 수까지의 곱을 구하는 프로그램을 만들어보세요. (난이도 : 下)

#include <iostream>
#include <vector>

// i i+1 i+2 i+3 i+4

int mul(int num, int count, int imul);

int main()
{
	int num;//입력한 숫자
	int count = 0;//현재 숫자
	int imul = 1;//최종 값
	std::vector<int> mulvec = {};

	std::cout << "수를 입력하세요" << std::endl;
	std::cin >> num;

	imul = mul(num,count,imul);
	std::cout << "값 : " << imul << std::endl;
	return 0;
}

int mul(int num, int count, int imul)
{
	if (num != count)
	{
		imul *= (count + 1);
		++count;
		mul(num, count,imul);
	}
	else {
		return imul;
	}
}