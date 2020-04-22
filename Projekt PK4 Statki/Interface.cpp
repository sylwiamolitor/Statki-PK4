#include "Interface.h"

Button::Button(std::string text, sf::Font& font, int characterSize, sf::Vector2f position)
{
	Button::text.setString(text);
	Button::text.setFont(font);
	Button::text.setCharacterSize(characterSize);
	Button::text.setPosition(position.x+25, position.y+15);
	Button::frame.setPosition(position.x, position.y);
	Button::frame.setOutlineColor(sf::Color(250, 150, 100));
	Button::frame.setFillColor(sf::Color(150, 50, 250));
	Button::frame.setOutlineThickness(10);
	Button::frame.setSize(sf::Vector2f(500, 100));
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform(); 
	
	target.draw(frame);
	target.draw(text);
}

Board::Board(sf::Font& font, sf::Vector2f position)
{
	/*Board::text.setString("1 2 3 4 5 6 7 8 9 10");
	Board::text.setFont(font);
	Board::text.setCharacterSize(20);
	Board::text.setPosition(position.x + 25, position.y + 15);
	*/
	
	Board::frame.setPosition(position.x+45, position.y+45);
	Board::frame.setOutlineColor(sf::Color::White);
	Board::frame.setFillColor(sf::Color::Transparent);
	Board::frame.setOutlineThickness(5);
	Board::frame.setSize(sf::Vector2f(400, 400));
	
}

void Board::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(frame);
}
