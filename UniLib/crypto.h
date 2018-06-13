#pragma once
#include "stdafx.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class crypto {
public:
	//Encrypts a file
	//file = the file to be encrypted, needs path too!
	//output = the file that will become after encryption, needs path too!
	//deleteOld = delete the old file
	//encryptionType = choose the encryption algorithm
	void encryptFile(string file, string output, bool deleteOld, int encryptionType, string password, int stringTypeEncryption) {
		if (encryptionType == 3) {
			//open the file
			ifstream infile(file);

			string data = "";
			string line;

			//get the file data
			while (getline(infile, line)) {
				data += line;
			}

			//encrypt the data
			data = crypto::encryptString(data, stringTypeEncryption, password);

			//close the file
			infile.close();

			//delete the old file
			if (remove(file.c_str()) != 0) {
				Utils::log("Error on deleting the old file!", false, true);
				return;
			}

			//create the file and open the new file
			ofstream outfile(file);

			//write the new data
			outfile << data;

			//close the file
			outfile.close();
		}
	}
	//Decrypts a file
	//file = the file to be decrypted, needs path too!
	//output = the file that will become after decryption, needs path too!
	//deleteOld = delete the old file
	//encryptionType = choose the decryption algorithm
	void decryptFile(string file, string output, bool deleteOld, int encryptionType, string password, int stringTypeEncryption) {
		if (encryptionType == 3) {
			//open the file
			ifstream infile(file);

			string data = "";
			string line;

			//get the file data
			while (getline(infile, line)) {
				data += line;
			}

			//ecnrypt the data
			data = crypto::decryptString(data, stringTypeEncryption, password);

			//close the file
			infile.close();

			//delete the old file
			if (remove(file.c_str()) != 0) {
				Utils::log("Error on deleting the old file!", false, true);
				return;
			}

			//create the file and open the new file
			ofstream outfile(file);

			//write the new data
			outfile << data;

			//close the file
			outfile.close();
		}
	}
	//Encrypts a string
	//encryptionType = choose the encryption algorithm
	string encryptString(string txt, int encryptionType, string password) {
		string final = "";

		if (encryptionType == 2) {
			//make sure that the key is at least as long as the txt is
			string tmp(password);
			while (password.size() < txt.size())
				password += tmp;

			//encrypt the string
			for (string::size_type i = 0; i < txt.size(); i++)
				txt[i] ^= password[i];

			final = txt;
		}

		return final;
	}
	//Decrypts a string
	//encryptionType = choose the decryption algorithm
	string decryptString(string txt, int encryptionType, string password) {
		string final = "";

		if (encryptionType == 2) {
			final = (txt, encryptionType, password);
		}

		return final;
	}
	//Password isnt needed for every algorithm!

	//Utils

	//Gets the encryption type id by name, used for the encryption functions
	int encryptionType(string type) {
		int id = 0;

		if (type == "AES" || type == "aes") {
			id = 1;
		}
		else if (type == "XOR" || type == "xor") {
			id = 2;
		}
		else if (type == "txt" || type == "text") {
			id = 3;
		}

		return id;
	}
};