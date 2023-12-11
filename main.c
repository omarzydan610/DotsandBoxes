#include<stdio.h>
int main(){
    int count1=65,count2=97;
    int i;
    for(int i=0;i<17;i++){
        if(i%4==0){
            for(int j=0;j<4;j++){
                printf("•");
                if(1){
                    printf("--%c--",count1++);
                }
                if(j==3){
                    printf("•");
                }
            }
            printf("\n");   
        }
        else{
            if(1){
                if(i%2==0){
                    for(int j=0;j<5;j++){
                        printf("%c     ",count2++);
                    }
                }
                else{
                    for(int j=0;j<5;j++){
                        printf("|     ");
                    }
                }
                printf("\n");
            }
        }
    }
}



//    •--A--•--B--•--C--•--D--•
//    |     |     |     |     |
//    a     b     c     d     e
//    |     |     |     |     |
//    •--E--•--F--•--G--•--H--•
//    |     |     |     |     |
//    f     g     h     i     j
//    |     |     |     |     |
//    •--I--•--J--•--K--•--L--•
//    |     |     |     |     |
//    k     l     m     n     p
//    |     |     |     |     |
//    •--M--•--N--•--P--•--Q--•
//    |     |     |     |     |
//    q     r     s     t     u
//    |     |     |     |     |
//    •--R--•--S--•--T--•--U--•