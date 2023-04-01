// Header files
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream.h>
#include<stdio.h>
#include<dos.h>
#include<time.h>


//-------------------------------------//

//Function----------------------------/
void start();
void info();
void about();
//-----------------------------------//
void main(){
int gd=0,gm;
initgraph(&gd,&gm,"C:/TURBOC3/BGI");
setbkcolor(GREEN);  //backgrond color
int x=220,y=230;
char ch;
while(1){  // loop for menu
cleardevice();
setcolor(1);
rectangle(50,50,600,450);
line(50,40,600,40);
setcolor(RED);
settextstyle(10,0,5) ;
setfillstyle(SOLID_FILL,RED);
outtextxy(getmaxx()/2-90,28,"SNAKE");
floodfill(250,60,RED);  // snake fill color
floodfill(340,80,RED);
floodfill(370,79,RED);
floodfill(406,80,RED);
floodfill(290,88,RED);
bar(getmaxx()/2-130,120,getmaxx()/2+160,130);
rectangle(x,y,x+230,y+30);  // yellow color menu selection
setfillstyle(SOLID_FILL,YELLOW);
floodfill(x+10,y+5,RED);
settextstyle(7,0,2);
setcolor(1);


 //menu
outtextxy(300,230,"START");
outtextxy(260,350,"GAME INFO");
outtextxy(300,310,"EXIT");
outtextxy(300,270,"ABOUT");


//movment of selction bar
ch=getch();
switch(ch){
case 72://up arrow key
	if(y==230){
	y=350;
	}
	else{
	 y-=40;
	}
	break;
case 80: // down arrow key
	if(y==350){
	y=230;
	}
	else
	y+=40;
	break;
case 13: // enter key for select the option
	if(y==230){

	 start();
	}
	else if(y==270){
	 about();
	}
	else if(y==310){
	closegraph();
	exit(0);
	}
	else if(y==350){

	info();
	}
	break;

}
delay(300);
}
}



