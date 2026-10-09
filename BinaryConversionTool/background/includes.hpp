#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class c_Vars {
public:
	int length = 0;
	int octetCount = 0;

	int bitCount = 0;
	int bitPosition = 0;
	int bitValue = 0;
	
	std::string input;
	std::string output;
	std::string binary;
	std::string hex;
	std::string decimal;
	std::string octal;
	std::string plainText;
	std::string passkey;


	void clear() {
		input.clear();
		output.clear();
		binary.clear();
		hex.clear();
		decimal.clear();
		octal.clear();
	}
};

c_Vars vars;

class c_Logging {
public:
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	void modifyConsoleColor(int color) {
		SetConsoleTextAttribute(hCons, color);
	}
	void Success(std::string message) {
		std::cout << "[+] " << message << std::endl;
	}
	void Error(std::string message) {
		SetConsoleTextAttribute(hCons, 4);
		std::cout << "[-] " << message << std::endl;
	}
	void Info(std::string message) {
		std::cout << "[*] " << message << std::endl;
	}
	void clear() {
		system("cls");
	}
};

c_Logging logger;