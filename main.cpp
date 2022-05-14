#include <iostream>

using namespace std;

class Vector {

    int size;
    int capacity;
    int* arr;

public:

    Vector(){
        size = 0;
        capacity = 1;
        arr = new int[capacity];
    }

    void add(int el){
        if (size == capacity) {
            int* temp = new int[capacity * 2];
            for (int i=0; i <= (size - 1) ; i++) {
                temp[i] = arr[i];
            }
            capacity *= 2;
            delete[] arr;
            arr = temp;
        }

        arr[size] = el;
        size++;
    }

    void reset() {
        size = 0;
    }

    void print(int x, int y, int moves){
        cout << moves << endl;
        for (int i=0; i < size/x; i++){
            for (int j=0; j < x; j++){
                cout << arr[i * y + j] << " ";
            }
            cout << endl;
        }
    }

    void swapV(int a, int b){
        swap(arr[a], arr[b]);
    }

    int getSize(){
        return size;
    }

    ~Vector(){

    }
};

class TicTacToe{

    int x;
    int y;
    int* board;
    Vector* possibleMoves;

public:
    TicTacToe(int x, int y) : x( x ), y( y ){
        board = new int[x*y];
        for (int i=0; i<x*y; i++){
            board[i] = 0;
        }
        possibleMoves = new Vector;
    }

    void setTheBoard(int field, int player){
        board[field] = player;
    }

    void generatePossibleMoves(int player){
        int moves = 0;
        for (int i=0; i<x*y; i++){
            if (board[i] == 0) {
                board[i] = player;
                save();
                board[i] = 0;
                moves++;
            }
        }
        possibleMoves->print(x, y, moves);
    }

    void save(){
        for (int i=0; i<x*y; i++){
            possibleMoves->add(board[i]);
        }
    }

    void print(){
        for (int i=0; i < x; i++){
            for (int j=0; j < y; j++){
                cout << board[i * y + j];
            }
            cout << endl;
        }
    }

    ~TicTacToe(){
        delete board;
    }

};

void inputBoard(int size, TicTacToe* g);

int main() {
    int x, y, player;
    cin >> x >> y;
    TicTacToe* game = new TicTacToe(x, y);
    inputBoard( x*y, game);
    cin >> player;
    game->generatePossibleMoves(player);
    //game->print();
    return 0;
}

void inputBoard(int size, TicTacToe* g){
    int player;
    for (int i=0; i < size; i++){
        cin >> player;
        g->setTheBoard(i, player);
    }
}