// game start
void start(){
 int dir=0,pdir=3,snakex[200],snakey[200],foodx=200,foody=200,len,food;
 for(int i=0;i<200;i++){
 snakex[i]=0;
 snakey[i]=0;
 }
 snakex[0]=60;
 snakey[0]=60;
 foodx=200;
 foody=200;
 len=1;
 food=0;

 int game=1;
 int delaytime=300;
char str[10];
sprintf(str,"%d",food);
srand(time(0));
// game loop start
 while(game){
 cleardevice();
 setcolor(1);
 rectangle(50,50,600,450);
 line(50,40,600,40);
 setcolor(RED);
 settextstyle(1,0,4);
 outtextxy(580,0,str); // score
 settextstyle(4,0,4);
 outtextxy(getmaxx()/2-70,0,"SNAKE");
  // check sanke byte whit food
 if(snakex[0]==foodx  && snakey[0]==foody){
  len+=1;
  food+=1;
  sprintf(str,"%d",food);
  if(delaytime!=100){
   delaytime-=10;
  }
  foodx=rand()%520+70;
  foody=rand()%370+70;
  foodx=(foodx/10)*10;
  foody=(foody/10)*10;





 }
  // print food
 setfillstyle(SOLID_FILL,RED);
 bar(foodx,foody,foodx+10,foody+10);
 setfillstyle(SOLID_FILL,YELLOW);
     // snake movment
    switch (dir)
    {
    case 0:
	if(pdir==1){
	    snakex[0]-=10;
	}
	else if(pdir==2){
	    snakey[0]-=10;

	}
	else if(pdir==3){
	    snakex[0]+=10;

	}
	else if(pdir==4){
	    snakey[0]+=10;
	}
	else{
	    dir=0;
	}
	break;
case 1:
	     snakex[0]-=10;
	    pdir=1;
	    break;
case 2:
	     snakey[0]-=10;
	    pdir=2;
	    break;
case 3:
	     snakex[0]+=10;
	    pdir=3;
	    break;
case 4:
	     snakey[0]+=10;

	    pdir=4;
	    break;
    case 5:
	 settextstyle(1,0,4);
	 outtextxy(getmaxx()/2-100,getmaxy()/2,"press enter for exit");
	 outtextxy(getmaxx()/2-250,getmaxy()/2+50,"press any arrow key to continue");
	 char op=getch();
	 if(op==13){
	  main();
	 }
	 else
	 break;
       //	}

}

// keys for sanke direction
if(kbhit()){
    char kb=getch();
    if(kb==75||kb=='a'||kb=='A'){
	dir=1;//left
    }
    else if(kb==72||kb=='w'||kb=='W'){
	dir=2;//up
    }
    else if(kb==77||kb=='D'||kb=='d'){
	dir=3;//right
    }
    else if(kb==80||kb=='s'||kb=='S'){
	dir=4; //down
    }
    else if(kb==13){
	dir=5;
    }
}
// snake print
for(int i=0;i<len;i++){
 bar(snakex[i],snakey[i],snakex[i]+10,snakey[i]+10);
}
// conect all the bar
for(i=199;i > 0;i--){
 snakex[i]=snakex[i-1];
 snakey[i]=snakey[i-1];

}
delay(delaytime);
// chech snake die or not
if(snakex[0]>=590||snakex[0]<=50|| snakey[0]>=440|| snakey[0]<=50){
 game=0;
}


}
settextstyle(1,0,4);
 outtextxy(getmaxx()/2-100,getmaxy()/2,"GAME OVER");
 outtextxy(getmaxx()/2-150,getmaxy()/2+50,"press y for play again");
 fflush(stdin);
char ch=getch();
if(ch=='y'|| ch=='Y'){
 start();
}
main();
}
//---------------------------------------//
void info()  {
cleardevice();
 setcolor(1);
 rectangle(50,50,600,450);
 line(50,40,600,40);
 setcolor(9);
 settextstyle(8,0,7);
 outtextxy(getmaxx()/2-150,getmaxy()/2-170,"CONTROLS");
 setcolor(1);
 settextstyle(8,0,3);
 outtextxy(100,200,"UP    :-    W / UP ARROW KEY ");
 outtextxy(100,250,"DOWN  :-    S / DOWN ARROW KEY");
 outtextxy(100,300,"RIGHT :-    D / RIGHT ARROW KEY");
 outtextxy(100,350,"LEFT  :-    A / LEFT ARROW KEY");
 getch();


}

void about(){

cleardevice();
 setcolor(1);
 rectangle(50,50,600,450);
 setcolor(9);
 settextstyle(8,0,4);
 outtextxy(getmaxx()/2-50,10,"ABOUT");
 outtextxy(200,300,"CONTECT DETAILS");
 setcolor(1);
 settextstyle(12,0,1);
 outtextxy(55,70,"Iconic Snake is a classic snake game developed by Kunwar Pal a");
 outtextxy(55,100,"student at Mangalmay College, as a mini project using C++ programing ");
 outtextxy(55,130,"The game is played on a single screen with retro-style graphics ");
 outtextxy(55,160,"and sound effects. The objective of the game is to guide the snake");
 outtextxy(55,190,"to eat as much food as possible without crashing into the walls. ");
 outtextxy(55,220,"The snake grows longer with each food item consumed, making it more ");
 outtextxy(55,250,"challenging to navigate the grid. The rule of the game is that ");
 outtextxy(55,280,"the snake will die and the game will end if it crashes into a wall.");
 line(50,310,600,310);
 line(50,340,600,340);
 setcolor(9);
  settextstyle(7,0,2);
 outtextxy(55,350,"CONTACT NO:- 9654508953");
 outtextxy(55,380,"EMAIL:- atul621311@gmail.com");
 outtextxy(55,410,"LINKEDIN:- www.linkedin.com/in/kunwarpal/");
 getch();


}

//------------------------------------------------------------------------------//