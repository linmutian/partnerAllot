#include <iostream>
#include <time.h> 
#include <population.h>
using namespace std;

int main()
{
	
	time_t tStart = clock();
	int ste[12] = { 17214,16056,18554,17518,10566,10218,9678,9624,9232,7056,6806,6730 };
	population p(ste);
	int maxIncome = 0;
	int bestAllot[12] = { 0 };
	for (int i = 0; i <100; i++)
	{
		p.evolution(maxIncome);
		if (maxIncome < p.maxWoodIncome)
		{
			maxIncome = p.maxWoodIncome;
			for (int j = 0; j < PartnerNum; j++)
				bestAllot[j] = p.king[j];
		}
	}
	time_t tEnd = clock();

	cout << "maxIncome = " << maxIncome << endl;
	cout << "  allot：";
	for(int i = 0;i < PartnerNum; i++)
	{
		cout << bestAllot[i] << "  ";
	}
	cout << endl;
	cout << " 耗时 = " << tEnd - tStart <<" ms. " << endl;
	system("pause");
	
    return 0;
}

