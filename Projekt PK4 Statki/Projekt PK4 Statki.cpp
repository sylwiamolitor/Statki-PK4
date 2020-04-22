

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Interface.h"
#include "GraphicObject.h"
#include "GameLogic.h"
#include <Windows.h>


//lista do zapisu




int main()
{

	sf::RenderWindow window(sf::VideoMode(1880, 1000), "Statki!");//, sf::Style::Fullscreen);
	Create_Board mine_board;
	Create_Board enemy_board;

	//rectangle.setPosition(200.f, 10.f); // i ustawiamy mu pozycję
	//sf::CircleShape shape(100.f);
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

	
	//odczyt z o=pliku

	Button przycisk_wyjscia("EXIT", font, 40, sf::Vector2f(1100, 100));
	Button przycisk_nowa_rozgrywka("NOWA ROZGRYWKA", font, 40, sf::Vector2f(1100, 300));
	Button przycisk_wynik_przeciwnika("WYNIK PRZECIWNIKA:", font, 40, sf::Vector2f(1100, 500));
	Button przycisk_twoj_wynik("TWOJ WYNIK:", font, 40, sf::Vector2f(1100, 700));
	Board plansza1(font, sf::Vector2f(0, 0));
	Board plansza2(font, sf::Vector2f(0, 500));
	// ... while
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
			}
			if (mouse_x > 1100 && mouse_y > 100 && mouse_x < 1600 && mouse_y < 200) //na sztywno
				window.close();

		 
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) //wciśnięto klawisz ESC
			window.close(); //zakończ aplikację
		
		window.draw(plansza1);
		window.draw(plansza2);
		window.draw(przycisk_wyjscia);
		window.draw(przycisk_nowa_rozgrywka);
		window.draw(przycisk_twoj_wynik);
		window.draw(przycisk_wynik_przeciwnika);
		window.display();
		window.clear();
	}
	//komunikat kto wygral i zapis do pliku
	//dzwieki?
	return 0;
}
/*
const std::string fontPath = "Resources/comic.ttf";
const sf::Vector2u windowDimensions = sf::Vector2u(800, 600);

class Player
{
public:
	Player(sf::Font& font, sf::Vector2f position)
		: shape(sf::Vector2f(1000.f, 1000.f))
		, text("DŁUUUUUGI TEEEEKST", font)
	{
		text.setFillColor(sf::Color::Blue);
	}

	void update(sf::Vector2f position)
	{
		sf::FloatRect textFrect = text.getGlobalBounds();
		sf::FloatRect shapeFrect = shape.getGlobalBounds();
		sf::Vector2f textPosition;

		textPosition.x = shapeFrect.left + (shapeFrect.width - textFrect.width) * 0.5f;
		textPosition.y = shapeFrect.top + (shapeFrect.height - textFrect.height) * 0.5f;

		shape.setPosition(position);
		text.setPosition(textPosition);
	}

	void draw(sf::RenderTarget& target) const
	{
		target.draw(shape);
		target.draw(text);
	}

private:
	sf::RectangleShape shape;
	sf::Text text;
};

int main()
{
	sf::RenderWindow window(sf::VideoMode(windowDimensions.x, windowDimensions.y), "Example Application");

	sf::Font font;
//	if (!font.loadFromFile(fontPath))
	//{
	//	std::cout << "Failed to load file at: " << fontPath << std::endl;
	//	return -1;
//	}

	Player player(font, sf::Vector2f(300.f, 300.f));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
//player.update(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));

		window.clear();
		player.draw(window);
		window.display();
	}

	return 0;
}*/