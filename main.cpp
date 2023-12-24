#include<stdio.h>
#include<iostream>
#include<time.h>
#include"ANSI-color-codes.h"
#include<vector>
#include<string.h>
using namespace std;

int index1,turn,NoMoves1,NoMoves2,upper,lower;
char usedChars[60];
char turns[60];
char boxes[30];
char boxes2[30];
typedef struct{
    char name[100];
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
    cin>>p1.name;
    cout<<"Hi "<<p1.name<<" ";
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
    cin>>p2.name;
    cout<<"Hi "<<p2.name<<" " ;
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
    cin>>p1.name;
    cout<<"Hi "<<p1.name<<" ";
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
    strcpy(p2.name,"Computer");
    p2.color=4;
}

int choosen(char a){
    for(int i=0;i<=60;i++){
        if(a==usedChars[i]){
            return turns[i];
        }
    }
    return 0;
}

void printPlayer(){
    if(turn==0 && p1.color==1){
        cout<<BRED<<p1.name<<reset;
    }
    else if(turn==0 && p1.color==2){
        cout<<BBLU<<p1.name<<reset;
    }
    else if(turn==0 && p1.color==3){
        cout<<BMAG<<p1.name<<reset;
    }
    else if(turn==0&& p1.color==4){
        cout<<BYEL<<p1.name<<reset;
    }
    else if(turn==1 && p2.color==1){
        cout<<BRED<<p2.name<<reset;
    }
    else if(turn==1 && p2.color==2){
        cout<<BBLU<<p2.name<<reset;
    }
    else if(turn==1 && p2.color==3){
        cout<<BMAG<<p2.name<<reset;
    }
    else if(turn==1 && p2.color==4){
        cout<<BYEL<<p2.name<<reset;
    }
}


