#include <stdio.h>
#include <math.h>


int main(int argc, char const *argv[])
{
    printf("Enter Mins: ");
    int mins;
    scanf("%d", &mins);
    int hours = 0;
    while(mins >= 60){
        mins -= 60;
        hours ++;


    }
    // mins = 1;
    mins = (int)round((double)mins / 15.0);
    // printf("%d", mins);

    if(mins == 4){
        mins = 0;
        hours ++;
    }
    else if(mins == 3){
        mins = 45;
    }
    else if(mins == 2){
        mins = 30;
    }
    else if(mins == 1){
        mins = 15;

    }
    else
    {
        mins = 0;
    }

    printf("Hours: %d, mins: %d", hours, mins);
    

    

    /* code */
    return 0;
}
