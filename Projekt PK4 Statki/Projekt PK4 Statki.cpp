

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Interface.h"
#include "GraphicObject.h"
#include "GameLogic.h"
#include <Windows.h>
#include <list>
#include <fstream>

//lista do zapisu
std::list<Button>ButtonList;



int main()
{

	std::ifstream plikWej("Zapis_Rozgrywki.txt");
	
	Create_Board my_board;
	Create_Board enemy_board;

	if (plikWej)
	{
		//dodac tablice zestrzeleń
		std::string linijka;
		for (int i = 0; i < 10; i++)
		{
			
			std::getline(plikWej, linijka);
			for (int j = 0; j < 10; j++)
			{
				if(linijka[j] == '1')
					my_board.set_ship(i, j);
			}//wczytuj do planszy swojej
		}
		std::getline(plikWej, linijka);

		for (int i = 0; i < 10; i++)
		{

			std::getline(plikWej, linijka);
			for (int j = 0; j < 10; j++)
			{
				if (linijka[j] == '1')
					my_board.shoot_ship(i, j);
			}//wczytuj do planszy swojej
		}
		std::getline(plikWej, linijka);



		for (int i = 0; i < 10; i++)
		{

			std::getline(plikWej, linijka);
			for (int j = 0; j < 10; j++)
			{
				if (linijka[j] == '1')
					enemy_board.set_ship(i, j);
			}		
		}

		std::getline(plikWej, linijka);


		for (int i = 0; i < 10; i++)
		{

			std::getline(plikWej, linijka);
			for (int j = 0; j < 10; j++)
			{
				if (linijka[j] == '1')
					enemy_board.shoot_ship(i, j);
			}
		}

		plikWej.close();
	}

	sf::RenderWindow window(sf::VideoMode(1880, 1000), "Statki!");//, sf::Style::Fullscreen);
	

	// O - trafiony , X puste, . nic
	//rozgrywka ty-komputer - komputer strzela randem

	window.clear(sf::Color(0, 0, 0));
	sf::RectangleShape rectangle(sf::Vector2f(225,100)); // tworzymy prostokąt
	rectangle.setPosition(200, 200);
	rectangle.setFillColor(sf::Color(255,255,255));
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		// error...
	}
	
	Button przycisk_wyjscia("EXIT", font, 40, sf::Vector2f(1100, 100));
	Button przycisk_nowa_rozgrywka("NOWA ROZGRYWKA", font, 40, sf::Vector2f(1100, 300));
	Button przycisk_wynik_przeciwnika("WYNIK PRZECIWNIKA:", font, 40, sf::Vector2f(1100, 500));
	Button przycisk_twoj_wynik("TWOJ WYNIK:", font, 40, sf::Vector2f(1100, 700));
	
	ButtonList.push_back(przycisk_nowa_rozgrywka);
	ButtonList.push_back(przycisk_twoj_wynik);
	ButtonList.push_back(przycisk_wyjscia);
	ButtonList.push_back(przycisk_wynik_przeciwnika);

	
	
	Board plansza1(font, sf::Vector2f(0, 0));
	Board plansza2(font, sf::Vector2f(0, 500));
	
	sf::Event event;
	sf::Mouse mouse;
	while (window.isOpen())
	{
		
		while (window.pollEvent(event)) 
		{

			float mouse_x=0; 
			float mouse_y=0;
			
			if (event.type == sf::Event::Closed)
				window.close();
			if (mouse.isButtonPressed(sf::Mouse::Left))
			{
				mouse_x = mouse.getPosition(window).x;
				mouse_y = mouse.getPosition(window).y;
			
				if (mouse_x > 1100 && mouse_y > 100 && mouse_x < 1600 && mouse_y < 200) //na sztywno
					window.close();
					
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) //wciśnięto klawisz ESC
				window.close(); //zakończ aplikację
		}
		
		
		window.draw(plansza1);
		window.draw(plansza2);
		
		for (Button a : ButtonList)
		{
			window.draw(a);
		}
		
		window.display();
		window.clear();
	}
	//komunikat kto wygral i zapis do pliku
	//dzwieki?
	
	std::ofstream plikWyj("Zapis_Rozgrywki.txt");
	
	if (plikWyj)
	{

		for (int i = 0; i < 10; i++)
		{

			for (int j = 0; j < 10; j++)
			{
				if (my_board.is_ship_there(i, j) == 1)
					plikWyj << 1;
				else
					plikWyj << 0;
			}
			plikWyj << std::endl;
		}
		plikWyj << std::endl;

		for (int i = 0; i < 10; i++)
		{

			for (int j = 0; j < 10; j++)
			{
				if (my_board.is_ship_there_shot(i, j) == 1)
					plikWyj << 1;
				else
					plikWyj << 0;
			}
			plikWyj << std::endl;
		}
		
		plikWyj << std::endl;


		for (int i = 0; i < 10; i++)
		{

			for (int j = 0; j < 10; j++)
			{
				if (enemy_board.is_ship_there(i, j) == 1)
					plikWyj << 1;
				else
					plikWyj << 0;
			}
			plikWyj << std::endl;
		}
		plikWyj << std::endl;

		for (int i = 0; i < 10; i++)
		{

			for (int j = 0; j < 10; j++)
			{
				if (enemy_board.is_ship_there_shot(i, j) == 1)
					plikWyj << 1;
				else
					plikWyj << 0;
			}
			plikWyj << std::endl;
		}

		plikWyj.close();
	}
	
	return 0;
}
