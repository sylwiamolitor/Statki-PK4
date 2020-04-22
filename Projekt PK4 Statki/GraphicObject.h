
#include <SFML/Graphics.hpp>
#include <iostream>

enum size { one, two, three, four }; // rozmiar
class Graphic_Object
{

};

class Ship : public Graphic_Object, public sf::Transformable, public sf::Drawable
{
	size rozmiar;
	int x;
	int y;
public:
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

class Main_screen : public Graphic_Object, public sf::Transformable, public sf::Drawable
{
public:
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};