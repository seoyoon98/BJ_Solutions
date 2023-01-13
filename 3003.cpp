#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    int king = 1;
    int queen = 1;
    int rook = 2;
    int bishop = 2;
    int knight = 2;
    int pawn = 8;
    
    int curKing, curQueen, curRook, curBishop, curKnight, curPawn;
    
    cin >> curKing >> curQueen >> curRook >> curBishop >> curKnight >> curPawn;
    
    cout << king - curKing << " " << queen - curQueen << " " << rook - curRook << " " << bishop - curBishop << " " << knight - curKnight << " " << pawn - curPawn << "\n";
    
    return 0;
}
