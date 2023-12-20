#include<stdio.h>
#include<iostream>
#include<time.h>
#include"ANSI-color-codes.h"
using namespace std;

int NoMoves1=0,NoMoves2=0,upper,lower;
char usedChars[60]={0};
char turns[60]={0};
char boxes[30]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
char boxes2[30]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
typedef struct{
    string playername;
    int color;
    int score;
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

int choosemode(){
    int ans;
    printf("Choose Mode\n1-1 VS 1\n2-Player VS Computer\n");
    cin>>ans;
    if(ans==1 || ans==2){
        return ans;
    }
    else{
        printf("Invalid Choice\n");
        return choosemode();
    }
}

void enterplayers1(){
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

void enterplayers2(){
    printf("Enter your name : ");
    cin>>p1.playername;
    cout<<"Hi "<<p1.playername<<" ";
    int ans=0;
    while(ans==0){
        printf("Choose your color\n");
        printf("1-Red\n2-Blue\n3-Pink\n");
        cin>>p1.color;
        if(p1.color>0 && p1.color<4){
            ans=1;
        }
        else{
            printf("Invalid Choice\n");
        }
    }
    p2.playername="Computer";
    p2.color=4;
}

int choosen(char a,int b){
    for(int i=0;i<=b;i++){
        if(a==usedChars[i]){
            return turns[i];
        }
    }
    return 0;
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


char lastline=' ';
void whoIsLast(char c,int def,int size){
    if(choosen(c,60)){
        if(choosen(c+1,60)){
            if(choosen(c-def,60)){
                lastline=c-def+size;
            }
            else{
                lastline=c-def;
            }
        }
        else{
            lastline=c+1;
        }
    }
    else{
        lastline=c;
    }
}


void computerLogic(char c,int size,int turn){
    lastline=' ';
    int count=0;
    int i=c-97;
    int def=32+((c%97)/(size+1));
    if(c>=97 && c<=126 && c!=97+size &&c!=97+(2*size)+1 && c!=97+(3*size)+2 && c!=97+(4*size)+3 && c!=97+(5*size)+4){
        for(int j=0;j<60;j++){
            if(usedChars[j]==c){
                count++;
            }
            if(usedChars[j]==c+1){
                count++;
            }
            if(usedChars[j]==c-def){
                count++;
            }
            if(usedChars[j]==c-def+size){
                count++;
            }
        }
    }
        if(count==3){
        whoIsLast(c,def,size);
    }
}

void isBox1(char c,int size,int turn){
    lastline=' ';
    int count=0;
    int i=c-97;
    int def=32+((c%97)/(size+1));
    if(c>=97 && c<=126 && c!=97+size &&c!=97+(2*size)+1 && c!=97+(3*size)+2 && c!=97+(4*size)+3 && c!=97+(5*size)+4){
        for(int j=0;j<60;j++){
            if(usedChars[j]==c){
                count++;
            }
            if(usedChars[j]==c+1){
                count++;
            }
            if(usedChars[j]==c-def){
                count++;
            }
            if(usedChars[j]==c-def+size){
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
    for(int i=0;i<=b;i++){
        if(usedChars[i]==x){
            printf("Already taken\n");
            return 1;
        }
    }
    return 0;
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


void printHorizontel(int index,char x,int size,int turn){
    for(int j=0;j<size;j++){
                printf("*");
                if(choosen(upper,index)==1){
                    if(p1.color==1){
                        printf(BRED "-----" reset);
                    }
                    else if(p1.color==2){
                        printf(BBLU "-----" reset);
                    }
                    else if(p1.color==3){
                        printf(BMAG "-----" reset);
                    }
                    else if(p1.color==4){
                        printf(BYEL "-----" reset);
                    }
                }
                else if(choosen(upper,index)==2){
                    if(p2.color==1){
                        printf(BRED "-----" reset);
                    }
                    else if(p2.color==2){
                        printf(BBLU "-----" reset);
                    }
                    else if(p2.color==3){
                        printf(BMAG "-----" reset);
                    }
                    else if(p2.color==4){
                        printf(BYEL "-----" reset);
                    }
                }
                else{
                    printf("--%c--",upper);
                }
                if(j==size-1){
                    printf("*");
                }
                upper++;
            }
}

void printNumInBox(int index,int i,int q){
    if(choosen(lower,index)==1){
                    if(i%2!=0){
                        if(p1.color==1){
                            printf(BRED "|     " reset);
                        }
                        else if(p1.color==2){
                            printf(BBLU "|     " reset);
                        }
                        else if(p1.color==3){
                            printf(BMAG "|     " reset);
                        }
                        else if(p1.color==4){
                            printf(BYEL "|     " reset);
                        }
                    }
                    else{
                        if(boxes[q]==' '){
                            if(p1.color==1){
                                printf(BRED "|  " reset"%c  ",boxes[q]);
                            }
                            else if(p1.color==2){
                                printf(BBLU "|  " reset"%c  ",boxes[q]);
                            }
                            else if(p1.color==3){
                                printf(BMAG "|  " reset"%c  ",boxes[q]);
                            }
                            else if(p1.color==4){
                                printf(BYEL "|  " reset"%c  ",boxes[q]);
                            }
                        }
                        else if(boxes[q]=='1' && p1.color==1){
                            printf(BRED "|  " reset BRED"%c  " reset,boxes[q]);
                        }
                        else if(boxes[q]=='1' && p1.color==2){
                            printf(BBLU "|  " reset BBLU"%c  " reset,boxes[q]);
                        }
                        else if(boxes[q]=='1' && p1.color==3){
                            printf(BMAG "|  " reset BMAG"%c  " reset,boxes[q]);
                        }
                        else if(boxes[q]=='1' && p1.color==4){
                            printf(BYEL "|  " reset BYEL"%c  " reset,boxes[q]);
                        }
                        else if(boxes[q]=='2' && p2.color==1){
                            if(p1.color==1){
                                printf(BRED "|  " reset BRED"%c  " reset,boxes[q]);
                            }
                            else if(p1.color==2){
                                printf(BBLU "|  " reset BRED"%c  " reset,boxes[q]);
                            }
                            else if(p1.color==3){
                                printf(BMAG "|  " reset BRED"%c  " reset,boxes[q]);
                            }
                            else if(p1.color==4){
                                printf(BYEL "|  " reset BRED"%c  " reset,boxes[q]);
                            }
                        }
                        else if(boxes[q]=='2' && p2.color==2){
                            if(p1.color==1){
                                printf(BRED "|  " reset BBLU"%c  " reset,boxes[q]);
                            }
                            else if(p1.color==2){
                                printf(BBLU "|  " reset BBLU"%c  " reset,boxes[q]);
                            }
                            else if(p1.color==3){
                                printf(BMAG "|  " reset BBLU"%c  " reset,boxes[q]);
                            }
                            else if(p1.color==4){
                                printf(BYEL "|  " reset BBLU"%c  " reset,boxes[q]);
                            }
                        }
                        else if(boxes[q]=='2' && p2.color==3){
                            if(p1.color==1){
                                printf(BRED "|  " reset BMAG"%c  " reset,boxes[q]);
                            }
                            else if(p1.color==2){
                                printf(BBLU "|  " reset BMAG"%c  " reset,boxes[q]);
                            }
                            else if(p1.color==3){
                                printf(BMAG "|  " reset BMAG"%c  " reset,boxes[q]);
                            }
                            else if(p1.color==4){
                                printf(BYEL "|  " reset BMAG"%c  " reset,boxes[q]);
                            }
                        }
                        else if(boxes[q]=='2' && p2.color==4){
                            if(p1.color==1){
                                printf(BRED "|  " reset BYEL"%c  " reset,boxes[q]);
                            }
                            else if(p1.color==2){
                                printf(BBLU "|  " reset BYEL"%c  " reset,boxes[q]);
                            }
                            else if(p1.color==3){
                                printf(BMAG "|  " reset BYEL"%c  " reset,boxes[q]);
                            }
                            else if(p1.color==4){
                                printf(BYEL "|  " reset BYEL"%c  " reset,boxes[q]);
                            }
                        }
                    }
                }
                else if(choosen(lower,index)==2){
                    if(i%2!=0){
                        if(p2.color==1){
                            printf(BRED "|     " reset);
                        }
                        else if(p2.color==2){
                            printf(BBLU "|     " reset);
                        }
                        else if(p2.color==3){
                            printf(BMAG "|     " reset);
                        }
                        else if(p2.color==4){
                            printf(BYEL "|     " reset);
                        }
                    }
                    else{
                        if(boxes[q]==' '){
                            if(p2.color==1){
                                printf(BRED "|  " reset"%c  ",boxes[q]);
                            }
                            else if(p2.color==2){
                                printf(BBLU "|  " reset"%c  ",boxes[q]);
                            }
                            else if(p2.color==3){
                                printf(BMAG "|  " reset"%c  ",boxes[q]);
                            }
                            else if(p2.color==4){
                                printf(BYEL "|  " reset"%c  ",boxes[q]);
                            }
                        }
                        else if(boxes[q]=='2' && p2.color==1){
                            printf(BRED "|  " reset BRED"%c  " reset,boxes[q]);
                        }
                        else if(boxes[q]=='2' && p2.color==2){
                            printf(BBLU "|  " reset BBLU"%c  " reset,boxes[q]);
                        }
                        else if(boxes[q]=='2' && p2.color==3){
                            printf(BMAG "|  " reset BMAG"%c  " reset,boxes[q]);
                        }
                        else if(boxes[q]=='2' && p2.color==4){
                            printf(BYEL "|  " reset BYEL"%c  " reset,boxes[q]);
                        }
                        else if(boxes[q]=='1' && p1.color==1){
                            if(p2.color==1){
                                printf(BRED "|  " reset BRED"%c  " reset,boxes[q]);
                            }
                            else if(p2.color==2){
                                printf(BBLU "|  " reset BRED"%c  " reset,boxes[q]);
                            }
                            else if(p2.color==3){
                                printf(BMAG "|  " reset BRED"%c  " reset,boxes[q]);
                            }
                            else if(p2.color==4){
                                printf(BYEL "|  " reset BRED"%c  " reset,boxes[q]);
                            }
                        }
                        else if(boxes[q]=='1' && p1.color==2){
                            if(p2.color==1){
                                printf(BRED "|  " reset BBLU"%c  " reset,boxes[q]);
                            }
                            else if(p2.color==2){
                                printf(BBLU "|  " reset BBLU"%c  " reset,boxes[q]);
                            }
                            else if(p2.color==3){
                                printf(BMAG "|  " reset BBLU"%c  " reset,boxes[q]);
                            }
                            else if(p2.color==4){
                                printf(BYEL "|  " reset BBLU"%c  " reset,boxes[q]);
                            }
                        }
                        else if(boxes[q]=='1' && p1.color==3){
                            if(p2.color==1){
                                printf(BRED "|  " reset BMAG"%c  " reset,boxes[q]);
                            }
                            else if(p2.color==2){
                                printf(BBLU "|  " reset BMAG"%c  " reset,boxes[q]);
                            }
                            else if(p2.color==3){
                                printf(BMAG "|  " reset BMAG"%c  " reset,boxes[q]);
                            }
                            else if(p2.color==4){
                                printf(BYEL "|  " reset BMAG"%c  " reset,boxes[q]);
                            }
                        }
                        else if(boxes[q]=='1' && p1.color==4){
                            if(p2.color==1){
                                printf(BRED "|  " reset BYEL"%c  " reset,boxes[q]);
                            }
                            else if(p2.color==2){
                                printf(BBLU "|  " reset BYEL"%c  " reset,boxes[q]);
                            }
                            else if(p2.color==3){
                                printf(BMAG "|  " reset BYEL"%c  " reset,boxes[q]);
                            }
                            else if(p2.color==4){
                                printf(BYEL "|  " reset BYEL"%c  " reset,boxes[q]);
                            }
                        }
                    }
                }
}

void printVertical(int index,char x,int size,int turn,int i){
    int q;
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
                if(choosen(lower,index)!=0){
                    printNumInBox(index,i,q);
                } 
                else{
                    if(i%2!=0){
                    printf("|     ");
                    }
                    else{
                        printf("%c  %c  ",lower,boxes[q]);
                    }
                }
                lower++;
            }
}

void printGrid(int index,char x,int size,int turn){
    upper=65,lower=96-size;
    usedChars[index]=x;
    turns[index]=(turn%2)+1;
    for(int i=0;i<(4*size)+1;i++){
        if(i%4==0){
            printHorizontel(index,x,size,turn);
            printf("\n"); 
            lower+=size+1;
        }
        else{
            printVertical(index,x,size,turn,i);   
            lower-=size+1;
            printf("\n");
        }
    }
    printf("\n");
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
            cout<<BRED<<p1.playername<<reset<<" WON\n\n";
        }
        else if(p1.color==2){
            cout<<BBLU<<p1.playername<<reset<<" WON\n\n";
        }
        else if(p1.color==3){
            cout<<BMAG<<p1.playername<<reset<<" WON\n\n";
        }
        else if(p1.color==4){
            cout<<BYEL<<p1.playername<<reset<<" WON\n\n";
        }
    }
    else if(score1()<score2()){
        if(p2.color==1){
            cout<<BRED<<p2.playername<<reset<<" WON\n\n";
        }
        else if(p2.color==2){
            cout<<BBLU<<p2.playername<<reset<<" WON\n\n";
        }
        else if(p2.color==3){
            cout<<BMAG<<p2.playername<<reset<<" WON\n\n";
        }
        else if(p2.color==4){
            cout<<BYEL<<p2.playername<<reset<<" WON\n\n";
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

void printremaininglines(int size,int b){
    int total=(size*(size+1))*2;
    int counter=0;
    for(int i=0;i<b;i++){
        if(usedChars[i]!=0){
            counter++;
        }
    }
    cout<<"Remaining lines "<<BGRN<<total-counter<<reset<<"\n\n";
}

void printtime(struct timespec begin,struct timespec end){
    int sec=end.tv_sec-begin.tv_sec;
    int min=0;
    if(sec>59){
        min=sec/60;
        sec%=60;
    }
    cout<<"Time spent : ";
    cout<<BGRN<<"0"<<min;
    if(sec<10){
        cout<<" : 0"<<sec<<reset<<"\n\n";
    }
    else{
        cout<<" : "<<sec<<reset<<"\n\n";
    }

}

void mode1(int index,int size,struct timespec begin){
    struct timespec end;
    int turn=0;
    char x=0;
    enterplayers1();
    printGrid(index,x,size,turn);
    while(index!=(size*(size+1))*2){
        timespec_get(&end,TIME_UTC);
        printscores();
        printmoves();
        printremaininglines(size,index);
        printtime(begin,end);
        printf("It's ");
        printPlayer(turn);
        printf(" turn\nEnter the letter of the line you want to choose : \n");
        cin>>x;
        if(!valid(x,size) || repeated(x,index)){
            continue;
        }
        if(turn%2==0 ){
            NoMoves1++;
        }
        else{
            NoMoves2++;
        }
        printGrid(index,x,size,turn);
        index++; 
        if(!filled()){
            turn++;
        }
    }
}

void mode2(int index,int size,struct timespec begin){
    struct timespec end;
    int turn=0;
    char x=0;
    enterplayers2();
    printGrid(index,x,size,turn);
    while(index!=(size*(size+1))*2){
        if(turn%2==0){
            timespec_get(&end,TIME_UTC);
            printscores();
            printmoves();
            printremaininglines(size,index);
            printtime(begin,end);
            printf("It's ");
            printPlayer(turn);
            printf(" turn\nEnter the letter of the line you want to choose : \n");
            cin>>x;
            if(!valid(x,size) || repeated(x,index)){
                continue;
            }
                NoMoves1++;
            printGrid(index,x,size,turn);
            index++; 
        }
        else{
            x='0';
            for(int i=97;i<97+(size*(size+1));i++){
                if(!choosen(i,index)){
                    x=i;
                    break;
                }
            }   
            if(x=='0'){
                for(int i=65;i<65+(size*(size+1));i++){
                    if(!choosen(i,index)){
                        x=i;
                        break;
                    }
                }  
            }
            for(int i=97;i<97+(size*(size+1));i++){
                    computerLogic(i,size,turn);
                    if(lastline!=' '){
                        break;
                    }
            }
            if(lastline!=' '){
                x=lastline;
            }
            NoMoves2++;
            printGrid(index,x,size,turn);
            index++; 
        }
        if(!filled()){
            turn++;
        }
    }
}

int main(){
    struct timespec begin,end2;
    timespec_get(&begin,TIME_UTC);
    int index=0;
    int size=chooseLevel();
    int mode=choosemode();
    if(mode==1){
        mode1(index,size,begin);
    }
    else{
        mode2(index,size,begin);
    }
    timespec_get (&end2,TIME_UTC);
    printscores();
    printmoves();
    printremaininglines(size,(size*(size+1)*2));
    printtime(begin,end2);
    printwinner();
}
