#include <iostream>
#include<bitset>

using namespace std;

class XOR
{
public:
	XOR(bool r1, bool r2);
	XOR(bool r1, bool r2, bool r3);
	XOR(bool r1, bool r2, bool r3, bool r4);
	XOR(bool r1, bool r2, bool r3, bool r4, bool x);
	~XOR();
	bitset<1> do_xor_with_number(int n);
private:
	bitset<1> b_r1;
	bitset<1> b_r2;
	bitset<1> b_r3;
	bitset<1> b_r4;
	bitset<1> b_x;
};

XOR::XOR(bool r1, bool r2)
{
	b_r1[0] = r1;
	b_r2[0] = r2;
}


XOR::XOR(bool r1, bool r2, bool r3)
{
	b_r1[0] = r1;
	b_r2[0] = r2;
	b_r3[0] = r3;
}

XOR::XOR(bool r1, bool r2, bool r3, bool r4)
{
	b_r1[0] = r1;
	b_r2[0] = r2;
	b_r3[0] = r3;
	b_r4[0] = r4;
}

XOR::XOR(bool r1, bool r2, bool r3, bool r4, bool x)
{
	b_r1[0] = r1;
	b_r2[0] = r2;
	b_r3[0] = r3;
	b_r4[0] = r4;
	b_x[0] = x;
}

XOR::~XOR()
{

}

bitset<1> XOR::do_xor_with_number(int n)
{
	if (n == 2)
	{
		return (b_r1 ^= b_r2);
	}

	else if (n == 3)
	{
		return (b_r1 ^= b_r2 ^= b_r3);
	}

	else if (n == 4)
	{
		return (b_r1 ^= b_r2 ^= b_r3 ^= b_r4);
	}

	else if (n == 5)
	{
		return (b_r1 ^= b_r2 ^= b_r3 ^= b_r4 ^= b_x);
	}

	else
	{
		cout << "can't match number" << endl;
	}
}
