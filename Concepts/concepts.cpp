#include <concepts>
#include <iterator>


// ------------------------------------------------------------------
// define simple concepts

template<typename T>
concept Small = sizeof(T) <= sizeof(int);

template<typename T>
concept Large = sizeof(T) > sizeof(int) && std::integral<T>;


// ------------------------------------------------------------------
// use concepts

// shorthand notation
template<Small T, Large U>
U add1(T a, U b)
{
	return a + b;
}

// basic requires clauses
template<typename T, typename U> 
	requires Small<T> && Large<U>
U add2(T a, U b)
{
	return a + b;
}

// trailing requires clauses
template<typename T, typename U, typename V>
U add3(T a, U b, V c)
	requires Small<T> || Large<U> && Large<V>
{
	return a + b + c;
}


// ------------------------------------------------------------------
// define complicated concepts with requires expression

template <typename Iter>
concept RandomAccessIterator = std::bidirectional_iterator<Iter>
&& requires (const Iter i, const Iter j, Iter k, const int n)
{
	i + n; i - n; n + i; i[n];    // Required to work on const operands
	k += n; k -= n;               // Only these (left) operands must be non-const
	i < j; i > j; i <= j; i >= j; // Required to work on const operands
};

template<class Iter>
concept RandomAccessIterator = std::bidirectional_iterator<Iter>
&& requires(const Iter i, const Iter j, Iter k, const int n)
{
	{ i - n } -> std::same_as<Iter>;
	{ i + n } -> std::same_as<Iter>; { n + i } -> std::same_as<Iter>;
	{ k += n }-> std::same_as<Iter&>; { k -= n }-> std::same_as<Iter&>;
	{ i[n] }  -> std::same_as<decltype(*i)>;
	{ i < j } -> std::convertible_to<bool>;
	// ... same for i > j, i <= j, and i >= j
};

template<class Container>
concept RandomAccessContainer = requires (Container c)
{
	{ c.begin() } -> RandomAccessIterator;
	// ...
};


int main()
{
	return 0;
}
