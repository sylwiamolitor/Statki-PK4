#include "Interface.h"



class Game_Logic
{	
	protected:
		bool if_ship_there[10][10];
		bool if_ship_shot[10][10];
	public:
		bool is_ship_there(int x, int y)
		{
			return if_ship_there[x][y];
		}
		bool is_ship_there_shot(int x, int y)
		{
			return if_ship_shot[x][y];
		}
		void set_ship(int x, int y)
		{
			if_ship_shot[x][y] = 0;
			if_ship_there[x][y] = 1;
		}
		void shoot_ship(int x, int y)
		{
			if_ship_shot[x][y] = 1;

		}
		

};

class Score : public Game_Logic
{
	protected:
		int Score;
	public:
		virtual int Count_Score()=0;
		virtual void Print_Score()=0;
};

class Mine : public Score 
{
		//int Mine_Score;
	public:
		int Count_Score();
		void Print_Score();
};

class Enemy : public Score
{
//		int Enemy_Score;
	public:
		int Count_Score();
		void Print_Score();
};

class Check_If_Ship_Shot : public Game_Logic
{
	public:
		bool Check_If_You_Shot_Ship(int x, int y)
		{
			if (is_ship_there(x,y))
			{
				if_ship_shot[x][y] = 1; //status = zestrzelony
				return true;
			}
		}
};


class Check_Position : public Game_Logic
{
	public:
		bool Check_If_Ship_Already_There(int x, int y)
		{
			return (is_ship_there(x,y)); //nie ma statku
		}
		bool Check_If_You_Can_Add_Ship(int x, int y)//Create_Board *pointer)
		{
			if (Check_If_Ship_Already_There(x, y)
				&& Check_If_Ship_Already_There(x-1, y-1)
				&& Check_If_Ship_Already_There(x, y-1)
				&& Check_If_Ship_Already_There(x+1, y-1)
				&& Check_If_Ship_Already_There(x-1, y)
				&& Check_If_Ship_Already_There(x+1, y)
				&& Check_If_Ship_Already_There(x-1, y+1)
				&& Check_If_Ship_Already_There(x, y+1)
				&& Check_If_Ship_Already_There(x+1, y+1)
				)

				return true;
			//main zakres statku i tam wielokrotnie wywolana ta funkcja i po sprawdzeniu calosci dodanie
		}
};

class Create_Board : public Check_Position //zmiana dziedziczenia
{
	
	public:
		Create_Board()
		{
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if_ship_shot[i][j] = if_ship_there[i][j] = 0;
				}
			}
		}
		bool Add_Ship(int x1, int x2, int y1, int y2, int size)
		{
			bool direction = false;
			if (x2 - x1 == 0)
				direction = true;
			for (int i = 0; i < size; i++)
			{
				if (direction)
				{
					if (!Check_If_You_Can_Add_Ship(x1, y1 + i ))
						return false;
				}
				else
				{
					if (!Check_If_You_Can_Add_Ship(x1 + i, y1))
						return false;
				}
			}
			for (int i = 0; i < size; i++)
			{
				if (direction)
				{
					set_ship(x1, y1 + i);
				}
				else
				{
					set_ship(x1 + i, y1);
				}
			}
			return true;
		}
		

};

