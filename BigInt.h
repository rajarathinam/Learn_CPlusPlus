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

#ifndef BIGINT_H_
#define BIGINT_H_

#include <iostream>
#include <string>

using namespace std;

class BigInteger {
private:
	string integer;
public:
	/* Constructs a big integer representation of the integer given as an argument */
	BigInteger(unsigned int integer);

	/* Parses the string given as an argument looking for an integer.
	 * Stops as soon as it finds a non-digit character.
	 * Trailing zeros will eventually get removed.
	 */
	BigInteger(string integer);

	/* Constructs a big integer representation of the integer given as an argument
	 * and assigns it to the internal representation of the big integer.
	 */
	void setInteger(unsigned int integer);
	static size_t getTrimIndex(const string& integer);
	void setInteger(string integer);
    friend ostream& operator<<(ostream& , BigInteger&);
	BigInteger& operator+(BigInteger&);
	string toString() const;
	BigInteger addInteger(const BigInteger& integer_to_add) const;
};

#endif /* BIGINT_H_ */
