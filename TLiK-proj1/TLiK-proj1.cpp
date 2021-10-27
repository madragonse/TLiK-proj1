#include <iostream>
#include <fstream>
#include <math.h>
#include <string>


void proj1(std::string filename = "ENG_1.txt")
{
	std::ifstream inputFile;
	size_t size = 0;

	int charAmount[256] = { 0 };
	float charPropability[256] = { 0 };
	int charDataSize[256] = { 0 };

	inputFile.open(filename, std::ios::in | std::ios::binary | std::ios::ate);
	char* inp;

	inputFile.seekg(0, std::ios::end);
	size = inputFile.tellg();
	inputFile.seekg(0, std::ios::beg);

	inp = new char[size + 1];
	inputFile.read(inp, size);
	inp[size] = '\0';

	int wholeCount = 0;
	for (size_t i = 0; i < strlen(inp); i++)
	{
		char t = inp[i];
		charAmount[t]++;
		wholeCount++;
	}

	for (int i = 0; i < 256; i++)
	{
		charPropability[i] = double(charAmount[i] / double(wholeCount));
	}

	for (int i = 0; i < 256; i++)
	{
		if (charPropability[i] == 0)
		{
			continue;
		}
		charDataSize[i] = (int)ceil(log2(1 / charPropability[i]));
	}

	//printf("\nAll letters counts\n");
	//for (int i = 0; i < 256; i++) {
	//	printf("Char: %d (%c) - %d\n", i, i, charAmount[i]);
	//}

	printf("\nAll letters propability\n");
	for (int i = 0; i < 256; i++) {
		if (charPropability[i] != 0)
		printf("Char: %d (%c) - %f\n", i, i, charPropability[i]);
	}

	printf("\nAll letters data size in bits\n");
	for (int i = 0; i < 256; i++) {
		if (charPropability[i] != 0)
		printf("Char: %d (%c) - %d\n", i, i, charDataSize[i]);
	}

	float messageEntropy = 0;

	for (int i = 0; i < 256; i++)
	{
		if (charPropability[i] > 0)
		{
			messageEntropy += charPropability[i] * charDataSize[i];
		}

	}


	printf("\nAll letters count: %d\n", wholeCount);
	printf("Message entopy: %f\n", messageEntropy);
}


int main()
{
	printf("\nText in polish language--------------------\n");
	proj1("POL_LIT_1.txt");
	printf("\nText in english language-------------------\n");
	proj1("ENG_1.txt");
	printf("\nPolish text thematically IT-------------------\n");
	proj1("POL_INF_1.txt");
	getchar();
	return 0;
}