#include "display.h"
#include <stdio.h>
#include <ncurses.h>

int main(void) {
    open_display();
    //reading values from stdin
    int hours;
    int minutes;
    int seconds;
    int ret; //returns number of successfully scanned items 
    display_colons();
    ret = scanf("%d:%d:%d", &hours, &minutes, &seconds);
    while(ret>=3){
        display_time(hours, minutes, seconds);
        clear();
        //display_colons();
        ret = scanf("%d:%d:%d", &hours, &minutes, &seconds);
    }
    clear();
    close_display();
    return 0;


    //sleep(2);
    //finish();
    //return 0;
}
