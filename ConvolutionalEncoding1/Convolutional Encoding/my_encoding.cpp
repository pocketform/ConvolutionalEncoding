#include <fstream>

#include <vector>
#include <string>

#include <sstream>

#include "xor_gate.h"

using namespace std;

int txt_n = 1;
string temp_data;
bitset<4> my_r;

void read_data()
{
	ifstream my_data;

	my_data.open("text.txt");

	my_data >> temp_data;

	my_data.close();
}

bitset<4> set_first_bitset(bitset<4> bit, int n)
{
	int temp;
	stringstream stream;

	stream << temp_data[n];
	stream >> temp;
	bit[0] = temp;

	stream.clear();

	return bit;
}

bitset<4> c_bit_order(bitset<4> m_bit)
{

	m_bit >> 1;
	m_bit[3] = m_bit[2];
	m_bit[2] = m_bit[1];
	m_bit[1] = m_bit[0];

	return m_bit;
}

void set_txt(bitset<1> output1, bitset<1> output2)
{
	string name_txt;
	stringstream stream;
	char op1;
	char op2;

	stream << txt_n;
	stream >> name_txt;
	stream.clear();

	stream << output1[0];
	stream >> op1;
	stream.clear();

	stream << output2[0];
	stream >> op2;
	stream.clear();

	name_txt += ".txt";
	std::ofstream ofs(name_txt, std::ofstream::app);
	//cout << "creat a txt named " << name_txt << endl;

	//ofs << output1 <<  output2;
	ofs.put(op1);
	ofs.put(op2);
	ofs.close();
}

void easy_mode_set_txt(bitset<1> output1, bitset<1> output2)
{
	string name_txt = "easy mode code.txt";
	stringstream stream;
	char op1;
	char op2;

	stream << output1[0];
	stream >> op1;
	stream.clear();

	stream << output2[0];
	stream >> op2;
	stream.clear();

	std::ofstream ofs(name_txt, std::ofstream::app);
	cout << "creat a txt named " << name_txt << endl;

	//ofs << output1 <<  output2;
	ofs.put(op1);
	ofs.put(op2);
	ofs.close();
}

void easy_encode()
{
	for (int i = 0; i < temp_data.size(); i++)
	{

		my_r = set_first_bitset(my_r, i);

		XOR xor1(my_r[0], my_r[1]);
		XOR xor2(my_r[2], my_r[3]);
		bitset<1> output1 = xor1.do_xor_with_number(2);
		bitset<1> output2 = xor2.do_xor_with_number(2);
		//cout << my_r[0] << my_r[1] << endl;
		//cout << output1 << endl;
		//cout << my_r[2] << my_r[3] << endl;
		//cout << output2 << endl;
		easy_mode_set_txt(output1, output2);
		my_r = c_bit_order(my_r);


	}
}

