#include <cassert>
#include <string>

using namespace std::literals;

int main() {

	// --------------------------------- Tipo de dato boolean ----------------------------------------------
	assert(true); // simple valor
	assert(false==false); // igualacion
	assert(true!=false); // no igual
	assert(not false); // negacion
	assert(false or true); // compuerta logica "or" denominado como "o"
	assert(true and true); // compuerta logica "and" denominado como "y"
		// Pruebas del tipo de dato Boolean
		assert(not false==true);
		assert(false || true);
		assert(true && true);
		assert((false or true) and (false==false));
		assert((false or true) and false==false);
		assert(true or (true and false));
		assert(false != (5.0 + 5.0 == 10.0));

	// ---------------------------------- Tipo de dato double -----------------------------------------------
	assert(2.0==1.0+1.0); // Suma
	assert(-1.0==1.0-2.0); // Resta
	assert(4.0==2.0*2.0); // Multiplicacion
	assert(0.1==1.0/10.0); // Division
	assert(0.1 != 0.2); // No igual
	assert(28.02 > 12.01); // Mayor
	assert(28.02 >= 28.02); // Mayor o Igual con resultado igual
	assert(28.02 >= 15.03); // Mayor o igual con resultado Mayor
	assert(3.02 < 10.5); // Menor
	assert(3.02 <= 3.02); // Menor o igual con resultado igual
	assert(3.02 <= 5.06); // Menor o igual con resultado menor
		// Pruebas del tipo de dato Double
		assert(1.0/3.0 > 0.33);
		assert(1.0/3.0 > 0.11*3.0);
		assert(2.0/3.0 != 0.11*3.0);
		assert(2.0/3.0 - 1.0/3.0 > 0.33);
		assert(2.0/3.0 - 1.0/3.0 != 0.33);
		assert(0.99 < 2.0/3.0 + 1.0/3.0);
		assert(2.0/3.0 + 1.0/3.0 != 0.99);
		assert(1.0 != 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1);

	/*
	 *  ------------------------------------- Tipo de dato char ----------------------------------------------
	 *
	 * En este tipo de dato podemos observar que cada uno de sus carateres Tiene determinado un numero espefico
	 * con ese numero realizaremos las posibles operaciones
	 *
	*/
	assert('a' == 'a'); // igualacion
	assert('a' != 'b'); // No igual
	assert('a' > 'A'); // Mayor
	assert('!' < '='); // Menor
	assert('z' - '!' > '!' + '$'); // Sumas y Restas
	assert('z' / '!' < 'z' * '!'); // Division y Multiplicacion
	assert('c' % '!' == 0); // Resto
		// Pruebas del tipo de dato Char
		assert('a' != 'A');
		assert('6' + '9' != 15);
		assert('m' == 109);
		assert('P' / '(' == 2);
		assert('A' == 'B' - 1);
		assert('2' * 2 == 100);
		assert('V' + 14 == ' ' + '+' + 25);

	// ----------------------------------------- tipo de dato unsigned ----------------------------------
	assert(3u == 3u); // Igualacion
	assert(5u != 10u); // No igual
	assert(5u < 18u); // Menor
	assert(8u > 3u); // Mayor
	assert(10u / 5u == 2u); // Division
	assert(5u * 5u == 25u); // Multiplicacion
	assert(6u + 9u == 30u - 15u); // Suma y Resta
	assert(100u % 3u == 1u); // Resto
		//Prueba del tipo de dato Unsigned
		assert(3000000001u == 3000000000u + 1u);

	// ------------------------------------------ tipo de dato int ---------------------------------------
	assert(4 == 4); // igualacion
	assert(5 != -5); // no igualacion
	assert(-8 < 8); // menor
	assert(26 > -26); // mayor
	assert(66 / -3 <= 0); // Division
	assert(20 * -2 <= 0); // Multiplicacion
	assert(28 - (-5) > 28 - 5); // resta
	assert(26 % (-5) >= 0); // resto
		// Prueba del tipo de Datos Int
		assert(3 * -5 < -8 * 1); // multiplicacion
		assert(26 % 5 >= 0);
		assert(30 % 6 == (-28) - (-28));
		assert((-2) * (-8) >= 0);
		assert((-2) * 1521 <= 5 * 3);
		assert(28 + (-5) == 12 + 11);

	// ------------------------------------------ tipo de dato string ------------------------------------
	assert("barrera"s == "ba"s + "rrera"s); // concatenacion
	assert("barrera"s != "Ba"s + "rrera"s); // no igual
	assert("aa"s > "AA"s); // mayor
	assert ("AB"s < "ab"s); // menor
	assert("barrera"s.length() == 7 ); // cantidad de caracteres del string
		// Pruebas del tipo de dato String
			assert("hola mundo"s != "hola"s + "mundo"s);
			assert("1"s < "2"s);
			assert("lucas"s.length() == "tomas"s.length());
			assert("barrera"s.length() >= "lucas"s.length());
			assert("tomas"s.length() <= "barrera"s.length());
}
