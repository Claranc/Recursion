#include"source.h";
#ifdef F1
int f(int x)
{
	// P0
	if (x <= 2)
		return 1;
	return f(x - 1) + f(x - 2); // P1 P2
}
int f(int n, vector<int>& buff)
{
	if (buff[n] > 0)
		return buff[n];
	buff[n] = f(n - 1) + f(n - 2);
	return buff[n];
}
#endif
