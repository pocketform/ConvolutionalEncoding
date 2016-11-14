#include <vector>
#include <fstream>
#include <sstream>
#include"xor_gate.h"


using namespace std;

enum State
{
	s_000,
	s_001,
	s_010,
	s_011,
	s_100,
	s_101,
	s_110,
	s_111,
};

struct InState
{
	bool in;

	int hamming = 0;

	bitset<2> b_output;

	InState* last_s = NULL;

	InState* t1;
	InState* t0;

	State now_s;
};

class Way_decoding
{
public:
	Way_decoding(int xor1[4], int xor2[4], string oput);
	~Way_decoding();
	InState get_instate() { return *my_instate; }
	void get_oder_bit();
	State get_state() { return o_state; }
	void output_get(int xor1, int xor2);
	void hamming_get(bitset<2> b_output, InState** mstate);
	void hanming_get(bitset<1> b_op1, bitset<1> b_op2, InState** mstate);

	void set_in(InState* mstate, bool new_in);
	void set_output(InState* mstate, bitset<1> new_op1,bitset<1> new_op2);
	void set_output(InState* mstate, bitset<2> new_output);
	void set_state(InState* mstate, State new_state);
	void change_state(InState** mstate);
	void next_state(InState** mstate, bitset<1> new_op1, bitset<1> new_op2);
	void in_get(InState* state);
	bool find_answer(State state, bitset<2> output);

	void easy_mode(bitset<2> out);
	void easy_answer();

	void finish(vector<bool> my_end);
	void go_to_de_it();

	void text_it();

private:
	int xor1_1;
	int xor1_2;
	int xor1_3;
	int xor1_4;

	int xor2_1;
	int xor2_2;
	int xor2_3;
	int xor2_4;

	string s_out;

	bitset<2> _0000;
	bitset<2> _0001;
	bitset<2> _0010;
	bitset<2> _0011;
	bitset<2> _0100;
	bitset<2> _0101;
	bitset<2> _0110;
	bitset<2> _0111;
	bitset<2> _1000;
	bitset<2> _1001;
	bitset<2> _1010;
	bitset<2> _1011;
	bitset<2> _1100;
	bitset<2> _1101;
	bitset<2> _1110;
	bitset<2> _1111;

	bitset<32> my_output;

	vector<bool> vb_in;
	vector<bool> save_me;

	State o_state = s_000;

	InState* my_instate;
};

Way_decoding::Way_decoding(int xor1[4], int xor2[4], string oput)
{
	xor1_1 = xor1[0];
	xor1_2 = xor1[1];
	xor1_3 = xor1[2];
	xor1_4 = xor1[3];

	xor2_1 = xor2[0];
	xor2_2 = xor2[1];
	xor2_3 = xor2[2];
	xor2_4 = xor2[3];

	s_out = oput;

	my_instate = new InState;
	my_instate->now_s = s_000;

	
}

Way_decoding::~Way_decoding()
{
}

void Way_decoding::get_oder_bit()
{
	_0000[0] = my_output[0];
	_0000[1] = my_output[1];
	_0001[0] = my_output[2];
	_0001[1] = my_output[3];
	_0010[0] = my_output[4];
	_0010[1] = my_output[5];
	_0011[0] = my_output[6];
	_0011[1] = my_output[7];
	_0100[0] = my_output[8];
	_0100[1] = my_output[9];
	_0101[0] = my_output[10];
	_0101[1] = my_output[11];
	_0110[0] = my_output[12];
	_0110[1] = my_output[13];
	_0111[0] = my_output[14];
	_0111[1] = my_output[15];
	_1000[0] = my_output[16];
	_1000[1] = my_output[17];
	_1001[0] = my_output[18];
	_1001[1] = my_output[19];
	_1010[0] = my_output[20];
	_1010[1] = my_output[21];
	_1011[0] = my_output[22];
	_1011[1] = my_output[23];
	_1100[0] = my_output[24];
	_1100[1] = my_output[25];
	_1101[0] = my_output[26];
	_1101[1] = my_output[27];
	_1110[0] = my_output[28];
	_1110[1] = my_output[29];
	_1111[0] = my_output[30];
	_1111[1] = my_output[31];

	cout << _0000 << endl;
	cout << _0001 << endl;
	cout << _0010 << endl;
	cout << _0011 << endl;
	cout << _0100 << endl;
	cout << _0101 << endl;
	cout << _0110 << endl;
	cout << _0111 << endl;
	cout << _1000 << endl;
	cout << _1001 << endl;
	cout << _1010 << endl;
	cout << _1011 << endl;
	cout << _1100 << endl;
	cout << _1101 << endl;
	cout << _1110 << endl;
	cout << _1111 << endl;
	my_output.reset();
}

