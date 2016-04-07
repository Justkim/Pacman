#include <SFML/Graphics.hpp>

#include <stdio.h> 
#include <unistd.h>


class Ghost{
	
	
	

	
	
	bool inBox;
	int randomNumber;
	int prekey;
	bool ghost1;
	bool ghost2;
	int frightenedTime;
	
    public:
    	
	   float gx;
	   float gy;
	   int gi;
	   int gj;
       sf::Texture gshape;
	   sf::Sprite ghost;
	   sf::Texture gfshape;
	   
	   
	   Ghost();
	   void setgxgy(int a,int b){gx=a*40+550;gy=b*40;};
	   int moveGhost();
	   void moveRandom();
	   void makeGhost1();
	   void makeGhost2();
	   int up();
	   int down();
	   int right();
	   int left();
	   
	   
	   
    
	
	
	
};
Ghost::Ghost()
{
	
	
	inBox=true;
	
	
    
    ghost.setScale(3,3);
    randomNumber=0;
    prekey=0;
    frightenedTime=0;
    gfshape.loadFromFile("frightened1.png"); 
 
	
	
} 


void Ghost::makeGhost1()
{
	gshape.loadFromFile("ghost1.png");
	ghost.setTexture(gshape);
	gi=13;
    gj=11;
	ghost.setPosition(990,520); 
    ghost1=true;
    ghost2=false;
    inBox=true;
    prekey=0;
	
}
void Ghost::makeGhost2()
{
	gshape.loadFromFile("ghost2.png");
 
    ghost.setTexture(gshape);
    gi=13;
    gj=9;
    ghost.setPosition(910,520); 
	ghost1=false;
	ghost2=true;
	inBox=true;
	prekey=0;
	
}
void Ghost::moveRandom()
{
	
	randomNumber=(rand()%4)+1;
	moveGhost();
	
	
	
	
		
}
int Ghost::left()
{
	   	if((map[gi][gj-1])!=1)
				{
					
				   
				   gj--;
				   setgxgy(gj,gi);
	               ghost.setPosition(gx,gy); 
	               prekey=2;
	               randomNumber=prekey;
	              
	               
				    if(gi==pi && gj==pj)
					if(frightened)
					{
						if(ghost1)
						{
						  makeGhost1();
						  frightened=false;
						}
					    else if(ghost2)
					    {
						  makeGhost2();
						  frightened=false;
					}
					else
					   pacmanIsAlive=false;
					return 1;
			}
			
			
			return 0;//movement wasn't allowed
		}
	
}
int Ghost::right()
{
	   	if((map[gi][gj+1])!=1)
				{
				  
				   gj++;
				   setgxgy(gj,gi);
	               ghost.setPosition(gx,gy); 
	               prekey=1;
	               randomNumber=prekey;
	               
				    if(gi==pi && gj==pj)
					if(frightened)
					{
						if(ghost1)
						{
						  makeGhost1();
						  frightened=false;
					    }
					else if(ghost2)
					   {
						makeGhost2();
						frightened=false;
					   }
					}
					else
					   pacmanIsAlive=false;
					return 1;
			}
	
	    return 0;
	
	
	
}
int Ghost::down()
{

	
	if((map[gi+1][gj])!=1)
				{
					
				   gi++;
				   setgxgy(gj,gi);
	               ghost.setPosition(gx,gy);
	               prekey=4; 
	               randomNumber=prekey;
	               
				    if(gi==pi && gj==pj)
					if(frightened)
					{
						if(ghost1)
						{
						  makeGhost1();
						  frightened=false;
						}
					else if(ghost2)
					    {
						makeGhost2();
						frightened=false;
					    }
					}
					else
					   pacmanIsAlive=false;
				   return 1;//movement is done 
			}
	return 0;//movement wasn't allowed
	
	
	
}
int Ghost::up()
{
	 
	
			   	if((map[gi-1][gj])!=1)
				{
				  
				   gi--;
				   setgxgy(gj,gi);
	               ghost.setPosition(gx,gy); 
	               prekey=3;
	               randomNumber=prekey;
	               
				   if(gi==pi && gj==pj)
					if(frightened)
					{
						if(ghost1)
						{
						  makeGhost1();
						  frightened=false;
					    }
					else if(ghost2)
					{
						makeGhost2();
						frightened=false;
					}
					}
					else
					   pacmanIsAlive=false;
				   return 1;
			}
		return 0;	
	
	
}			
	
int Ghost::moveGhost()
{
	
	if(frightened)
	{
	  
	  frightenedTime++;
	  ghost.setTexture(gfshape);
	  
	  
    }
	else
	{
	   
	  frightenedTime=0;
	  ghost.setTexture(gshape);
	  
	  
	}
	if(frightenedTime==100)
		frightened=false;
 
	
	if(inBox)
		{
	    if(ghost1)
		while(gi>=10)
		  {
			gi--;
			setgxgy(gj,gi);
	        ghost.setPosition(gx,gy); 
	        
	       }
	      if(ghost2)
	      while(gi<=14)
		  {
			gi++;
			setgxgy(gj,gi);
	        ghost.setPosition(gx,gy); 
	        
	       }
	      
	    inBox=false;
	    return 0;
	}
	    
	
	switch(randomNumber)
	{
		case 0:
			moveRandom();
		break;
		case 3:
		
		 if(up()==1)	
		  randomNumber=prekey;
		 else
			moveRandom();
		break;
	
		case 4:
		 if(down()==1)
			randomNumber=prekey;
		 else
			moveRandom();
		break;
		case 1:
		 if(right()==1)
			randomNumber=prekey;
		 else
			moveRandom();
		break;
		case 2:
		 if(left()==1)
			randomNumber=prekey;
		 else
			moveRandom();
		
		break;
		 
    }
    
   return 0; 
	
	    
	
	
	
	
	
}
