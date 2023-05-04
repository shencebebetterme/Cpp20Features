#include <iostream>
import mymodule;

int main()
{
	int i = 1;
	int j = 2;
	auto k = myadd(i, j);

	std::cout << k << std::endl;

	return 0;
}