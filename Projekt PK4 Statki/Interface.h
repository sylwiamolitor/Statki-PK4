#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>


enum shot_or_not { shot, not_shot }; //czy zestrzelony



class Interface
{
protected:
	sf::Text text;
	sf::Font font;
	sf::Vector2f position;
	sf::RectangleShape frame;

	public:
		virtual	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

class Button :  public sf::Transformable, public sf::Drawable  
{
	sf::Text text;
	sf::Font font;
	sf::Vector2f position;
	sf::RectangleShape frame;
	public:
		Button(std::string text, sf::Font& font, int characterSize, sf::Vector2f position);
		void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};




class Board : public sf::Transformable, public sf::Drawable
{
	
	sf::Font font;
	sf::Vector2f position;
	sf::RectangleShape frame;
	public:
		Board(sf::Font& font, sf::Vector2f position);
		void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};

class Field : public Board
{
public:
	//Field();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
	char content;
	bool hit_or_not;
};

class Count_Score : public Interface, public sf::Transformable, public sf::Drawable
{
public:
	void show_score();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};

