#pragma once
#include <iostream>
#include <cstdlib>
#include <numeric> //for std::gcd() std::lcm()
#include <cmath>   //for signbit()
using namespace std;

class Fraction {
	//numrator    : 分子
	//denominator : 分母
private:
	int numrator, denominator;
	//符号整理
	void adjustSign();
	void reduce();

public:
	Fraction(int numerator = 0, int denominator = 1);
	int getNumerator()   const { return numrator; }
	int getDenominator() const { return denominator; }
	//double型小数表現に変換した値を返す
	double getScaler() const { return (double)numrator / denominator; }
	bool isMinus() const;
	//四則演算
	void operator+=(Fraction frac);
	void operator-=(Fraction frac);
	void operator*=(Fraction frac);
	void operator/=(Fraction frac);
	bool operator< (Fraction frac) const;
	bool operator> (Fraction frac) const;
	bool operator==(Fraction frac) const;
	friend istream& operator>>(istream& stream, Fraction& frac);
};

//四則演算
Fraction operator+(Fraction f0, Fraction f1);
Fraction operator-(Fraction f0, Fraction f1);
Fraction operator*(Fraction f0, Fraction f1);
Fraction operator/(Fraction f0, Fraction f1);

//入出力（入力のみfriend）
istream& operator>>(istream& stream, Fraction& frac);
ostream& operator<<(ostream& stream, const Fraction frac);