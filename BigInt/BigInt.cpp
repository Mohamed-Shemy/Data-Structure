#include "BigInt.h"
#include <iostream>
using namespace std;
enum relation { LESS, GRATER, EQUAL };

BigInt::BigInt()
{
}

inline BigInt::BigInt(const BigInt &)
{
}

relation compare(Dlist<int> f, Dlist<int> s)
{
	bool finsh = false;
	int d1, d2;
	f.resetBackward();
	s.resetBackward();
	while (!finsh)
	{
		f.getNext(d1, finsh);
		s.getNext(d2, finsh);
		if (d1 < d2) return LESS;
		if (d1 > d2) return GRATER;
	}
	return EQUAL;
}

inline bool BigInt::operator<(BigInt s)
{
	if (sign == MINUS && s.sign == PLUS)
		return true;
	else if (sign == PLUS && s.sign == MINUS)
		return false;
	else if (sign == PLUS && numDigits < s.numDigits)
		return true;
	else if (sign == PLUS && numDigits > s.numDigits)
		return false;
	else if (sign == MINUS && numDigits > s.numDigits)
		return true;
	else if (sign == MINUS && numDigits < s.numDigits)
		return false;
	else
	{
		relation r = compare(number, s.number);
		if (sign == PLUS && r == LESS)
			return true;
		else if (sign == PLUS && r == GRATER)
			return false;
		else if (sign == MINUS && r == GRATER)
			return true;
	}
	return false;
}

inline bool BigInt::operator==(BigInt s)
{
	if ((sign == MINUS && s.sign == PLUS) || (sign == PLUS && s.sign == MINUS)) return false;
	return (compare(number, s.number) == EQUAL);
}

void sub(Dlist<int> f, Dlist<int> s, Dlist<int> r)
{
	int d1, d2;
	bool br = false;
	bool f1 = false;
	bool f2 = false;
	f.resetBackward();
	s.resetBackward();
	while (!f1 && !f2)
	{
		f.getBack(d1, f1);
		if (br)
			if (d1 != 0)
			{
				d1 = d1 - 1;
				br = false;
			}
			else
			{
				d1 = 9;
				br = true;
			}
		s.getBack(d2, f2);
		if (d2 <= d1)
			r.setFront(d1 - d2);
		else
		{
			br = true;
			r.setFront(d1 + 10 - d2);
		}
	}

	while (!f1)
	{
		f.getBack(d1, f1);
		if (br)
			if (d1 != 0)
			{
				d1 = d1 - 1;  br = false;
			}
			else
			{
				d1 = 9;    br = true;
			}
		r.setFront(d1);
	}
}

void add(Dlist<int> f, Dlist<int> s, Dlist<int> r)
{
	int carry = 0;
	int tmp;
	int digit1, digit2;
	bool finsh1 = (f.length() == 0);
	bool finsh2 = (s.length() == 0);
	f.resetBackward();
	s.resetBackward();

	while (!finsh1 && !finsh2)
	{
		f.getBack(digit1, finsh1);
		s.getBack(digit2, finsh2);
		tmp = digit1 + digit2 + carry;
		carry = tmp / 10;
		r.setFront(tmp % 10);
	}
	while (!finsh1)
	{
		f.getBack(digit1, finsh1);
		tmp = digit1 + carry;
		carry = tmp / 10;
		r.setFront(tmp % 10);
	}
	while (!finsh2)
	{
		s.getBack(digit2, finsh2);
		tmp = digit2 + carry;
		carry = tmp / 10;
		r.setFront(tmp % 10);
	}
	if (carry != 0)
		r.setFront(carry);
}

void mul(Dlist<int> f, Dlist<int> s, Dlist<int> r)
{
	// F grater than S
	int d1, d2, m;
	int zero = 0;
	bool f1 = false;
	bool f2 = false;
	int carry = 0;
	f.resetBackward();
	s.resetBackward();
	Dlist<int> tmp;
	r.setFront(0);
	while (!f2)
	{
		carry = 0;
		for (int i = 0; i < zero; i++)
			tmp.setFront(0);
		s.getBack(d2, f2);
		if (d2 == 0) { zero++; continue; }
		while (!f1)
		{
			f.getBack(d1, f1);
			m = d1 * d2 + carry;
			tmp.setFront(m % 10);
			carry = m / 10;
		}
		if (carry > 0)
			tmp.setFront(carry);
		zero++;
		f.resetBackward();
		add(r, tmp, r);
		tmp.clear();
	}
}

void div(Dlist<int> f, Dlist<int> s, Dlist<int> r)
{

}

inline BigInt BigInt::operator+(BigInt s)
{
	Sign self, ssign;
	BigInt r;
	if (sign == s.sign)
	{
		add(number, s.number, r.number);
		r.sign = sign;
	}
	else
	{
		self = sign;
		ssign = s.sign;
		sign = PLUS;
		s.sign = PLUS;
		if (*this < s)
		{
			sub(s.number, number, r.number);
			r.sign = ssign;
		}
		else if (s < *this)
		{
			sub(number, s.number, r.number);
			r.sign = self;
		}
		sign = self;
	}
	r.numDigits = r.number.length();
	return r;
}

inline BigInt BigInt::operator-(BigInt s)
{
	BigInt r;
	if (sign != s.sign)
	{
		add(number, s.number, r.number);
		if (sign == PLUS)
			r.sign = sign;
		else
			r.sign = MINUS;
	}
	else
		if (*this < s)
		{
			sub(s.number, number, r.number);
			r.sign = MINUS;
		}
		else
		{
			sub(number, s.number, r.number);
			r.sign = PLUS;
		}
	return r;
}

inline BigInt BigInt::operator*(BigInt s)
{
	BigInt r;

	if (number.length() > s.number.length())
		mul(number, s.number, r.number);
	else
		mul(s.number, number, r.number);

	if (sign == s.sign)
		r.sign = PLUS;
	else
		r.sign = MINUS;
	return r;
}

inline BigInt BigInt::operator/(BigInt s)
{
	BigInt r;
	if (numDigits < s.numDigits)
	{
		r.number.setFront(0);
		r.sign = PLUS;
	}
	else
	{
		div(number, s.number, r.number);
		if (sign == s.sign)
			r.sign = PLUS;
		else
			r.sign = MINUS;
	}
	return r;
}

inline void BigInt::insert(int x)
{
	number.setEnd(x);
}

inline void BigInt::write(std::ostream & out)
{
}

void BigInt::print()
{
	if (sign == MINUS)
		cout << "-";
	bool f = false;
	int i;
	number.getNext(i, f);
	while (!f)
	{
		number.getBack(i, f);
		cout << i;
	}
}
