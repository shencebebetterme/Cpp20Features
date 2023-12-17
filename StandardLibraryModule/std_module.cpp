import std;

/*
* The difference between import std and import std.compat is that
* 
import std; imports everything in namespace std from C++ headers (e.g.
std::sort from <algorithm>) and C wrapper headers (e.g. std::fopen from
<cstdio>). It also imports ::operator new etc. from <new>.

import std.compat; imports all of the above, plus the global namespace
counterparts for the C wrapper headers (e.g. ::fopen)

For more information, see
https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2021/p2465r1.pdf
*/

int main()
{
	int a = 1;
	std::cout << std::format("Hello, {} is {}!\n", "value", a);
	return 0;
}
