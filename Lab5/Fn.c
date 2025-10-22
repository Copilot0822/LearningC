#include <stdio.h>
#include <math.h>


int baseArray[4] = {0, 0, 0, 0};

void inputs(){
    // printf("Give Input ($ 0 0 0 0 to stop): ");

    char oper;
    int inBase;
    int num1;
    int num2;
    int outBase;

    int good = 0;

    //breaks once allowed input is aquired
    while(1){
        good = 0;
        printf("Give Input ($ 0 0 0 0 to stop): ");

        // char oper;
        // int inBase;
        // int num1;
        // int num2;
        // int outBase;

    
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
        if(checkBase(num1, inBase)){
            good++;
        }
        else{
            printf("\ninvalid parameter: Num1 not Based");
        }



        //num2 check
        if(num2 > 0){
            good++;
        }
        else{
            printf("\ninvalid parameter: Num2 not positive");
        }
        if(checkBase(num2, inBase)){
            good++;
        }
        else{
            printf("\ninvalid parameter: Num2 not Based");
        }





        if(outBase >= 2 && outBase <= 10){
            good++;
        }
        else{
            printf("\ninvalid parameter: Output Base");
        }

        

        


        printf("\ngood: %d\n", good);

        if(good >= 7){
            break;
        }
        



    }

    baseArray[3] = outBase;

    baseArray[1] = toDecimalConverter(num1, inBase);
    // baseArray[1] = num1;

    // baseArray[2] = num2;

    baseArray[2] = toDecimalConverter(num2, inBase);


    




}

int digitFinder(int num){
    for(int i = 1; 1; i++){
        if(num% (int)(pow(10, i)) == num){
            return i;
        }
    }
}
int checkBase(int num, int base){
    int numDigits = digitFinder(num);
    
    int out = 1;
    int arr[19];

    // printf("numdiigits: %d", numDigits);


    for(int i = 0; i< numDigits; i++){
        int digit = num%(int)pow(10, i+1);
        if(i == 0){
            arr[i] = digit;
        }
        else{
            arr[i] = (digit-arr[i-1])/pow(10, i);

        }

        if(arr[i] >= base){
            out = 0;
        }
        // printf("\n%d\n", arr[i]);
    }
    return out;
}
int toDecimalConverter(int num, int base){
    int numDigits = digitFinder(num);
    int arr[19] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int out = 0;

    for(int i = 0; i< numDigits; i++){
        int digit = num%(int)pow(10, i+1);
        if(i == 0){
            arr[i] = digit;
        }
        else{
            arr[i] = (digit-arr[i-1])/(int)pow(10, i);

        }
    }
    for(int i = 0; i<18; i++){
        out += arr[i]*(int)pow(base, i);
    }
    return out;


}


int calculate(){
    if(baseArray[0] == 0){
        return baseArray[1] + baseArray[2];
    }
    else if(baseArray[0] == 1){
        return baseArray[1] - baseArray[2];
    }
    else if(baseArray[0] == 2){
        return baseArray[1] * baseArray[2];
    }
    else{
        return (int)round((double)baseArray[1] / (double)baseArray[2]);
    }
}

// int output(int outputNum, int base){

// }

int main(int argc, char const *argv[])
{

    // printf("%d\n\n", digitFinder(111));


    // printf("%d\n\n", checkBase(4210, 4));
    // printf("\n%d\n", toDecimalConverter(11, 2));
    // printf("\n%d\n", toDecimalConverter(11, 2));


    inputs();
    printf("%d %d %d %d", (baseArray[0]), (baseArray[1]), (baseArray[2]), (baseArray[3]));
    printf("\n%d", calculate());



    


    /* code */
    return 0;
}