char lastline=' ';
void whoIsLast(char c,int def,int size){
    if(choosen(c)){
        if(choosen(c+1)){
            if(choosen(c-def)){
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

void computerLogic(char c,int size){
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

int isBox1(char c,int size){
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
        if(turn==0){
        boxes[i]='1';
        return 1;
        }
        else{
            boxes[i]='2';
            return 2;
        }
    }
    else{
        // boxes[i]=' ';
        return 0;
    }

}

void isBox2(char c,int size){
    char a,b;
    a=32+((c%65)/size);
    isBox1(c+a,size);
    b=(32-size)+((c%(65+size))/size);
    isBox1(c+b,size);
    
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

bool repeated(char x){
    for(int i=0;i<=60;i++){
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

bool filled2(){
    for(int i=0;i<30;i++){
        if(boxes[i]!=boxes2[i]){
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


void printHorizontel(char x,int size){
    for(int j=0;j<size;j++){
                printf("*");
                if(choosen(upper)==1){
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
                else if(choosen(upper)==2){
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

void printNumInBox(int i,int q){
    if(choosen(lower)==1){
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
                else if(choosen(lower)==2){
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

void printVertical(char x,int size,int i){
    int q;
    for(int j=0;j<size+1;j++){
                if(x>=97 && x<=126){
                    isBox1(x,size);
                    if(x!='a'){
                    isBox1(x-1,size);
                    }
                }
                else{
                    isBox2(x,size);
                }
                q=(i/4)*(size+1)+j;
                if(choosen(lower)!=0){
                    printNumInBox(i,q);
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

void printGrid(char x,int size){
    upper=65,lower=96-size;
    usedChars[index1]=x;
    turns[index1]=(turn%2)+1;
    for(int i=0;i<(4*size)+1;i++){
        if(i%4==0){
            printHorizontel(x,size);
            printf("\n"); 
            lower+=size+1;
        }
        else{
            printVertical(x,size,i);   
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



int winner(int ans,char name[],int len){
    FILE *pF=fopen("winners.txt","r");
    vector <string> winners(0); 
    char buffer[255];
    while(fgets(buffer,255,pF)!=NULL){
        winners.push_back(buffer);
    }
    fclose(pF);
    int plyedMatches=winners.size();
    string sotedWinners[plyedMatches];
    int sortedWinners2[plyedMatches];
    for(int i=0;i<plyedMatches;i++){
        sortedWinners2[i]=0;
    }
    int index1=0;
    for(int i=0;i<winners.size();i++){
        string name=winners[i];
        sotedWinners[index1]=name;
        if(name=="0"){
            continue;
        }
        for(int j=i;j<winners.size();j++){
            if(winners[j]==name){
                sortedWinners2[index1]++;
                winners[j]="0";
            }
        }
        index1++;
        if(index1==plyedMatches){
            index1--;
            break;
        }
    }

    for(int i=0;i<plyedMatches;i++){
        for(int j=0;j<plyedMatches-1;j++){
            if(sortedWinners2[j]<sortedWinners2[j+1]){
                swap(sortedWinners2[j],sortedWinners2[j+1]);
                swap(sotedWinners[j],sotedWinners[j+1]);
            }
        }
    }

    int score,rank;
    for(int i=0;i<plyedMatches;i++){
        int flag=1;
        for (int j=0;j<len;j++){
            if(name[j]!=sotedWinners[i][j]){
                flag=0;
                break;
            }
        }
        if(flag==0){
            continue;
        }
        else{
            rank=i;
            score=sortedWinners2[i];
        }
    }
    if(ans==1){
        return score;
    }
    else{
        return rank;
    }

}

void printwinner(){
    if(score1()>score2()){
        if(p1.color==1){
            cout<<BRED<<p1.name<<reset<<" WON\n";
        }
        else if(p1.color==2){
            cout<<BBLU<<p1.name<<reset<<" WON\n";
        }
        else if(p1.color==3){
            cout<<BMAG<<p1.name<<reset<<" WON\n";
        }
        else if(p1.color==4){
            cout<<BYEL<<p1.name<<reset<<" WON\n";
        }
        FILE *pF=fopen("winners.txt","a");
        fprintf(pF,"\n");
        fputs(p1.name,pF);
        fprintf(pF,"\n\n");
        fclose(pF);
        printf("Your current score is %i\n",winner(1,p1.name,strlen(p1.name)));
        printf("Your current rank is %i\n",winner(2,p1.name,strlen(p1.name)));
    }
    else if(score1()<score2()){
        if(p2.color==1){
            cout<<BRED<<p2.name<<reset<<" WON\n";
        }
        else if(p2.color==2){
            cout<<BBLU<<p2.name<<reset<<" WON\n";
        }
        else if(p2.color==3){
            cout<<BMAG<<p2.name<<reset<<" WON\n";
        }
        else if(p2.color==4){
            cout<<BYEL<<p2.name<<reset<<" WON\n";
        }
        if(strcmp(p2.name,"Computer")!=0){
            FILE *pF=fopen("winners.txt","a");
            fprintf(pF,"\n");
            fputs(p2.name,pF);
            fprintf(pF,"\n\n");
            fclose(pF);
        printf("Your current score is %i\n",winner(1,p2.name,strlen(p2.name)));
        printf("Your current rank is %i\n",winner(2,p2.name,strlen(p2.name)));
        }
    }
    else{
        printf("DRAW\n") ;
    }
}

void printmoves(){
    if(p1.color==1){
    cout<<BRED<<p1.name<<reset<<" Moved "<<BRED<<NoMoves1<<reset<<" moves.\n";
    }
    else if(p1.color==2){
    cout<<BBLU<<p1.name<<reset<<" Moved "<<BBLU<<NoMoves1<<reset<<" moves.\n";
    }
    else if(p1.color==3){
    cout<<BMAG<<p1.name<<reset<<" Moved "<<BMAG<<NoMoves1<<reset<<" moves.\n";
    }
    else if(p1.color==4){
    cout<<BYEL<<p1.name<<reset<<" Moved "<<BYEL<<NoMoves1<<reset<<" moves.\n";
    }
    if(p2.color==1){
    cout<<BRED<<p2.name<<reset<<" Moved "<<BRED<<NoMoves2<<reset<<" moves.\n\n";
    }
    else if(p2.color==2){
    cout<<BBLU<<p2.name<<reset<<" Moved "<<BBLU<<NoMoves2<<reset<<" moves.\n\n";
    }
    else if(p2.color==3){
    cout<<BMAG<<p2.name<<reset<<" Moved "<<BMAG<<NoMoves2<<reset<<" moves.\n\n";
    }
    else if(p2.color==4){
    cout<<BYEL<<p2.name<<reset<<" Moved "<<BYEL<<NoMoves2<<reset<<" moves.\n\n";
    }
}

void printremaininglines(int size){
    int total=(size*(size+1))*2;
    int counter=0;
    for(int i=0;i<index1;i++){
        if(usedChars[i]!=0){
            counter++;
        }
    }
    cout<<"Remaining lines "<<BGRN<<total-counter<<reset<<"\n\n";
}



void mode1(int size){
    int move=0;
    int u1,u2;
    char x=0,ans;
    enterplayers1();
    printGrid(x,size);
    while(index1!=(size*(size+1))*2){
        printscores();
        printmoves();
        printremaininglines(size);
        printf("It's ");
        printPlayer();
        printf(" turn\nEnter the letter of the line you want to choose : \n");
        cin>>x;
        if(!valid(x,size) || repeated(x)){
            continue;
        }
        printGrid(x,size);
        if(turn==0){
            NoMoves1++;
        }
        else{
            NoMoves2++;
        }
        index1++; 
        if(!filled()){
            turn=(turn+1)%2;
        }
    }
}

void mode2(int size){
    char x=0;
    enterplayers2();
    printGrid(x,size);
    while(index1!=(size*(size+1))*2){
        if(turn==0){
            printscores();
            printmoves();
            printremaininglines(size);
            printf("It's ");
            printPlayer();
            printf(" turn\nEnter the letter of the line you want to choose : \n");
            cin>>x;
            if(!valid(x,size) || repeated(x)){
                continue;
            }
                NoMoves1++;
            printGrid(x,size);
            index1++; 
        }
        else{
            x='0';
            for(int i=97;i<97+(size*(size+1));i++){
                if(!choosen(i)){
                    x=i;
                    break;
                }
            }   
            if(x=='0'){
                for(int i=65;i<65+(size*(size+1));i++){
                    if(!choosen(i)){
                        x=i;
                        break;
                    }
                }  
            }
            for(int i=97;i<97+(size*(size+1));i++){
                    computerLogic(i,size);
                    if(lastline!=' '){
                        break;
                    }
            }
            if(lastline!=' '){
                x=lastline;
            }
            NoMoves2++;
            printGrid(x,size);
            index1++; 
        }
        if(!filled()){
            turn=(turn+1)%2;
        }
    }
}



void newGame(){
    for(int i=0;i<60;i++){
        usedChars[i]=turns[i]=0;
    }
    for(int i=0;i<30;i++){
        boxes[i]=boxes2[i]=' ';
    }
    index1=turn=NoMoves1=NoMoves2=0;
    int size=chooseLevel();
    int mode=choosemode();
    if(mode==1){
        mode1(size);
    }
    else{
        mode2(size);
    }
    printscores();
    printmoves();
    printremaininglines(size);
    printwinner();
}

void topTen(){
    FILE *pF=fopen("winners.txt","r");
    vector <string> winners(0); 
    char buffer[255];
    while(fgets(buffer,255,pF)!=NULL){
        winners.push_back(buffer);
    }
    fclose(pF);
    int plyedMatches=winners.size();
    string sotedWinners[plyedMatches];
    int sortedWinners2[plyedMatches];
    for(int i=0;i<plyedMatches;i++){
        sortedWinners2[i]=0;
    }
    int index1=0;
    for(int i=0;i<winners.size();i++){
        string name=winners[i];
        sotedWinners[index1]=name;
        if(name=="0"){
            continue;
        }
        for(int j=i;j<winners.size();j++){
            if(winners[j]==name){
                sortedWinners2[index1]++;
                winners[j]="0";
            }
        }
        index1++;
        if(index1==plyedMatches){
            index1--;
            break;
        }
    }

    for(int i=0;i<plyedMatches;i++){
        for(int j=0;j<plyedMatches-1;j++){
            if(sortedWinners2[j]<sortedWinners2[j+1]){
                swap(sortedWinners2[j],sortedWinners2[j+1]);
                swap(sotedWinners[j],sotedWinners[j+1]);
            }
        }
    }

    string topPlayers[11];
    if(index1>11){
        for(int i=0;i<11;i++){
            topPlayers[i]=sotedWinners[i];
        }
        for(int i=1;i<11;i++){
            cout<<i<<"- "<<topPlayers[i];
        }
    }
    else{
        for(int i=0;i<index1;i++){
            topPlayers[i]=sotedWinners[i];
        }
        for(int i=1;i<index1;i++){
            cout<<i<<"- "<<topPlayers[i];
        }
    }
}





void userManual(){
    printf("Welcome to Dots&Boxes game\n\n");
    printf("-The game consists of a grid of some boxes devided into lines.\n-Each player in his turn select one line\n");
    printf("-The target is to close a box\n-The player who close a box his score increases by one and he have another turn\n");
    printf("-The game ends when all lines are selected\n");
}

void menu(){
    char ans;
    printf("\nPress\n1-New Game\n2-Load Game\n3-Top Players\n4-User Manual\n5-Exit\n");
    cin>>ans;
    if(ans=='1'){
        newGame();
    }
    else if(ans=='2'){
        
    }
    else if(ans=='3'){
        topTen();
    }
    else if(ans=='4'){
        userManual();
    }
    else if(ans=='5'){
        return;
    }
    else{
        printf("Invalid Choice\n");
        menu();
    }
    menu();
}

int main(){
    printf("== Welcome to Dots&Boxes game ==\n");
    menu();
}
