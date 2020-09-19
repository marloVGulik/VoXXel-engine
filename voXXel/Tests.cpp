#include "Tests.h"

void runTests() {

	int stepSize = 8;
	int bitAmount = 3;
	char type = ' ';

	int dataSize = 0;
	unsigned long long int arraySize = 0;

	float structSize = 0;
	int totalByteAmount = 0;


	std::cout << "Type step size (integer pls): ";
	std::cin >> stepSize;
	std::cout << "\nType array size (typeof): ";
	std::cin >> type;

	switch (type)
	{
	case('l'):
		dataSize = 8;
		arraySize = 18446744073709551615;
		break;
	case('i'):
		dataSize = 4;
		arraySize = 4294967295;
		break;
	case('s'):
		dataSize = 2;
		arraySize = 65535;
		break;
	default:
		dataSize = 4;
		arraySize = 4294967295;
		break;
	}




	structSize = float((3 + dataSize * 8) / 8);
	std::cout << "\nTotal struct size in bytes (rounded): " << structSize << "\n";

	unsigned long long int number = 0;
	unsigned int mp = 1;
	do {
		number += std::pow(stepSize, mp) * structSize;
		std::cout << "Number: " << number << ", power: " << mp << "\n";
		mp++;
	} while (std::pow(stepSize, mp) < arraySize);
	mp--;
	std::cout << "\nMax power multiplier: " << mp << "\n\n";

	std::cout << "Total size of all (In KB): " << unsigned long long int((structSize * arraySize) / 1000) << "\n";
	std::cout << "Total size of all (In MB): " << unsigned long long int((structSize * arraySize) / 1000000) << "\n";
	std::cout << "Total size of all (In GB): " << unsigned long long int((structSize * arraySize) / 1000000000) << "\n\n";

	std::cout << "Total size of all (In KB): " << number / 1000 << "\n";
	std::cout << "Total size of all (In MB): " << number / 1000000 << "\n";
	std::cout << "Total size of all (In GB): " << number / 1000000000 << "\n\n";

	std::cout << "Dimensions: " << std::cbrt(std::pow(stepSize, mp)) << " x " << std::cbrt(std::pow(stepSize, mp)) << " x " << std::cbrt(std::pow(stepSize, mp)) << "\n\n\n\n";


	int* pointerSizeTest = nullptr;
	std::cout << sizeof(pointerSizeTest) << ", " << sizeof(*pointerSizeTest);
}