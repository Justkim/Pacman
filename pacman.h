#include <SFML/Graphics.hpp>
#include <unistd.h> 

int pi;
int pj;

class Pacman{
	
	   float px;
	   float py;
	   int prekey;
	   bool mouthOpen;
	  
       
	   
	public:
	
	   
	   
	   
	   sf::Texture shape1;
	   sf::Texture shape2;
	   sf::Texture shape3;
	   sf::Texture shape4;
	   sf::Texture shape5;
	   sf::Texture shape6;
	   sf::Texture shape7;
	   sf::Texture shape8;
       sf::Sprite pacman;
       bool gameStart;
	     
         



       
       
	   
       void movePacman();
       int up();
       int down();
       int right();
       int left();
       void showPacman();
       int getpi(){return pi;};
       int getpj(){return pj;};
       Pacman();
       void setpxpy(int a,int b){px=a*40+550;py=b*40;};
       void makePacman();
	   
};
Pacman::Pacman()
{
    
    score=0; 

	
}
void Pacman::makePacman()
{
	 
 pacman.setTexture(shape1);
 pacman.setPosition(950,760); 
 pacman.setScale(3,3);
 prekey=0;
 pi=19;
 pj=10;
 mouthOpen=false;
 gameStart=false;
 int i=0;
 int j=0;
}
int  Pacman::right()
{
	

	if(pj+1>20)
	{
		usleep(120000);
		return 0;
	}
	if((map[pi][pj+1])!=1 && (map[pi][pj+1])!=-2)
	
		{
			if(map[pi][pj+1]==0)
				score++;
			if(map[pi][pj+1]==2)
		    {
				score+=2;
				frightened=true;
			}
				
	        pj++;
	        setpxpy(pj,pi);
	        pacman.setPosition(px,py); 
	        map[pi][pj]=-1;
	        
	
	 if(!mouthOpen)
	     {
	        pacman.setTexture(shape2);
	        mouthOpen= true;
	      }
	      else
           {
			pacman.setTexture(shape1);
	        mouthOpen= false;
	      }
	      usleep(120000);
	      return 1;
	   }
	
	usleep(120000);
	return 0;
	
	
	
	
}
int Pacman::left()
{
	

	if(pj-1<0)
	{
		usleep(120000);
		return 0;
		
    }
	if((map[pi][pj-1])!=1 && (map[pi][pj-1])!=-2)
		
		{
			if(map[pi][pj-1]==0)
				score++;
			if(map[pi][pj-1]==2)
			{
				score+=2;
				frightened=true;
			}
	        pj--;
	        setpxpy(pj,pi);
	        pacman.setPosition(px,py);
	        map[pi][pj]=-1;
	     if(!mouthOpen)
	     {
	        pacman.setTexture(shape4);
	        mouthOpen= true;
	      }
	      else
           {
			pacman.setTexture(shape3);
	        mouthOpen= false;
	      }
	      usleep(120000);
			  
	        return 1;
		}
	usleep(120000);
    return 0;
	
}
int Pacman::down()
{
	

     if(pi+1>23)
     {
		usleep(120000);
		return 0;
	 }
	if((map[pi+1][pj])!=1 && (map[pi+1][pj])!=-2)
	
		{
			
			if(map[pi+1][pj]==0)
				score++;
			if(map[pi+1][pj]==2)
			{
				score+=2;
			    frightened=true;
			}	
			pi++;
			//printf("pi is %d and pj is %d map is %d \n",pi,pj,map[pi][pj]);
			setpxpy(pj,pi);
			pacman.setPosition(px,py); 
			map[pi][pj]=-1;
			
		 if(!mouthOpen)
	     {
	        pacman.setTexture(shape8);
	        mouthOpen= true;
	      }
	      else
           {
			pacman.setTexture(shape7);
	        mouthOpen= false;
	      }
	       usleep(120000);
	       return 1;
	      
		}
		
	      usleep(120000);
	
	return 0;
}

int Pacman::up()
{
 

	if(pi-1<0)
	{
		usleep(120000);
		return 0;
	}
	if((map[pi-1][pj])!=1 && (map[pi-1][pj])!=-2)
		
		{
			if(map[pi-1][pj]==0)
				score++;
			if(map[pi-1][pj]==2)
			{
				score+=2;
				frightened=true;
			}
				
			pi--;
			setpxpy(pj,pi);
			pacman.setPosition(px,py);
			map[pi][pj]=-1;
		
		
		 if(!mouthOpen)
	     {
	        pacman.setTexture(shape6);
	        mouthOpen= true;
	      }
	      else
           {
			pacman.setTexture(shape5);
	        mouthOpen= false;
	      }
	      
	      usleep(120000);
	      return 1;
	  }
	   usleep(120000);
	return 0;
}



void Pacman::movePacman()//moves the pacman
{
	
	
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))    
    {
	  gameStart=true;
	  prekey=1;
	  right();
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
      {
		gameStart=true;
        prekey=2;
        left();
       }

   else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
     {
		 gameStart=true;
		 prekey=3;
		 up();
	 }
    
  else  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))	
   {
	   gameStart=true;
	   prekey=4;
	   down();
     
    }
    else
		switch(prekey)
		{
			case 1:
				right();
			break;
			case 2:
				left();
			break;
			case 3:
				up();
			break;
			case 4:
				down();
			break;
		}
				
   


}//end of movePacman	
		
		
