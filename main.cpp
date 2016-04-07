#include "map.h" 
#include "pacman.h"
#include "ghost.h"
#include <SFML/Graphics.hpp>
#include <stdio.h>



Ghost ghost1;
Ghost ghost2;
int live=3;
char number[4];//the string that holds the score

sf::Text Numbers;

 
void showNumbers()
{
	snprintf(number,sizeof(number),"%d",score);
	Numbers.setString(number);
}


int main()
{
	
	
  sf::RenderWindow window(sf::VideoMode(3000,3000), "Pacman");
  window.setFramerateLimit(40);
  
  Numbers.setPosition(350,200);
  Numbers.setCharacterSize(50);
  Numbers.setColor(sf::Color::Red);
   

 int map1[24][21]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1},
{1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,0,1,1,1,0,1},{1,2,1,1,1,0,1,1,0,1,1,1,0,1,1,0,1,1,1,2,1}
 ,{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1},
 {1,0,0,0,0,1,1,1,0,1,1,1,0,1,1,1,0,0,0,0,1},{1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1},
 {1,1,1,1,0,1,1,1,0,0,0,0,0,1,1,1,0,1,1,1,1},{-1,-1,-1,1,0,1,1,1,0,0,0,0,0,1,1,1,0,1,-1,-1,-1}
 ,{1,1,1,1,0,1,1,-2,-2,-2,-2,-2,-2,-2,1,1,0,1,1,1,1},{1,0,0,0,0,1,1,-2,-2,-2,-2,-2,-2,-2,1,1,0,0,0,0,1}
 
  ,{1,0,0,0,0,1,1,-2,-2,-2,-2,-2,-2,-2,1,1,0,0,0,0,1},{1,1,1,1,0,1,1,-2,-2,-2,-2,-2,-2,-2,1,1,0,1,1,1,1},
  {-1,-1,-1,1,0,1,1,1,0,0,0,0,0,1,1,1,0,1,-1,-1,-1},{1,1,1,1,0,1,1,1,0,0,0,0,0,1,1,1,0,1,1,1,1},
  {1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1},{1,0,0,0,0,1,1,1,0,1,1,1,0,1,1,1,0,0,0,0,1},
  {1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,2,1,1,1,0,1,1,0,1,1,1,0,1,1,0,1,1,1,2,1},{1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,0,1,1,1,0,1},
  {1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
  for(int i=0;i<24;i++)
	for(int j=0;j<21;j++)
		map[i][j]=map1[i][j];
  

 Map gameMap[24][21];
 

 Pacman pacman;

 //pacman.setmap(map);
 
 pacman.shape1.loadFromFile("pacmanRC.gif"); 
 pacman.shape2.loadFromFile("pacmanRO.gif"); 
 pacman.shape3.loadFromFile("pacmanLC.gif"); 
 pacman.shape4.loadFromFile("pacmanLO.gif"); 
 pacman.shape5.loadFromFile("pacmanUC.gif"); 
 pacman.shape6.loadFromFile("pacmanUO.gif"); 
 pacman.shape7.loadFromFile("pacmanDO.gif"); 
 pacman.shape8.loadFromFile("pacmanDC.gif"); 
 
 //score
 
 
  sf::Font font;
  font.loadFromFile("Ubuntu_Bold.ttf");
  sf::Text showScore;
  showScore.setFont(font);
  Numbers.setFont(font);
  showScore.setString("Score:");
  showScore.setPosition(200,200);
  showScore.setCharacterSize(50);
  showScore.setColor(sf::Color::Red);
 
  
  
  
  
  //
 
 pacman.shape1.setSmooth(true);
 pacman.shape2.setSmooth(true);
 pacman.shape3.setSmooth(true);
 pacman.shape4.setSmooth(true);
 pacman.shape5.setSmooth(true);
 pacman.shape6.setSmooth(true);
 pacman.shape7.setSmooth(true);
 pacman.shape8.setSmooth(true);
 pacman.makePacman();
 int i;int j;
 ghost1.makeGhost1();
 ghost2.makeGhost2();
   while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
      
      
     for(i=0;i<24;i++)
      for(j=0;j<21;j++)
      {
		  if(map[i][j]==1)
		    {
			  gameMap[i][j].setxy(j,i);
			  gameMap[i][j].makeBlock();
			  window.draw(gameMap[i][j].getr());
			  
			}
		  else if((map[i][j])==0)
		  {
		      gameMap[i][j].setxy(j,i);
			  gameMap[i][j].makeBlock();
			  window.draw(gameMap[i][j].getc());
			  
		  }
		  else if((map[i][j])==2)
		  {
			  gameMap[i][j].setxy(j,i);
			  gameMap[i][j].makeBlock();
			  window.draw(gameMap[i][j].getc2());
		   }
			  
		  
             
	  }
	    showNumbers();
	    window.draw(showScore);
	    window.draw(Numbers);
	    window.draw(pacman.pacman);
	    window.draw(ghost1.ghost);
	    window.draw(ghost2.ghost);
	    pacman.movePacman();
	   if(pacman.gameStart)
	   {
	    ghost1.moveGhost();
	    ghost2.moveGhost();
	   
	   }
	   if (!pacmanIsAlive)
	   {
		pacman.makePacman();
		live--;
		pacman.gameStart=false;
		ghost1.makeGhost1();
		ghost2.makeGhost2();
		pacmanIsAlive=true;
	   }
	   
		
	   if(!live)
	   {
		   showScore.setString("Game Over");
           showScore.setPosition(800,800);
           showScore.setCharacterSize(70);
           showScore.setColor(sf::Color::Red);
           
		   
		}
		if(score==186)
		{
		   showScore.setString("You Won");
           showScore.setPosition(800,800);
           showScore.setCharacterSize(70);
           showScore.setColor(sf::Color::Red);
           
           
         }
			
	    window.display();
        window.clear();
    }
	return 0;
}
        
