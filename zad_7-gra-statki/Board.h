#pragma once
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

#include "Ship.h"


using namespace std;

class Board {
	public:
	int matrix[12][12];
	void showmyboard();
	void addShip(const Ship& s);
	Board();
	bool ifok(const Ship& s);
};