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
	void operator+=(Fraction frac);
	void operator-=(Fraction frac);
	void operator*=(Fraction frac);
	void operator/=(Fraction frac);
	bool operator< (Fraction frac) const;
	bool operator> (Fraction frac) const;
	bool operator==(Fraction frac) const;
	friend istream& operator>>(istream& stream, Fraction& frac);
};

//�l�����Z
Fraction operator+(Fraction f0, Fraction f1);
Fraction operator-(Fraction f0, Fraction f1);
Fraction operator*(Fraction f0, Fraction f1);
Fraction operator/(Fraction f0, Fraction f1);

//���o�́i���͂̂�friend�j
istream& operator>>(istream& stream, Fraction& frac);
ostream& operator<<(ostream& stream, const Fraction frac);