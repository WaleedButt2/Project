#include "../FileHandling.cpp"
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "../../Header/Elements/Elements.h"
using namespace std;
Elements::Elements(){
    Elements::Fire=File("Fire");
    Elements::Ice=File("Ice");
}