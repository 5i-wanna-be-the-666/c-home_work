#include<iostream> 
#include<string>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
void shengcheng(int a, int b);
int max(int a, int b, int c);
int juli(int a, int b, int c, int d);
void yidong(char s[][79], int a, int b);
class ditu
{
public:
	int zhi[25][79];
	char fu[25][79];
	ditu(int a = 0) :floor(a)
	{
		for (int i = 0; i < 25; i++)
			for (int j = 0; j < 79; j++)
			{
				zhi[i][j] = rand() % 1900 + 1;

			}
	}
	int floor;

};

int i = 0, x = 0;
double damage = 0;
class ren
{
public:
	double attrack;
	double fan;
	double zuidaHp;
	double Hp;
	double shanghai;
	int sha;
	int zhengying;
	int qian;

	virtual void jineng1()
	{
	}
	ren(double a = 0, double b = 0, double c = 0, int d = 0, char p = '\0', double e = 0, double f = 0, int g = 0) :Hp(a), attrack(b), fan(c), zhengying(d), zu(p), shanghai(e), sha(f), qian(g)
	{
		if (zhengying == 1)
			qian = 100;
		if (zhengying == 2)
			qian = rand() % 50;

	}

	virtual void jineng2(ren*& pc)
	{

	}

	~ren()
	{}
	char zu;
};

class tool
{
public:
	int x0;
	virtual void xiaoguo(ren*& pc) {
	}
};

class gold :public tool
{

public:
	void xiaoguo(ren*& pc)
	{

		x0 = rand() % 2 + 1;
		pc->qian += 2 * x0;
		cout << "you money add " << x0 << endl;
	}
};

class yao :public tool
{

public:
	void xiaoguo(ren*& pc)
	{

		x0 = rand() % 6;
		if (x0 == 0)
		{
			pc->Hp += 10;
			cout << "you hp add 10" << endl;
			if (pc->Hp > pc->zuidaHp)
				pc->Hp = pc->zuidaHp;
		}
		if (x0 == 1)
		{
			pc->attrack += 5;
			cout << "you atk add 5" << endl;
		}
		if (x0 == 2)
		{
			pc->fan += 5;
			cout << "you def add 5" << endl;
		}
		if (x0 == 3)
		{
			pc->Hp -= 10;
			cout << "you hp reduce 10" << endl;
			if (pc->Hp <= 0)
				pc->Hp = 1;
		}
		if (x0 == 4)
		{
			pc->attrack -= 5;
			cout << "you atk reduce 5" << endl;
		}
		if (x0 == 5)
		{
			pc->fan -= 5;
			cout << "you def reduce 5" << endl;
		}
	}

};
class shade :public ren
{
	void jineng1()
	{}

public:shade() :ren(125, 25, 25, 1, 's')
{
	zuidaHp = Hp;
}
	  ~shade()
	  {}
};


class drow :public ren
{


public:drow() :ren(150, 25, 25, 1, 'd')
{
	jineng1();
	zuidaHp = Hp;
}
	  void jineng1()
	  {
		  Hp = Hp * 1.5; attrack *= 1.5; fan *= 1.5;
		  cout << "drow Launch his skill became stronger" << endl;
	  }
	  ~drow()
	  {}
};


class vampire :public ren
{


public:vampire() :ren(50, 25, 25, 1, 'v')
{
	zuidaHp = Hp;
}
	  void jineng1()
	  {

		  Hp += 5;
		  cout << "vampire Launch his skill Hp add 5" << endl;
	  }
	  ~vampire()
	  {}
};


class troll :public ren
{


public:troll() :ren(120, 25, 15, 1, 't')
{
	zuidaHp = Hp;
}
	  void jineng1()
	  {

		  Hp += 5;
		  if (Hp > 120)
			  Hp = 120;
		  cout << "troll Launch his skill Hp add 10" << endl;
	  }
	  ~troll()
	  {}
};


class goblin :public ren
{
public:goblin() :ren(110, 15, 20, 1, 'g')
{
	zuidaHp = Hp;
}
	  void jineng1()
	  {

		  qian += 5;
		  cout << "goblin Launch his skill money add 5" << endl;

	  }
	  ~goblin()
	  {}
};




class hunman :public ren
{
public:hunman() :ren(140, 20, 30, 2, 'H')
{}
	  void jineng2(ren*& p)
	  {
		  if (Hp == 0)
		  {


		  }
	  }
};


class dwarf :public ren
{
public:dwarf() :ren(100, 20, 30, 2, 'W')
{}
	  void jineng2(ren*& p)
	  {

	  }
};


class elf :public ren
{
public:elf() :ren(140, 30, 10, 2, 'E')
{}
	  void jineng2(ren*& p)
	  {
		  if (p->zu != 'd')
		  {
			  attrack *= 2;
			  cout << "elf's attrack has turn to double" << endl;
		  }
	  }
};


class orcs :public ren
{
public:orcs() :ren(180, 30, 25, 2, 'O')
{}
	  void jineng2(ren*& p)
	  {
		  if (p->zu == 'g')
		  {
			  attrack *= 1.5;
			  cout << "orcs's attrack has turn to 1.5" << endl;
		  }
	  }
};


class halfling :public ren
{
public:
	int x0;
	halfling() :ren(100, 15, 20, 2, 'L')
	{}
	void jineng2(ren*& pc)
	{

		x0 = rand() % 10 + 1;
		if (x0 > 5)

		{
			Hp += pc->attrack * 100 / (100 + 15);
			cout << "you have missed" << endl;

		}


	}
};














class merchant :public ren
{
public:merchant() :ren(30, 70, 5, 3, 'M')
{}
	  void jineng2(ren*& pc)
	  {

	  }
};



