#pragma once
#include <iostream>

int gcd(int e, int totient);

class RSA
{
	int p;
	int q;
	int n;
	int e;
	int d;
	int totient;

public:
	RSA(int key, int number);
	int encryption(int M);
	int decryption(int C);
	int attack1(int C);
	int attack2(int C);
};
