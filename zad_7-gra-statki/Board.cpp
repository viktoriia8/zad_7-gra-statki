#include "Board.h"


using namespace std;

void Board::showmyboard() {
	int i, j;
	cout << "   a b c d e f g h i j \n";
	cout << "----------------------\n";
	for (i = 0; i < 10; i++) {
		if (i!=9)
		cout << i+1 << "| ";
		else if(i==9)cout << "0" << "| ";
		for (j = 0; j < 10; j++) {
			if (matrix[i][j] == 0) cout << ".";             //puste miejsca na mapie
			else if (matrix[i][j] == 1) cout << "#";		//Statki
			else if (matrix[i][j] == 2)cout << "x";			//strzelone puste miejsca
			else if (matrix[i][j] == 3) cout << "\033[1;31m" << "#" << "\033[0m";   //strzelone statki(czerwone)
			cout << " ";
		};
		cout << "|\n";
	};
	cout << "       Moja mapka\n";
};
void Board::addShip(const Ship& s){
	string place = s.place;
	int num = atoi(&place[0])-1;
	int ch = int(place[1])-97;
	matrix[num][ch] = 1;

};

Board::Board(){
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			matrix[i][j] = 0;
		}
	}
};

bool Board::ifok(const Ship& s) {
	int edgec = 0;
	int edgen = 0;
	int edge = 0;
	string place_ = s.place;
	int row = atoi(&place_[0])-1;
	int column = int(place_[1])-97;
	//int corner=0;
	if (row == 0 or row == 9)edgen = 1;
	if (column == 0 or column == 9)edgec = 1;
	edge = edgen + edgec;
	//if (edge == 2) corner = 1;
	if (edge != 2 && edge!=1) {
		int j = column;
		int i = row;       //sprawdzenie czy mo¿na umieœciæ statek w czêœci œrodkowej pola(nie z bregów)
		for ((i - 1); i<(row + 2); i++) {
			for ((j - 1); j<(column + 1); j++) {
				if (matrix[i][j] != 0) return 0;
			}
		}return 1;
	}
	if (edgen == 1) {
		if (s.place[0] == 1) {
			int f = 0;
			int h = column;
			for ((h - 1); h<(column + 1); h++) {
				if (matrix[f][h] != 0) return 0;
				if (matrix[f + 1][h] != 0) return 0;
			}
			return 1;
		}														//sprawdzanie dla górnego i dolnego brzegu bez kratek w rogu

		if (s.place[0] == 0) {
			int f = 9;
			int h = column;
			for ((h - 1); h<(column + 1); h++) {
				if (matrix[f][h] != 0) return 0;
				if (matrix[f - 1][h] != 0) return 0;
			}
			return 1;
		}

	};
	if (edgec == 1) {
		if (column == 0) {
			int f = 0;
			int h = row;
			for ((h - 1); h<(row + 1); h++) {
				if (matrix[h][f] != 0) return 0;
				if (matrix[h + 1][f] != 0) return 0;
			}
			return 1;
		}														//sprawdzanie dla prawego i lewego brzegu bez kratek w rogu

		if (column == 9) {
			int f = 9;
			int h = row;
			for ((h - 1); h<(row + 1); h++) {
				if (matrix[h][f] != 0) return 0;
				if (matrix[h - 1][f] != 0) return 0;
			}
			return 1;
		}

	};
	if (row == 0 and column == 0) {
		for (int d = 0; d < 2; d++) {
			for (int k = 0; k < 2; k++) {                        //sprawdzenie dla kratki 1a
				if (matrix[d][k] != 0)return 0;
			}
		}return 1;
	}
	if (s.place[0] == 0 and s.place[1] == 97) {
		for (int d = 9; d > 7; d--) {
			for (int k = 0; k < 2; k++) {						//sprawdzenie dla kratki 0a
				if (matrix[d][k] != 0)return 0;
			}
		}return 1;
	}

	if (row == 0 and column == 9) {
		for (int d = 0; d < 2; d++) {
			for (int k = 9; k > 7; k--) {                        //sprawdzenie dla kratki 1j
				if (matrix[d][k] != 0)return 0;
			}
		}return 1;
	}
	if (row == 0 and column == 9) {
		for (int d = 9; d > 7; d--) {
			for (int k = 9; k > 7; k--) {						//sprawdzenie dla kratki 0j
				if (matrix[d][k] != 0)return 0;
			}
		}return 1;
	}

	return 1;
};
