#include "md5.h"
#include <iostream>

using namespace std;

void PrintMD5(const string &str, MD5 &md5) {
	cout << "Digest of \"" << str << "\": "; 
	cout << md5.toString() << endl;
}


int main() {

	MD5 md5;	

	string message;
	cout << "Input the message: ";
	cin >> message;	

	md5.update(message);
	PrintMD5(message, md5);
	 
	return 0;
}