//TODO need finish all posibility
void Way_decoding::output_get(int xor1_n, int xor2_n)
{
	
	if (xor1_n == 2 && xor2_n == 2)
	{
		//int ar = 0;
		int s = 0;
		int x = 1;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					for (int n = 0; n < 2; n++)
					{
						bool b_x1_1;
						if (xor1_1 == 0)
						{
							b_x1_1 = i;
						}
						if (xor1_1 == 1)
						{
							b_x1_1 = j;
						}
						if (xor1_1 == 2)
						{
							b_x1_1 = k;
						}
						if (xor1_1 == 3)
						{
							b_x1_1 = n;
						}
						bool b_x1_2;
						if (xor1_2 == 0)
						{
							b_x1_2 = i;
						}
						if (xor1_2 == 1)
						{
							b_x1_2 = j;
						}
						if (xor1_2 == 2)
						{
							b_x1_2 = k;
						}
						if (xor1_2 == 3)
						{
							b_x1_2 = n;
						}
						bool b_x2_1;
						if (xor2_1 == 0)
						{
							b_x2_1 = i;
						}
						if (xor2_1 == 1)
						{
							b_x2_1 = j;
						}
						if (xor2_1 == 2)
						{
							b_x2_1 = k;
						}
						if (xor2_1 == 3)
						{
							b_x2_1 = n;
						}
						bool b_x2_2;
						if (xor2_2 == 0)
						{
							b_x2_2 = i;
						}
						if (xor2_2 == 1)
						{
							b_x2_2 = j;
						}
						if (xor2_2 == 2)
						{
							b_x2_2 = k;
						}
						if (xor2_2 == 3)
						{
							b_x2_2 = n;
						}

						XOR xor1(b_x1_1, b_x1_2);
						XOR xor2(b_x2_1, b_x2_2);

						bitset<1> output1 = xor1.do_xor_with_number(2);
						bitset<1> output2 = xor2.do_xor_with_number(2);

						my_output[s] = output1[0];
						my_output[x] = output2[0];

						cout << i << j << k << n << "\n";
						cout << output1[0] <<output2[0] << endl;
						//cout << "output1 is " << my_output[s] << " output2 is " << my_output[x] << endl;

						s++;
						s++;
						x++;
						x++;

					}
				}
			}
		}
		get_oder_bit();
		//text_it();
	}

	if (xor1_n == 2 && xor2_n == 3)
	{
		XOR xor1(xor1_1, xor1_2);
		XOR xor2(xor2_1, xor2_2);

		//int ar = 0;
		int s = 0;
		int x = 1;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					for (int n = 0; n < 2; n++)
					{


						bitset<1> output1 = xor1.do_xor_with_number(2);
						bitset<1> output2 = xor2.do_xor_with_number(3);

						my_output[s] = output1[0];
						my_output[x] = output2[0];

						//cout << i << j << k << n << "\n";
						//cout << "output1 is " << output1[0] << " output2 is " << output2[0] << endl;
						//cout << "output1 is " << my_output[s] << " output2 is " << my_output[x] << endl;

						s++;
						s++;
						x++;
						x++;

					}
				}
			}
		}
		Way_decoding::get_oder_bit();
	}

	if (xor1_n == 2 && xor2_n == 4)
	{
		XOR xor1(xor1_1, xor1_2);
		XOR xor2(xor2_1, xor2_2);

		//int ar = 0;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					for (int n = 0; n < 2; n++)
					{
						int s = 0;
						int x = 1;

						bitset<1> output1 = xor1.do_xor_with_number(2);
						bitset<1> output2 = xor2.do_xor_with_number(4);

						my_output[s] = output1[0];
						my_output[x] = output2[0];

						//cout << i << j << k << n << "\n";
						//cout << "output1 is " << output1[0] << " output2 is " << output2[0] << endl;
						//cout << "output1 is " << my_output[s] << " output2 is " << my_output[x] << endl;

						s++;
						x++;

					}
				}
			}
		}
		Way_decoding::get_oder_bit();
	}

	if (xor1_n == 3 && xor2_n == 2)
	{
		XOR xor1(xor1_1, xor1_2, xor1_3);
		XOR xor2(xor2_1, xor2_2);
		int s = 0;
		int x = 1;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					for (int n = 0; n < 2; n++)
					{


						bitset<1> output1 = xor1.do_xor_with_number(3);
						bitset<1> output2 = xor2.do_xor_with_number(2);

						my_output[s] = output1[0];
						my_output[x] = output2[0];

						//cout << i << j << k << n << "\n";
						//cout << "output1 is " << output1[0] << " output2 is " << output2[0] << endl;
						//cout << "output1 is " << my_output[s] << " output2 is " << my_output[x] << endl;

						s++;
						s++;
						x++;
						x++;
					}
				}
			}
		}
		Way_decoding::get_oder_bit();
	}

	if (xor1_n == 3 && xor2_n == 3)
	{
		XOR xor1(xor1_1, xor1_2);
		XOR xor2(xor2_1, xor2_2);

		//int ar = 0;
		int s = 0;
		int x = 1;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					for (int n = 0; n < 2; n++)
					{


						bitset<1> output1 = xor1.do_xor_with_number(3);
						bitset<1> output2 = xor2.do_xor_with_number(3);

						my_output[s] = output1[0];
						my_output[x] = output2[0];

						//cout << i << j << k << n << "\n";
						//cout << "output1 is " << output1[0] << " output2 is " << output2[0] << endl;
						//cout << "output1 is " << my_output[s] << " output2 is " << my_output[x] << endl;

						s++;
						s++;
						x++;
						x++;

					}
				}
			}
		}
		get_oder_bit();
	}

	if (xor1_n == 3 && xor2_n == 4)
	{
		XOR xor1(xor1_1, xor1_2);
		XOR xor2(xor2_1, xor2_2);

		int ar = 0;
		int s = 0;
		int x = 1;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					for (int n = 0; n < 2; n++)
					{


						bitset<1> output1 = xor1.do_xor_with_number(3);
						bitset<1> output2 = xor2.do_xor_with_number(4);

						my_output[s] = output1[0];
						my_output[x] = output2[0];

						//cout << i << j << k << n << "\n";
						//cout << "output1 is " << output1[0] << " output2 is " << output2[0] << endl;
						//cout << "output1 is " << my_output[s] << " output2 is " << my_output[x] << endl;

						s++;
						s++;
						x++;
						x++;

					}
				}
			}
		}
		get_oder_bit();
	}

	if (xor1_n == 4 && xor2_n == 2)
	{
		XOR xor1(xor1_1, xor1_2, xor1_3, xor1_4);
		XOR xor2(xor2_1, xor2_2);
		int s = 0;
		int x = 1;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					for (int n = 0; n < 2; n++)
					{



						bitset<1> output1 = xor1.do_xor_with_number(4);
						bitset<1> output2 = xor2.do_xor_with_number(2);

						my_output[s] = output1[0];
						my_output[x] = output2[0];

						//cout << i << j << k << n << "\n";
						//cout << "output1 is " << output1[0] << " output2 is " << output2[0] << endl;
						//cout << "output1 is " << my_output[s] << " output2 is " << my_output[x] << endl;

						s++;
						s++;
						x++;
						x++;
					}
				}
			}
		}
		get_oder_bit();
	}

	if (xor1_n == 4 && xor2_n == 3)
	{
		XOR xor1(xor1_1, xor1_2);
		XOR xor2(xor2_1, xor2_2);

		//int ar = 0;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					for (int n = 0; n < 2; n++)
					{
						int s = 0;
						int x = 1;

						bitset<1> output1 = xor1.do_xor_with_number(4);
						bitset<1> output2 = xor2.do_xor_with_number(3);

						my_output[s] = output1[0];
						my_output[x] = output2[0];

						//cout << i << j << k << n << "\n";
						//cout << "output1 is " << output1[0] << " output2 is " << output2[0] << endl;
						//cout << "output1 is " << my_output[s] << " output2 is " << my_output[x] << endl;

						s++;
						x++;

					}
				}
			}
		}
		get_oder_bit();
	}

	if (xor1_n == 4 && xor2_n == 4)
	{
		XOR xor1(xor1_1, xor1_2);
		XOR xor2(xor2_1, xor2_2);

		//int ar = 0;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					for (int n = 0; n < 2; n++)
					{
						int s = 0;
						int x = 1;

						bitset<1> output1 = xor1.do_xor_with_number(4);
						bitset<1> output2 = xor2.do_xor_with_number(4);

						my_output[s] = output1[0];
						my_output[x] = output2[0];

						//cout << i << j << k << n << "\n";
						//cout << "output1 is " << output1[0] << " output2 is " << output2[0] << endl;
						//cout << "output1 is " << my_output[s] << " output2 is " << my_output[x] << endl;

						s++;
						x++;

					}
				}
			}
		}
		get_oder_bit();
	}

}
void Way_decoding::hamming_get(bitset<2> b_output, InState** mstate)
{
	if (b_output[0] != (*mstate)->b_output[0])
	{
		(*mstate)->hamming = (*mstate)->hamming + 1;
	}
	if (b_output[1] != (*mstate)->b_output[1])
	{
		(*mstate)->hamming = (*mstate)->hamming + 1;
	}

}
void Way_decoding::hanming_get(bitset<1> b_op1, bitset<1> b_op2, InState ** mstate)
{
	//if (b_op1[0] != )
	//{

	//}
}
void Way_decoding::set_in(InState * mstate, bool new_in)
{
	mstate->in = new_in;
}
void Way_decoding::set_output(InState * mstate, bitset<1> new_op1, bitset<1> new_op2)
{
	mstate->b_output[0] = new_op1[0];
	mstate->b_output[1] = new_op2[0];
}
void Way_decoding::set_output(InState * mstate, bitset<2> new_output)
{
	mstate->b_output = new_output;
}
void Way_decoding::set_state(InState * mstate, State new_state)
{
	mstate->now_s = new_state;
}
void Way_decoding::change_state(InState ** mstate)
{
	if ((*mstate)->now_s == s_000)
	{
		set_state((*mstate)->t0, s_000);
		set_output((*mstate)->t0, _0000);
		set_state((*mstate)->t1, s_100);
		set_output((*mstate)->t1, _1000);
	}
	if ((*mstate)->now_s == s_100)
	{
		set_state((*mstate)->t0, s_010);
		set_output((*mstate)->t0, _0100);
		set_state((*mstate)->t1, s_110);
		set_output((*mstate)->t1, _1100);
	}
	if ((*mstate)->now_s == s_010)
	{
		set_state((*mstate)->t0, s_001);
		set_output((*mstate)->t0, _0010);
		set_state((*mstate)->t1, s_101);
		set_output((*mstate)->t1, _1010);
	}
	if ((*mstate)->now_s == s_110)
	{
		set_state((*mstate)->t0, s_011);
		set_output((*mstate)->t0, _0110);
		set_state((*mstate)->t1, s_111);
		set_output((*mstate)->t1, _1110);
	}
	if ((*mstate)->now_s == s_001)
	{
		set_state((*mstate)->t0, s_000);
		set_output((*mstate)->t0, _0001);
		set_state((*mstate)->t1, s_100);
		set_output((*mstate)->t1, _1001);
	}
	if ((*mstate)->now_s == s_101)
	{
		set_state((*mstate)->t0, s_010);
		set_output((*mstate)->t0, _0101);
		set_state((*mstate)->t1, s_110);
		set_output((*mstate)->t1, _1101);
	}
	if ((*mstate)->now_s == s_011)
	{
		set_state((*mstate)->t0, s_001);
		set_output((*mstate)->t0, _0011);
		set_state((*mstate)->t1, s_101);
		set_output((*mstate)->t1, _1011);
	}
	if ((*mstate)->now_s == s_111)
	{
		set_state((*mstate)->t0, s_011);
		set_output((*mstate)->t0, _0111);
		set_state((*mstate)->t1, s_111);
		set_output((*mstate)->t1, _1111);
	}
}
void Way_decoding::next_state(InState ** mstate , bitset<1> new_op1, bitset<1> new_op2)
{
	InState* temp1 = new InState;
	InState* temp0 = new InState;

	(*mstate)->t1 = temp1;
	(*mstate)->t0 = temp0;
	
	set_in((*mstate)->t1, 1);
	set_in((*mstate)->t0, 0);
	change_state(mstate);

}
void Way_decoding::in_get(InState* state)
{
	if (state->last_s != NULL)
	{
		vb_in.push_back(state->in);
		Way_decoding::in_get(state->last_s);
	}
}
//bool Way_decoding::find_answer(State state, bitset<2> output)
//{
//	//if (state = s_000)
//	//{
//	//	if (true)
//	//	{
//
//	//	}
//	//}
//}
void Way_decoding::easy_mode(bitset<2> out)
{

	if (o_state == s_000)
	{
		if (out == _0000 )
		{
			save_me.push_back(0);
			o_state = s_000;
		}
		else if (out == _1000)
		{
			save_me.push_back(1);
			o_state = s_100;
		}
	}
	else if (o_state == s_100)
	{
		if (out == _0100)
		{
			save_me.push_back(0);
			o_state = s_010;
		}
		else if (out == _1100)
		{
			save_me.push_back(1);
			o_state = s_110;
		}
	}
	else if (o_state == s_010)
	{
		if (out == _0010)
		{
			save_me.push_back(0);
			o_state = s_001;
		}
		else if (out == _1010)
		{
			save_me.push_back(1);
			o_state = s_101;
		}
	}
	else if (o_state == s_110)
	{
		if (out == _0110)
		{
			save_me.push_back(0);
			o_state = s_011;
		}
		else if (out == _1110)
		{
			save_me.push_back(1);
			o_state = s_111;
		}
	}
	else if (o_state == s_001)
	{
		if (out == _0001)
		{
			save_me.push_back(0);
			o_state = s_000;
		}
		else if (out == _1001)
		{
			save_me.push_back(1);
			o_state = s_100;
		}
	}
	else if (o_state == s_101)
	{
		if (out == _0101)
		{
			save_me.push_back(0);
			o_state = s_010;
		}
		else if (out == _1101)
		{
			save_me.push_back(1);
			o_state = s_110;
		}
	}
	else if (o_state == s_011)
	{
		if (out == _0011)
		{
			save_me.push_back(0);
			o_state = s_001;
		}
		else if (out == _1011)
		{
			save_me.push_back(1);
			o_state = s_101;
		}
	}
	else if (o_state == s_111)
	{
		if (out == _0111)
		{
			save_me.push_back(0);
			o_state = s_011;
		}
		else if (out == _1111)
		{
			save_me.push_back(1);
			o_state = s_111;
		}
	}
}

