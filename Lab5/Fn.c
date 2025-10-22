#include <stdio.h>

int baseArray[4] = {0, 0, 0, 0};

void inputs(){
    // printf("Give Input ($ 0 0 0 0 to stop): ");

    // char oper;
    // int inBase;
    // int num1;
    // int num2;
    // int outBase;

    int good = 0;


    while(1){
        good = 0;
        printf("Give Input ($ 0 0 0 0 to stop): ");

        char oper;
        int inBase;
        int num1;
        int num2;
        int outBase;

    
        scanf(" %c %d %d %d %d", &oper, &inBase, &num1, &num2, &outBase);

        printf("%c %d %d %d %d", oper, inBase, num1, num2, outBase);


        //operator check
        if(oper == '$') {
            printf("out");
            exit(0);
        }
        else if(oper == '+'){
            baseArray[0] = 0;
            good++;
        }
        else if(oper == '-'){
            baseArray[0] = 1;
            good++;
        }
        else if(oper == '*'){
            baseArray[0] = 2;
            good++;
        }
        else if(oper == '/'){
            baseArray[0] = 3;
            good++;
        }
        else{
            printf("\ninvalid parameter: Operator, %c", oper);
        }

        // in base check
        if(inBase>= 2 && inBase<=10){
            good++;
        }
        else{
            printf("\ninvalid parameter: Input Base");
        }

        //num1 check
        if(num1 > 0){
            good ++;
        }
        else{
            printf("\ninvalid parameter: Num1 not positive");
        }


        //num2 check
        if(num2 > 0){
            good++;
        }
        else{
            printf("\ninvalid parameter: Num2 not positive");
        }

        if(outBase >= 2 && num2 <= 10){
            good++;
        }
        else{
            printf("\ninvalid parameter: Output Base");
        }


        printf("\ngood: %d\n", good);

        if(good >= 5){
            break;
        }
        



    }


    




}



int main(int argc, char const *argv[])
{
    inputs();
    printf("%d %d %d %d", (baseArray[0]), (baseArray[1]), (baseArray[2]), (baseArray[3]));


    /* code */
    return 0;
}
