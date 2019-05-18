#pragma once
#include <iostream>
#include <cstdlib>
#include <numeric> //for std::gcd() std::lcm()
#include <cmath>   //for signbit()
using namespace std;

class Fraction {
	//numrator    : ���q
	//denominator : ����
private:
	int numrator, denominator;
	//��������
	void adjustSign();
	void reduce();

public:
	Fraction(int numerator = 0, int denominator = 1);
	int getNumerator()   const { return numrator; }
	int getDenominator() const { return denominator; }
	//double�^�����\���ɕϊ������l��Ԃ�
	double getScaler() const { return (double)numrator / denominator; }
	bool isMinus() const;
	//�l�����Z
	void operator+=(const Fraction&);
	void operator-=(const Fraction&);
	void operator*=(const Fraction&);
	void operator/=(const Fraction&);
	bool operator< (const Fraction&) const;
	bool operator> (const Fraction&) const;
	bool operator==(const Fraction&) const;
	friend istream& operator>>(istream&, Fraction&);
};

//�l�����Z
Fraction operator+(const Fraction&, const Fraction&);
Fraction operator-(const Fraction&, const Fraction&);
Fraction operator*(const Fraction&, const Fraction&);
Fraction operator/(const Fraction&, const Fraction&);

//���o�́i���͂̂�friend�j
istream& operator>>(istream&, Fraction&);
ostream& operator<<(ostream&, const Fraction&);