//put 2 elements in xor1 and put 2 elements in xor2
void get_tow_way1()
{
	for (int i = 0; i < temp_data.size(); i++)
	{
		int xor1_1 = 0;
		int xor1_2 = xor1_1 + 1;
		int xor2_1;
		int xor2_2;
		int xor2_3;
		int xor2_4;


		my_r = c_bit_order(my_r);
		my_r = set_first_bitset(my_r, i);
		txt_n = 1;

		//get xor1_1
		while (xor1_1 < 4)
		{

			//cout << "the value of n is " << n << "\n";

			//get xor1_2
			while (xor1_2 < 4)
			{

				//cout << "xor1_1 is " << xor1_1 << " and xor1_2 is " << xor1_2 <<" and output is " << output_1[0]<< "\n";

				//way1  
				//get xor2_1
				for (xor2_1 = 0; xor2_1 < 4; xor2_1++)
				{

					if (xor2_1 != xor1_1 && xor2_1 != xor1_2)
					{
						//cout << "xor2_1 is " << xor2_1 << "\n";

						//get xor2_2
						for (xor2_2 = 0; xor2_2 < 4; xor2_2++)
						{

							if (xor2_2 != xor1_1 && xor2_2 != xor1_2 && xor2_2 != xor2_1)
							{
								XOR xor1(my_r[xor1_1], my_r[xor1_2]);
								XOR xor2(my_r[xor2_1], my_r[xor2_2]);

								bitset<1> output1 = xor1.do_xor_with_number(2);
								bitset<1> output2 = xor2.do_xor_with_number(2);

								set_txt(output1, output2);

								//cout << "xor2_2 is " << xor2_2 << "\n";
								//cout << "output1 is " << output1[0] << " output2 is " << output2[0] << endl;
								txt_n++;
							}
						}
						break;
					}
				}
				xor1_2++;
			}

			xor1_1++;
			xor1_2 = xor1_1 + 1;

			//txt_n++;
		}
		//cout << my_r[0] << my_r[1] << my_r[2] << my_r[3] << endl;
	}

	my_r.reset();
}
//put 2 elements in xor1 and put 3 elements in xor2
void get_tow_way2()
{
	for (int i = 0; i < temp_data.size(); i++)
	{
		int xor1_1 = 0;
		int xor1_2 = xor1_1 + 1;
		int xor2_1;
		int xor2_2;
		int xor2_3;
		int xor2_4;


		my_r = c_bit_order(my_r);
		my_r = set_first_bitset(my_r, i);
		txt_n = 1 + 6;

		//get xor1_1
		while (xor1_1 < 4)
		{

			//cout << "the value of n is " << n << "\n";

			//get xor1_2
			while (xor1_2 < 4)
			{

				//cout << "xor1_1 is " << xor1_1 << " and xor1_2 is " << xor1_2 <<" and output is " << output_1[0]<< "\n";

				//way1  
				//get xor2_1
				for (xor2_1 = 0; xor2_1 < 4; xor2_1++)
				{

					if (xor2_1 != xor1_1 && xor2_1 != xor1_2)
					{
						//cout << "xor2_1 is " << xor2_1 << "\n";

						//get xor2_2
						for (xor2_2 = 0; xor2_2 < 4; xor2_2++)
						{

							if (xor2_2 != xor1_1 && xor2_2 != xor1_2 && xor2_2 != xor2_1)
							{

								for (xor2_3 = 0; xor2_3 < 4; xor2_3++)
								{
									if (xor2_3 == xor1_1)
									{
										XOR xor1(my_r[xor1_1], my_r[xor1_2]);
										XOR xor2(my_r[xor2_1], my_r[xor2_2], my_r[xor2_3]);

										bitset<1> output1 = xor1.do_xor_with_number(2);
										bitset<1> output2 = xor1.do_xor_with_number(3);


										set_txt(output1, output2);

										//cout << "xor2_2 is " << xor2_2 << "\n";
										//cout << "output1 is " << output1[0] << " output2 is " << output2[0] << endl;
										txt_n++;
									}

									if (xor2_3 == xor1_2)
									{
										XOR xor1(my_r[xor1_1], my_r[xor1_2]);
										XOR xor2(my_r[xor2_1], my_r[xor2_2], my_r[xor2_3]);

										bitset<1> output1 = xor1.do_xor_with_number(2);
										bitset<1> output2 = xor1.do_xor_with_number(3);


										set_txt(output1, output2);

										//cout << "xor2_2 is " << xor2_2 << "\n";
										//cout << "output1 is " << output1[0] << " output2 is " << output2[0] << endl;
										txt_n++;
									}
								}
							}
						}
						break;
					}
				}
				xor1_2++;
			}

			xor1_1++;
			xor1_2 = xor1_1 + 1;

			//txt_n++;
		}
		//cout << my_r[0] << my_r[1] << my_r[2] << my_r[3] << endl;
	}
	my_r.reset();
}
//put 2 elements in xor1 and put 4 elements in xor2
void get_tow_way3()
{
	for (int i = 0; i < temp_data.size(); i++)
	{
		int xor1_1 = 0;
		int xor1_2 = xor1_1 + 1;
		int xor2_1;
		int xor2_2;
		int xor2_3;
		int xor2_4;


		my_r = c_bit_order(my_r);
		my_r = set_first_bitset(my_r, i);
		txt_n = 1 + 18;

		//get xor1_1
		while (xor1_1 < 4)
		{

			//cout << "the value of n is " << n << "\n";

			//get xor1_2
			while (xor1_2 < 4)
			{

				//cout << "xor1_1 is " << xor1_1 << " and xor1_2 is " << xor1_2 <<" and output is " << output_1[0]<< "\n";

				//way1  
				//get xor2_1
				for (xor2_1 = 0; xor2_1 < 4; xor2_1++)
				{

					if (xor2_1 != xor1_1 && xor2_1 != xor1_2)
					{
						//cout << "xor2_1 is " << xor2_1 << "\n";

						//get xor2_2
						for (xor2_2 = 0; xor2_2 < 4; xor2_2++)
						{

							if (xor2_2 != xor1_1 && xor2_2 != xor1_2 && xor2_2 != xor2_1)
							{
								xor2_3 = xor1_1;
								xor2_4 = xor1_2;

								XOR xor1(my_r[xor1_1], my_r[xor1_2]);

								XOR xor2(my_r[xor2_1], my_r[xor2_2], my_r[xor2_3], my_r[xor2_4]);

								bitset<1> output1 = xor1.do_xor_with_number(2);
								bitset<1> output2 = xor2.do_xor_with_number(4);

								set_txt(output1, output2);

								//cout << "xor2_2 is " << xor2_2 << "\n";
								//cout << "output1 is " << output1[0] << " output2 is " << output2[0] << endl;
								txt_n++;
							}
						}
						break;
					}
				}
				xor1_2++;
			}

			xor1_1++;
			xor1_2 = xor1_1 + 1;

			//txt_n++;
		}
		//cout << my_r[0] << my_r[1] << my_r[2] << my_r[3] << endl;
	}
	my_r.reset();
}
//put 3 elements in xor1 and put 2 elements in xor2 
void get_three_way1()
{
	for (int i = 0; i < temp_data.size(); i++)
	{
		int xor1_1 = 0;
		int xor1_2 = xor1_1 + 1;
		int xor1_3 = xor1_2 + 1;
		int xor2_1;
		int xor2_2;
		int xor2_3;
		int xor2_4;


		my_r = c_bit_order(my_r);
		my_r = set_first_bitset(my_r, i);
		txt_n = 1 + 24;

		int text = 0;
		//get xor1_1

		while (xor1_1 < 4)
		{

			//cout << "the value of n is " << n << "\n";

			//get xor1_2
			while (xor1_2 < 4)
			{
				//get xor1_3
				while (xor1_3 < 4)
				{

					//way1
					//get xor2_1

					for (xor2_1 = 0; xor2_1 < 4; xor2_1++)
					{
						if (xor2_1 != xor1_1 && xor2_1 != xor1_2 && xor2_1 != xor1_3)
						{
							//cout << "xor2_1 is " << xor2_1 << "\n";

							//get xor2_2
							for (xor2_2 = 0; xor2_2 < 4; xor2_2++)
							{

								if (xor2_2 != xor2_1)
								{

									XOR xor1(my_r[xor1_1], my_r[xor1_2], my_r[xor1_3]);
									XOR xor2(my_r[xor2_1], my_r[xor2_2]);

									bitset<1> output1 = xor1.do_xor_with_number(3);
									bitset<1> output2 = xor2.do_xor_with_number(2);

									set_txt(output1, output2);

									//cout << "xor2_2 is " << xor2_2 << "\n";
									//cout << "output1 is " << output1[0] << " output2 is " << output2[0] << endl;
									txt_n++;
									//text++;

									//cout << text << endl;
								}
							}
							break;
						}
					}


					//cout << "xor1_1 is " << xor1_1 << " xor1_2 is " << xor1_2 << " xor1_3 is " << xor1_3 << endl;
					xor1_3++;
				}

				//cout << "xor1_1 is " << xor1_1 << " and xor1_2 is " << xor1_2 <<" and output is " << output_1[0]<< "\n";



				xor1_2++;
				xor1_3 = xor1_2 + 1;
			}

			xor1_1++;
			xor1_2 = xor1_1 + 1;
			xor1_3 = xor1_2 + 1;

			//txt_n++;
		}
		//cout << my_r[0] << my_r[1] << my_r[2] << my_r[3] << endl;
	}
	my_r.reset();
}
//put 3 elements in xor1 and put 3 elements in xor2 
void get_three_way2()
{
	for (int i = 0; i < temp_data.size(); i++)
	{
		int xor1_1 = 0;
		int xor1_2 = xor1_1 + 1;
		int xor1_3 = xor1_2 + 1;
		int xor2_1;
		int xor2_2;
		int xor2_3;
		int xor2_4;

		my_r = c_bit_order(my_r);
		my_r = set_first_bitset(my_r, i);
		txt_n = 1 + 36;

		//int text = 0;

		//get xor1_1
		while (xor1_1 < 4)
		{
			//cout << "the value of n is " << n << "\n";
			//get xor1_2
			while (xor1_2 < 4)
			{
				//get xor1_3
				while (xor1_3 < 4)
				{
					//way1
					//get xor2_1
					for (xor2_1 = 0; xor2_1 < 4; xor2_1++)
					{
						if (xor2_1 != xor1_1 && xor2_1 != xor1_2 && xor2_1 != xor1_3)
						{
							//cout << "xor2_1 is " << xor2_1 << "\n";

							//get xor2_2
							for (xor2_2 = 0; xor2_2 < 4; xor2_2++)
							{

								if (xor2_2 != xor2_1)
								{
									//get xor2_3
									for (xor2_3 = xor2_2 + 1; xor2_3 < 4; xor2_3++)
									{
										if (xor2_3 != xor2_1 && xor2_3 != xor2_2)
										{
											XOR xor1(my_r[xor1_1], my_r[xor1_2], my_r[xor1_3]);
											XOR xor2(my_r[xor2_1], my_r[xor2_2], my_r[xor2_3]);

											bitset<1> output1 = xor1.do_xor_with_number(3);
											bitset<1> output2 = xor2.do_xor_with_number(3);

											set_txt(output1, output2);

											//cout << "xor2_2 is " << xor2_2 << "\n";
											//cout << "output1 is " << output1[0] << " output2 is " << output2[0] << endl;
											txt_n++;
											//text++;
											//cout << text << endl;
										}
									}
								}
							}
							break;
						}
					}
					//cout << "xor1_1 is " << xor1_1 << " xor1_2 is " << xor1_2 << " xor1_3 is " << xor1_3 << endl;
					xor1_3++;
				}
				//cout << "xor1_1 is " << xor1_1 << " and xor1_2 is " << xor1_2 <<" and output is " << output_1[0]<< "\n";
				xor1_2++;
				xor1_3 = xor1_2 + 1;
			}
			xor1_1++;
			xor1_2 = xor1_1 + 1;
			xor1_3 = xor1_2 + 1;
			//txt_n++;
		}
		//cout << my_r[0] << my_r[1] << my_r[2] << my_r[3] << endl;
	}
	my_r.reset();
}
//put 3 elements in xor1 and put 4 elements in xor2 
void get_three_way3()
{
	for (int i = 0; i < temp_data.size(); i++)
	{
		int xor1_1 = 0;
		int xor1_2 = xor1_1 + 1;
		int xor1_3 = xor1_2 + 1;
		int xor2_1;
		int xor2_2;
		int xor2_3;
		int xor2_4;

		my_r = c_bit_order(my_r);
		my_r = set_first_bitset(my_r, i);
		txt_n = 1 + 48;

		//int text = 0;

		//get xor1_1
		while (xor1_1 < 4)
		{
			//cout << "the value of n is " << n << "\n";
			//get xor1_2
			while (xor1_2 < 4)
			{
				//get xor1_3
				while (xor1_3 < 4)
				{

					XOR xor1(my_r[xor1_1], my_r[xor1_2], my_r[xor1_3]);
					XOR xor2(my_r[0], my_r[1], my_r[2], my_r[3]);

					bitset<1> output1 = xor1.do_xor_with_number(3);
					bitset<1> output2 = xor2.do_xor_with_number(4);

					set_txt(output1, output2);

					//cout << "output1 is " << output1[0] << " output2 is " << output2[0] << endl;

					txt_n++;

					//text++;
					//cout << text << endl;
					//get xor2_1

					//cout << "xor1_1 is " << xor1_1 << " xor1_2 is " << xor1_2 << " xor1_3 is " << xor1_3 << endl;
					xor1_3++;
				}
				//cout << "xor1_1 is " << xor1_1 << " and xor1_2 is " << xor1_2 <<" and output is " << output_1[0]<< "\n";
				xor1_2++;
				xor1_3 = xor1_2 + 1;
			}
			xor1_1++;
			xor1_2 = xor1_1 + 1;
			xor1_3 = xor1_2 + 1;
			//txt_n++;
		}
	//	cout << my_r[0] << my_r[1] << my_r[2] << my_r[3] << endl;
	}
	my_r.reset();
}
//put 4 elements in xor1 and put 2 elements in xor2 
void get_four_way1()
{
	for (int i = 0; i < temp_data.size(); i++)
	{
		int xor1_1 = 0;
		int xor2_1 = 0;
		int xor2_2 = xor2_1 + 1;
		int xor2_3;
		int xor2_4;

		my_r = c_bit_order(my_r);
		my_r = set_first_bitset(my_r, i);
		txt_n = 1 + 52;

		//int text = 0;

		//get xor1_1
		while (xor2_1 < 4)
		{
			//cout << "the value of n is " << n << "\n";
			//get xor1_2
			while (xor2_2 < 4)
			{
				XOR xor1(my_r[0], my_r[1], my_r[2], my_r[3]);
				XOR xor2(my_r[xor2_1], my_r[xor2_2]);

				bitset<1> output1 = xor1.do_xor_with_number(4);
				bitset<1> output2 = xor2.do_xor_with_number(2);

				set_txt(output1, output2);

				//cout << "output1 is " << output1[0] << " output2 is " << output2[0] << endl;

				txt_n++;

				//text++;
				//cout << text << endl;
				//get xor2_1

				//cout << "xor1_1 is " << xor1_1 << " xor1_2 is " << xor1_2 << " xor1_3 is " << xor1_3 << endl;
				//cout << "xor1_1 is " << xor1_1 << " and xor1_2 is " << xor1_2 <<" and output is " << output_1[0]<< "\n";
				xor2_2++;

			}
			xor2_1++;
			xor2_2 = xor1_1 + 1;
			//txt_n++;
		}
		//cout << my_r[0] << my_r[1] << my_r[2] << my_r[3] << endl;
	}
	my_r.reset();
}
//put 4 elements in xor1 and put 3 elements in xor2 
void get_four_way2()
{
	for (int i = 0; i < temp_data.size(); i++)
	{
		int xor1_1 = 0;
		int xor2_1 = 0;
		int xor2_2 = xor2_1 + 1;
		int xor2_3 = xor2_2 + 1;
		int xor2_4;

		my_r = c_bit_order(my_r);
		my_r = set_first_bitset(my_r, i);
		txt_n = 1 + 64;

		int text = 0;

		//get xor1_1
		while (xor2_1 < 4)
		{
			//cout << "the value of n is " << n << "\n";
			//get xor1_2
			while (xor2_2 < 4)
			{
				//get xor2_3
				while (xor2_3 < 4)
				{
					XOR xor1(my_r[0], my_r[1], my_r[2], my_r[3]);
					XOR xor2(my_r[xor2_1], my_r[xor2_2], my_r[xor2_3]);

					bitset<1> output1 = xor1.do_xor_with_number(4);
					bitset<1> output2 = xor2.do_xor_with_number(3);

					set_txt(output1, output2);

					//cout << "output1 is " << output1[0] << " output2 is " << output2[0] << endl;

					txt_n++;

					//text++;
					//cout << text << endl;

					xor2_3++;
				}

				//cout << "xor1_1 is " << xor1_1 << " xor1_2 is " << xor1_2 << " xor1_3 is " << xor1_3 << endl;
				//cout << "xor1_1 is " << xor1_1 << " and xor1_2 is " << xor1_2 <<" and output is " << output_1[0]<< "\n";
				xor2_2++;
				xor2_3 = xor2_2 + 1;

			}
			xor2_1++;
			xor2_2 = xor2_1 + 1;
			xor2_3 = xor2_2 + 1;
			//txt_n++;
		}
		//cout << my_r[0] << my_r[1] << my_r[2] << my_r[3] << endl;
	}
	my_r.reset();
}
//put 4 elements in xor1 and put 4 elements in xor2 
void get_four_way3()
{
	for (int i = 0; i < temp_data.size(); i++)
	{

		my_r = c_bit_order(my_r);
		my_r = set_first_bitset(my_r, i);
		txt_n = 1 + 68;

		XOR xor1(my_r[0], my_r[1], my_r[2], my_r[3]);
		XOR xor2(my_r[0], my_r[1], my_r[2], my_r[3]);

		bitset<1> output1 = xor1.do_xor_with_number(4);
		bitset<1> output2 = xor2.do_xor_with_number(4);

		set_txt(output1, output2);

		//get xor1_1

		//cout << my_r[0] << my_r[1] << my_r[2] << my_r[3] << endl;
	}
	my_r.reset();
}

void do_something()
{
	int in;
	cin >> in;

	if (in == 0)
	{
		cout << "waiting....." << endl;
		get_tow_way1();
		get_tow_way2();
		get_tow_way3();
		get_three_way1();
		get_three_way2();
		get_three_way3();
		get_four_way1();
		get_four_way2();
		get_four_way3();
	}

	if (in == 1)
	{
		cout << "waiting....." << endl;
		easy_encode();
	}

	else
	{
		cout << "please try again" << endl;
		do_something();
	}

}

int main()
{
	//text input
	read_data();


	cout << "please choose mode" << endl;
	cout << "easy mode have 1 way to encoding" << endl;
	cout << "hard mode have 69 ways to encoding" << endl;
	cout << "enter 1 to run easy mode" << endl;
	cout << "enter 0 to run hard mode" << endl;

	do_something();
	cout << "program has finished " << endl;


	//// text XOR class
	//XOR xor1(0, 1, 0, 1, 1);
	//bitset<1> my_bit;
	//
	//my_bit = xor1.do_xor_with_number(5);
	//
	//cout << my_bit;

	int exit;
	cin >> exit;

	return 0;


}

