#ifndef DIRECTIONNUMBER_H
#define DIRECTIONNUMBER_H
#include <iostream>
#include <string>
#include <cmath>


//Класс DirectionNumber предствляет из себя класс двоичных дробей
class DirectionNumber
{
private:
	//Числитель
	int m_;
	//Степень двойки в знаменателе
	int degree_;
public:
	//Конструктор по умолчанию
	DirectionNumber();
	//Конструктор с параметрами
	DirectionNumber(int m, int degree);
	//XOR (исключающее ИЛИ)
	DirectionNumber operator^(DirectionNumber &obj);
	//Потоковый ввод
	friend std::istream& operator>>(std::istream& is, DirectionNumber& direction_number);
	//Потоковый вывод
	friend std::ostream& operator<<(std::ostream& os, DirectionNumber& direction_number);
};

#endif // DIRECTIONNUMBER_H