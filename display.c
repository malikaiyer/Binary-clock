#include "display.h"
#include "ncurses.h"

#define WHITE 1
#define GREEN 2
#define RED 3
#define BLUE 4
#define BLACK 5

int open_display(void){
    int exit= initscr() ? 1:0;
    start_color();
    init_pair(WHITE, COLOR_WHITE, COLOR_WHITE);
    init_pair(GREEN, COLOR_GREEN, COLOR_GREEN);
    init_pair(RED, COLOR_RED, COLOR_RED);
    init_pair(BLUE, COLOR_BLUE, COLOR_BLUE);
    init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);
    refresh();
    return 0;
}
void display_time(int hours, int minutes, int seconds){
    display_colons();
    display_hours(hours);
    display_minutes(minutes);
    display_seconds(seconds);
}
void display_colons(void){
  
    //Sets foreground and background to WHITE when drawing
     attron(COLOR_PAIR(WHITE));
   
   // move(1,2);
    for (int col=2; col<=3; col++){
       mvaddch(2,col,'#');
    }

   // move(2,2);
    for(int col=5; col<=6; col++){
        mvaddch(2,col,'#');
    }

   // move(4,2);
    for (int col=2; col<=3; col++){
       mvaddch(3,col,'#');
    }

   // move(5,2);
    for(int col=5; col<=6 ; col++){
        mvaddch(3,col,'#');
    }
   // move(1,5);
    for(int col=2; col<=3 ; col++){
        mvaddch(5,col,'#');
    }
   
    // move(2,5);
     for (int col=5; col<=6; col++){
         mvaddch(5,col,'#');
    }
    
    //move(4,5);
    for(int col=2; col<=3; col++){
         mvaddch(6,col,'#');
     }
    
    //move(5,5);
    for (int col=5; col<=6; col++){
      mvaddch(6,col,'#');
     }
    refresh();
} 

void display_hours(int hours){
    attron(COLOR_PAIR(GREEN));

   // move(1,7);
    int setHr=hours;
    int row = 1;
    while (setHr!=0){
        if(setHr%2==1){
            mvaddch(row,1,'#');
        }
        row+=1;
        setHr=setHr/2;
    }
    refresh();
}

void display_minutes(int minutes){
    attron(COLOR_PAIR(RED));
   //move(4,7);
   int row=1;
   while(minutes>0){
     if(minutes%2==1){
       mvaddch(row,4,'#');
   }
    row=row+1;
    minutes=minutes/2; 
    }
    refresh();
}

void display_seconds(int seconds){
    attron(COLOR_PAIR(BLUE));
  /*  int setSec = seconds;
    while(setSec!=0){
        if((setSec%32)!= setSec){
            move(1,7);
            addch('#');
                setSec = setSec%32;
        }
         if((setSec%16)!= setSec){
              move(2,7);
              addch('#');
              setSec = setSec%16;
          }
         if((setSec%8)!= setSec){
             move(3,7);
             addch('#');
             setSec = setSec%8;
             }
         if((setSec%4)!= setSec){
             move(4,7);
             addch('#');
             setSec = setSec%4;
          }
         if((setSec%2)!= setSec){
             move(5,7);
             addch('#');
             setSec = setSec%2;
          }
          if((setSec%1)!= setSec){
              move(6,7);
              addch('#');
              setSec = setSec%1;
          }
          refresh();
    }
}*/
    //move(7,7);
    int row=1;
    while(seconds>0){
     if(seconds%2==1){
        mvaddch(row,7,'#');
      }
     row=row+1;
     seconds=seconds/2;
    }
   refresh();

}

void close_display(void){
    endwin();
}


/*
void display_sigma(void) {
    initscr();
    start_color();
    init_pair(WHITE, COLOR_WHITE, COLOR_WHITE);
    init_pair(GREEN, COLOR_GREEN, COLOR_GREEN);

    // Sets forground and background to WHITE when drawing
    attron(COLOR_PAIR(WHITE));
    // Top and bottom of sigma
    move(0,3);
    for(int col=3; col<8; col++) {
        addch('#');
    }
    move(6,3);
    for(int col=3; col<8; col++) {
        addch('#');
    }

    // Middle. Make it green, just for fun!
    attron(COLOR_PAIR(GREEN));
    for(int col=4; col<7; col++) {
        mvaddch(col-3,col,'#');
        mvaddch(9-col,col,'#');
    }
    refresh();
}*/

void fill_pixels(void) {
    attron(COLOR_PAIR(BLACK));
   // move(0,0); 
    for(int i=0; i<8; i++) {
         for(int j=0; j<8; j++) {
              mvaddch(i,j,'#');
          }
        }
    refresh();
 }
       

void finish(void) {
    endwin();
} 
