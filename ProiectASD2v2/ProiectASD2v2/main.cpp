#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

typedef struct TicTacToe
{
	int blockNo;
	struct TicTacToe *next;
}Alist;


void draw(void);
void play(void);
void compVSplayer(Alist *[]);
void playerVSplayer(Alist *[]);
void make_list(Alist **);
void printplayer(int );
void printcomp(int );
int compwin(Alist ** ,int []);
void rules(void);
void help(void);

char name[10];
char name1[10];


int main()
{
	int ch;






	do
	{






		cout<<"\n\n**** MENU *****\n"<<"1. RULES\n"<<"2. PLAY\n"<<"3. HELP\n"<<"4. QUIT\n";
		cout<<"\n\nEnter your choice: ";
		cin>>ch;

		switch(ch)
		{
		case 1:
			rules();
			break;
		case 2:
			play();
			break;
		case 3:
			help();
			break;
		case 4:


			return 0;

		default :
			play();
			break;
		}

	}while(1);
}

void play(void)
{

	int ch;
	Alist *GRAPH[10];
	make_list(GRAPH);
	do
	{


		cout<<"*** GAME TYPE ***\n"
			<<"1.COMP Vs PLAYER\n"
			<<"2.PLAYER Vs PLAYER\n"
			<<"3.BACK TO MAIN MENU \n";
		cout<<"\nEnter you'r choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1:

			cout<<"\nEnter your Name : ";
			cin>>name;
			name[0] = toupper(name[0]);
			draw();

			cout<<"ALL THE BEST Ms."<<name;
			cout<<"\n\t Plz play First ";
			compVSplayer(GRAPH);
			break;
		case 2:
			cout<<"\nEnter First player Name : ";
			cin>>name;
			name[0] = toupper(name[0]);
			cout<<"\nEnter Second Player Name : ";
			cin>>name1;
			name1[0] = toupper(name1[0]);
			draw();

			cout<<"\n\nALL THE BEST TO BOHT OF YOU ";
			cout<<"\n\tMr. "<<name<<" Plz play First ";
			playerVSplayer(GRAPH);
			break;
		default:
			ch = 0;
			break;
		}
	}while(ch!=0);

}
void compVSplayer(Alist *GRAPH[])
{
	Alist * node;
	int i,flag[10],Num,block1,block2,pwin=0,compNo=0,cwin=0;

	Alist *ptr=GRAPH[5];

	for(i=0;i<10;i++)
	{
		flag[i]=0;
	}

	cout<<"Enter Block No :";

	for(i=1;i<5;i++)
	{

		cout<<"         ";

		cin>>Num;
		if(flag[Num]==0 && Num > 0 && Num < 10 )
		{
			flag[Num] = 1;
			printplayer(Num);

			for(node = GRAPH[Num];node!=NULL;node=node->next->next)
			{
				block1 = node->blockNo;
				block2 = node->next->blockNo;
				if(flag[block1]==1&&flag[block2]==1)
				{

					cout<<"\""<<name<<"\"You win the Game !";
					pwin=1;
					break;
				}


				if(flag[block1]==1 && flag[block2]==0)
				{
					compNo = block2;
				}
				if(flag[block2]==1 && flag[block1]==0)
				{
					compNo = block1;
				}
			}

			if(pwin==1)
				break;


			if(flag[5]==0)
			{
				printcomp(5);
				flag[5] = 2;
			}
			else
			{


				cwin = compwin(GRAPH,flag);

				if(cwin == 1)
					break;


				if(compNo==0)
				{
					while(ptr)
					{
						if(flag[ptr->blockNo] == 0)
						{
							compNo = ptr->blockNo;
							break;
						}
						ptr = ptr->next;
					}
				}

				printcomp(compNo);
				flag[compNo] = 2;
			}
			compNo = 0;

		}

		else
		{


			cout<<"Sorry ! \""<<name;
			cout<<" \" you are trying to overlod the block ! or Invalid Input";
			getch();

			cout<<"                                                                           ";
			--i;
			Num = 0;
		}
	}

	if(i==5 && cwin == 0 && pwin == 0)
	{

		cout<<" Draw Match ! Try Again !";
	}
	getch();
}



