/* main �Լ��� ���ڶ��?? */
#include <iostream>
#include "plus.h"
using namespace std;
int main(int argc, char* argv[]) 
{
	int answer = 0;
	if (*argv[2] == '+')
	{
		answer = plus_func(atoi(argv[1]), atoi(argv[3]));
	}
	cout << answer;

	return 0;
}