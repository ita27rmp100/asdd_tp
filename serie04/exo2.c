#include <stdio.h>
#include <stdlib.h>

int DecToBin(int n){
    if(n==0){
        return 1;
    }
    else{
        return DecToBin(n/2) ;
        printf("%d",n%2);
    }
}

int main(){
    DecToBin(5);

    return 1;
}