#include "stdafx.h"
#include "DirectionNumber.h"


//����������� �� ���������
DirectionNumber::DirectionNumber() : m_(0), degree_(0) {}

//����������� � �����������
DirectionNumber::DirectionNumber(int m, int degree) : m_(m), degree_(degree) {}

//XOR (����������� ���)
DirectionNumber DirectionNumber::operator^(DirectionNumber &obj) {
	int m_temp, degree_temp;
	//���� ������� ������ � ������� ����� ������, ��� � �������,
	//����� ���������� ����������� ���������� ����� ������ �� ������� �����,
	//����� ������������ ������� ��������������� ����� ���������� �������
	if (this->degree_ > obj.degree_) {
		obj.m_ <<= (this->degree_ - obj.degree_);
		degree_temp = this->degree_;
	}
	//�����, ���� ������� ������ � ������� ����� ������, ��� � �������,
	//����� ���������� ����������� ���������� ����� ������ �� ������� �����,
	//����� ������������ ������� ��������������� ����� ���������� �������
	else {
		this->m_ <<= (obj.degree_ - this->degree_);
		degree_temp = obj.degree_;
	}
	//���������� �������� XOR ����� �����������
	m_temp = this->m_ ^ obj.m_;
	DirectionNumber result(m_temp, degree_temp);
	return result;
}

//��������� ����
std::istream& operator>>(std::istream& is, DirectionNumber& direction_number) {
	std::cout << "m_ = ";
	is >> direction_number.m_;
	std::cout << "degree_ = ";
	is >> direction_number.degree_;
	return is;
}

//��������� �����
std::ostream& operator<<(std::ostream& os, DirectionNumber& direction_number) {
	os << double(direction_number.m_) / pow(2, direction_number.degree_);
	return os;
}