inline void Way_decoding::easy_answer()
{
	string name_txt = "easy mode.txt";
	stringstream stream;

	cout << "creat a txt named " << name_txt << endl;
	cout << "waiting....." << endl;

	for (vector<bool>::iterator it = save_me.begin(); it != save_me.end(); ++it)
	{
		char out;
		ofstream ofs(name_txt, ofstream::app);

		stream << (*it);
		stream >> out;
		stream.clear();
		
		ofs.put(out);
		//cout << ' ' << *it;
		//cout << '\n';

		ofs.close();
	}
}

inline void Way_decoding::finish(vector<bool> my_end)
{
	//string name_txt;
	//string str_end;
	//stringstream stream;
	//char op1;
	//char op2;

	//stream << my_end;
	//stream >> str_end;
	//stream.clear();

	//stream << output1[0];
	//stream >> op1;
	//stream.clear();

	//stream << output2[0];
	//stream >> op2;
	//stream.clear();

	//name_txt += ".txt";
	//std::ofstream ofs(name_txt, std::ofstream::app);
	//cout << "creat a txt named " << name_txt << endl;

	////ofs << output1 <<  output2;
	//ofs.put(op1);
	//ofs.put(op2);
	//ofs.close();
}

inline void Way_decoding::go_to_de_it()
{
	for (int i = 0; i < s_out.size(); i = i + 2)
	{
		//set tow bit to decoder
		bitset<2> o_oput;
		stringstream stream;
		bool b_temp;

		stream << s_out[i];
		stream >> b_temp;
		o_oput[0] = b_temp;
		stream.clear();

		stream << s_out[i + 1];
		stream >> b_temp;
		o_oput[1] = b_temp;
		stream.clear();
	
	}

	//cout << "finished the oder " << endl;

	InState* temp_state = new InState;


	Way_decoding::in_get(temp_state);

	vb_in.flip();

	for (vector<bool>::iterator it = vb_in.begin(); it != vb_in.end(); ++it)
	{
		std::cout << ' ' << *it;
		std::cout << '\n';
	}
	
}

void Way_decoding::text_it()
{
	cout << "I can do it " << endl;
}
