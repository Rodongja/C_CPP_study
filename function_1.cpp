
//문제 1
//사용자로 부터 5 명의 학생의 수학, 국어, 영어 점수를 입력 받아서 평균이 가장 높은 사람 부터 평균이 가장 낮은 사람까지 정렬되어 출력하도록 하세요.
//특히, 평균을 기준으로 평균 이상인 사람 옆에는 '합격', 아닌 사람은 '불합격' 을 출력하게 해보세요(난이도 : 中上).

#include <iostream>

void func(int (*arr)[3]);

int main() {


	int arr[5][3] = {};

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << "점수를 입력하세요 : " << std::endl;
			std::cin >> arr[i][j];
			if (arr[i][j] > 100 || arr[i][j] < 0)
			{
				std::cout << "점수를 다시 입력하세요" << std::endl;
				j--;
			}
		}
	}

	func(arr);

	return 0;
}

void func(int (*arr)[3])
{
	int class_avg = 0;
	int row_avg = 0;
	int student_avg[5] = {};
	int top = 0;

	// 학생 마다의 평균
	for (int i = 0; i < 5; ++i)
	{
		int sum_arr = 0;
		for (int j = 0; j < 3; ++j)
		{
			sum_arr += arr[i][j];
		}
		student_avg[i] = (sum_arr/3);
	}	

	// 반 전체의 평균
	for (int i = 0; i < 5; ++i)
	{
		class_avg += student_avg[i];
	}
	class_avg /= 5;

	// 내림차순 정렬
	int temp = 0;
	int j = 0;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = i + 1; j < 5; ++j)
		{
			if (student_avg[i] < student_avg[j])
			{
				temp = student_avg[j];
				student_avg[j] = student_avg[i];
				student_avg[i] = temp;
			}
		}
	}

	std::cout << "반 평균 : " << class_avg << "점" << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		if (class_avg < student_avg[i])
			std::cout << i+1 << "등 학생의 평균 : " << student_avg[i] << "합격" << std::endl;
		else
			std::cout << i+1 << "등 학생의 평균 : " << student_avg[i] << "불합격" << std::endl;
	}
}