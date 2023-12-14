#include<stdio.h>
#include<iostream>
#include"ANSI-color-codes.h"
using namespace std;

char arr[60]={0};
char boxes[30]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
char boxes2[30]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
typedef struct{
    string playername;
    int color;
}player;
player p1,p2;
int NoMoves1=0,NoMoves2=0;

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
        if(p1.color>0 && p1.color<5){
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

void p1TurnWithLetter(char x,int q){
    if(p1.color==1){
        printf(BRED "|  %c  " reset,boxes[q]);
    }
    else if(p1.color==2){
        printf(BBLU "|  %c  " reset ,boxes[q]);
    }
    else if(p1.color==3){
        printf(BMAG "|  %c  " reset ,boxes[q]);
    }
    else if(p1.color==4){
        printf(BYEL "|  %c  " reset ,boxes[q]);
    }
}

void p2TurnWithLetter(char x,int q){
    if(p2.color==1){
        printf(BRED "|  %c  " reset,boxes[q]);
    }
    else if(p2.color==2){
        printf(BBLU "|  %c  " reset,boxes[q]);
    }
    else if(p2.color==3){
        printf(BMAG "|  %c  " reset,boxes[q]);
    }
    else if(p2.color==4){
        printf(BYEL "|  %c  " reset,boxes[q]);
    }
}

void printPlayer(int x){
    if(x%2==0){
        NoMoves1++;
    }
    else{
        NoMoves2++;
    }

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

void isBox1(char c,int size,int turn){
    int count=0;
    int i=c-97;
    int def=32+((c%97)/(size+1));
    if(c>=97 && c<=126 && c!=97+size &&c!=97+(2*size)+1 && c!=97+(3*size)+2 && c!=97+(4*size)+3 && c!=97+(5*size)+4){
        for(int j=0;j<60;j++){
            if(arr[j]==c){
                count++;
            }
            if(arr[j]==c+1){
                count++;
            }
            if(arr[j]==c-def){
                count++;
            }
            if(arr[j]==c-def+size){
                count++;
            }
        }
    }
    if(count==4){
        if(turn%2==0){
        boxes[i]='1';
        }
        else{
            boxes[i]='2';
        }
    }
}

void isBox2(char c,int size,int turn){
    char a,b;
    a=32+((c%65)/size);
    isBox1(c+a,size,turn);
    b=(32-size)+((c%(65+size))/size);
    isBox1(c+b,size,turn);
    
}

void print(int index,char x,int size,int turn){
    int count1=65,count2=96-size,q;
    arr[index]=x;
    for(int i=0;i<(4*size)+1;i++){
        if(i%4==0){
            for(int j=0;j<size;j++){
                printf("*");
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
                    printf("*");
                }
                count1++;
            }
            printf("\n"); 
            count2+=size+1;
        }
        else{
            for(int j=0;j<size+1;j++){
                if(x>=97 && x<=126){
                    isBox1(x,size,turn);
                    if(x!='a'){
                    isBox1(x-1,size,turn);
                    }
                }
                else{
                    isBox2(x,size,turn);
                }
                q=(i/4)*(size+1)+j;
                if(choosen(count2,index) && count2!=x){
                    if(i%2!=0){
                        printf(BGRN "|     " reset);
                    }
                    else{
                        if(boxes[q]==' '){
                            printf(BGRN "|  " reset"%c  ",boxes[q]);
                        }
                        else if(boxes[q]=='1' && p1.color==1){
                            printf(BGRN "|  " reset BRED"%c  " reset,boxes[q]);
                        }
                        else if(boxes[q]=='1' && p1.color==2){
                            printf(BGRN "|  " reset BBLU"%c  " reset,boxes[q]);
                        }
                        else if(boxes[q]=='1' && p1.color==3){
                            printf(BGRN "|  " reset BMAG"%c  " reset,boxes[q]);
                        }
                        else if(boxes[q]=='1' && p1.color==1){
                            printf(BGRN "|  " reset BYEL"%c  " reset,boxes[q]);
                        }
                        else if(boxes[q]=='2' && p2.color==1){
                            printf(BGRN "|  " reset BRED"%c  " reset,boxes[q]);
                        }
                        else if(boxes[q]=='2' && p2.color==2){
                            printf(BGRN "|  " reset BBLU"%c  " reset,boxes[q]);
                        }
                        else if(boxes[q]=='2' && p2.color==3){
                            printf(BGRN "|  " reset BMAG"%c  " reset,boxes[q]);
                        }
                        else if(boxes[q]=='2' && p2.color==4){
                            printf(BGRN "|  " reset BYEL"%c  " reset,boxes[q]);
                        }
                    }
                }
                else if(choosen(count2,index) && count2==x){
                    if(turn%2==0){
                        if(i%2!=0){
                            p1turn('V');
                        }
                        else{
                            p1TurnWithLetter('V',q);
                        }
                    }
                    else{
                        if(i%2!=0){
                            p2turn('V');
                        }
                        else{
                            p2TurnWithLetter('V',q);
                        }
                    }
                }
                else{
                    if(i%2!=0){
                    printf("|     ");
                    }
                    else{
                        printf("%c  %c  ",count2,boxes[q]);
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

void finalPrint(int size){
    int count1=65,count2=96-size,q;
    for(int i=0;i<(4*size)+1;i++){
        if(i%4==0){
            for(int j=0;j<size;j++){
                printf("•");
                printf(BGRN "-----" reset);
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
                q=(i/4)*(size+1)+j;
                if(i%2==0){
                    if(boxes[q]==' '){
                        printf(BGRN "|  " reset"%c  ",boxes[q]);
                    }
                    else if(boxes[q]=='1' && p1.color==1){
                        printf(BGRN "|  " reset BRED"%c  " reset,boxes[q]);
                    }
                    else if(boxes[q]=='1' && p1.color==2){
                        printf(BGRN "|  " reset BBLU"%c  " reset,boxes[q]);
                    }
                    else if(boxes[q]=='1' && p1.color==3){
                        printf(BGRN "|  " reset BMAG"%c  " reset,boxes[q]);
                    }
                    else if(boxes[q]=='1' && p1.color==1){
                        printf(BGRN "|  " reset BYEL"%c  " reset,boxes[q]);
                    }
                    else if(boxes[q]=='2' && p2.color==1){
                        printf(BGRN "|  " reset BRED"%c  " reset,boxes[q]);
                    }
                    else if(boxes[q]=='2' && p2.color==2){
                        printf(BGRN "|  " reset BBLU"%c  " reset,boxes[q]);
                    }
                    else if(boxes[q]=='2' && p2.color==3){
                        printf(BGRN "|  " reset BMAG"%c  " reset,boxes[q]);
                    }
                    else if(boxes[q]=='2' && p2.color==4){
                        printf(BGRN "|  " reset BYEL"%c  " reset,boxes[q]);
                    }
                }
                else{
                    printf(BGRN "|     " reset);
                }
                count2++;
            }
            count2-=size+1;
            printf("\n");
        }
    }
    printf("\n");
}

bool filled(){
    for(int i=0;i<30;i++){
        if(boxes[i]!=boxes2[i]){
            for(int j=0;j<30;j++){
                boxes2[j]=boxes[j];
            }
            return 1;
        }
    }
    return 0;
}

int score1(){
    int counter1=0;
    for(int i=0;i<30;i++){
        if(boxes[i]=='1'){
            counter1++;
        }
    }
    return counter1;
}

int score2(){
    int counter2=0;
    for(int i=0;i<30;i++){
        if(boxes[i]=='2'){
            counter2++;
        }
    }
    return counter2;
}

void printscores(){
    printf("Current Score:\n     ");
    if(p1.color==1){
        printf(BRED "%i  " reset,score1());
    }
    else if(p1.color==2){
        printf(BBLU"%i  " reset,score1());
    }
    else if(p1.color==3){
        printf(BMAG"%i  " reset,score1());
    }
    else if(p1.color==4){
        printf(BYEL"%i  " reset,score1());
    }
    if(p2.color==1){
        printf(BRED"%i\n\n" reset,score2());
    }
    else if(p2.color==2){
        printf(BBLU"%i\n\n" reset,score2());
    }
    else if(p2.color==3){
        printf(BMAG"%i\n\n" reset,score2());
    }
    else if(p2.color==4){
        printf(BYEL"%i\n\n" reset,score2());
    }
}

void printwinner(){
    if(score1()>score2()){
        if(p1.color==1){
            cout<<BRED<<p1.playername<<reset<<" WON\n";
        }
        else if(p1.color==2){
            cout<<BBLU<<p1.playername<<reset<<" WON\n";
        }
        else if(p1.color==3){
            cout<<BMAG<<p1.playername<<reset<<" WON\n";
        }
        else if(p1.color==4){
            cout<<BYEL<<p1.playername<<reset<<" WON\n";
        }
    }
    else if(score1()<score2()){
        if(p2.color==1){
            cout<<BRED<<p2.playername<<reset<<" WON\n";
        }
        else if(p2.color==2){
            cout<<BBLU<<p2.playername<<reset<<" WON\n";
        }
        else if(p2.color==3){
            cout<<BMAG<<p2.playername<<reset<<" WON\n";
        }
        else if(p2.color==4){
            cout<<BYEL<<p2.playername<<reset<<" WON\n";
        }
    }
    else{
        printf("DRAW\n") ;
    }
}

void printmoves(){
    if(p1.color==1){
    cout<<BRED<<p1.playername<<reset<<" Moved "<<BRED<<NoMoves1<<reset<<" moves.\n";
    }
    else if(p1.color==2){
    cout<<BBLU<<p1.playername<<reset<<" Moved "<<BBLU<<NoMoves1<<reset<<" moves.\n";
    }
    else if(p1.color==3){
    cout<<BMAG<<p1.playername<<reset<<" Moved "<<BMAG<<NoMoves1<<reset<<" moves.\n";
    }
    else if(p1.color==4){
    cout<<BYEL<<p1.playername<<reset<<" Moved "<<BYEL<<NoMoves1<<reset<<" moves.\n";
    }
    if(p2.color==1){
    cout<<BRED<<p2.playername<<reset<<" Moved "<<BRED<<NoMoves2<<reset<<" moves.\n\n";
    }
    else if(p2.color==2){
    cout<<BBLU<<p2.playername<<reset<<" Moved "<<BBLU<<NoMoves2<<reset<<" moves.\n\n";
    }
    else if(p2.color==3){
    cout<<BMAG<<p2.playername<<reset<<" Moved "<<BMAG<<NoMoves2<<reset<<" moves.\n\n";
    }
    else if(p2.color==4){
    cout<<BYEL<<p2.playername<<reset<<" Moved "<<BYEL<<NoMoves2<<reset<<" moves.\n\n";
    }
}

int main(){
    int index=0,turn=0;
    char x=0;
    int size=chooseLevel();
    enterPlayers();
    print(index,x,size,turn);
    while(index!=(size*(size+1))*2){
        printscores();
        printmoves();
        printf("It's ");
        printPlayer(turn);
        printf(" turn\nEnter the letter of the line you want to choose : \n");
        getchar();
        scanf("%c",&x);
        if(!valid(x,size) || repeated(x,index)){
            continue;
        }
        print(index,x,size,turn);
        index++;
        if(!filled()){
            turn++;
        }
    }
    finalPrint(size);
    printscores();
    printwinner();
    printmoves();
}
