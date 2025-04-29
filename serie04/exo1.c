#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int power(int base, int exp){
    if(exp==0){
        return 1;
    }
    else{
        return base * power(base,exp-1);
    }
}

int main(){

    printf("%i",power(3,2));

    return 0;
}