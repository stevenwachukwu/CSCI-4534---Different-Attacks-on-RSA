#include "RSA.h"
#include "chrono"

using namespace std;

using namespace std::chrono;

int decryption(string);


int gcd(int a, int b) {
	int f;
	while ((a % b) > 0) {
		f = a % b;
		a = b;
		b = f;
	}
	return b;
} //the gcd function for the program

RSA::RSA(int key, int number) {
	n = number;
	e = key % totient;
	d = 1;
} //the RSA function for the program

int exp(int message, int exponent, int Number) {
	int i;
	int x;
	int product;
	i = exponent;
	product = 1;
	x = message % Number;
	while (i > 0) {
		if (i % 2 != 0) {
			product = (product * x) % Number;
		}
		x = (x * x) % Number;
		i = i / 2;
	}
	return product;
} //the exponent function for the program

int RSA::encryption(int m) {
	exp(m, e, n);
	int c;
	c = exp(m, e, n);
	return c;
}

int RSA::decryption(int c) {
	exp(c, d, n);
	int m;
	m = exp(c, d, n);
	return m;
}

int RSA::attack1(int C) {
	auto begin = chrono::high_resolution_clock::now();
	auto stop = chrono::high_resolution_clock::now();
	int M = 0;
	while (exp(M, e, n) != C) {
		M++;
	}
	cout << "\nThe time taken for Attack 1 was " << chrono::duration_cast<chrono::nanoseconds>(stop - begin).count() << " nanoseconds\n";
	cout << "The plaintext M was " << M << endl;
	return M;
} //attack 1 function

int RSA::attack2(int C) {
	auto begin = chrono::high_resolution_clock::now();
	auto stop = chrono::high_resolution_clock::now();
	int M;
	for (int i = 2; i < n; i++) {
		if (n % i == 0 && gcd(i, n / i) == 1) {
			p = i;
			q = n / i;
			break;
		}
	}
	totient = (p - 1) * (q - 1);
	d = 1;
	for (;;) {
		if ((e * d) % totient == 1) {
			break;
		}
		else {
			d++;
		}
	}
	M = exp(C, d, n);
	cout << "\nThe time taken for Attack 2 was " << chrono::duration_cast<chrono::nanoseconds>(stop - begin).count() << " nanoseconds\n";
	cout << "The prime value p was " << p << " and the prime value q was " << q << endl;
	cout << "The private key d was " << d << endl;
	cout << "The plaintext M was " << M << endl;
	return M;
} //attack 2 function
