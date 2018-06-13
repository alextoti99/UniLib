#pragma once
#include "stdafx.h"
#include <iostream>
#include <ctime>

using namespace std;

class Utils {
public:
	//Will log the string txt, in the console (if its console program will be show)
	static void log(string txt, bool endLine, bool error) {
		if (txt.c_str() == NULL || txt.length() <= 0) {
			cout << "Cant log empty text!";
			return;
		}

		if (error) {
			perror(txt.c_str());
		}
		else {
			if (endLine) {
				cout << txt.c_str() << endl;
			}
			else {
				cout << txt.c_str();
			}
		}
	}

	//Will log the string text at the file path you choose, with name of the file the current time
	static void log(string txt, string filePath) {
		if (txt.length() <= 0) {
			log("Invalid log text!", false, true);
			return;
		}
		else if (filePath.length() <= 0) {
			log("Invalid file path!", false, true);
			return;
		}

		time_t t = time(0); //get time now
		tm* now = localtime(&t);

		//get the year/money/ay/hour/minute/second
		int year = (now->tm_year);
		int month = (now->tm_mon);
		int day = (now->tm_mday);
		int hour = (now->tm_hour);
		int minute = (now->tm_min);
		int second = (now->tm_sec);

		//stracture of the fileName = year/money/ay/hour/minute/second
		string f1 = year + "/" + month;
		string f2 = "/" + day;
		string f3 = "/" + hour;
		string f4 = "/" + minute;
		string f5 = "/" + second;

		string fileName = f1 + f2 + f3 + f4 + f5;
		string fullFilePath = filePath + fileName + ".txt";

		//create the file and open the new file
		ofstream outfile(fullFilePath.c_str());

		//write the new data
		outfile << txt << "\n";

		//close the file
		outfile.close();
	}
};