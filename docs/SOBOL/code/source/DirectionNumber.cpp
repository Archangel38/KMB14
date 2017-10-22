#include "stdafx.h"
#include "DirectionNumber.h"


//Конструктор по умолчанию
DirectionNumber::DirectionNumber() : m_(0), degree_(0) {}

//Конструктор с параметрами
DirectionNumber::DirectionNumber(int m, int degree) : m_(m), degree_(degree) {}

//XOR (исключающее ИЛИ)
DirectionNumber DirectionNumber::operator^(DirectionNumber &obj) {
	int m_temp, degree_temp;
	//Если степень двойки у первого числа больше, чем у второго,
	//тогда дописываем необходимое количество нулей справа от второго числа,
	//затем приравниваем степень результирующего числа наибольшей степени
	if (this->degree_ > obj.degree_) {
		obj.m_ <<= (this->degree_ - obj.degree_);
		degree_temp = this->degree_;
	}
	//Иначе, если степень двойки у второго числа больше, чем у первого,
	//тогда дописываем необходимое количество нулей справа от первого числа,
	//затем приравниваем степень результирующего числа наибольшей степени
	else {
		this->m_ <<= (obj.degree_ - this->degree_);
		degree_temp = obj.degree_;
	}
	//Производим операцию XOR между числителями
	m_temp = this->m_ ^ obj.m_;
	DirectionNumber result(m_temp, degree_temp);
	return result;
}

//Потоковый ввод
std::istream& operator>>(std::istream& is, DirectionNumber& direction_number) {
	std::cout << "m_ = ";
	is >> direction_number.m_;
	std::cout << "degree_ = ";
	is >> direction_number.degree_;
	return is;
}

//Потоковый вывод
std::ostream& operator<<(std::ostream& os, DirectionNumber& direction_number) {
	os << double(direction_number.m_) / pow(2, direction_number.degree_);
	return os;
}
