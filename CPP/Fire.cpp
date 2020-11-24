#include "../Header/Fire.h"
#include <iostream>
#include <fstream>
#include <strings.h>
#include <string>
using namespace std;
Fire::Fire(){
    string line;
    fstream(file);
    file.open("../Files/Spell List.txt",ios::in);
    while(file){
        getline(file,line);
        cout<<line<<endl;
    }
    file.close();
}
int Fire::get_damage(){
    return 0;
}