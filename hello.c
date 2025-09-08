#include <stdio.h>

int main() {
    int nums[3] = {10,20,30};

    int value1 = *nums;
    int value2 = *(nums+1);
    int value3 = *(nums+2);

    printf("v1 %d v2 %d v3 %d", value1, value2, value3);




    return 0;
}