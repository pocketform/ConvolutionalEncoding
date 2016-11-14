#include <fstream>

#include"way_of_decoding.h"

using namespace std;

int txt_n = 1;

bitset<4> my_r;
string temp_data;
vector<bool> save_me;

string help[4][8];

void read_data()
{
	ifstream my_data;

	my_data.open("text.txt");

	my_data >> temp_data;

	my_data.close();

	//cout << temp_data << endl;
}

void loop_tow_way1()
{
	int xor1_1 = 0;
	int xor1_2 = xor1_1 + 1;
	int xor2_1;
	int xor2_2;
	int xor2_3;
	int xor2_4;

	txt_n = 1;


	//put 2 registers in xor1 and put 2 registers in xor2
	//get xor1_1
	while (xor1_1 < 4)
	{

		//cout << "the value of n is " << n << "\n";

		//get xor1_2
		while (xor1_2 < 4)
		{
			cout << "xor1_1 is " << xor1_1 << " and xor1_2 is " << xor1_2 << "\n";

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
							cout << "xor2_2 is " << xor2_2 << "\n";


							cout << txt_n << "\n" << endl;
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
}

void easy_mode()
{
	bool b_temp;
	bitset<2> o_oput;
	State save_state = s_000;

	int x1_get2[4];
	int x2_get2[4];
	
	x1_get2[0] = 0;
	x1_get2[1] = 1;
	x2_get2[0] = 2;
	x2_get2[1] = 3;
	
	Way_decoding deco_output(x1_get2, x2_get2, temp_data);

	deco_output.output_get(2, 2);


	for (int i = 0; i < temp_data.size(); i = i + 2)
	{
		stringstream stream;
		//set tow bit to decoder
		State t_state;

		stream << temp_data[i];
		stream >> b_temp;
		o_oput[0] = b_temp;
		stream.clear();

		stream << temp_data[i + 1];
		stream >> b_temp;
		o_oput[1] = b_temp;
		stream.clear();
		deco_output.easy_mode(o_oput);
		
	}

	deco_output.easy_answer();
}

void do_something()
{
	int in;
	cin >> in;

	if (in == 0)
	{
		cout << "sory this function didn't finish " << endl;
	}

	if (in == 1)
	{
		cout << "waiting....." << endl;
		easy_mode();
	}

	else
	{
		cout << "please try again" << endl;
		do_something();
	}
}

int main()
{

	read_data();

	cout << "please choose mode" << endl;
	cout << "easy mode have 1 way to decoding" << endl;
	cout << "hard mode have 69 ways to decoding" << endl;
	cout << "enter 1 to run easy mode" << endl;
	cout << "enter 0 to run hard mode" << endl;
	do_something();


		//stream << o_oput[0];
		//stream >> op1;
		//stream.clear();
		//
		//stream << o_oput[1];
		//stream >> op2;
		//stream.clear();
		//
		//std::ofstream ofs(name_txt, std::ofstream::app);
		//cout << "creat a txt named " << name_txt << endl;
		//
		////ofs << output1 <<  output2;
		//ofs.put(op1);
		//ofs.put(op2);
		//ofs.close();





	////loop_tow_way1;
	//int text = 0;
//
	//int xor1_1 = 0;
	//int xor1_2 = xor1_1 + 1;
	//int xor2_1;
	//int xor2_2;
	//int xor2_3;
	//int xor2_4;
//
	////get xor1_1
	//while (xor1_1 < 4)
	//{
	//	//get xor1_2
	//	while (xor1_2 < 4)
	//	{
	//		//get xor2_1
	//		for (xor2_1 = 0; xor2_1 < 4; xor2_1++)
	//		{
	//			if (xor2_1 != xor1_1 && xor2_1 != xor1_2)
	//			{
	//				//get xor2_2
	//				for (xor2_2 = 0; xor2_2 < 4; xor2_2++)
	//				{
	//					if (xor2_2 != xor1_1 && xor2_2 != xor1_2 && xor2_2 != xor2_1)
	//					{
	//						cout << "xor1_1 is " << xor1_1 << "\n";
	//						cout << "xor1_2 is " << xor1_2 << "\n";
	//						cout << "xor2_1 is " << xor2_1 << "\n";
	//						cout << "xor2_2 is " << xor2_2 << "\n";
	//						cout << txt_n << "\n";
	//
	//
	//						int x1_get2[4];
	//						int x2_get2[4];
//
	//						x1_get2[0] = xor1_1;
	//						x1_get2[1] = xor1_2;
	//						x2_get2[0] = xor2_1;
	//						x2_get2[1] = xor2_2;
	//
	//						Way_decoding deco_output(x1_get2, x2_get2,temp_data);
	//						deco_output.output_get(2, 2);
	//						deco_output.go_to_de_it();
	//
	//
	//						txt_n++;
	//					}
	//				}
	//				break;
	//			}
	//		}
	//		xor1_2++;
	//	}
	//	xor1_1++;
	//	xor1_2 = xor1_1 + 1;
	//	//txt_n++;
	//}
//
	//text of way_decoding 



	return 0;
}
