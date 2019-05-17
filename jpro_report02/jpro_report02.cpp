#include <iostream>
using namespace std;
#include "Fraction.h"

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