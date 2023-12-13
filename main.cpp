#include<stdio.h>
#include<iostream>
#include"ANSI-color-codes.h"
using namespace std;

char arr[60]={0};

typedef struct{
    string playername;
    int color;
}player;
player p1,p2;

int chooseLevel(){
    int ans;
    printf("Choose your level\n1-Biginer\n2-Expert\n");
    cin>>ans;
    if(ans==1){
        return 2;
    }
    else if(ans==2){
        return 5;
    }
    else{
        printf("Invalid Choice\n");
        return chooseLevel();
    }
}

void enterPlayers(){
    printf("Enter player1 name : ");
    cin>>p1.playername;
    cout<<"Hi "<<p1.playername<<" ";
    int ans=0;
    while(ans==0){
        printf("Choose your color\n");
        printf("1-Red\n2-Blue\n3-Pink\n4-Yellow\n");
        cin>>p1.color;
        if(p1.color>0&&p1.color<5){
            ans=1;
        }
        else{
            printf("Invalid Choice\n");
        }
    }

    printf("Enter player2 name : ");
    cin>>p2.playername;
    cout<<"Hi "<<p2.playername<<" " ;
    ans=0;
    while(ans==0){
        printf("Choose your color\n");
        printf("1-Red\n2-Blue\n3-Pink\n4-Yellow\n");
        cin>>p2.color;
        if(p2.color==p1.color){
            printf("Already taken\n");
        }
        else if(p2.color>0&&p2.color<5){
            ans=1;
        }
        else{
            printf("Invalid Choice\n");
        }
    }
}

bool choosen(char a,int b){
    for(int i=0;i<=b;i++){
        if(a==arr[i]){
            return 1;
        }
    }
    return 0;
}

void p1turn(char x){
    if(x=='H' && p1.color==1){
        printf(BRED "-----" reset);
    }
    else if(x=='H' && p1.color==2){
        printf(BBLU "-----" reset);
    }
    else if(x=='H' && p1.color==3){
        printf(BMAG "-----" reset);
    }
    else if(x=='H' && p1.color==4){
        printf(BYEL "-----" reset);
    }
    else if(x=='V' && p1.color==1){
        printf(BRED "|     " reset);
    }
    else if(x=='V' && p1.color==2){
        printf(BBLU "|     " reset);
    }
    else if(x=='V' && p1.color==3){
        printf(BMAG "|     " reset);
    }
    else if(x=='V' && p1.color==4){
        printf(BYEL "|     " reset);
    }
}

void p2turn(char x){
    if(x=='H' && p2.color==1){
        printf(BRED "-----" reset);
    }
    else if(x=='H' && p2.color==2){
        printf(BBLU "-----" reset);
    }
    else if(x=='H' && p2.color==3){
        printf(BMAG "-----" reset);
    }
    else if(x=='H' && p2.color==4){
        printf(BYEL "-----" reset);
    }
    else if(x=='V' && p2.color==1){
        printf(BRED "|     " reset);
    }
    else if(x=='V' && p2.color==2){
        printf(BBLU "|     " reset);
    }
    else if(x=='V' && p2.color==3){
        printf(BMAG "|     " reset);
    }
    else if(x=='V' && p2.color==4){
        printf(BYEL "|     " reset);
    }
}

void printPlayer(int x){
    if(x%2==0 && p1.color==1){
        cout<<BRED<<p1.playername<<reset;
    }
    else if(x%2==0 && p1.color==2){
        cout<<BBLU<<p1.playername<<reset;
    }
    else if(x%2==0 && p1.color==3){
        cout<<BMAG<<p1.playername<<reset;
    }
    else if(x%2==0 && p1.color==4){
        cout<<BYEL<<p1.playername<<reset;
    }
    else if(x%2==1 && p2.color==1){
        cout<<BRED<<p2.playername<<reset;
    }
    else if(x%2==1 && p2.color==2){
        cout<<BBLU<<p2.playername<<reset;
    }
    else if(x%2==1 && p2.color==3){
        cout<<BMAG<<p2.playername<<reset;
    }
    else if(x%2==1 && p2.color==4){
        cout<<BYEL<<p2.playername<<reset;
    }
}

void print(int index,char x,int size,int turn){
        int count1=65,count2=96-size;
        arr[index]=x;
        for(int i=0;i<(4*size)+1;i++){
            if(i%4==0){
                for(int j=0;j<size;j++){
                    printf("•");
                    if(choosen(count1,index) && count1!=x){
                        printf(BGRN "-----" reset);
                    }
                    else if(choosen(count1,index) && count1==x){
                        if(turn%2==0){
                            p1turn('H');
                        }
                        else{
                            p2turn('H');
                        }
                    }
                    else{
                        printf("--%c--",count1);
                    }
                    if(j==size-1){
                        printf("•");
                    }
                    count1++;
                }
                printf("\n"); 
                count2+=size+1;
            }
            else{
                for(int j=0;j<size+1;j++){
                    if(choosen(count2,index) && count2!=x){
                        printf(BGRN "|     " reset);
                    }
                    else if(choosen(count2,index) && count2==x){
                        if(turn%2==0){
                            p1turn('V');
                        }
                        else{
                            p2turn('V');
                        }
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
                count2-=size+1;
                printf("\n");
            }
        }
        printf("\n");
}

bool valid(char x,int size){
    if(size==5){
        if((x>=65&&x<=94)||(x>=97&&x<=126)){
            return 1;
        }
        else{
            printf("Invalid Character\n");
            return 0;
        }
    }
    else{
        if((x>=65&&x<=70)||(x>=97&&x<=102)){
            return 1;
        }
        else{
            printf("Invalid Character\n");
            return 0;
        }
    }
}

bool repeated(char x,int b){
    for(int i=0;i<b;i++){
        if(arr[i]==x){
            printf("Already taken\n");
            return 1;
        }
    }
    return 0;
}

int main(){
    int index=0,turn=0;
    char x=0;
    int size=chooseLevel();
    enterPlayers();
    print(index,x,size,turn);
    while(index!=(size*(size+1))*2){
        printf("It's ");
        printPlayer(turn);
        printf(" turn\nEnter the letter of the line uou want to choose : \n");
        cin>>x;
        if(!valid(x,size) || repeated(x,index)){
            continue;
        }
        print(index,x,size,turn);
        index++;
        turn++;
    }
}
