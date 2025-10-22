#include <stdio.h>
#include <stdbool.h>

bool isOdd(int number){
    return (number % 2) != 0;
}
int main(){
    
    long double pi = 4;
    long double terms = 1;
    long double num = 3;
    
    printf("Enter number of terms: ");

    int numterms;

    scanf("%d", &numterms);

    for(int i = 1;i<=numterms;i++){
        if(isOdd(i)){
            terms -=(1/num);
        }
        else{
            terms +=(1/num);
        }

        //terms += 1/num;
        // printf("%Lf\n", terms);
        num +=2;
    }
    pi = pi*terms;

    printf("pi is: %Lf", pi);

    return 0;
}