#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]){
    float x, y;

    printf("Enter X: ");
    scanf("%f", &x);

    printf("\nEnter Y: ");
    scanf("%f", &y);

    x = round(x*100)/100;
    y = round(y*100)/100;

    // printf("%f %f", x, y);

    if(x == 0&& y ==0){
        printf("(%.2f, %.2f) is on the origin", x, y);

    }
    else if(x > 0){
        if(y<0){
            printf("(%.2f, %.2f) is in IV", x, y);
        }
        else if(y == 0){
            printf("(%.2f, %.2f) is on the positive X axis", x, y);
        }
        else{
            printf("(%.2f, %.2f) is in I", x, y);
        }
    }
    else if(x==0){
        if(y<0){
            printf("(%.2f, %.2f) is on the negative Y axis", x, y);
        }
        else{
            printf("(%.2f, %.2f) is on the positive Y axis", x, y);
        }
    }
    else{
        if(y<0){
            printf("(%.2f, %.2f) is in III", x, y);
        }
        else if(y == 0){
            printf("(%.2f, %.2f) is on the Negative X axis", x, y);
        }
        else{
            printf("(%.2f, %.2f) is in II", x, y);
        }
    }









    



    return 0;
}
