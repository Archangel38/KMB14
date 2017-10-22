#ifndef DIRECTIONNUMBER_H
#define DIRECTIONNUMBER_H
#include <iostream>
#include <string>
#include <cmath>


//����� DirectionNumber ����������� �� ���� ����� �������� ������
class DirectionNumber
{
private:
	//���������
	int m_;
	//������� ������ � �����������
	int degree_;
public:
	//����������� �� ���������
	DirectionNumber();
	//����������� � �����������
	DirectionNumber(int m, int degree);
	//XOR (����������� ���)
	DirectionNumber operator^(DirectionNumber &obj);
	//��������� ����
	friend std::istream& operator>>(std::istream& is, DirectionNumber& direction_number);
	//��������� �����
	friend std::ostream& operator<<(std::ostream& os, DirectionNumber& direction_number);
};

#endif // DIRECTIONNUMBER_H