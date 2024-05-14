#include <stdio.h>
#include <string.h>
 
int print(char* ch){
// int print(char ch[]){
    printf("%s\n",ch);
    ch[0]='a';
    printf("%s\n",ch);

}

int main(){

    char ch[100]="char";
    print(ch);
    printf("%s\n",ch);

}
