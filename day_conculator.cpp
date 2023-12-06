
#include <iostream>

class Date {
	int year;
	int month;  // 1 부터 12 까지.
	int day;    // 1 부터 31 까지.

public:
	void SetDate(int year_, int month_, int day_)
	{
		year = year_;
		month = month_;
		day = day_;
	}
	void AddDay(int inc)
	{
		day += inc;
		day_update();
	}
	void AddMonth(int inc)
	{
		month += inc;
		month_update();
	}
	void AddYear(int inc)
	{
		year += inc;
	}
	void day_update()
	{
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (day > 31)
			{
				day -= 31;
				AddMonth(1);
				day_update();
			}
			break;
		case 2:
			if (day > 28)
			{
				day -= 28;
				AddMonth(1);
				day_update();
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (day > 30)
			{
				day -= 30;
				AddMonth(1);
				day_update();
			}
			break;
		}
	}

	void month_update()
	{
		if (month > 12)
		{
			month -= 12;
			AddYear(1);
		}

		if (month > 12)
			month_update();
	}

	void ShowDate()
	{
		std::cout << year << "년 " << month << "월 " << day << "일 입니다." << std::endl;
	}
};

int main(void)
{
	Date date;
	date.SetDate(0, 0, 0);

	while (true)
	{
		int idx = 0;

		std::cout << "원하는 명령을 입력해주세요" << std::endl;
		std::cout << "1 : 날짜 선택" << std::endl;
		std::cout << "2 : day 추가" << std::endl;
		std::cout << "3 : month 추가" << std::endl;
		std::cout << "4 : year 추가" << std::endl;
		std::cout << "5 : 날짜 보기" << std::endl;
		std::cout << "6 : 프로그램 종료" << std::endl;

		std::cin >> idx;

		switch (idx)
		{
		case 1:
		{
			int y, m, d = 0;

			std::cout << "year를 입력하세요" << std::endl;
			std::cin >> y;

			std::cout << "month를 입력하세요" << std::endl;
			std::cin >> m;

			std::cout << "day를 입력하세요" << std::endl;
			std::cin >> d;


			date.SetDate(y, m, d);
			break;
		}
		case 2:
		{
			std::cout << "더하려는 수를 입력하세요" << std::endl;
			std::cin >> idx;

			date.AddDay(idx);
			break;
		}
		case 3:
		{
			std::cout << "더하려는 수를 입력하세요" << std::endl;
			std::cin >> idx;

			date.AddMonth(idx);
			break;
		}
		case 4:
		{
			std::cout << "더하려는 수를 입력하세요" << std::endl;
			std::cin >> idx;

			date.AddYear(idx);
			break;
		}
		case 5:
		{
			date.ShowDate();
			break;
		}
		case 6:
		{
			exit(0);
		}
		}
	}

	return 0;
}
