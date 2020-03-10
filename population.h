#pragma once

const int StageNum = 18; // �ؿ���
const int PartnerNum = 12;  // С�������
const int PopulationNum = 300; // ��Ⱥ����
const int KingNum = 4; //������ż������
const double varianceRatio = 0.05; // ������
const double crossRatio = 0.8; // ������

class population
{
public:
	population(int[PartnerNum]);

	void init();
	void eval();
	void select();
	void crossOver(int, int);
	void cross();
	void variance();
	void evolution(int incomeThreshold =1000);

	int calcIncome(int partnerAllot[PartnerNum + 2]);
	void setPartnerGHF(int [PartnerNum]);
	int maxWoodIncome;
	int king[PartnerNum];

private:
	/*
	pol ����Ⱥ ������pol[i]�ı���Ϊ:
	pol[i][0~11]Ϊ����ؿ�;
	pol[i][12]Ϊ��Ӧ��ľͷ����;
	pol[i][13]Ϊ��Ӧ�ܽ������.
	*/
	int **pop = new int*[PopulationNum];
	int partGFH[PartnerNum]; // ���Ĺ�����

	int stageGFH[StageNum]= // �ؿ����蹥����
	{ 350,900,1200,2200,2800,4000,4800,8000,9000,10000,11000,20000,22000,23000,25000,35000,51000,54000 };
	int stageIncomeWood[StageNum] = // �ؿ�ľͷ����
	{ 300,600,900,1200,1500,1800,2100,2400,2700,3000,3300,3600,3900,4200,4500,4800,5100,5400 };
	int stageIncomeCoin[StageNum] = // �ؿ��������
	{ 289716,442332,464316,508548,552780,575028,619260,663492,
		773940,884652,995112,1106076,1217304,1328532,1439760,1550988,1662216,1773444 };
};