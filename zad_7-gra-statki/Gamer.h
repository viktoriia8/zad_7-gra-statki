#include <iostream>
#include <conio.h>
#include <stdlib.h>     
#include <time.h>       
#include <string>  
#include <fstream>
#include <vector>
#include <cstring>
#include <cassert>
#include <algorithm>
#pragma once
#include"Board.h"


using namespace std;

class Gamer {
public:
	string name;
	Board myBoard;
	Gamer(string name_) :name(name_){};
};
