#include <iostream>
#include <string>

std::pair<int, int> comparing (std::string* image, std::string* secret, int imageSize, int secretSize)
{
	unsigned int change = 0;
	unsigned int byte = 1;
	for (int i = 0; i < secretSize; i++)
	{
		for (int j=0; j<8; j++)
		{
			if (image[i][j]!=secret[i][j])
			{
				change++;
			}
		}
	}
	unsigned int changeBefore = 0;
	unsigned int changeAfter = 0;
	for(int i=0; i<imageSize-secretSize; i++)
	{
		for(int j=0; j<8; j++)
		{
			if (image[i][j] != secret[i][j]) changeBefore++;
			if (image[i+secretSize][j] != secret[i+secretSize][j]) changeAfter++;
		}
		if(change>change-changeBefore+changeAfter)
		{
			byte = i + 1;
			change = change - changeBefore + changeAfter;
		}
	}
	return std::pair<int, int>(change, byte);
}

int main()
{
	int imageSize, secretSize;
	std::cin >> imageSize >> secretSize;
	std::string* image = new std::string[imageSize];
	std::string* secret = new std::string[secretSize];
	std::string x;
	for (int i = 0; i < imageSize; i++) {
		std::cin >> x;
		image[i] = x;
	}
	for (int i = 0; i < secretSize; i++) {
		std::cin >> x;
		secret[i] = x;
	}
	auto p = comparing(image, secret, imageSize, secretSize);
	std::cout << "Yes" << std::endl<<p.second<<" "<<p.first;
}
