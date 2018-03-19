#include"source.h";
#ifdef F3
int f(int n)
{
	vector<int> a(2, 1);
	for (int i = 2; i < n; i++)
		a.push_back(a[i - 1] + a[i - 2]);
	return a[n - 1];
}
#endif
