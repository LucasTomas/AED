#include <cassert>
#include <string>

int main() {
	// tipo de dato boolean
	assert(true);
	assert(false==false);
	assert(true!=false);
	assert(not false);
	assert(not false==true);
	assert(false or true);
	assert(false || true);
	assert(true and true);
	assert(true && true);
	assert((false or true) and (false==false));
	assert((false or true) and false==false);
	assert(true or (true and false));
	// tipo de dato double
	assert(2.0==1.0+1.0);
	assert(1.0==2.0-1.0);
	assert(4.0==2.0*2.0);
	assert(2.0==8.0/4.0);
	assert(0.1==1.0/10.0);
	assert(0.1 != 0.2);
	assert(28.02 > 12.01);
	assert(28.02 >= 28.02);
	assert(28.02 >= 15.03);
	assert(3.02 < 10.5);
	assert(3.02 <= 3.02);
	assert(3.02 <= 5.06);
	assert(1.0/3.0 > 0.33);
	assert(1.0/3.0 > 0.11*3.0);
	assert(2.0/3.0 != 0.11*3.0);
	assert(2.0/3.0 - 1.0/3.0 > 0.33);
	assert(2.0/3.0 - 1.0/3.0 != 0.33);
	assert(0.99 < 2.0/3.0 + 1.0/3.0);
	assert(2.0/3.0 + 1.0/3.0 != 0.99);
	// tipo de dato char
	assert('a' == 'a');
	assert('a' != 'b');
	assert('a' != 'A');
	assert('a' > 'A');
	assert('!' < '=');
	assert('z' - '!' > '!' + '$');
	assert('z' / '!' < 'z' * '!');
	assert('c' % '!' == 0);
	// tipo de dato unsigned
	assert(3 == 3);
	assert(5 != 10);
	assert(5 < 18);
	assert(8 > 3);
	assert(10 / 5 == 2);
	assert(5 * 5 == 25);
	assert(6 + 9 == 30 - 15);
	assert(100 % 3 == 1);
	assert(22 % 4 >= 0);
	assert(9 / 3 <= 8 * 2);
	// tipo de dato int
	assert(4 == 4);
	assert(5 != -5);
	assert(-8 < 8);
	assert(26 > -26);
	assert(3 * -5 < -8 * 1);
	assert(28 - (-5) > 28 - 5);
	assert(26 % (-5) >= 0);
	assert(26 % 5 >= 0);
	assert(66 / -3 <= 0);
	assert(20 * -2 <= 0);
	assert(30 % 6 == (-28) - (-28));
	assert((-2) * (-8) >= 0);
	assert((-2) * 1521 <= 5 * 3);
	assert(28 + (-5) == 12 + 11);
	// tipo de dato string
}