int compwin(Alist **GRAPH ,int flag[])
{
	int i,cwin=0,block1,block2;
	Alist *node;
	for(i=1;i<10;i++)
	{
		if(flag[i] == 2)
			for(node = GRAPH[i]; node!=NULL ; node = node->next->next)
			{
				block1 = node->blockNo;
				block2 = node->next->blockNo;

				if((flag[block1]== 2 && flag[block2] ==0)||((flag[block2] == 2)&&flag[block1] == 0))
				{
					if(flag[block1] == 2)
						printcomp(block2);
					else
						printcomp(block1);



					cwin=1;
					break;
				}
				if(cwin == 1)
					break;
			}
		}
	 return cwin;}

void make_list(Alist ** GRAPH)
{
	int i,j;
	Alist *node;

	int A1[] = {6,5,9,2,3,4,7};
	int A2[] = {4,5,8,1,3};
	int A3[] = {6,5,7,1,2,6,9};
	int A4[] = {4,5,6,1,7};
	int A5[] = {8,2,8,4,6,1,9,3,7};
	int A6[] = {4,5,4,3,9};
	int A7[] = {6,5,3,4,1,8,9};
	int A8[] = {4,5,2,7,9};
	int A9[] = {6,5,1,6,3,8,7};

	for(i=0;i<10;i++)
	{
		GRAPH[i] = NULL;
	}


	for(i=A1[0];i>=1;i--)
	{
		node = new Alist;
		node ->blockNo = A1[i];
		node->next = GRAPH[1];
		GRAPH[1]   = node;
	}

	for(i=A2[0];i>=1;i--)
	{
		node = new Alist;
		node ->blockNo = A2[i];
		node->next = GRAPH[2];
		GRAPH[2]   = node;
	}
	for(i=A3[0];i>=1;i--)
	{
		node = new Alist;
		node ->blockNo = A3[i];
		node->next = GRAPH[3];
		GRAPH[3]   = node;
	}
	for(i=A4[0];i>=1;i--)
	{
		node = new Alist;
		node ->blockNo = A4[i];
		node->next = GRAPH[4];
		GRAPH[4]   = node;
	}
	for(i=A5[0];i>=1;i--)
	{
		node = new Alist;
		node ->blockNo = A5[i];
		node->next = GRAPH[5];
		GRAPH[5]   = node;
	}
	for(i=A6[0];i>=1;i--)
	{
		node = new Alist;
		node ->blockNo = A6[i];
		node->next = GRAPH[6];
		GRAPH[6]   = node;
	}
	for(i=A7[0];i>=1;i--)
	{
		node = new Alist;
		node ->blockNo = A7[i];
		node->next = GRAPH[7];
		GRAPH[7]   = node;
	}
	for(i=A8[0];i>=1;i--)
	{
		node = new Alist;
		node ->blockNo = A8[i];
		node->next = GRAPH[8];
		GRAPH[8]   = node;
	}
	for(i=A9[0];i>=1;i--)
	{
		node = new Alist;
		node ->blockNo = A9[i];
		node->next = GRAPH[9];
		GRAPH[9]   = node;
	}

}


