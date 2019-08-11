#include "genetic.h"
#include <algorithm>
#include <time.h> 
#include <iomanip>
#include <iostream>
using namespace std;

genetic::genetic()
{
	for (int i = 0; i<12; i++)
	{
		this->partSte[i] = 0;
		this->bestAllot[i] = 0;
	}
	calcTime = 1000;
	bestReward = 0;
}

void genetic::setSteValue(int index, int value)
{
	this->partSte[index] = value;
}

void genetic::setCalcTime(int time)
{
	this->calcTime = time;
}

int genetic::getBestReward()
{
	return this->bestReward;
}

int genetic::getBestAllot(int index)
{
	return this->bestAllot[index];
}

int genetic::evolution()
{
	int notValid = 0;
	for (int i = 0; i < 12; i++) 
	{
		if(this->partSte[i]==0)
		{
			notValid = 1;
		}
	}
	if (notValid)
		return 0;

	srand((unsigned)time(NULL));
	clock_t timeNow, timeLast, timeStart;

	polution p;
	for (int i = 0; i < 12; i++)
	{
		p.setPartnerSte(i, this->partSte[i]);
	}
	p.evolution();

	timeLast = clock();
	timeStart = clock();
	for (int i = 0; i < calcTime; i++)
	{
		p.reInit();
		p.evolution();
		if (p.kingReward > this->bestReward)
		{
			this->bestReward = p.kingReward;
			for (int i = 0; i < PartnerNum; i++)
			{
				this->bestAllot[i] = p.king[i];
			}
		}
		timeNow = clock();
		if (i == calcTime - 1)
		{
			cout << " All calculations completed !!";
		}
		else if (timeNow - timeLast > 10000)
		{
			double timeRest = 1.0*(timeNow - timeStart)*(calcTime - i) / (1000 * i);
			cout << " " << i << " calculations completed , current progress : " << fixed << setprecision(3) << 100.0*i / calcTime << " % , ";
			cout << "time remaining estimated : " << (int)timeRest << " s" << endl;
			timeLast = timeNow;
		}

	}
	return 1;


}

void genetic::output()
{
	//5850 10570 12466 6238 3944 3902 3394 3310 1454 1372 1332 356
	/*
	©°©¤©´
	©¦  ©¦
	©¸©¤©¼
	*/
	//cout << "©°©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©´" << endl;
	cout << "  »ï°éÐòºÅ  ";
	for (int i = 0; i < PartnerNum; i++) 
	{
		cout << setw(4) << i+1;
	}
	cout << endl << "  ·ÖÅä¹Ø¿¨  ";
	for (int i = 0; i < PartnerNum; i++) 
	{
		cout << setw(4) << this->getBestAllot(i)+1;
	}
	cout << endl << endl;

	cout << " ¹Ø¿¨ ·ÖÅä»ï°é" << endl;
	for (int j = 0; j < StageNum; j++) {
		cout << setw(5) << j + 1;
		for (int i = 0; i < PartnerNum; i++)
		{
			if (this->getBestAllot(i) == j) {
				cout << setw(4) << i + 1;
			}
		}
		cout << endl;
	}
	cout << endl;
}