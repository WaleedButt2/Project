#include <iostream>
#include <fstream>
#include <string.h>
#include <string.h>
#include <string>
using namespace std;
int main(){
    string line;
    char *str,*rank,*name,*og;
    ifstream(file);
    file.open("Files/Spell List.txt");
    getline(file,line);
    while(file){
        getline(file,line);
        og=&line[0];
        strcpy(str,og);
        rank = strtok(str, "#");
        cout<<rank;str=&line[0];
        //name=strtok(str,"!");
        cout<<str;
        //printf("%s\n", str); 
        //cout<<str<<endl;
    }
    printf("\n");
    file.close();
}