void playerVSplayer(Alist *GRAPH[])
{
	int i,Num,p1win = 0 ,p2win =0 , flag[10];
	int block1,block2,cr = 0;
	Alist *node;

	for(i=0;i<10;i++)
		flag[i] = 0;


	cout<<"Enter Block No :";
	for(i=0;i<9;)
	{

		cout<<"         ";

		cin>>Num;

		if(flag[Num]==0 && Num > 0 && Num < 10 )
		{
			++i;
			flag[Num] = 1;
			printplayer(Num);

			for(node = GRAPH[Num];node!=NULL;node=node->next->next)
			{
				block1 = node->blockNo;
				block2 = node->next->blockNo;
				if(flag[block1]==1&&flag[block2]==1)
				{

					cout<<"\""<<name<<"\"You win the Game !";
					p1win=1;
					break;
				}
			}
			if(p1win == 1)
				break;
			if(i == 9)
				break;
			do
			{

				cout<<"         ";

				cin>>Num;

				if(flag[Num]==0 && Num > 0 && Num < 10 )
				{
					++i;
					flag[Num] = 2;
					printcomp(Num);
					cr = 1;
					for(node = GRAPH[Num];node!=NULL;node=node->next->next)
					{
						block1 = node->blockNo;
						block2 = node->next->blockNo;
						if(flag[block1]==2 && flag[block2]==2)
						{

							cout<<"\""<<name1<<"\"You win the Game !";
							p2win=1;
							break;
						}
					}
				}
				else
				{


					cout<<"Sorry ! \""<<name1;
					cout<<" \" you are trying to overlod the block ! or Invalid Input";
					getch();

					cout<<"                                                                           ";
					cr = 0;
					Num = 0;
				}
			}while(cr == 0);
			if(p2win == 1)
				break;
		}
		else
		{


			cout<<"Sorry ! \""<<name;
			cout<<" \" you are trying to overlod the block ! or Invalid Input";
			getch();

			cout<<"                                                                           ";
			Num = 0;
		}
	}
	if(i == 9 && p1win == 0 && p2win == 0) //check for Draw match
	{

		cout<<" Draw Match ! Try Again !";
	}
	getch();
}

void draw(void)
{
	int i,j;
	int num=1;
	char h=205;
	char v=186;
	char c=206;

	for(i=6;i<12;i+=5)
	{

		for(j=0;j<=30;j++)
			cout<<h;
	}
	for(j=10;j<=20;j+=10)
	{
		for(i=2;i<17;i++)
		{

			cout<<v;
		}
	}
	for(i=35;i<=45;i+=10)
		for(j=9;j<=14;j+=5)
		{

			cout<<c;
		}
		for(j=0;j<=10;j+=5)
			for(i=0;i<=20;i+=10)
			{

				cout<<num++;
			}
}

void printplayer(int place)
{
	if(place==1)
	{

		cout<<"X";

	}
	else if(place==2)
	{

		cout<<"X";

	}
	else if(place==3)
	{

		cout<<"X";

	}
	else if(place==4)
	{

		cout<<"X";

	}
	else if(place==5)
	{

		cout<<"X";

	}
	else if(place==6)
	{

		cout<<"X";

	}
	else if(place==7)
	{

		cout<<"X";

	}
	else if(place==8)
	{

		cout<<"X";

	}
	else if(place==9)
	{

		cout<<"X";

	}
}

void printcomp(int place)
{
	if(place==1)
	{

		cout<<"O";

	}
	else if(place==2)
	{

		cout<<"O";

	}
	else if(place==3)
	{

		cout<<"O";

	}
	else if(place==4)
	{

		cout<<"O";

	}
	else if(place==5)
	{

		cout<<"O";

	}
	else if(place==6)
	{

		cout<<"O";

	}
	else if(place==7)
	{

		cout<<"O";

	}
	else if(place==8)
	{

		cout<<"O";

	}
	else if(place==9)
	{

		cout<<"O";

	}
}

void rules(void)
{

	cout<<"\n\n\nThe rules of the game are as follows:-\n\n"<<"Press the number indicated near the playing box \n" <<"to put the symbol \" X \" in the playing box.\n"<<"\nDo not press a number in which a symbol such as\n"<<"\"'X' or 'O'\" already exist. If you do so the\n"<<"program will give error due to illegal inputs\n"<<"\nYour aim is to get a line containing 3 'X'\n"<<"either horizontally or vertically or diagonally\n"<<"with alternative inputs by you and computer\n";
void board();

	getch();
}

void help(void)
{
	cout<<"\n\nAs the rule of the Game get a line containing 3 'X'\n"
		<<"either hrizontally or vertically or diagonally\n"
		<<"with alternative inputs by you and computer.\n"
		<<"\nAlways try to occupy the middle box and\n"
		<<"then the corners for confusing the computer\n";

	getch();
}


