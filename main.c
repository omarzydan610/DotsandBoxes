#include<stdio.h>
#include"ANSI-color-codes.h"

char arr[1000]={0};
int choosen(char a,int b){
    for(int i=0;i<=b;i++){
        if(a==arr[i]){
            return 1;
        }
    }
    return 0;
}




int main(){
    int index=0;
    char x;
            int count1=65,count2=92;
        arr[index]=x;
        for(int i=0;i<17;i++){
            if(i%4==0){
                for(int j=0;j<4;j++){
                    printf("•");
                    if(!choosen(count1,index)){
                        printf("--%c--",count1);
                    }
                    else{
                        printf(BRED"-----"reset);
                    }
                    if(j==3){
                        printf("•");
                    }
                    count1++;
                }
                printf("\n"); 
                count2+=5;
            }

            else{
                for(int j=0;j<5;j++){
                    if((choosen(count2,index))){
                        printf(BBLU"|     "reset);
                    }
                    else{
                        if(i%2!=0){
                        printf("|     ");
                        }
                        else{
                            printf("%c     ",count2);
                        }
                    }
                    count2++;
                }
                count2-=5;
                printf("\n");
            }
        }
        printf("\n");
    while(1){
        int count1=65,count2=92;
        printf("Enter the letter of the line : \n");
        scanf("%c",&x);
        arr[index]=x;
        for(int i=0;i<17;i++){
            if(i%4==0){
                for(int j=0;j<4;j++){
                    printf("•");
                    if(!choosen(count1,index)){
                        printf("--%c--",count1);
                    }
                    else{
                        printf(BRED"-----"reset);
                    }
                    if(j==3){
                        printf("•");
                    }
                    count1++;
                }
                printf("\n"); 
                count2+=5;
            }

            else{
                for(int j=0;j<5;j++){
                    if((choosen(count2,index))){
                        printf(BBLU"|     "reset);
                    }
                    else{
                        if(i%2!=0){
                        printf("|     ");
                        }
                        else{
                            printf("%c     ",count2);
                        }
                    }
                    count2++;
                }
                count2-=5;
                printf("\n");
            }
        }
        index++;
        printf("\n");
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



        //   for(int j=0;j<5;j++){
        //             if(1){
        //                 if(i%2==0){
        //                     printf("%c     ",count2);
        //                     count2++;   
        //                 }
        //                 else{
        //                     printf("|     ");
        //                 }
        //             }
        //             else{
        //                 printf(BBLU"|     " reset);
        //                 if(i%2==0){
        //                     count2++;
        //                 }
        //             }
        //         }
        //         printf("\n");






        // 
            //     printf("|     |     |     |     |\n%c     %c     %c     %c     %c\n|     |     |     |     |\n",count2,count2+1,count2+2,count2+3,count2+4);
            //     count2+=5;
            // }



