#include "Fraction.h"
//�R���X�g���N�^
//default : numrator = 0, denominator = 1
Fraction::Fraction(int numrator, int denominator) {
	if (denominator == 0) {
		cerr << "�����0���ݒ肳��Ă��܂�" << endl;
		exit(EXIT_FAILURE);
	}
	this->numrator = numrator;
	this->denominator = denominator;
	reduce();
	adjustSign();
}

//�l�����Z�q
void Fraction::operator+=(const Fraction& frac) {
	//����̍ŏ����{�������߂ĕ���𑵂��ĉ��Z
	//��c++17 or later
	int LCM = lcm(this->getDenominator(), frac.getDenominator());
	int mul0 = LCM / this->getDenominator();
	int mul1 = LCM / frac.getDenominator();

	int numrator = mul0 * this->getNumerator() + mul1 * frac.getNumerator();
	int denominator = LCM;

	this->numrator = numrator;
	this->denominator = denominator;
	reduce();
	adjustSign();
}
void Fraction::operator-=(const Fraction& frac) {
	//����̍ŏ����{�������߂ĕ���𑵂��Č��Z
	//��c++17 or later
	int LCM = lcm(this->getDenominator(), frac.getDenominator());
	int mul0 = LCM / this->getDenominator();
	int mul1 = LCM / frac.getDenominator();

	int numrator = mul0 * this->getNumerator() - mul1 * frac.getNumerator();
	int denominator = LCM;

	this->numrator = numrator;
	this->denominator = denominator;
	reduce();
	adjustSign();
}
void Fraction::operator*=(const Fraction& frac) {
	this->numrator *= frac.getNumerator();
	this->denominator *= frac.getDenominator();
	reduce();
	adjustSign();
}
void Fraction::operator/=(const Fraction& frac) {
	this->numrator *= frac.getDenominator();
	this->denominator *= frac.getNumerator();
	reduce();
	adjustSign();
}

Fraction operator+(const Fraction& f0, const Fraction& f1) {
	Fraction f = f0;
	f += f1;
	return f;
}
Fraction operator-(const Fraction& f0, const Fraction& f1) {
	Fraction f = f0;
	f -= f1;
	return f;
}
Fraction operator*(const Fraction& f0, const Fraction& f1) {
	Fraction f = f0;
	f *= f1;
	return f;
}
Fraction operator/(const Fraction& f0, const Fraction& f1) {
	Fraction f = f0;
	f /= f1;
	return f;
}

//��r���Z�q
bool Fraction::operator<(const Fraction& frac) const {
	return this->getScaler() < frac.getScaler();
}
bool Fraction::operator>(const Fraction& frac) const {
	return this->getScaler() > frac.getScaler();
}
bool Fraction::operator==(const Fraction& frac) const {
	return this->getScaler() == frac.getScaler();
}

//���o�́i���͂̂�friend�j
istream& operator>>(istream& stream, Fraction& frac) {
	int numerator, denominator;
	stream >> numerator >> denominator;
	if (denominator == 0) {
		cerr << "�����0���ݒ肳��Ă��܂�" << endl;
		exit(EXIT_FAILURE);
	}
	frac.numrator = numerator;
	frac.denominator = denominator;
	frac.reduce();
	frac.adjustSign();
	return stream;
}
ostream& operator<<(ostream& stream, const Fraction& frac) {
	if (frac.getDenominator() == 1 || frac.getNumerator() == 0) stream << frac.getNumerator();
	else stream << "(" << frac.getNumerator() << "/" << frac.getDenominator() << ")";
	return stream;
}

//��
void Fraction::reduce() {
	//��c++17 or later
	int GCD = gcd(this->getNumerator(), this->getDenominator());
	if (GCD == 0) return;
	this->numrator /= GCD;
	this->denominator /= GCD;
}

bool Fraction::isMinus() const {
	bool isMinus = signbit(getScaler()) != 0;
	return isMinus;
}

//��������
void Fraction::adjustSign() {
	if (this->isMinus()) {
		this->denominator = abs(this->getDenominator());
		this->numrator = abs(this->getNumerator()) * -1;
	}
	else {
		this->denominator = abs(this->getDenominator());
		this->numrator = abs(this->getNumerator());
	}
}