// sobol.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DirectionNumber.h"

int main()
{
	DirectionNumber a,b,z;
	std::cin >> a >> b;
	z = a^b;
	std::cout << z << std::endl;
	system("pause");
	return 0;
}

