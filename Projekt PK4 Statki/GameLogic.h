#include "Interface.h"



class Game_Logic
{	
private:
	bool if_ship_there[10][10];
	bool if_ship_shot[10][10];
public:
	int is_ship_there(int x, int y);
	int is_ship_there_shot(int x, int y);

};

class Score : public Game_Logic
{
public:
	virtual int Count_Score()=0;
	virtual void Print_Score()=0;
};

class Mine : public Score 
{
	int Mine_Score;
public:
	int Count_Score();
	void Print_Score();
};

class Enemy : public Score
{
	int Enemy_Score;
public:
	int Count_Score();
	void Print_Score();
};

class Check_If_Ship_Shot : public Game_Logic
{
	public:
		bool Check_If_You_Shot_Ship(int x, int y);
};


class Check_Position : public Game_Logic
{
public:
	bool Check_If_Ship_Already_There();
	bool Check_If_You_Can_Add_Ship()//Create_Board *pointer)
	{
		//if (pointer->if_ship_there == 0 && (pointer + 1)->if_ship_there == 0 && (pointer - 1)->if_ship_there == 0 && (pointer - 10)->if_ship_there == 0 && (pointer + 10)->if_ship_there == 0 && (pointer - 9)->if_ship_there == 0 && (pointer - 11)->if_ship_there == 0 && (pointer + 9)->if_ship_there == 0 && (pointer + 11)->if_ship_there == 0)
		//{
			//+uwzglednic dodawanie np 4polowych statkow
		//	return true;
		//}
		//else
			//return false;
	}
};

class Create_Board : public Game_Logic
{
	
	public:
		Create_Board() 
		{ 
			for (int i = 0; i < 10; i++)
				for (int j = 0; j < 10; j++)
					break;//	if_ship_shot[i][j] = if_ship_there[i][j] = 0;
		}
		bool Add_Ship(Create_Board *pointer, int size)
		{
			//sprawdzic w mainie if (Check_If_You_Can_Add_Ship(pointer) == true) //inaczej jak wiecej niz 1 miejsce zajmuje
			//{

			//}
		}
		

};
