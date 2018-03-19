#include"source.h";
#ifdef F4
struct mat2
{
	int a11;
	int a12;
	int a21;
	int a22;
	mat2(int a11, int a12, int a21, int a22)
	{
		this->a11 = a11;
		this->a12 = a12;
		this->a21 = a21;
		this->a22 = a22;
	}
};

mat2 mult(mat2 m1, mat2 m2)
{
	mat2 rlt(m1.a11 * m2.a11 + m1.a12 * m2.a21, m1.a11 * m2.a12 + m1.a12 * m2.a22,
		m1.a21 * m2.a11 + m1.a22 * m2.a21, m1.a21 * m2.a12 + m1.a22 * m2.a22);
	return rlt;
}

int f(int n)
{
	if (n <= 2)
		return 1;
	n -= 2;
	int k = 0;
	int mask = 1;
	mat2 km(1, 0, 0, 1);
	mat2 mm(0, 1, 1, 1);
	while (k < n)
	{
		if (n & mask)
		{
			k += mask;
			km = mult(km, mm);
		}
		cout << "m1 " << mask << endl;
		mask = (mask << 1);
		cout << "m2 " << mask << endl;
		mm = mult(mm, mm);
	}
	return km.a12 + km.a22;
}
#endif
