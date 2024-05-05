/*This program is my solution for the last question of HW#2. This program was created to see which two RSA attacks run the fastest.
Author: Steve Nwachukwu
Course: Cryptography and Data Security
Semester: Spring 2024
Professor: Chandra
*/

#include "RSA.h"

using namespace std;

int main() {
	int e; //variable for public key
	int n; //variable for the modulo
	int ciphertext; //variable for ciphertext
	
	cout << "Please enter in the public key: ";
	cin >> e;

	cout << "Please enter in the modulo: ";
	cin >> n;

	cout << "Please enter in the ciphertext: ";
	cin >> ciphertext;

	RSA processor(e,n); //RSA constructor that takes in the key and modulo
	cout << "\nFrom Attack 1: ";
	int M1 = processor.attack1(ciphertext); //RSA constructor utilizes the attack 1 function

	cout << "\nFrom Attack 2: ";
	int M2 = processor.attack2(ciphertext); //RSA constructor utilizes the attack 2 function

	return 0;
}
