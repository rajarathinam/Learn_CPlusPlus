/*
 * BigInteger Class, performs basic arithmetic operations of very large integers.
 * Copyright (C) 2011  Mahmoud Mechehoul
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <algorithm>
#include "BigInt.h"

using namespace std;

BigInteger::BigInteger(unsigned int integer) {
	setInteger(integer);
}

BigInteger::BigInteger(string integer)
{
	for (int i = 0; i < (int)integer.size() && integer[i] >= '0' && integer[i] <= '9'; i++) {
		this->integer += integer[i];
	}

	if (this->integer.size() == 0) {
		this->integer = "0";
	} else {
		this->integer = integer.substr(getTrimIndex(integer));
	}
}

void BigInteger::setInteger(unsigned int integer)
{
	if (integer == 0) this->integer = "0";

	while (integer)
	{
		this->integer = (char)((integer % 10) + '0');// + this->integer;
		integer /= 10;
	}
}

void BigInteger::setInteger(string integer)
{
	this->integer = integer;
}
size_t BigInteger::getTrimIndex(const string& integer) 
{
	size_t index = 0;
	while (integer[index] == '0' && index < integer.size() - 1) index++;
	return index;
}

ostream& operator<<(ostream& out , BigInteger& obj)
{
	out<<obj.integer;
	return out;
}
string BigInteger::toString() const 
{
        return integer;
}
BigInteger BigInteger::addInteger(const BigInteger& integer_to_add) const
{
        int a_n = max((int)(integer_to_add.toString().size() - toString().size()), 0);
        int b_n = max((int)(toString().size() - integer_to_add.toString().size()), 0);
        string a = string(a_n, '0') + toString();
        string b = string(b_n, '0') + integer_to_add.toString();

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string result; int carry = 0;

        for (int i = 0; i < (int)a.size(); i++) {
         int sum = (a[i] - '0') + (b[i] - '0') + carry;
         result += ((char)(sum % 10 + '0'));
         carry = sum / 10;
        }

        if (carry != 0) result += ((char)(carry + '0'));

        reverse(result.begin(), result.end());

        return BigInteger(result.substr(getTrimIndex(result)));
}
BigInteger& BigInteger::operator+(BigInteger& obj)
{
 //return addInteger(BigInteger(obj));
    return obj ;
}
int defeef()
{
	BigInteger a("999999999999999999999");
	BigInteger b("999999999999999999999");
	BigInteger c(a+b);


	cout<<c;
	return 0;
}