class dragon :public ren
{
public:dragon() :ren(150, 20, 20, 3, 'D')
{}
	  void jineng2(ren*& pc)
	  {

	  }
};
int main()
{



	int hh0 = 1, ww0 = 1, ff0 = 1, ee0 = 1, orc0 = 1, mm0 = 1, dd0 = 1;
	srand((unsigned int)time(NULL));
	ditu tu;
	int j = 0, k, chang, kuang, cn = 0, mix, l, heng, shu, r, o, u, jilu, wei = 0, nc, cnn;
	int x = 0, y = 0;
	char temp = '.', temp1, temp2;
	char a[25][79];

	string gtmd, aa, kongge;
	char ch, xuanze;
again:
	hh0 = 1, ww0 = 1, ff0 = 1, ee0 = 1, orc0 = 1, mm0 = 1, dd0 = 1;
	ren* pc=nullptr;
	ren* diren=nullptr;
	tool* zhizhen;
	ch = '\0';

	shade aaa;
	drow bbb;
	vampire ccc;
	troll ddd;
	goblin eee;

	hunman hh[21];
	dwarf  ww[21];
	halfling ff[21];
	elf  ee[21];
	orcs  orc[21];
	merchant  mm[21];
	dragon dd[21];

	yao yaoyao;
	gold golden;
	cout << "[s]:shade 125hp,25atk,25def" << endl << "[d]:drow 150hp,25atk,15def" << endl << "[v]:vampire 50hp,25atk,25def" << endl << "[t]troll 125hp,25atk,25def" << endl << "[g]:goblin 110hp,15atk,20def" << endl;
	cout << "choose your character:";
	while (ch != 's' && ch != 'd' && ch != 'v' && ch != 't' && ch != 'g')
	{
		cin >> ch;
		if (ch != 's' && ch != 'd' && ch != 'v' && ch != 't' && ch != 'g')
			cout << "date wrong,please try again" << endl;
	}
	if (ch == 's')
		pc = &aaa;
	if (ch == 'd')
		pc = &bbb;
	if (ch == 'v')
		pc = &ccc;
	if (ch == 't')
		pc = &ddd;
	if (ch == 'g')
		pc = &eee;

loop:
	cout << "----------------------------------------------------------------------------------" << endl;






	memset(tu.fu, '\0', sizeof(tu.fu));
	kuang = rand() % 3 + 8;
	chang = kuang;
	for (x = 0; x < kuang; x++)
	{
		tu.fu[x][0] = '|';
		tu.fu[x][78] = '|';
		tu.fu[25 - x][0] = '|';
		tu.fu[25 - x][78] = '|';
	}

	//(1)
	shu = kuang;
	heng = 0;
	while (shu > 0)
	{
		x = rand() % 3 + 3;
		y = rand() % 1 + 8;
		if (shu - x == 1)
			shu = x + 2;
		if (shu < x)
			x = shu;
		if (79 - heng < y)
			y = 79 - heng;
		for (i = heng; i < heng + y; i++)
		{
			if (i >= 78)
				break;

			tu.fu[shu][i] = '-';
		}
		for (i = shu - x + 1; i <= shu; i++)
			tu.fu[i - 1][heng + y] = '|';
		for (j = shu - 1; j >= shu - x; j--)
			for (i = 1; i < heng + y; i++)
				tu.fu[j][i] = '.';
		heng += y;
		shu -= x;

	}
	for (i = 1; i < heng; i++)
		tu.fu[0][i] = '-';






	//(2)
	shu = kuang;
	heng = 78;
	while (shu > 0)
	{
		x = rand() % 3 + 3;
		y = rand() % 1 + 8;
		if (shu - x == 1)
			shu = x + 2;
		if (shu < x)
			x = shu;
		if (heng < 38)
			y = 38 - heng;
		for (i = heng - y + 1; i <= heng; i++)
		{
			if (i >= 78)
				break;

			tu.fu[shu][i] = '-';
		}
		for (i = shu - x + 1; i <= shu; i++)
			tu.fu[i - 1][heng - y] = '|';
		for (j = shu - 1; j >= shu - x; j--)
			for (i = 77; i > heng - y; i--)
				tu.fu[j][i] = '.';
		heng -= y;
		shu -= x;
	}
	for (i = 78; i > heng; i--)
		tu.fu[0][i] = '-';





	//(3)		
	shu = 25 - kuang;
	heng = 0;
	while (shu < 24)
	{
		x = rand() % 3 + 3;
		y = rand() % 1 + 8;
		if (shu == 23)
			shu = 22;
		if (24 - shu < x)
			x = 24 - shu;
		if (79 - heng < y)
			y = 79 - heng;
		for (i = heng; i < heng + y; i++)
		{
			if (i >= 78)
				break;

			tu.fu[shu][i] = '-';
		}
		for (i = shu + 1; i < shu + x; i++)
			tu.fu[i][heng + y] = '|';
		for (j = shu + 1; j <= shu + x; j++)
			for (i = 1; i < heng + y; i++)
				tu.fu[j][i] = '.';
		heng += y;
		shu += x;

	}
	for (i = 1; i < heng; i++)
		tu.fu[24][i] = '-';




	//(4)		
	heng = 78;
	shu = 25 - kuang;
	while (shu < 24)
	{
		x = rand() % 3 + 3;
		y = rand() % 1 + 8;
		if (shu == 23)
			shu = 22;
		if (24 - shu < x)
			x = 24 - shu;
		if (heng < 38)
			y = 38 - heng;
		for (i = heng - y + 1; i <= heng; i++)
		{
			if (i >= 78)
				break;
			tu.fu[shu][i] = '-';
		}
		for (i = shu + 1; i < shu + x; i++)
			tu.fu[i][heng - y] = '|';
		for (j = shu + 1; j <= shu + x; j++)
			for (i = 77; i > heng - y; i--)
				tu.fu[j][i] = '.';
		heng -= y;
		shu += x;

	}
	for (i = 78; i > heng; i--)
		tu.fu[24][i] = '-';



	// ????????		
	i = 1; j = 1; cn = 0;
	while (1)
	{
		if (tu.fu[i][j] == '|')
		{
			cn++;
			tu.fu[i][j] = '+';
			j++;
		}

		if (cn == 1)
			tu.fu[i][j] = '#';
		if (cn == 2)
			break;
		j++;

	}


	// ????????	
	i = 23; j = 1; cn = 0;
	while (1)
	{
		if (tu.fu[i][j] == '|')
		{
			cn++;
			tu.fu[i][j] = '+';
			j++;
		}
		if (cn == 1 && tu.fu[i][j] == '.')
		{
			tu.fu[i][j - 1] = '+';
			break;
		}

		if (cn == 1)
			tu.fu[i][j] = '#';
		if (cn == 2)
			break;
		j++;

	}






	// ????????	
	r = rand() % 2 + 1;
	o = rand() % 2 + 2;
	u = rand() % 4 + 14;
	tu.fu[chang][r] = '+';
	tu.fu[25 - chang][r] = '+';
	for (i = chang + 1; i < 25 - chang; i++)
		tu.fu[i][r] = '#';


	for (i = r + 1; i <= r + 1 + u; i++)
	{
		if (tu.fu[chang + o][i] == '\0')
			tu.fu[chang + o][i] = '#';
		else break;
	}
	u = rand() % 5 + 4;
	for (j = chang + o; j >= chang + o - u; j--)
	{
		if (tu.fu[j][i] == '\0')
			tu.fu[j][i] = '#';
		else break;
	}
	// ????????			
	r = rand() % 2 + 74;
	tu.fu[chang][r] = '+';
	tu.fu[25 - chang][r] = '+';
	for (i = chang + 1; i < 25 - chang; i++)
		tu.fu[i][r] = '#';


	o = rand() % 2 + 3;
	u = rand() % 4 + 15;
	for (i = r - 1; i >= r - 1 - u; i--)
	{
		if (tu.fu[chang + o][i] == '\0')
			tu.fu[chang + o][i] = '#';
		else break;
	}
	u = rand() % 5 + 4;
	for (j = chang + o; j >= chang + o - u; j--)
	{
		if (tu.fu[j][i] == '\0')
			tu.fu[j][i] = '#';
		else break;
	}




	//  (5)		
	shu = 6;
	kuang = 40;
	jilu;
	for (j = 0; j < 5; j++)
	{

		x = rand() % 2 + 2;
		y = rand() % 2 + 7;
		r = rand() % 2 + 8;
		if (j == 0)
		{
			for (k = kuang - r + 1; k < kuang + y; k++)
			{
				tu.fu[shu - 1][k] = '-';
			}
			tu.fu[shu - 1][kuang + (y - r - 1) / 2] = '+';//(5)(1??)(??)
			jilu = shu - 1;
		}

		for (i = shu; i < shu + x; i++)
		{
			tu.fu[i][kuang - r] = '|';
			tu.fu[i][kuang + y] = '|';


			for (k = kuang - r + 1; k < kuang + y; k++)
				tu.fu[i][k] = '.';
		}

		shu += x;

	}

	for (k = kuang - r + 1; k < kuang + y; k++)
		tu.fu[shu][k] = '-';






	//(5)(2??)(??)
	tu.fu[shu][kuang + (y - r - 1) / 2] = '+';



	// ???????????? 
	x = rand() % 2 + 2;
	j = rand() % 6 + 3;
	for (k = shu + 1; k <= shu + 1 + x; k++)
	{
		if (tu.fu[k][kuang + (y - r - 1) / 2] == '\0')
			tu.fu[k][kuang + (y - r - 1) / 2] = '#';
		else break;
	}

	for (i = kuang + (y - r - 1) / 2 + 1; i <= kuang + (y - r - 1) / 2 + j; i++)
		tu.fu[k - 1][i] = '#';

	k = shu + 2 + x;
	for (i = 0; i < 10; i++)
	{
		if (tu.fu[k][kuang + (y - r - 1) / 2 + j] == '\0')
			tu.fu[k][kuang + (y - r - 1) / 2 + j] = '#';

		else break;

		k++;
	}
	k = 1;
	o = rand() % 1 + 2;
	while (1)
	{
		if (tu.fu[23][k] != '+')
			k++;
		else break;

	}

	for (i = 22; i >= 22 - o; i--)
	{
		if (tu.fu[i][k + o] == '\0')
			tu.fu[i][k + o] = '#';
		else break;

	}
	while (1)
	{
		if (tu.fu[i + 1][k + o + 1] == '\0')
			tu.fu[i + 1][k + o + 1] = '#';
		else break;
		k++;
	}


	//????????????	
	u = rand() % 2 + 2;
	j = rand() % 6 + 3;
	for (k = jilu - 1; k >= jilu - u; k--)
	{
		if (tu.fu[k][kuang + (y - r - 1) / 2] == '\0')
			tu.fu[k][kuang + (y - r - 1) / 2] = '#';
		else break;
	}

	for (i = kuang + (y - r - 1) / 2 + 1; i >= kuang + (y - r - 1) / 2 - j; i--)
		tu.fu[k - 1][i] = '#';




	k = 1;
	o = rand() % 2 + 1;
	while (1)
	{
		if (tu.fu[1][k] != '+')
			k++;
		else break;

	}

	for (i = 2; i <= 2 + o; i++)
	{
		if (tu.fu[i][k + o] == '\0')
			tu.fu[i][k + o] = '#';
		else break;

	}
	while (1)
	{
		if (tu.fu[i - 1][k + o + 1] == '\0')
			tu.fu[i - 1][k + o + 1] = '#';
		else break;
		k++;
	}

	//(5)(3??)(??)	
	y += 2;
	while (tu.fu[shu / 2][kuang + y] != '|')
		y--;
	tu.fu[shu / 2][kuang + y] = '+';


	u = rand() % 4 + 12;
	for (i = kuang + y + 1; i <= kuang + y + u; i++)
	{
		if (tu.fu[shu / 2][i] == '\0')
			tu.fu[shu / 2][i] = '#';
		else break;

	}

	//(5)(4??)(??)
	while (tu.fu[shu / 2][kuang + -r + 1] != '|')
		r++;

	tu.fu[shu / 2][kuang - r + 1] = '+';
	u = rand() % 4 + 12;
	for (i = kuang - r; i >= kuang - r - u; i--)
	{
		if (tu.fu[shu / 2][i] == '\0')
			tu.fu[shu / 2][i] = '#';
		else break;

	}

	int flag = 1;
	i = rand() % 23 + 1, j = rand() % 77 + 1;
	int xx, yy;
	while (flag)
	{
		if (tu.fu[i][j] == '.')
		{
			tu.fu[i][j] = '@';
			xx = i, yy = j;
			flag = 0;
		}
		i = rand() % 23 + 1, j = rand() % 77 + 1;

	}


	flag = 1;
	i = rand() % 23 + 1, j = rand() % 77 + 1;
	while (flag)
	{
		if (tu.fu[i][j] == '.' && juli(i, j, xx, yy) >= 30)
		{
			tu.fu[i][j] = '/';

			flag = 0;
		}
		i = rand() % 23 + 1, j = rand() % 77 + 1;

	}
	cn = 1;
	y = 900;
	nc = 1;
	cnn = 1;
	while (cn <= 20 && y >= 300)
	{
		for (i = 1; i < 24; i += 2)
		{
			x = rand() % 3 + 4;
			if (cn > 20 && nc > 20)
				break;
			for (j = 1; j < 78; j += x)
			{
				if (cn > 20 && nc > 20)
					break;




				if (tu.zhi[i][j] >= y)
				{

					if (tu.zhi[i][j] >= y + 200 && tu.zhi[i][j] <= y + 450 && tu.fu[i][j] == '.' && cn <= 20)
					{

						tu.fu[i][j] = hh[cn].zu;

						cn++;
					}




					if (tu.zhi[i][j] >= y + 450 && tu.zhi[i][j] <= y + 600 && tu.fu[i][j] == '.' && cn <= 20 && i >= 6)
					{

						tu.fu[i][j] = ww[cn].zu;

						cn++;
					}




					if (tu.zhi[i][j] >= y + 600 && tu.zhi[i][j] <= y + 700 && tu.fu[i][j] == '.' && cn <= 20)
					{

						tu.fu[i][j] = ff[cn].zu;

						cn++;
					}



					if (tu.zhi[i][j] >= y + 700 && tu.zhi[i][j] <= y + 800 && tu.fu[i][j] == '.' && cn <= 20 && j >= 40)
					{

						tu.fu[i][j] = ee[cn].zu;

						cn++;
					}


					if (tu.zhi[i][j] >= y + 800 && tu.zhi[i][j] <= y + 900 && tu.fu[i][j] == '.' && cn <= 20 && i >= 5)
					{

						tu.fu[i][j] = orc[cn].zu;

						cn++;
					}


					if (tu.zhi[i][j] >= y + 900 && tu.zhi[i][j] <= y + 1000 && tu.fu[i][j] == '.' && cn <= 20)
					{

						tu.fu[i][j] = mm[cn].zu;

						cn++;
					}


				}

				if (tu.zhi[i][j] < y)
				{

					flag = 1;
					if (tu.zhi[i][j] > y - 600 && tu.zhi[i][j] < y - 250 && tu.fu[i][j] == '.' && nc <= 20 && i >= 10)
					{
						if (cnn <= 4)
							for (o = i - 1; o <= i + 1 && flag; o++)
								for (u = j - 1; u <= j + 1 && flag; u++)
								{
									if (tu.fu[o][u] == '.')
									{
										tu.fu[o][u] = 'D';
										cnn++;
										flag = 0;
									}
								}
						tu.fu[i][j] = 'G';
						nc++;
					}

					if (tu.zhi[i][j] >= y - 250 && tu.zhi[i][j] < y && tu.fu[i][j] == '.' && nc <= 20)
					{
						tu.fu[i][j] = 'P';
						nc++;
					}
				}
			}
		}
		y -= 100;
	}






	for (i = 0; i < 25; i++)
	{

		for (j = 0; j < 79; j++)
		{
			cout << tu.fu[i][j];
		}

		cout << endl;
	}
	tu.floor++;
	if (tu.floor == 6)
	{
		cout << "conguralation you past it" << endl;
		goto over;
	}

	cout << "----------------------------------------------------------------------------------" << endl;
	cout << "                                                                       Floor=" << tu.floor << endl;
	cout << "Now you hp=" << pc->Hp << endl;
	cout << "attrack=" << pc->attrack << endl;
	cout << "def=" << pc->fan << endl;
	cout << "money=" << pc->qian << endl;
	cout << "you are at" <<"("<< xx << "," << yy <<")"<< endl;
	//????




	cout << "if you don't kown how to play,please input 'i'." << endl;
	while (1)
	{


	chong:

		cin >> gtmd;



		if (gtmd == "i")//????
		{
			cout << "frist use no,so,we,ea,nw,ne,se,sw to move" << endl << "second if there is 'g' in any direction,you can go through to get it. " << "most important use 'a' then input any direction to attrack ennemys or 'u'  then input any direction to use those P" << endl << "have fun" << endl;
		}
		if (gtmd == "no")//??
		{
			if (tu.fu[xx - 1][yy] == '/')
				break;
			if (tu.fu[xx - 1][yy] == '.' || tu.fu[xx - 1][yy] == '#' || tu.fu[xx - 1][yy] == '+' || tu.fu[xx - 1][yy] == 'G')
			{
				if (tu.fu[xx - 1][yy] == 'G')
				{
					zhizhen = &golden;
					zhizhen->xiaoguo(pc);
					tu.fu[xx - 1][yy] = '.';
				}
				tu.fu[xx][yy] = temp;
				temp = tu.fu[xx - 1][yy];
				tu.fu[xx - 1][yy] = '@';
				xx--;
			}
		}


		if (gtmd == "so")//??
		{
			if (tu.fu[xx + 1][yy] == '/')
				break;
			if (tu.fu[xx + 1][yy] == '.' || tu.fu[xx + 1][yy] == '#' || tu.fu[xx + 1][yy] == '+' || tu.fu[xx + 1][yy] == 'G')
			{
				if (tu.fu[xx + 1][yy] == 'G')
				{
					zhizhen = &golden;
					zhizhen->xiaoguo(pc);
					tu.fu[xx - 1][yy] = '.';
				}
				tu.fu[xx][yy] = temp;
				temp = tu.fu[xx + 1][yy];
				tu.fu[xx + 1][yy] = '@';

				xx++;
			}
		}
		if (gtmd == "ea")//??
		{
			if (tu.fu[xx][yy + 1] == '/')
				break;
			if (tu.fu[xx][yy + 1] == '.' || tu.fu[xx][yy + 1] == '#' || tu.fu[xx][yy + 1] == '+' || tu.fu[xx][yy + 1] == 'G')
			{
				if (tu.fu[xx][yy + 1] == 'G')
				{
					zhizhen = &golden;
					zhizhen->xiaoguo(pc);
					tu.fu[xx][yy + 1] = '.';
				}
				tu.fu[xx][yy] = temp;
				temp = tu.fu[xx][yy + 1];
				tu.fu[xx][yy + 1] = '@';

				yy++;
			}
		}
		if (gtmd == "we")//??
		{
			if (tu.fu[xx][yy - 1] == '/')
				break;

			if (tu.fu[xx][yy - 1] == '.' || tu.fu[xx][yy - 1] == '#' || tu.fu[xx][yy - 1] == '+' || tu.fu[xx][yy - 1] == 'G')
			{
				if (tu.fu[xx][yy - 1] == 'G')
				{
					zhizhen = &golden;
					zhizhen->xiaoguo(pc);
					tu.fu[xx][yy - 1] = '.';
				}
				tu.fu[xx][yy] = temp;
				temp = tu.fu[xx][yy - 1];
				tu.fu[xx][yy - 1] = '@';

				yy--;
			}

		}


		if (gtmd == "ne")//????
		{
			if (tu.fu[xx - 1][yy + 1] == '/')
				break;
			if (tu.fu[xx - 1][yy + 1] == '.' || tu.fu[xx - 1][yy + 1] == '#' || tu.fu[xx - 1][yy + 1] == '+' || tu.fu[xx - 1][yy + 1] == 'G')
			{
				if (tu.fu[xx - 1][yy + 1] == 'G')
				{
					zhizhen = &golden;
					zhizhen->xiaoguo(pc);
					tu.fu[xx - 1][yy + 1] = '.';
				}
				tu.fu[xx][yy] = temp;
				temp = tu.fu[xx - 1][yy + 1];
				tu.fu[xx - 1][yy + 1] = '@';

				xx--;
				yy++;
			}
		}
		if (gtmd == "nw")//????
		{
			if (tu.fu[xx - 1][yy - 1] == '/')
				break;
			if (tu.fu[xx - 1][yy - 1] == '.' || tu.fu[xx - 1][yy - 1] == '#' || tu.fu[xx - 1][yy - 1] == '+' || tu.fu[xx - 1][yy - 1] == 'G')
			{
				if (tu.fu[xx - 1][yy - 1] == 'G')
				{
					zhizhen = &golden;
					zhizhen->xiaoguo(pc);
					tu.fu[xx - 1][yy - 1] = '.';
				}
				tu.fu[xx][yy] = temp;
				temp = tu.fu[xx - 1][yy + 1];
				tu.fu[xx - 1][yy + 1] = '@';

				xx--;
				yy--;
			}
		}
		if (gtmd == "se")//????
		{
			if (tu.fu[xx + 1][yy + 1] == '/')
				break;
			if (tu.fu[xx + 1][yy + 1] == '.' || tu.fu[xx + 1][yy + 1] == '+' || tu.fu[xx - 1][yy + 1] == '+' || tu.fu[xx + 1][yy + 1] == 'G')
			{
				if (tu.fu[xx + 1][yy + 1] == 'G')
				{
					zhizhen = &golden;
					zhizhen->xiaoguo(pc);
					tu.fu[xx + 1][yy + 1] = '.';
				}
				tu.fu[xx][yy] = temp;
				temp = tu.fu[xx + 1][yy + 1];
				tu.fu[xx + 1][yy + 1] = '@';
				xx++;
				yy++;
			}
		}

		if (gtmd == "sw")//????
		{
			if (tu.fu[xx + 1][yy - 1] == '/')
				break;
			if (tu.fu[xx + 1][yy - 1] == '.' || tu.fu[xx + 1][yy - 1] == '#' || tu.fu[xx + 1][yy - 1] == '+' || tu.fu[xx + 1][yy - 1] == 'G')
			{
				if (tu.fu[xx + 1][yy - 1] == 'G')
				{
					zhizhen = &golden;
					zhizhen->xiaoguo(pc);
					tu.fu[xx + 1][yy - 1] = '.';
				}
				tu.fu[xx][yy] = temp;
				temp = tu.fu[xx + 1][yy - 1];
				tu.fu[xx + 1][yy - 1] = '@';

				xx++;
				yy--;
			}
		}


		//???? 
		if (gtmd == "q")
		{
			cout << "Thank for playing , have fun" << endl;
			goto over;
		}


		//???? 
		if (gtmd == "r")
		{

			goto again;
		}

		// ???? 

		if (gtmd == "u")

		{
			cin >> aa;
			if (aa != "no" && aa != "we" && aa != "ea" && aa != "so")
			{
				cout << "wrong instruction please try again" << endl;
				//	goto chong;
			}
			if (aa == "no")//??
			{
				if (tu.fu[xx - 1][yy] == 'P')
				{

					zhizhen = &yaoyao;
					zhizhen->xiaoguo(pc);
					tu.fu[xx - 1][yy] = '.';
				}
				else
				{
					cout << "wrong instruction please try again" << endl;
					goto chong;
				}
			}

			if (aa == "so")//??

			{

				if (tu.fu[xx + 1][yy] == 'P')
				{

					zhizhen = &yaoyao;
					zhizhen->xiaoguo(pc);
					tu.fu[xx + 1][yy] = '.';
				}
				else
				{
					cout << "wrong instruction please try again" << endl;
					goto chong;
				}
			}

			if (aa == "we")//??

			{
				if (tu.fu[xx][yy - 1] == 'P')
				{

					zhizhen = &yaoyao;
					zhizhen->xiaoguo(pc);
					tu.fu[xx][yy - 1] = '.';
				}
				else
				{
					cout << "wrong instruction please try again" << endl;
					goto chong;
				}
			}

			if (aa == "ea")//??

			{
				if (tu.fu[xx][yy + 1] == 'P')
				{
					zhizhen = &yaoyao;
					zhizhen->xiaoguo(pc);

					tu.fu[xx][yy + 1] = '.';
				}
				else
				{
					cout << "wrong instruction please try again" << endl;
					goto chong;
				}
			}
		}


		// ???? 

		if (gtmd == "a")
		{

			cin >> aa;
			if (aa != "no" && aa != "we" && aa != "ea" && aa != "so")
			{
				cout << "wrong instruction please try again" << endl;
				goto chong;
			}

			if (aa == "no")//??

			{
				if (tu.fu[xx - 1][yy] != '.' && tu.fu[xx - 1][yy] != '#' && tu.fu[xx - 1][yy] != '+' && tu.fu[xx - 1][yy] != '@' && tu.fu[xx - 1][yy] != '|' && tu.fu[xx - 1][yy] != '-' && tu.fu[xx - 1][yy] != '\0' && tu.fu[xx - 1][yy] != '/')
				{

					if (tu.fu[xx - 1][yy] == hh[hh0].zu)
					{
						if (hh[hh0].Hp != hh[hh0 - 1].Hp)
							hh0--;

						diren = &hh[hh0];
						if (pc->zu != 'd')
							pc->jineng1();
						diren->Hp -= (pc->attrack * 100 / (100 + diren->fan));
						cout << diren->zu << "{" << diren->Hp << "}" << endl;
						cout << "you make damage=" << (pc->attrack * 100 / (100 + diren->fan)) << endl;


						if (diren->Hp <= 0)
						{
							cout << "you killed " << diren->zu << endl;
							pc->qian += diren->qian;
							cout << "you get " << diren->qian << "$" << endl;
							tu.fu[xx - 1][yy] = 'G';
							hh0++;
						}

						hh0++;
					}

					if (tu.fu[xx - 1][yy] == ww[ww0].zu)
					{
						if (ww[ww0].Hp != ww[ww0 - 1].Hp)
							ww0--;
						diren = &ww[ww0];
						if (pc->zu != 'd')
							pc->jineng1();
						diren->Hp -= (pc->attrack * 100 / (100 + diren->fan));
						cout << diren->zu << "{" << diren->Hp << "}" << endl;
						cout << "you make damage=" << (pc->attrack * 100 / (100 + diren->fan)) << endl;
						if (diren->Hp <= 0)
						{
							cout << "you killed " << diren->zu << endl;
							pc->qian += diren->qian;
							cout << "you get " << diren->qian << "$" << endl;
							tu.fu[xx - 1][yy] = '.';
							ww0++;
						}
						ww0++;
					}

					if (tu.fu[xx - 1][yy] == ee[ee0].zu)
					{
						if (ee[ee0].Hp != ee[ee0 - 1].Hp)
							ee0--;
						diren = &ee[ee0];
						if (pc->zu != 'd')
							pc->jineng1();
						diren->Hp -= (pc->attrack * 100 / (100 + diren->fan));
						cout << diren->zu << "{" << diren->Hp << "}" << endl;
						cout << "you make damage=" << (pc->attrack * 100 / (100 + diren->fan)) << endl;
						if (diren->Hp <= 0)
						{
							cout << "you killed " << diren->zu << endl;
							pc->qian += diren->qian;
							cout << "you get " << diren->qian << "$" << endl;
							tu.fu[xx - 1][yy] = '.';
							ee0++;
						}
						ee0++;
					}

					if (tu.fu[xx - 1][yy] == ff[ff0].zu)
					{
						if (ff[ff0].Hp != ff[ff0 - 1].Hp)
							ff0--;
						diren = &ff[ff0];
						if (pc->zu != 'd')
							pc->jineng1();
						diren->Hp -= (pc->attrack * 100 / (100 + diren->fan));

						diren->jineng2(pc);
						cout << diren->zu << "{" << diren->Hp << "}" << endl;
						cout << "you make damage=" << (pc->attrack * 100 / (100 + diren->fan)) << endl;
						if (diren->Hp <= 0)
						{
							cout << "you killed " << diren->zu << endl;
							pc->qian += diren->qian;
							cout << "you get " << diren->qian << "$" << endl;
							tu.fu[xx - 1][yy] = '.';
							ff0++;
						}
						ff0++;
					}

					if (tu.fu[xx - 1][yy] == orc[orc0].zu)
					{
						if (orc[orc0].Hp != orc[orc0 - 1].Hp)
							orc0--;
						diren = &orc[orc0];
						if (pc->zu != 'd')
							pc->jineng1();
						diren->Hp -= (pc->attrack * 100 / (100 + diren->fan));
						cout << diren->zu << "{" << diren->Hp << "}" << endl;
						cout << "you make damage=" << (pc->attrack * 100 / (100 + diren->fan)) << endl;
						if (diren->Hp <= 0)
						{
							cout << "you killed " << diren->zu << endl;
							pc->qian += diren->qian;
							cout << "you get " << diren->qian << "$" << endl;
							tu.fu[xx - 1][yy] = '.';
							orc0++;
						}
						orc0++;
					}


					if (tu.fu[xx - 1][yy] == dd[dd0].zu)
					{
						if (dd[dd0].Hp != dd[dd0 - 1].Hp)
							dd0--;
						diren = &dd[dd0];
						if (pc->zu != 'd')
							pc->jineng1();
						diren->Hp -= (pc->attrack * 100 / (100 + diren->fan));
						cout << diren->zu << "{" << diren->Hp << "}" << endl;
						cout << "you make damage=" << (pc->attrack * 100 / (100 + diren->fan)) << endl;
						if (diren->Hp <= 0)
						{
							cout << "you killed " << diren->zu << endl;
							pc->qian += diren->qian;
							cout << "you get " << diren->qian << "$" << endl;
							tu.fu[xx - 1][yy] = '.';
							dd0++;
						}
						if (diren->Hp > 0)
						{
							pc->Hp -= (diren->attrack * 100 / (100 + pc->fan));
							cout << "you are hurted=" << (diren->attrack * 100 / (100 + pc->fan)) << endl;
							if (pc->Hp <= 0)
							{
								xuanze;
								cout << "You dead,want do you want?" << endl;
								cout << "1:Try again" << endl << "else:Quit the game" << endl;
								cin >> xuanze;
								if (xuanze == '1')
									goto again;
								else
									goto over;
							}

						}
						dd0++;
					}



				}
				else
				{
					cout << "Wrong instrction" << endl;
					goto chong;
				}
			}
			if (aa == "so")//??
			{
				if (tu.fu[xx + 1][yy] != '.' && tu.fu[xx + 1][yy] != '#' && tu.fu[xx + 1][yy] != '+' && tu.fu[xx + 1][yy] != '@' && tu.fu[xx + 1][yy] != '|' && tu.fu[xx + 1][yy] != '-' && tu.fu[xx + 1][yy] != '\0' && tu.fu[xx + 1][yy] != '/')
				{

					if (tu.fu[xx + 1][yy] == hh[hh0].zu)
					{
						if (hh[hh0].Hp != hh[hh0 - 1].Hp)
							hh0--;
						diren = &hh[hh0];
						if (pc->zu != 'd')
							pc->jineng1();
						diren->Hp -= (pc->attrack * 100 / (100 + diren->fan));
						cout << diren->zu << "{" << diren->Hp << "}" << endl;
						cout << "you make damage=" << (pc->attrack * 100 / (100 + diren->fan)) << endl;
						if (diren->Hp <= 0)
						{
							cout << "you killed " << diren->zu << endl;
							pc->qian += diren->qian;
							cout << "you get " << diren->qian << "$" << endl;
							tu.fu[xx + 1][yy] = 'G';
							hh0++;
						}
						hh0++;
					}


					if (tu.fu[xx + 1][yy] == ww[ww0].zu)
					{
						if (ww[ww0].Hp != ww[ww0 + 1].Hp)
							ww0--;
						diren = &ww[ww0];
						if (pc->zu != 'd')
							pc->jineng1();
						diren->Hp -= (pc->attrack * 100 / (100 + diren->fan));
						cout << diren->zu << "{" << diren->Hp << "}" << endl;
						cout << "you make damage=" << (pc->attrack * 100 / (100 + diren->fan)) << endl;
						if (diren->Hp <= 0)
						{
							cout << "you killed " << diren->zu << endl;
							pc->qian += diren->qian;
							cout << "you get " << diren->qian << "$" << endl;
							tu.fu[xx + 1][yy] = '.';
							ww0++;
						}
						ww0++;
					}

					if (tu.fu[xx + 1][yy] == ee[ee0].zu)
					{
						if (ee[ee0].Hp != ee[ee0 - 1].Hp)
							ee0--;
						diren = &ee[ee0];
						if (pc->zu != 'd')
							pc->jineng1();
						diren->Hp -= (pc->attrack * 100 / (100 + diren->fan));
						cout << diren->zu << "{" << diren->Hp << "}" << endl;
						cout << "you make damage=" << (pc->attrack * 100 / (100 + diren->fan)) << endl;
						if (diren->Hp <= 0)
						{
							cout << "you killed " << diren->zu << endl;
							pc->qian += diren->qian;
							cout << "you get " << diren->qian << "$" << endl;
							tu.fu[xx + 1][yy] = '.';
							ee0++;
						}
						ee0++;
					}

					if (tu.fu[xx + 1][yy] == ff[ff0].zu)
					{
						if (ff[ff0].Hp != ff[ff0 - 1].Hp)
							ff0--;
						diren = &ff[ff0];
						if (pc->zu != 'd')
							pc->jineng1();


						diren->Hp -= (pc->attrack * 100 / (100 + diren->fan));
						diren->jineng2(pc);
						cout << diren->zu << "{" << diren->Hp << "}" << endl;
						cout << "you make damage=" << (pc->attrack * 100 / (100 + diren->fan)) << endl;
						if (diren->Hp <= 0)
						{
							cout << "you killed " << diren->zu << endl;
							pc->qian += diren->qian;
							cout << "you get " << diren->qian << "$" << endl;
							tu.fu[xx + 1][yy] = '.';
							ff0++;
						}
						ff0++;
					}

					if (tu.fu[xx + 1][yy] == orc[orc0].zu)
					{
						if (orc[orc0].Hp != orc[orc0 - 1].Hp)
							orc0--;
						diren = &orc[orc0];
						if (pc->zu != 'd')
							pc->jineng1();
						diren->Hp -= (pc->attrack * 100 / (100 + diren->fan));
						cout << diren->zu << "{" << diren->Hp << "}" << endl;
						cout << "you make damage=" << (pc->attrack * 100 / (100 + diren->fan)) << endl;
						if (diren->Hp <= 0)
						{
							cout << "you killed " << diren->zu << endl;
							pc->qian += diren->qian;
							cout << "you get " << diren->qian << "$" << endl;
							tu.fu[xx + 1][yy] = '.';
							orc0++;
						}
						orc0++;
					}

					if (tu.fu[xx + 1][yy] == dd[dd0].zu)
					{
						if (dd[dd0].Hp != dd[dd0 - 1].Hp)
							dd0--;
						diren = &dd[dd0];
						if (pc->zu != 'd')
							pc->jineng1();
						diren->Hp -= (pc->attrack * 100 / (100 + diren->fan));
						cout << diren->zu << "{" << diren->Hp << "}" << endl;
						cout << "you make damage=" << (pc->attrack * 100 / (100 + diren->fan)) << endl;
						if (diren->Hp <= 0)
						{
							cout << "you killed " << diren->zu << endl;
							pc->qian += diren->qian;
							cout << "you get " << diren->qian << "$" << endl;
							tu.fu[xx + 1][yy] = '.';
							dd0++;
						}

						if (diren->Hp > 0)
						{
							pc->Hp -= (diren->attrack * 100 / (100 + pc->fan));
							cout << "you are hurted=" << (diren->attrack * 100 / (100 + pc->fan)) << endl;
							if (pc->Hp <= 0)
							{
								xuanze;
								cout << "You dead,want do you want?" << endl;
								cout << "1:Try again" << endl << "else:Quit the game" << endl;
								cin >> xuanze;
								if (xuanze == '1')
									goto again;
								else
									goto over;
							}
						}
						dd0++;
					}


				}
				else {
					cout << "Wrong instrction" << endl;
					goto chong;
				}
			}
			if (aa == "ea")//??


			{

				if (tu.fu[xx][yy + 1] != '.' && tu.fu[xx][yy + 1] != '#' && tu.fu[xx][yy + 1] != '+' && tu.fu[xx][yy + 1] != '@' && tu.fu[xx][yy + 1] != '|' && tu.fu[xx][yy + 1] != '+' && tu.fu[xx][yy + 1] != '\0' && tu.fu[xx][yy + 1] != '/')
				{

					if (tu.fu[xx][yy + 1] == hh[hh0].zu)
					{
						if (hh[hh0].Hp != hh[hh0 - 1].Hp)
							hh0--;
						diren = &hh[hh0];
						if (pc->zu != 'd')
							pc->jineng1();
						diren->Hp -= (pc->attrack * 100 / (100 + diren->fan));
						cout << diren->zu << "{" << diren->Hp << "}" << endl;
						cout << "you make damage=" << (pc->attrack * 100 / (100 + diren->fan)) << endl;
						if (diren->Hp <= 0)
						{
							cout << "you killed " << diren->zu << endl;
							pc->qian += diren->qian;
							cout << "you get " << diren->qian << "$" << endl;
							tu.fu[xx][yy + 1] = 'G';
							hh0++;
						}
						hh0++;
					}


					if (tu.fu[xx][yy + 1] == ww[ww0].zu)
					{
						if (ww[ww0].Hp != ww[ww0 - 1].Hp)
							ww0--;
						diren = &ww[ww0];
						if (pc->zu != 'd')
							pc->jineng1();
						diren->Hp -= (pc->attrack * 100 / (100 + diren->fan));
						cout << diren->zu << "{" << diren->Hp << "}" << endl;
						cout << "you make damage=" << (pc->attrack * 100 / (100 + diren->fan)) << endl;
						if (diren->Hp <= 0)
						{
							cout << "you killed " << diren->zu << endl;
							pc->qian += diren->qian;
							cout << "you get " << diren->qian << "$" << endl;
							tu.fu[xx][yy + 1] = '.';
							ww0++;
						}
						ww0++;
					}

					if (tu.fu[xx][yy + 1] == ee[ee0].zu)
					{
						if (ee[ee0].Hp != ee[ee0 - 1].Hp)
							ee0--;
						diren = &ee[ee0];
						if (pc->zu != 'd')
							pc->jineng1();
						diren->Hp -= (pc->attrack * 100 / (100 + diren->fan));
						cout << diren->zu << "{" << diren->Hp << "}" << endl;
						cout << "you make damage=" << (pc->attrack * 100 / (100 + diren->fan)) << endl;
						if (diren->Hp <= 0)
						{
							cout << "you killed " << diren->zu << endl;
							pc->qian += diren->qian;
							cout << "you get " << diren->qian << "$" << endl;
							tu.fu[xx][yy + 1] = '.';
							ee0++;
						}
						ee0++;
					}

					if (tu.fu[xx][yy + 1] == ff[ff0].zu)
					{
						if (ff[ff0].Hp != ff[ff0 - 1].Hp)
							ff0--;
						diren = &ff[ff0];
						if (pc->zu != 'd')
							pc->jineng1();
						diren->Hp -= (pc->attrack * 100 / (100 + diren->fan));
						diren->jineng2(pc);
						cout << diren->zu << "{" << diren->Hp << "}" << endl;
						cout << "you make damage=" << (pc->attrack * 100 / (100 + diren->fan)) << endl;
						if (diren->Hp <= 0)
						{
							cout << "you killed " << diren->zu << endl;
							pc->qian += diren->qian;
							cout << "you get " << diren->qian << "$" << endl;
							tu.fu[xx][yy + 1] = '.';
							ff0++;
						}
						ff0++;
					}

					if (tu.fu[xx][yy + 1] == orc[orc0].zu)
					{
						if (orc[orc0].Hp != orc[orc0 - 1].Hp)
							orc0--;
						diren = &orc[orc0];
						if (pc->zu != 'd')
							pc->jineng1();
						diren->Hp -= (pc->attrack * 100 / (100 + diren->fan));
						cout << diren->zu << "{" << diren->Hp << "}" << endl;
						cout << "you make damage=" << (pc->attrack * 100 / (100 + diren->fan)) << endl;
						if (diren->Hp <= 0)
						{
							cout << "you killed " << diren->zu << endl;
							pc->qian += diren->qian;
							cout << "you get " << diren->qian << "$" << endl;
							tu.fu[xx][yy + 1] = '.';
							orc0++;

						}
						orc0++;
					}

					if (tu.fu[xx][yy + 1] == dd[dd0].zu)
					{
						if (dd[dd0].Hp != dd[dd0 - 1].Hp)
							dd0--;
						diren = &dd[dd0];
						if (pc->zu != 'd')
							pc->jineng1();
						diren->Hp -= (pc->attrack * 100 / (100 + diren->fan));
						cout << diren->zu << "{" << diren->Hp << "}" << endl;
						cout << "you make damage=" << (pc->attrack * 100 / (100 + diren->fan)) << endl;
						if (diren->Hp <= 0)
						{
							cout << "you killed " << diren->zu << endl;
							pc->qian += diren->qian;
							cout << "you get " << diren->qian << "$" << endl;
							tu.fu[xx][yy + 1] = '.';
							dd0++;

						}
						if (diren->Hp > 0)
						{
							pc->Hp -= (diren->attrack * 100 / (100 + pc->fan));
							cout << "you are hurted=" << (diren->attrack * 100 / (100 + pc->fan)) << endl;
							if (pc->Hp <= 0)
							{
								xuanze;
								cout << "You dead,want do you want?" << endl;
								cout << "1:Try again" << endl << "else:Quit the game" << endl;
								cin >> xuanze;
								if (xuanze == '1')
									goto again;
								else
									goto over;
							}

						}
						dd0++;
					}



				}
				else {
					cout << "Wrong instrction" << endl;
					goto chong;
				}
			}

			if (aa == "we")//??

			{
				if (tu.fu[xx][yy - 1] != '.' && tu.fu[xx][yy - 1] != '#' && tu.fu[xx][yy - 1] != '+' && tu.fu[xx][yy - 1] != '@' && tu.fu[xx][yy - 1] != '|' && tu.fu[xx][yy - 1] != '-' && tu.fu[xx][yy - 1] != '\0' && tu.fu[xx][yy - 1] != '/')
				{

					if (tu.fu[xx][yy - 1] == hh[hh0].zu)
					{
						if (hh[hh0].Hp != hh[hh0 - 1].Hp)
							hh0--;
						diren = &hh[hh0];
						if (pc->zu != 'd')
							pc->jineng1();
						diren->Hp -= (pc->attrack * 100 / (100 + diren->fan));
						cout << diren->zu << "{" << diren->Hp << "}" << endl;
						cout << "you make damage=" << (pc->attrack * 100 / (100 + diren->fan)) << endl;
						if (diren->Hp <= 0)
						{
							cout << "you killed " << diren->zu << endl;
							pc->qian += diren->qian;
							cout << "you get " << diren->qian << "$" << endl;
							tu.fu[xx][yy - 1] = 'G';
							hh0++;

						}
						hh0++;
					}


					if (tu.fu[xx][yy - 1] == ww[ww0].zu)
					{
						if (ww[ww0].Hp != ww[ww0 - 1].Hp)
							ww0--;
						diren = &ww[ww0];
						if (pc->zu != 'd')
							pc->jineng1();
						diren->Hp -= (pc->attrack * 100 / (100 + diren->fan));
						cout << diren->zu << "{" << diren->Hp << "}" << endl;
						cout << "you make damage=" << (pc->attrack * 100 / (100 + diren->fan)) << endl;
						if (diren->Hp <= 0)
						{
							cout << "you killed " << diren->zu << endl;
							pc->qian += diren->qian;
							cout << "you get " << diren->qian << "$" << endl;
							tu.fu[xx][yy - 1] = '.';
							ww0++;

						}
						ww0++;
					}

					if (tu.fu[xx][yy - 1] == ee[ee0].zu)
					{
						if (ee[ee0].Hp != ee[ee0 - 1].Hp)
							ee0--;
						diren = &ee[ee0];
						if (pc->zu != 'd')
							pc->jineng1();
						diren->Hp -= (pc->attrack * 100 / (100 + diren->fan));
						cout << diren->zu << "{" << diren->Hp << "}" << endl;
						cout << "you make damage=" << (pc->attrack * 100 / (100 + diren->fan)) << endl;
						if (diren->Hp <= 0)
						{
							cout << "you killed " << diren->zu << endl;
							pc->qian += diren->qian;
							cout << "you get " << diren->qian << "$" << endl;
							tu.fu[xx][yy - 1] = '.';
							ee0++;

						}
						ee0++;
					}

					if (tu.fu[xx][yy - 1] == ff[ff0].zu)
					{
						if (ff[ff0].Hp != ff[ff0 - 1].Hp)
							ff0--;
						diren = &ff[ff0];
						if (pc->zu != 'd')
							pc->jineng1();
						diren->Hp -= (pc->attrack * 100 / (100 + diren->fan));
						diren->jineng2(pc);
						cout << diren->zu << "{" << diren->Hp << "}" << endl;
						cout << "you make damage=" << (pc->attrack * 100 / (100 + diren->fan)) << endl;
						if (diren->Hp <= 0)
						{
							cout << "you killed " << diren->zu << endl;
							pc->qian += diren->qian;
							cout << "you get " << diren->qian << "$" << endl;
							tu.fu[xx][yy - 1] = '.';
							ff0++;

						}
						ff0++;
					}

					if (tu.fu[xx][yy - 1] == orc[orc0].zu)
					{
						if (orc[orc0].Hp != orc[orc0 - 1].Hp)
							orc0--;
						diren = &orc[orc0];
						if (pc->zu != 'd')
							pc->jineng1();
						diren->Hp -= (pc->attrack * 100 / (100 + diren->fan));
						cout << diren->zu << "{" << diren->Hp << "}" << endl;
						cout << "you make damage=" << (pc->attrack * 100 / (100 + diren->fan)) << endl;
						if (diren->Hp <= 0)
						{
							cout << "you killed " << diren->zu << endl;
							pc->qian += diren->qian;
							cout << "you get " << diren->qian << "$" << endl;
							tu.fu[xx][yy - 1] = '.';
							orc0++;

						}
						orc0++;
					}

					if (tu.fu[xx][yy - 1] == dd[dd0].zu)
					{
						if (dd[dd0].Hp != dd[dd0 - 1].Hp)
							dd0--;
						diren = &dd[dd0];
						if (pc->zu != 'd')
							pc->jineng1();
						diren->Hp -= (pc->attrack * 100 / (100 + diren->fan));
						cout << diren->zu << "{" << diren->Hp << "}" << endl;
						cout << "you make damage=" << (pc->attrack * 100 / (100 + diren->fan)) << endl;
						if (diren->Hp <= 0)
						{
							cout << "you killed " << diren->zu << endl;
							pc->qian += diren->qian;
							cout << "you get " << diren->qian << "$" << endl;
							tu.fu[xx][yy - 1] = '.';
							dd0++;

						}

						if (diren->Hp > 0)
						{
							pc->Hp -= (diren->attrack * 100 / (100 + pc->fan));
							cout << "you are hurted=" << (diren->attrack * 100 / (100 + pc->fan)) << endl;
							if (pc->Hp <= 0)
							{
								xuanze;
								cout << "You dead,want do you want?" << endl;
								cout << "1:Try again" << endl << "else:Quit the game" << endl;
								cin >> xuanze;
								if (xuanze == '1')
									goto again;
								else
									goto over;
							}

						}
						dd0++;
					}





				}
				else {
					cout << "Wrong instrction" << endl;
					goto chong;
				}
			}

		}




		if (0)
		{
		fight:
			if (mm[mm0].Hp != mm[mm0 - 1].Hp)
				mm0--;
			diren = &mm[mm0];
			if (pc->zu != 'd')
				pc->jineng1();
			diren->Hp -= (pc->attrack * 100 / (100 + diren->fan));
			cout << "What are you doing?!" << endl;
			cout << diren->zu << "{hp:" << diren->Hp << "}" << endl;
			cout << "you make damage=" << (pc->attrack * 100 / (100 + diren->fan)) << endl;
			if (diren->Hp <= 0)
			{
				cout << "you killed " << diren->zu << endl;
				pc->qian += diren->qian;
				cout << "you get " << diren->qian << "$" << endl;
				tu.fu[xx][yy - 1] = '.';
				cout << "please input 1 to cleromancy to decide what can you get intput else to abandon this chance" << endl;
				cin >> xuanze;
				if (xuanze == '1')
				{
					x = rand() % 5 + 1;

					if (x == 1)
					{
						pc->Hp += 10;


						if (pc->Hp > pc->zuidaHp)
							pc->Hp = pc->zuidaHp;
					}
					if (x == 2)
					{

						pc->attrack += 5;
					}
					if (x == 3)
					{

						pc->fan += 5;
					}
					if (x == 4)
					{

						pc->attrack += 20;
					}
					if (x == 5)
					{

						pc->fan += 20;


					}
				}
			}
			mm0++;
		}

		for (i = xx - 1; i <= xx + 1; i++)
			for (j = yy - 1; j <= yy + 1; j++)
			{
				if (tu.fu[i][j] != '.' && tu.fu[i][j] != '#' && tu.fu[i][j] != '+' && tu.fu[i][j] != '@' && tu.fu[i][j] != '|' && tu.fu[i][j] != '-' && tu.fu[i][j] != '\0' && tu.fu[i][j] != '/' && abs(i - xx + j - yy) == 1 && tu.fu[i][j] != 'G' && tu.fu[i][j] != 'P' && tu.fu[i][j] != 'D')
				{
					if (tu.fu[i][j] == hh[hh0].zu)
					{

						if (hh[hh0].Hp != hh[hh0 - 1].Hp)
							hh0--;
						diren = &hh[hh0];


						pc->Hp -= (diren->attrack * 100 / (100 + pc->fan));
						cout << "you are hurted=" << (diren->attrack * 100 / (100 + pc->fan)) << endl;
						if (pc->Hp <= 0)
						{

							cout << "You dead,want do you want?" << endl;
							cout << "1:Try again" << endl << "else:Quit the game" << endl;
							cin >> xuanze;
							if (xuanze == '1')
								goto again;
							else
								goto over;
						}

						hh0++;
					}



					if (tu.fu[i][j] == ww[ww0].zu)
					{
						if (ww[ww0].Hp != ww[ww0 - 1].Hp)
							ww0--;

						diren = &ww[ww0];
						pc->Hp -= (diren->attrack * 100 / (100 + pc->fan));
						cout << "you are hurted=" << (diren->attrack * 100 / (100 + pc->fan)) << endl;
						if (pc->Hp <= 0)
						{

							cout << "You dead,want do you want?" << endl;
							cout << "1:Try again" << endl << "else:Quit the game" << endl;
							cin >> xuanze;
							if (xuanze == '1')
								goto again;
							else
								goto over;
						}
						ww0++;
					}

					if (tu.fu[i][j] == ee[ee0].zu)
					{
						if (ee[ee0].Hp != ee[ee0 - 1].Hp)
							ee0--;
						diren = &ee[ee0];
						diren->jineng2(pc);
						pc->Hp -= (diren->attrack * 100 / (100 + pc->fan));

						cout << "you are hurted=" << (diren->attrack * 100 / (100 + pc->fan)) << endl;
						if (pc->zu != 'd')
							diren->attrack /= 2;
						if (pc->Hp <= 0)
						{

							cout << "You dead,want do you want?" << endl;
							cout << "1:Try again" << endl << "else:Quit the game" << endl;
							cin >> xuanze;
							if (xuanze == '1')
								goto again;
							else
								goto over;
						}

						ee0++;
					}

					if (tu.fu[i][j] == ff[ff0].zu)
					{
						if (ff[ff0].Hp != ff[ff0 - 1].Hp)
							ff0--;
						diren = &ff[ff0];
						pc->Hp -= (diren->attrack * 100 / (100 + pc->fan));
						cout << "you are hurted=" << (diren->attrack * 100 / (100 + pc->fan)) << endl;
						if (pc->Hp <= 0)
						{

							cout << "You dead,want do you want?" << endl;
							cout << "1:Try again" << endl << "else:Quit the game" << endl;
							cin >> xuanze;
							if (xuanze == '1')
								goto again;
							else
								goto over;
						}
						ff0++;
					}

					if (tu.fu[i][j] == orc[orc0].zu)
					{
						if (orc[orc0].Hp != orc[orc0 - 1].Hp)
							orc0--;
						diren = &orc[orc0];
						diren->jineng2(pc);
						pc->Hp -= (diren->attrack * 100 / (100 + pc->fan));

						cout << "you are hurted=" << (diren->attrack * 100 / (100 + pc->fan)) << endl;
						if (pc->zu == 'g')
							diren->attrack /= 1.5;
						if (pc->Hp <= 0)
						{

							cout << "You dead,want do you want?" << endl;
							cout << "1:Try again" << endl << "else:Quit the game" << endl;
							cin >> xuanze;
							if (xuanze == '1')
								goto again;
							else
								goto over;
						}
						orc0++;
					}

					if (tu.fu[i][j] == mm[mm0].zu)
					{
						if (mm[mm0].Hp != mm[mm0 - 1].Hp)
						{

							mm0--;

							diren = &mm[mm0];
							pc->Hp -= (diren->attrack * 100 / (100 + pc->fan));
							cout << "you are hurted=" << (diren->attrack * 100 / (100 + pc->fan)) << endl;

							if (pc->Hp <= 0)
							{

								cout << "You dead,want do you want?" << endl;
								cout << "1:Try again" << endl << "else:Quit this  (lj)game" << endl;
								cin >> xuanze;
								if (xuanze == '1')
									goto again;
								else
									goto over;
							}
						}

						else
						{
							cout << "Oh courageous,what do you eager to?" << endl;
							printf("1:HP<you hp retire 10> $25\n2:At<you attrack add 5>$ 15\n3:DEf<you def add 5> $25\n4:a sowrd in stone<you attrck add 20> $999\n5:a close from the universiry<you def add 20> $999\n6:F*ck *ou<if you kill him,will fall dowm someting from his bag>\n7:Noting I don??t mean I??m poor yeas\n");
							cin >> x;

							if (x == 1)
							{
								pc->Hp += 10;
								pc->qian -= 25;

								if (pc->Hp > pc->zuidaHp)
									pc->Hp = pc->zuidaHp;
							}
							if (x == 2)
							{
								pc->qian -= 15;
								pc->attrack += 5;
							}
							if (x == 3)
							{
								pc->qian -= 25;
								pc->fan += 5;
							}
							if (x == 4)
							{
								pc->qian -= 999;
								pc->attrack += 20;
							}
							if (x == 5)
							{
								pc->qian -= 999;
								pc->fan += 20;

							}
							if (x == 6)
								goto fight;
							if (x == 7)
								x = 0;

						}
						mm0++;

					}
				}
			}


		for (i = 0; i < 25; i++)

		{
			for (j = 0; j < 79; j++)
			{
				if (tu.fu[i][j] != '.' && tu.fu[i][j] != '#' && tu.fu[i][j] != '+' && tu.fu[i][j] != '@' && tu.fu[i][j] != '|' && tu.fu[i][j] != '-' && tu.fu[i][j] != '\0' && tu.fu[i][j] != '/' && tu.fu[i][j] != 'M' && tu.fu[i][j] != 'G' && tu.fu[i][j] != 'P' && tu.fu[i][j] != 'D')
				{


					temp1 = tu.fu[i][j];
					temp2;
					flag = 1;


					r = rand() % 4;
					if (r == 1)
						for (u = i - 1; u <= i + 1 && flag; u++)
							for (o = j - 1; o <= j + 1 && flag; o++)
								if (tu.fu[u][o] == '.')
								{
									temp2 = tu.fu[u][o];
									tu.fu[u][o] = temp1;
									tu.fu[i][j] = temp2;

									flag = 0;


								}


					if (r == 2)
						for (u = i + 1; u >= i - 1 && flag; u--)
							for (o = j - 1; o <= j + 1 && flag; o++)
								if (tu.fu[u][o] == '.')
								{
									temp2 = tu.fu[u][o];
									tu.fu[u][o] = temp1;
									tu.fu[i][j] = temp2;

									flag = 0;


								}

					if (r == 3)
						for (u = i - 1; u <= i + 1 && flag; u++)
							for (o = j + 1; o >= j - 1 && flag; o--)
								if (tu.fu[u][o] == '.')
								{
									temp2 = tu.fu[u][o];
									tu.fu[u][o] = temp1;
									tu.fu[i][j] = temp2;

									flag = 0;


								}

					if (r == 4)
						for (u = i + 1; u >= i - 1 && flag; u--)
							for (o = j + 1; o >= j - 1 && flag; o--)
								if (tu.fu[u][o] == '.')
								{
									temp2 = tu.fu[u][o];
									tu.fu[u][o] = temp1;
									tu.fu[i][j] = temp2;

									flag = 0;


								}


				}
			}

		}
		cout << "if had konwn the information input 1 or 2 or........";
		cin >> kongge;
		for (i = 0; i < 25; i++)

		{
			for (j = 0; j < 79; j++)
			{

				cout << tu.fu[i][j];
			}

			cout << endl;
		}
		cout << "----------------------------------------------------------------------------------" << endl;
		cout << "                                                                       Floor=" << tu.floor << endl;
		cout << "Now you hp=" << pc->Hp << endl;
		cout << "attrack=" << pc->attrack << endl;
		cout << "def=" << pc->fan << endl;
		cout << "money=" << pc->qian << endl;
		cout << "you are at" << "(" << xx << "," << yy << ")" << endl;


	}
	cout << "----------------------------------------------------------------------------------" << endl;

	//????	
	goto loop;

over:  return 0;
}

int max(int a, int b, int c)
{
	int m;
	if (a < b)
		m = a;
	else m = b;
	if (m < c)
		return c;
	return m;
}
int juli(int a, int b, int c, int d)
{
	int sum;
	sum = sqrt((a - c) * (a - c) + (b - d) * (b - d));
	return sum;
}
void yidong(char s[][79], int a, int b)
{


}