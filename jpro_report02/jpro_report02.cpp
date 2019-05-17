#include <iostream>
#include <cstdlib>
#include <numeric> //for std::gcd() std::lcm()
#include <cmath>   //for signbit()
using namespace std;

///Fraction
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
	double getScaler() const {return (double)numrator/denominator; }
	bool isMinus() const;
	void operator+=(Fraction frac);
	void operator-=(Fraction frac);
	void operator*=(Fraction frac);
	void operator/=(Fraction frac);
	bool operator<(const Fraction frac) const;
	bool operator>(const Fraction frac) const;
	bool operator==(const Fraction frac) const;
	friend istream& operator>>(istream& stream, Fraction& frac);
};

//コンストラクタ
//default : numrator = 0, denominator = 1
Fraction::Fraction(int numrator, int denominator) {
	if (denominator == 0) {
		cerr << "分母に0が設定されています" << endl;
		exit(EXIT_FAILURE);
	}
	this->numrator = numrator;
	this->denominator = denominator;
	reduce();
	adjustSign();
}

//四則演算子
void Fraction::operator+=(Fraction frac){
	//分母の最小公倍数を求めて分母を揃えて加算
	//※c++17 or later
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
void Fraction::operator-=(Fraction frac){
	//分母の最小公倍数を求めて分母を揃えて減算
	//※c++17 or later
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
void Fraction::operator*=(Fraction frac){
	this->numrator *= frac.getNumerator(); this->denominator *= frac.getDenominator();
	reduce();
	adjustSign();
}
void Fraction::operator/=(Fraction frac){
	this->numrator *= frac.getDenominator(); this->denominator *= frac.getNumerator();
	reduce();
	adjustSign();
}

Fraction operator+(Fraction f0, Fraction f1) {
	f0 += f1;
	return f0;
}
Fraction operator-(Fraction f0, Fraction f1) {
	f0 -= f1;
	return f0;
}
Fraction operator*(Fraction f0, Fraction f1) {
	f0 *= f1;
	return f0;
}
Fraction operator/(Fraction f0, Fraction f1) {
	f0 /= f1;
	return f0;
}

//比較演算子
bool Fraction::operator<(const Fraction frac) const {
	return this->getScaler() < frac.getScaler();
}
bool Fraction::operator>(const Fraction frac) const {
	return this->getScaler() > frac.getScaler();
}
bool Fraction::operator==(const Fraction frac) const {
	return this->getScaler() == frac.getScaler();
}

//入出力（入力のみfriend）
istream& operator>>(istream& stream, Fraction& frac) {
	int numerator, denominator;
	stream >> numerator >> denominator;
	if (denominator == 0) {
		cerr << "分母に0が設定されています" << endl;
		exit(EXIT_FAILURE);
	}
	frac.numrator = numerator;
	frac.denominator = denominator;
	frac.reduce();
	frac.adjustSign();
	return stream;
}
ostream& operator<<(ostream& stream, const Fraction frac) {
	if (frac.getDenominator() == 1 || frac.getNumerator() == 0) stream << frac.getNumerator();
	else stream << "(" << frac.getNumerator() << "/" << frac.getDenominator() << ")";
	return stream;
}

//約分
void Fraction::reduce() {
	//※c++17 or later
	int GCD = gcd(this->getNumerator(), this->getDenominator());
	if (GCD == 0) return;
	this->numrator    /= GCD;
	this->denominator /= GCD;
}

bool Fraction::isMinus() const {
	bool isMinus = signbit(getScaler()) != 0;
	return isMinus;
}

//符号整理
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

int main()
{
	const Fraction f1(1, 2), f2(2, 3), f3(2);
	Fraction f4(2, 4), f5(-3, 5), f6(0);
	Fraction g1, g2;
	cout << f1 << '+' << f2 << '=' << f1 + f2 << '\n';
	cout << f1 << '-' << f2 << '=' << f1 - f2 << '\n';
	cout << f1 << '*' << f3 << '=' << f1 * f3 << '\n';
	cout << f1 << '-' << f4 << '=' << f1 - f4 << '\n';
	cout << f2 << '/' << f4 << '=' << f2 / f4 << '\n';
	cout << f2 << '/' << f5 << '=' << f2 / f5 << '\n';
	cout << f6 << '*' << f2 << '=' << f6 * f2 << '\n';
	cout << 1 << '+' << f5 << '=' << 1 + f5 << '\n';
	cout << "分数を入力-->"; cin >> g1;
	cout << "分数を入力-->"; cin >> g2;
	if (g1 > g2) cout << g1 << '>' << g2 << '\n';
	if (g1 < g2) cout << g1 << '<' << g2 << '\n';
	if (g1 == g2) cout << g1 << "==" << g2 << '\n';
	cout << g1 << '*' << g2 << '=' << g1 * g2 << '\n';
	cout << g1 << '*' << 20 << '=' << g1 * 20 << '␣';
	cout << 20 << '*' << g1 << '=' << 20 * g1 << '\n';
	return 0;
}