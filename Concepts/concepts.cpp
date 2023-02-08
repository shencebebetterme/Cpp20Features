
template<typename T>
concept Small = sizeof(T) <= sizeof(int);

int main()
{
	return 0;
}