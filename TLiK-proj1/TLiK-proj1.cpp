#include <iostream>
#include <fstream>

int main()
{
	std::ifstream inputFile;
	size_t size = 0; // here

	int charAmount[256] = { 0 };

	inputFile.open("ENG_1.txt", std::ios::in | std::ios::binary | std::ios::ate);
	char* inp;

	inputFile.seekg(0, std::ios::end);
	size = inputFile.tellg();
	inputFile.seekg(0, std::ios::beg);

	inp = new char[size + 1];
	inputFile.read(inp, size);
	inp[size] = '\0';

	//print data
	for (size_t i = 0; i < strlen(inp); i++)
	{
		char t = inp[i];
		charAmount[t]++;
	}

	for (int i = 0; i < 256; i++) {
		printf("Char: %d (%c) - %d\n", i, i, charAmount[i]);
	}

	getchar();
	return 0;
}