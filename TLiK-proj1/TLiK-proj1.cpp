#include <iostream>
#include <fstream>
#include <math.h>

int main()
{
	std::ifstream inputFile;
	size_t size = 0;

	int charAmount[256] = { 0 };
	float charPropability[256] = { 0 };
	int charDataSize[256] = { 0 };

	inputFile.open("ENG_1.txt", std::ios::in | std::ios::binary | std::ios::ate);
	char* inp;

	inputFile.seekg(0, std::ios::end);
	size = inputFile.tellg();
	inputFile.seekg(0, std::ios::beg);

	inp = new char[size + 1];
	inputFile.read(inp, size);
	inp[size] = '\0';

	int wholeCount = 0;
	//print data
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

	printf("\nAll letters counts\n");
	for (int i = 0; i < 256; i++) {
		printf("Char: %d (%c) - %d\n", i, i, charAmount[i]);
	}

	printf("\nAll letters propability\n");
	for (int i = 0; i < 256; i++) {
		printf("Char: %d (%c) - %f\n", i, i, charPropability[i]);
	}

	printf("\nAll letters data size in bits\n");
	for (int i = 0; i < 256; i++) {
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


	printf("All letters count: %d\n", wholeCount);
	printf("Message entopy: %f\n", messageEntropy);

	getchar();
	return 0;
}