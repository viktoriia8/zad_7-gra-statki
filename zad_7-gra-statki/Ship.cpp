#include "Ship.h"
#include<string>
#include<iostream>
using namespace std;

Ship::Ship() {
	cout << "Wspó³rzêdne statka:";
	int h = 1;
	int g = 1;
	do {
		cin >> place;
		for (int i = 0; i < 10; i++) {
			if (place[0] == i) h = 0; 
		}
		place[1] = tolower(place[1]);
		for (int k = 97; k < 107; k++) {
			if (place[1] == k and h == 0) g = 0;
		};	
	} while (g);
};


bool Ship::ifok(Board *board,Ship s) {
	int edgec = 0;
	int edgen = 0;
	//int corner=0;
	if (s.place[0] == 0 or s.place[0] == 1)edgen = 1;
	if (s.place[1] == 97 or s.place[1] == 106)edgec = 1;
	int edge = edgen + edgec;
	//if (edge == 2) corner = 1;
	if (edge != 2) {
		int i = atoi(&s.place[0]);       //sprawdzenie czy mo¿na umieœciæ statek w czêœci œrodkowej pola(nie z bregów)
		int j = atoi(&s.place[1])-97;
		for ((i - 1); i + 1; i++) {
			for ((j - 1); j + 1; j++) {
				if (board->matrix[i][j] != 0) return 0;
			}
		}
		return 1;
	}
	if(edgen==1){
		if (s.place[0] == 1) {
			int f = 0;
			int h = atoi(&s.place[1])-97;
			for ((h-1); h+1;h++) {
				if(board->matrix[f][h] != 0) return 0;
				if (board->matrix[f+1][h] != 0) return 0;
			}
			return 1;
		}														//sprawdzanie dla górnego i dolnego brzegu bez kratek w rogu

		if (s.place[0] == 0) {
			int f = 9;
			int h = atoi(&s.place[1]) - 97;
			for ((h-1); h + 1; h++) {
				if (board->matrix[f][h] != 0) return 0;
				if (board->matrix[f - 1][h] != 0) return 0;
			}
			return 1;
		}

	};
	if (edgec == 1) {
		if (s.place[1] == 97) {
			int f = 0;
			int h = atoi(&s.place[0]);
			for ((h - 1); h + 1; h++) {
				if (board->matrix[h][f] != 0) return 0;
				if (board->matrix[h + 1][f] != 0) return 0;
			}
			return 1;
		}														//sprawdzanie dla prawego i lewego brzegu bez kratek w rogu

		if (s.place[1] == 106) {
			int f = 9;
			int h = atoi(&s.place[0]);
			for ((h - 1); h + 1; h++) {
				if (board->matrix[h][f] != 0) return 0;
				if (board->matrix[h - 1][f] != 0) return 0;
			}
			return 1;
		}

	};
	if (s.place[0] == 1 and s.place[1] == 97) {
		for (int d = 0; d < 2; d++) {
			for (int k = 0; k < 2; k++) {                        //sprawdzenie dla kratki 1a
				if (board->matrix[d][k] != 0)return 0;
			}
		}return 1;
	}
	if (s.place[0] == 0 and s.place[1] == 97) {
		for (int d = 9; d > 7; d--) {
			for (int k = 0; k < 2; k++) {						//sprawdzenie dla kratki 0a
				if (board->matrix[d][k] != 0)return 0;
			}
		}return 1;
	}

	if (s.place[0] == 1 and s.place[1] == 106) {
		for (int d = 0; d < 2; d++) {
			for (int k = 9; k >7; k--) {                        //sprawdzenie dla kratki 1j
				if (board->matrix[d][k] != 0)return 0;
			}
		}return 1;
	}
	if (s.place[0] == 0 and s.place[1] == 106) {
		for (int d = 9; d > 7; d--) {
			for (int k = 9; k > 7; k--) {						//sprawdzenie dla kratki 0j
				if (board->matrix[d][k] != 0)return 0;
			}
		}return 1;
	}

	
};



