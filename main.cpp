#include<stdio.h>
#include<iostream>
#include<time.h>
#include"ANSI-color-codes.h"
#include<vector>
#include<string.h>
#include<unistd.h>
using namespace std;

int index1,turn,NoMoves1=0,NoMoves2=0,upper,lower,size2,mod2,moves=-1;
char usedChars[60];
int turns[60];
char boxes[30],boxes2[30];
int undoarr[25][3][60]={0};
int redoarr[25]={0};
typedef struct{
    char name[100];
    int color;
    int score=0;
}player;
player p1,p2;

int chooseLevel(){
    char ans;
    printf("Choose your level\n1-Biginer\n2-Expert\n");
    cin>>ans;
    if(ans=='1'){
        size2=2;
        return 2;
    }
    else if(ans=='2'){
        size2=5;
        return 5;
    }
    else{
        printf("Invalid Choice\n");
        return chooseLevel();
    }
}

int choosemode(){
    char ans;
    printf("Choose Mode\n1-1 VS 1\n2-Player VS Computer\n");
    cin>>ans;
    if(ans=='1'){
        mod2=1;
        return 1;
    }
    else if(ans=='2'){
        mod2=2;
        return 2;
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
    char c1,c2;
    while(ans==0){
        printf("Choose your color\n");
        printf("1-Red\n2-Blue\n3-Pink\n4-Yellow\n");
        cin>>c1;
        if(c1=='1' || c1=='2' || c1=='3'|| c1=='4'){
            ans=1;
            p1.color=c1-'0';
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
        cin>>c2;
        if(c1==c2){
            printf("Already taken\n");
        }
        else if(c2=='1' || c2=='2' || c2=='3'|| c2=='4'){
            ans=1;
            p2.color=c2-'0';
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
    char c1;
    while(ans==0){
        printf("Choose your color\n");
        printf("1-Red\n2-Blue\n3-Pink\n");
        cin>>c1;
        if(c1=='1' || c1=='2' || c1=='3'){
            ans=1;
            p1.color=c1-'0';
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

void score1(){
    int counter1=0;
    for(int i=0;i<30;i++){
        if(boxes[i]=='1'){
            counter1++;
        }
    }
    p1.score=counter1;
}

void score2(){
    int counter2=0;
    for(int i=0;i<30;i++){
        if(boxes[i]=='2'){
            counter2++;
        }
    }
    p2.score=counter2;
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
    if(x!=0){
        turns[index1]=(turn%2)+1;
    }
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
    score1();
    score2();
    printf("Current Score:\n     ");
    if(p1.color==1){
        printf(BRED "%i  " reset,p1.score);
    }
    else if(p1.color==2){
        printf(BBLU"%i  " reset,p1.score);
    }
    else if(p1.color==3){
        printf(BMAG"%i  " reset,p1.score);
    }
    else if(p1.color==4){
        printf(BYEL"%i  " reset,p1.score);
    }
    if(p2.color==1){
        printf(BRED"%i\n\n" reset,p2.score);
    }
    else if(p2.color==2){
        printf(BBLU"%i\n\n" reset,p2.score);
    }
    else if(p2.color==3){
        printf(BMAG"%i\n\n" reset,p2.score);
    }
    else if(p2.color==4){
        printf(BYEL"%i\n\n" reset,p2.score);
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
    string sortedwinners[plyedMatches];
    int sortedWinners2[plyedMatches];
    for(int i=0;i<plyedMatches;i++){
        sortedWinners2[i]=0;
    }
    int index1=0;
    for(int i=0;i<winners.size();i++){
        string name=winners[i];
        sortedwinners[index1]=name;
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
                swap(sortedwinners[j],sortedwinners[j+1]);
            }
        }
    }

    int score,rank;
    for(int i=0;i<plyedMatches;i++){
        int flag=1;
        for (int j=0;j<len;j++){
            if(name[j]!=sortedwinners[i][j]){
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
    score1();
    score2();
    if(p1.score>p2.score){
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
    else if(p1.score<p2.score){
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

void calculateMoves(){
    int count1=0,count2=0;
    for(int i=0;i<60;i++){
        if(turns[i]==1){
            count1++;
        }
        else if(turns[i]==2){
            count2++;
        }
    }
    NoMoves1=count1;
    NoMoves2=count2;
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

void save(){
    printf("Enter Name\n");
    char savingfile2[255];
    char savingfile[255];
    scanf("%s",&savingfile2);
    strcpy(savingfile,savingfile2);
    strcat(savingfile,".txt");
    char *ptf=savingfile;
    if(access(ptf,F_OK)==-1){
    FILE *opF=fopen(savingfile,"w");
    fclose(opF);
    FILE *pF=fopen(savingfile,"a");
    fprintf(pF ,"%s\n",p1.name);
    fprintf(pF ,"%d\n",p1.color);
    fprintf(pF ,"%d\n",p1.score);
    fprintf(pF ,"%s\n",p2.name);
    fprintf(pF ,"%d\n",p2.color);
    fprintf(pF ,"%d\n",p2.score);
    fprintf(pF ,"%d\n",index1);
    fprintf(pF ,"%d\n",turn);
    fprintf(pF ,"%d\n",size2);
    fprintf(pF ,"%d\n",mod2);
    for(int i=0;i<60;i++){
        fprintf(pF ,"%c\n",usedChars[i]);
    }
        fprintf(pF ,"%c",'\n');
    for(int i=0;i<60;i++){
        fprintf(pF ,"%i\n",turns[i]);
    }
        fprintf(pF ,"%c",'\n');
    for(int i=0;i<30;i++){
        fprintf(pF ,"%c\n",boxes[i]);
    }
        fprintf(pF ,"%c",'\n');
    for(int i=0;i<30;i++){
        fprintf(pF ,"%c\n",boxes2[i]);
    }
    fclose(pF);
    FILE *sF=fopen("savedGames.txt","a");
    fprintf(pF ,"\n%s",savingfile2);
    fclose(sF);
    }
    else{
        printf("already taken\n");
        save();
    }
}

int maxredo=0;
void undo(int size);
void redo(int size){
    turn++;

    printGrid(char(redoarr[moves+1]),size);
    index1++;
    moves++;
    if(moves==maxredo){
        char ans;
        char ans2=0;
        while(ans2==0){
            cout<<"Press\n1-undo\n2-continue\n";
            cin>>ans;
            if(ans=='1'){
                ans2=1;
                undo(size);
            }
            else if(ans=='2'){
                ans2=1;
                return;
            }
            else{
                printf("Invalid Choice\n");
            }
        }
    }
    else{
        char ans;
        char ans2=0;
        while(ans2==0){
            cout<<"Press\n1-undo\n2-redo\n3-continue\n";
            cin>>ans;
            if(ans=='1'){
                ans2=1;
                undo(size);
            }
            else if(ans=='2'){
                ans2=1;
                filled();
                turn--;
                redo(size);
            }
            else if(ans=='3'){
                ans2=1;
                return;
            }
            else{
                printf("Invalid Choice\n");
            }
        }
    }
}

void undo(int size){
    turn--;
    index1--;
    redoarr[moves]=usedChars[index1];
    for(int j=0;j<3;j++){
        if(j==0){
            for(int k=0;k<60;k++){
                usedChars[k]=undoarr[moves][j][k];
            }
        }
        else if(j==1){
            for(int k=0;k<60;k++){
                turns[k]=undoarr[moves][j][k];
            }
        }
        else{
            for(int k=0;k<30;k++){
                boxes[k]=undoarr[moves][j][k];
                boxes2[k]=boxes[k];
            }
        }
    }
    printGrid(0,size);
    moves--;
    if(moves>-1){
        char ans;
        char ans2=0;
        while(ans2==0){
            cout<<"Press\n1-undo\n2-redo\n3-continue\n";
            cin>>ans;
            if(ans=='1'){
                ans2=1;
                turn++;
                undo(size);
            }
            else if(ans=='2'){
                ans2=1;
                redo(size);
            }
            else if(ans=='3'){
                ans2=1;
                return;
            }
            else{
                printf("Invalid Choice\n");
            }
        }
    }
    else{
        char ans;
        char ans2=0;
        while(ans2==0){
            cout<<"Press\n1-redo\n2-continue\n";
            cin>>ans;
            if(ans=='1'){
                ans2=1;
                redo(size);
            }
            else if(ans=='2'){
                ans2=1;
                return;
            }
            else{
                printf("Invalid Choice\n");
            }
        }
    }

}

void first(){
            for(int j=0;j<3;j++){
                if(j==0){
                    for(int k=0;k<60;k++){
                        undoarr[0][j][k]=usedChars[k];
                    }
                }
                else if(j==1){
                    for(int k=0;k<60;k++){
                        undoarr[0][j][k]=turns[k];
                    }
                }
                else{
                    for(int k=0;k<30;k++){
                        undoarr[0][j][k]=boxes[k];
                        boxes2[k]=boxes[k];
                    }
                }
            }
}


char lastline2=' ';
void whoIsLast2_1(char c,int size){
        int def=32+((c%97)/(size+1));
        if(!choosen(c+1)){
            lastline2=c+1;
        }
        else if(!choosen(c-def)){
                lastline2=c-def;
            }
        else if(!choosen(c-def+size)){
                lastline2=c-def+size;
            }
}
void whoIsLast2_2(char c,int size){
        int def=32+((c%97)/(size+1));
        if(!choosen(c-1)){
            lastline2=c-1;
        }
        else if(!choosen(c-def-1)){
                lastline2=c-def-1;
            }
        else if(!choosen(c-def+size-1)){
                lastline2=c-def+size-1;
            }
}

void whoIsLast2_3(char c,int size){
    int def=32+(c%65)/size;
        if(!choosen(c+size)){
            lastline2=c+size;
        }
        else if(!choosen(c+def)){
                lastline2=c+def;
            }
        else if(!choosen(c+def+1)){
                lastline2=c+def+1;
            }
}

void whoIsLast2_4(char c,int size){
    int def=32+(c%65)/size;
        if(!choosen(c-size)){
            lastline2=c-size;
        }
        else if(!choosen(c-size-1+def)){
                lastline2=c-size-1+def;
            }
        else if(!choosen(c-size+def)){
                lastline2=c-size+def;
            }
}

vector<char> dfss(0);

void printDFS(int size){
    int S=dfss.size();
    for(int i=0;i<S;i++){
        if(choosen(dfss[S-1-i])){
            continue;
        }
        printGrid(dfss[S-1-i],size);
        filled();
        index1++;
    }
}
void emptydfss(){
    int S=dfss.size();
    for(int i=0;i<S;i++){
        dfss.pop_back();
    }
}

void dfs2(char c,int size);
void dfs3(char c,int size);
void dfs4(char c,int size);

void dfs1(char c,int size){
    if(c==97+size ||c==97+(2*size)+1 || c==97+(3*size)+2 || c==97+(4*size)+3 || c==97+(5*size)+4){
        return;
    }
    int count=0;
    int def=32+((c%97)/(size+1));
    int flag=1;
    if(c!=97+size &&c!=97+(2*size)+1 && c!=97+(3*size)+2 && c!=97+(4*size)+3 && c!=97+(5*size)+4){
        for(int j=0;j<60;j++){
            if(dfss.size()>0){
                if(dfss[dfss.size()-1]==c && flag==1){
                    count++;
                    flag=0;
                }
            }
            else{
                lastline2=c;
                dfss.push_back(c);
                if(usedChars[j]==c){
                    count++;
                }
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
        whoIsLast2_1(lastline2,size);
        dfss.push_back(lastline2);
        if(lastline2>=97 && lastline2<=126){
            dfs1(lastline2,size);
        }
        else{
            if(lastline2==c-def+size){
                dfs3(lastline2,size);
            }
            else{            
                dfs4(lastline2,size);
            }
        }
    }
    if(count==4){
        printDFS(size);
        return;
    }
} 


void dfs2(char c,int size){
    if(c==97 ||c==97+(1*size)+1 || c==97+(2*size)+2 || c==97+(3*size)+3 || c==97+(4*size)+4){
        return;
    }
    int count=0;
    int def=32+((c%97)/(size+1));
    int flag=1;
    if(c!=97 &&c!=97+(1*size)+1 && c!=97+(2*size)+2 && c!=97+(3*size)+3 && c!=97+(4*size)+4){
        for(int j=0;j<60;j++){
            if(dfss.size()>0){
                if(dfss[dfss.size()-1]==c && flag==1){
                    count++;
                    flag=0;
                }
            }
            else{
                lastline2=c;
                dfss.push_back(c);
                if(usedChars[j]==c){
                    count++;
                }
            }
            if(usedChars[j]==c-1){
                count++;
            }
            if(usedChars[j]==c-def-1){
                count++;
            }
            if(usedChars[j]==c-def+size-1){
                count++;
            }
        }
    }
    if(count==3){
        whoIsLast2_2(lastline2,size);
        dfss.push_back(lastline2);
        if(lastline2>=97 && lastline2<=126){
            dfs2(lastline2,size);
        }
        else{
            if(lastline2==c-def+size-1){
                dfs3(lastline2,size);
            }
            else{            
                dfs4(lastline2,size);
            }
        }
    }
    if(count==4){
        printDFS(size);
        return;
    }
} 


void dfs3(char c,int size){
    int def2;
    if(size==2){
        def2=1;
    }
    else{
        def2=0;
    }
    if(c==65+(size*size)-def2  ||c==65+(size*size)-def2+1  || c==65+(size*size)-def2+2 || c==65+(size*size)-def2+3 || c==65+(size*size)-def2+4){
        return;
    }
    int count=0;
    int flag=1;
    int def=32+(c%65)/size;
    if(c!=65+(size*size)-def2 &&c!=65+(size*size)-def2+1 && c!=65+(size*size)-def2+2&& c!=65+(size*size)-def2+3&& c!=65+(size*size)-def2+4){
        for(int j=0;j<60;j++){
            if(dfss.size()>0){
                if(dfss[dfss.size()-1]==c && flag==1){
                    count++;
                    flag=0;
                }
            }
            else{
                lastline2=c;
                dfss.push_back(c);
                if(usedChars[j]==c){
                    count++;
                }
            }
            if(usedChars[j]==c+size){
                count++;
            }
            if(usedChars[j]==c+def){
                count++;
            }
            if(usedChars[j]==c+def+1){
                count++;
            }
        }
    }
    if(count==3){
        whoIsLast2_3(lastline2,size);
        dfss.push_back(lastline2);
        if(lastline2>=97 && lastline2<=126){
            if(lastline2==c+def+1){
                dfs1(lastline2,size);
            }
            else{
                dfs2(lastline2,size);
            }
        }
        else{
            dfs3(lastline2,size);
        }
    }
    if(count==4){
        printDFS(size);
        return;
    }
}


void dfs4(char c,int size){
    if(size==2){
        if(c==65 ||c==66){
            return;
        }
    }
    else{
        if(c==65 ||c==66||c==67||c==68||c==69){
            return;
        }
    }
    int count=0;
    int def=32+(c%65)/size;
    int flag=1;
    if(size==5){
        if(c!=65 && c!=66 && c!=67 && c!=68 && c!=69){
            for(int j=0;j<60;j++){
                if(dfss.size()>0){
                    if(dfss[dfss.size()-1]==c && flag==1){
                        count++;
                        flag=0;
                    }
                }
                else{
                    lastline2=c;
                    dfss.push_back(c);
                    if(usedChars[j]==c){
                        count++;
                    }
                }
                if(usedChars[j]==c-size){
                    count++;
                }
                if(usedChars[j]==c-size-1+def){
                    count++;
                }
                if(usedChars[j]==c-size+def){
                    count++;
                }
            }
        }
    }
    else{
        if(c!=65 && c!=66){
            for(int j=0;j<60;j++){
                if(dfss.size()>0){
                    if(dfss[dfss.size()-1]==c && flag==1){
                        count++;
                        flag=0;
                    }
                }
                else{
                    lastline2=c;
                    dfss.push_back(c);
                    if(usedChars[j]==c){
                        count++;
                    }
                }
                if(usedChars[j]==c-size){
                    count++;
                }
                if(usedChars[j]==c-size-1+def){
                    count++;
                }
                if(usedChars[j]==c-size+def){
                    count++;
                }
            }
        }
    }
    if(count==3){
        whoIsLast2_4(lastline2,size);
        dfss.push_back(lastline2);
        if(lastline2>=97 && lastline2<=126){
            if(lastline2==c-size+def){
                dfs1(lastline2,size);
            }
            else{
                dfs2(lastline2,size);
            }
        }
        else{
            dfs4(lastline2,size);
        }
    }
    if(count==4){
        printDFS(size);
        return;
    }
} 



int continueGame1(int size){
    char x=0,ans;
    printGrid(x,size);
    while(index1!=(size*(size+1))*2){
        moves++;
        printscores();
        calculateMoves();
        printmoves();
        printremaininglines(size);
        printf("It's ");
        printPlayer();
        printf(" turn\nEnter the letter of the line you want to choose : \n");
        cin>>x;
        if(!valid(x,size) || repeated(x)){
            moves=-1;
            continue;
        }
        printGrid(x,size);
        if(index1+1!=(size*(size+1))*2){
            char ans;
            char ans2=0;
            while(ans2==0){
                cout<<"Press\n1-undo\n2-continue\n3-save&quit\n";
                cin>>ans;
                if(ans=='1'){
                    ans2=1;
                    index1++;
                    undo(size);
                    index1--;
                }
                else if(ans=='2'){
                    ans2=1;
                }
                else if(ans=='3'){
                    ans2=1;
                    save();
                    return 0;
                }
                else{
                    printf("Invalid Choice\n");
                }
            }
        }
        for(int j=0;j<3;j++){
            if(j==0){
                for(int k=0;k<60;k++){
                    undoarr[moves+1][j][k]=usedChars[k];
                }
            }
            else if(j==1){
                for(int k=0;k<60;k++){
                    undoarr[moves+1][j][k]=turns[k];
                }
            }
            else{
                for(int k=0;k<30;k++){
                    undoarr[moves+1][j][k]=boxes[k];
                }
            }
        }
        index1++; 
        if(!filled()){
            maxredo=0;
            turn=(turn+1)%2;
            moves--;
            for(int i=0;i<25;i++){
                redoarr[i]=0;
            }
            for(int i=0;i<25;i++){
                for(int j=0;j<3;j++){
                    for(int k=0;k<60;k++){
                        undoarr[i][j][k]=0;
                    }
                }
            }
            for(int j=0;j<3;j++){
                if(j==0){
                    for(int k=0;k<60;k++){
                        undoarr[0][j][k]=usedChars[k];
                    }
                }
                else if(j==1){
                    for(int k=0;k<60;k++){
                        undoarr[0][j][k]=turns[k];
                    }
                }
                else{
                    for(int k=0;k<30;k++){
                        undoarr[0][j][k]=boxes[k];
                    }
                }
            }
        }
        else{
            maxredo++;
            for(int j=0;j<3;j++){
                if(j==0){
                    for(int k=0;k<60;k++){
                        undoarr[moves+1][j][k]=usedChars[k];
                    }
                }
                else if(j==1){
                    for(int k=0;k<60;k++){
                        undoarr[moves+1][j][k]=turns[k];
                    }
                }
                else{
                    for(int k=0;k<30;k++){
                        undoarr[moves+1][j][k]=boxes[k];
                    }
                }
            }
            emptydfss();
            if(x>=97&&x<=126){
                dfs1(x,size);
                emptydfss();
                dfs2(x,size);
            }
            else{
                dfs3(x,size);
                emptydfss();
                dfs4(x,size);
            }
        }
    }
    return 1;
}

int continueGame2(int size){
    char x=0;
    while(index1!=(size*(size+1))*2){
        if(turn==0){
            moves++;
            printscores();
            calculateMoves();
            printmoves();
            printremaininglines(size);
            printf("It's ");
            printPlayer();
            printf(" turn\nEnter the letter of the line you want to choose : \n");
            cin>>x;
            if(!valid(x,size) || repeated(x)){
                moves--;
                continue;
            }
            printGrid(x,size);
            if(index1+1!=(size*(size+1))*2){
                char ans;
                char ans2=0;
                while(ans2==0){
                    cout<<"Press\n1-undo\n2-continue\n3-save&quit\n";
                    cin>>ans;
                    if(ans=='1'){
                        ans2=1;
                        index1++;
                        undo(size);
                        index1--;
                    }
                    else if(ans=='2'){
                        ans2=1;
                    }
                    else if(ans=='3'){
                        ans2=1;
                        save();
                        return 0;
                    }
                    else{
                        printf("Invalid Choice\n");
                    }
                }
            }
            for(int j=0;j<3;j++){
                if(j==0){
                    for(int k=0;k<60;k++){
                        undoarr[moves+1][j][k]=usedChars[k];
                    }
                }
                else if(j==1){
                    for(int k=0;k<60;k++){
                        undoarr[moves+1][j][k]=turns[k];
                    }
                }
                else{
                    for(int k=0;k<30;k++){
                        undoarr[moves+1][j][k]=boxes[k];
                    }
                }
            }
            index1++; 
            if(!filled()){
                turn=(turn+1)%2;
                moves=-1;
                for(int i=0;i<25;i++){
                    redoarr[i]=0;
                }
                for(int i=0;i<25;i++){
                    for(int j=0;j<3;j++){
                        for(int k=0;k<60;k++){
                            undoarr[i][j][k]=0;
                        }
                    }
                }
                for(int j=0;j<3;j++){
                    if(j==0){
                        for(int k=0;k<60;k++){
                            undoarr[0][j][k]=usedChars[k];
                        }
                    }
                    else if(j==1){
                        for(int k=0;k<60;k++){
                            undoarr[0][j][k]=turns[k];
                        }
                    }
                    else{
                        for(int k=0;k<30;k++){
                            undoarr[0][j][k]=boxes[k];
                        }
                    }
                }
            }
            else{
                for(int j=0;j<3;j++){
                    if(j==0){
                        for(int k=0;k<60;k++){
                            undoarr[moves+1][j][k]=usedChars[k];
                        }
                    }
                    else if(j==1){
                        for(int k=0;k<60;k++){
                            undoarr[moves+1][j][k]=turns[k];
                        }
                    }
                    else{
                        for(int k=0;k<30;k++){
                            undoarr[moves+1][j][k]=boxes[k];
                        }
                    }
                }
                emptydfss();
                if(x>=97&&x<=126){
                    dfs1(x,size);
                    emptydfss();
                    dfs2(x,size);
                }
                else{
                    dfs3(x,size);
                    emptydfss();
                    dfs4(x,size);
                }
            }
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
            printGrid(x,size);
            index1++; 
            if(!filled()){
                maxredo=0;
                turn=(turn+1)%2;
                moves=-1;
                for(int i=0;i<25;i++){
                    redoarr[i]=0;
                }
                for(int i=0;i<25;i++){
                    for(int j=0;j<3;j++){
                        for(int k=0;k<60;k++){
                            undoarr[i][j][k]=0;
                        }
                    }
                }
                for(int j=0;j<3;j++){
                    if(j==0){
                        for(int k=0;k<60;k++){
                            undoarr[0][j][k]=usedChars[k];
                        }
                    }
                    else if(j==1){
                        for(int k=0;k<60;k++){
                            undoarr[0][j][k]=turns[k];
                        }
                    }
                    else{
                        for(int k=0;k<30;k++){
                            undoarr[0][j][k]=boxes[k];
                        }
                    }
                }
            }
            else{
                maxredo++;
                for(int j=0;j<3;j++){
                    if(j==0){
                        for(int k=0;k<60;k++){
                            undoarr[moves+1][j][k]=usedChars[k];
                        }
                    }
                    else if(j==1){
                        for(int k=0;k<60;k++){
                            undoarr[moves+1][j][k]=turns[k];
                        }
                    }
                    else{
                        for(int k=0;k<30;k++){
                            undoarr[moves+1][j][k]=boxes[k];
                        }
                    }
                }
            }
        }
    }
        return 1 ;
}
void menu();
int mode1(int size){
    char x=0,ans;
    enterplayers1();
    printGrid(x,size);
    while(index1!=(size*(size+1))*2){
        moves++;
        printscores();
        calculateMoves();
        printmoves();
        printremaininglines(size);
        printf("It's ");
        printPlayer();
        printf(" turn\nEnter the letter of the line you want to choose : \n");
        cin>>x;
        if(!valid(x,size) || repeated(x)){
            moves--;
            continue;
        }
        printGrid(x,size);
        if(index1+1!=(size*(size+1))*2){
            char ans;
            char ans2=0;
            while(ans2==0){
                cout<<"Press\n1-undo\n2-continue\n3-save&quit\n";
                cin>>ans;
                if(ans=='1'){
                    ans2=1;
                    index1++;
                    undo(size);
                    index1--;
                }
                else if(ans=='2'){
                    ans2=1;
                }
                else if(ans=='3'){
                    ans2=1;
                    save();
                    return 0;
                }
                else{
                    printf("Invalid Choice\n");
                }
            }
        }
        for(int j=0;j<3;j++){
            if(j==0){
                for(int k=0;k<60;k++){
                    undoarr[moves+1][j][k]=usedChars[k];
                }
            }
            else if(j==1){
                for(int k=0;k<60;k++){
                    undoarr[moves+1][j][k]=turns[k];
                }
            }
            else{
                for(int k=0;k<30;k++){
                    undoarr[moves+1][j][k]=boxes[k];
                }
            }
        }
        index1++; 
        if(!filled()){
            maxredo=0;
            turn=(turn+1)%2;
            moves=-1;
            for(int i=0;i<25;i++){
                redoarr[i]=0;
            }
            for(int i=0;i<25;i++){
                for(int j=0;j<3;j++){
                    for(int k=0;k<60;k++){
                        undoarr[i][j][k]=0;
                    }
                }
            }
            for(int j=0;j<3;j++){
                if(j==0){
                    for(int k=0;k<60;k++){
                        undoarr[0][j][k]=usedChars[k];
                    }
                }
                else if(j==1){
                    for(int k=0;k<60;k++){
                        undoarr[0][j][k]=turns[k];
                    }
                }
                else{
                    for(int k=0;k<30;k++){
                        undoarr[0][j][k]=boxes[k];
                    }
                }
            }
        }
        else{
            maxredo++;
            for(int j=0;j<3;j++){
                if(j==0){
                    for(int k=0;k<60;k++){
                        undoarr[moves+1][j][k]=usedChars[k];
                    }
                }
                else if(j==1){
                    for(int k=0;k<60;k++){
                        undoarr[moves+1][j][k]=turns[k];
                    }
                }
                else{
                    for(int k=0;k<30;k++){
                        undoarr[moves+1][j][k]=boxes[k];
                    }
                }
            }
            emptydfss();
            if(x>=97&&x<=126){
                dfs1(x,size);
                emptydfss();
                dfs2(x,size);
            }
            else{
                dfs3(x,size);
                emptydfss();
                dfs4(x,size);
            }
        }
    }
        return 1 ;
}

int mode2(int size){
    char x=0;
    enterplayers2();
    printGrid(0,size);
    while(index1!=(size*(size+1))*2){
        if(turn==0){
            moves++;
            printscores();
            calculateMoves();
            printmoves();
            printremaininglines(size);
            printf("It's ");
            printPlayer();
            printf(" turn\nEnter the letter of the line you want to choose : \n");
            cin>>x;
            if(!valid(x,size) || repeated(x)){
                moves--;
                continue;
            }
            printGrid(x,size);
            if(index1+1!=(size*(size+1))*2){
                char ans;
                char ans2=0;
                while(ans2==0){
                    cout<<"Press\n1-undo\n2-continue\n3-save&quit\n";
                    cin>>ans;
                    if(ans=='1'){
                        ans2=1;
                        index1++;
                        undo(size);
                        index1--;
                    }
                    else if(ans=='2'){
                        ans2=1;
                    }
                    else if(ans=='3'){
                        ans2=1;
                        save();
                        return 0;
                    }
                    else{
                        printf("Invalid Choice\n");
                    }
                }
            }
            for(int j=0;j<3;j++){
                if(j==0){
                    for(int k=0;k<60;k++){
                        undoarr[moves+1][j][k]=usedChars[k];
                    }
                }
                else if(j==1){
                    for(int k=0;k<60;k++){
                        undoarr[moves+1][j][k]=turns[k];
                    }
                }
                else{
                    for(int k=0;k<30;k++){
                        undoarr[moves+1][j][k]=boxes[k];
                    }
                }
            }
            index1++; 
            if(!filled()){
                maxredo=0;
                turn=(turn+1)%2;
                moves=-1;
                for(int i=0;i<25;i++){
                    redoarr[i]=0;
                }
                for(int i=0;i<25;i++){
                    for(int j=0;j<3;j++){
                        for(int k=0;k<60;k++){
                            undoarr[i][j][k]=0;
                        }
                    }
                }
                for(int j=0;j<3;j++){
                    if(j==0){
                        for(int k=0;k<60;k++){
                            undoarr[0][j][k]=usedChars[k];
                        }
                    }
                    else if(j==1){
                        for(int k=0;k<60;k++){
                            undoarr[0][j][k]=turns[k];
                        }
                    }
                    else{
                        for(int k=0;k<30;k++){
                            undoarr[0][j][k]=boxes[k];
                        }
                    }
                }
            }
            else{
                maxredo++;
                for(int j=0;j<3;j++){
                    if(j==0){
                        for(int k=0;k<60;k++){
                            undoarr[moves+1][j][k]=usedChars[k];
                        }
                    }
                    else if(j==1){
                        for(int k=0;k<60;k++){
                            undoarr[moves+1][j][k]=turns[k];
                        }
                    }
                    else{
                        for(int k=0;k<30;k++){
                            undoarr[moves+1][j][k]=boxes[k];
                        }
                    }
                }
                emptydfss();
                if(x>=97&&x<=126){
                    dfs1(x,size);
                    emptydfss();
                    dfs2(x,size);
                }
                else{
                    dfs3(x,size);
                    emptydfss();
                    dfs4(x,size);
                }
            }
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
            printGrid(x,size);
            index1++; 
            if(!filled()){
                maxredo=0;
                turn=(turn+1)%2;
                moves=-1;
                for(int i=0;i<25;i++){
                    redoarr[i]=0;
                }
                for(int i=0;i<25;i++){
                    for(int j=0;j<3;j++){
                        for(int k=0;k<60;k++){
                            undoarr[i][j][k]=0;
                        }
                    }
                }
                for(int j=0;j<3;j++){
                    if(j==0){
                        for(int k=0;k<60;k++){
                            undoarr[0][j][k]=usedChars[k];
                        }
                    }
                    else if(j==1){
                        for(int k=0;k<60;k++){
                            undoarr[0][j][k]=turns[k];
                        }
                    }
                    else{
                        for(int k=0;k<30;k++){
                            undoarr[0][j][k]=boxes[k];
                        }
                    }
                }
            }
            else{
                maxredo++;
                for(int j=0;j<3;j++){
                    if(j==0){
                        for(int k=0;k<60;k++){
                            undoarr[moves+1][j][k]=usedChars[k];
                        }
                    }
                    else if(j==1){
                        for(int k=0;k<60;k++){
                            undoarr[moves+1][j][k]=turns[k];
                        }
                    }
                    else{
                        for(int k=0;k<30;k++){
                            undoarr[moves+1][j][k]=boxes[k];
                        }
                    }
                }
            }
        }
    }
        return 1 ;
}

void newGame(){
    int x;
    for(int i=0;i<60;i++){
        usedChars[i]=' ';
        turns[i]=0;
    }
    for(int i=0;i<30;i++){
        boxes[i]=boxes2[i]=' ';
    }
    index1=turn=0;
    int size=chooseLevel();
    int mode=choosemode();
    first();
    if(mode==1){
    x = mode1(size);
    }
    else{
    x = mode2(size);
    }
    if ( x==1){
    printscores();
    calculateMoves();
    printmoves();
    printremaininglines(size);
    printwinner();
}
}

void menu();

void load(){
    char nlines;
    FILE *sg=fopen("savedGames.txt","r");
    vector <string> Games(0); 
    char buffer[255];
    if(fgets(buffer,255,sg)==NULL){
        printf("No saved games.");
        return;
    }
    while(fgets(buffer,255,sg)!=NULL){
            Games.push_back(buffer);
    }
    fclose(sg);
    for(int i=0;i<Games.size();i++){
        cout<<i+1<<"- "<<Games[i];
    }
    cout<<endl;
    cout<<"Enter game's name\n";
    char loadedFile2[255]={'\0'};
    cin>>loadedFile2;
    strcat(loadedFile2,".txt");
    // int flag=0;
    // for(int i=0;i<Games.size();i++){
    // for(int j=0;j<255;j++){
    //         if(loadedFile2[j]==Games[i][j]){
    //             flag++;
    //             break;
    //         }
    //     }
    // }
    char *ptf=loadedFile2;
    if(access(ptf,F_OK)==-1){
        cout<<"Not exist\n";
        menu();
        return;
    }
    else{
    FILE *pF=fopen(loadedFile2,"r");
    fscanf(pF ,"%s",&p1.name);
    fscanf(pF ,"%d",&p1.color);
    fscanf(pF ,"%d",&p1.score);
    fscanf(pF ,"%s",&p2.name);
    fscanf(pF ,"%d",&p2.color);
    fscanf(pF ,"%d",&p2.score);
    fscanf(pF ,"%d",&index1);
    fscanf(pF ,"%d",&turn);
    fscanf(pF ,"%d",&size2);
    fscanf(pF ,"%d",&mod2);
    fscanf(pF ,"%c",&nlines);
    int i=0;
    vector <string> usedcharv(0); 
    while(fgets(buffer,255,pF)!=NULL&&i<60){
        usedcharv.push_back(buffer);
        i++;
    }
    i=0;
    vector <string> turnsv(0); 
    while(fgets(buffer,255,pF)!=NULL&&i<60){
        turnsv.push_back(buffer);
        i++;
    }
    i=0;
    vector <string> boxesv(0); 
    while(fgets(buffer,255,pF)!=NULL&&i<30){
        boxesv.push_back(buffer);
        i++;
    }
    i=0;
    vector <string> boxes2v(0); 
    while(fgets(buffer,255,pF)!=NULL&&i<30){
        boxes2v.push_back(buffer);
        i++;
    }
    fclose(pF);
    for(int j=0;j<60;j++){
        usedChars[j]=usedcharv[j][0];
    }
    for(int l=0;l<60;l++){

        char x=turnsv[l][0];
        turns[l]=x-'0';

    }
    for(int j=0;j<30;j++){
        boxes[j]=boxesv[j][0];
    }
    for(int j=0;j<30;j++){
        boxes2[j]=boxes2v[j][0];
    }
    index1++;
    if(!filled()){
        turn=(turn+1)%2;
    }
    // turn=(turn+1)%2;
    first();
    int x;
    if(mod2==1){
    x= continueGame1(size2);
    }
    else{
    x=continueGame2(size2);
    }
    if (x==1){
    printscores();
    calculateMoves();
    printmoves();
    printremaininglines(size2);
    printwinner();
    // remove(loadedFile);
    // return 0;
    }
    }
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
    string sortedwinners[plyedMatches];
    int sortedWinners2[plyedMatches];
    for(int i=0;i<plyedMatches;i++){
        sortedWinners2[i]=0;
    }
    int index1=0;
    for(int i=0;i<winners.size();i++){
        string name=winners[i];
        sortedwinners[index1]=name;
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
                swap(sortedwinners[j],sortedwinners[j+1]);
            }
        }
    }

    string topPlayers[11];
    printf("\n");
    if(index1>11){
        for(int i=0;i<11;i++){
            topPlayers[i]=sortedwinners[i];
        }
        for(int i=1;i<11;i++){
            cout<<i<<"- "<<topPlayers[i]<<"  Won "<<sortedWinners2[i]<<" times"<<"\n\n";
        }
    }
    else{
        for(int i=0;i<index1;i++){
            topPlayers[i]=sortedwinners[i];
        }
        for(int i=1;i<index1;i++){
            cout<<i<<"- "<<topPlayers[i]<<"  Won "<<sortedWinners2[i]<<" times"<<"\n\n";
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
    int ans2=0;
    while(ans2==0){
        printf("\nPress\n1-New Game\n2-Load Game\n3-Top Players\n4-User Manual\n5-Exit\n");
        cin>>ans;
        if(ans=='1'){
            ans2=1;
            newGame();
        }
        else if(ans=='2'){
            ans2=1;
            load();
        }
        else if(ans=='3'){
            ans2=1;
            topTen();
        }
        else if(ans=='4'){
            ans2=1;
            userManual();
        }
        else if(ans=='5'){
            ans2=1;
            return;
        }
        else{
            printf("Invalid Choice\n");
        }
    }
    menu();
}

int main(){
    printf("== Welcome to Dots&Boxes game ==\n");
    menu();
}
