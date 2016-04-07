
#include <SFML/Graphics.hpp>
//some global values
int map[24][21];
bool frightened;
bool pacmanIsAlive=true;
int score;


class Map//define a class for properties of any point on the screen 
{ 

	    float x;
	    float y;
	      
	    sf::RectangleShape rectangle;
	    sf::CircleShape circle;
	  
	    
	    
	public:
	  
	    
	
	
	    sf::RectangleShape getr(){return rectangle;};
	    sf::CircleShape getc(){return circle;};
	    sf::CircleShape getc2(){circle.setFillColor(sf::Color::Yellow);
			                      return circle;};
	    float getx(){return x+20;};
	    float gety(){return y+20;};
	    float setxy(int a,int b){x=a*40+550;y=b*40;};
	    void  makeBlock();
	    
	    
	    
	    
};

void Map::makeBlock()
{
	 
	  
	  rectangle.setPosition(x,y);
	  rectangle.setFillColor(sf::Color::Blue);
	  rectangle.setSize(sf::Vector2f(40,40));
      circle.setRadius(6);
	  circle.setFillColor(sf::Color::White);
	  circle.setPosition(x+20,y+20);
	  circle.setPointCount(100);

}

