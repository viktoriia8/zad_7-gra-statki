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
#include "Board.h"




using namespace std;

class Ship {
public:
	string place;  //miejsce statka na tablicy
	Ship();
	bool ifok(Board *board,Ship s);
	friend class Board;
};

