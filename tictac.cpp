#include <iostream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char current_marker;
int current_player;
//GAME BOARD
void drawboard() {
    cout << "Current board: \n";
    for(int i = 0; i<SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            cout << " " << board[i][j];
            if (j < SIZE - 1){
                cout << " |";
            }
        }
        cout << endl;
        if (i < SIZE - 1){
            cout << "---|---|---\n";
        }
    }
}
//GAME MARKER PLACEMENT (X/O)
bool placeMarker(int row, int col) {
    if((row < 0 || row > SIZE ) || (col < 0 || col > SIZE)) {
        cout << "Invalid move! Try again." << endl;
        return false;
    }
    if(board[row][col] != ' ') {
        cout << "Slot already occupied! Try again." << endl;
        return false;
    }
    board[row][col] = current_marker;
    return true;
}
//CONDITIONS OF WINNING
int winner() {
    //Rows
    for(int i = 0; i< SIZE; i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return current_player;
        }
    }
    //Columns
    for(int i = 0; i < SIZE; i++){
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return current_player;
        }
    }
    //Diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return current_player;
    }

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return current_player;
    }

    return 0;
}
//SWAPPING OF PLAYER TURNS AND MARKER
void swapPlayerMarker() {
    if(current_marker == 'X') {
        current_marker = 'O';
    }
    else {
        current_marker = 'X';
    }
    current_player = (current_player == 1) ? 2 : 1;
}
//MAIN Fn
void tictac() {
    char marker1;
    cout << "Player 1, Choose your marker(X/O): ";
    cin >> marker1;
    current_marker = marker1;
    current_player = 1;

    drawboard();
    int player_won = 0;
  //LOOP TO CREATE PLAYERS' TURNS
    for(int i = 0; i < SIZE*SIZE; i++) {
        cout << "Player " << current_player << "'s turn. Enter row (1-3) and column(1-3): ";
        int row, col;
        cin >> row >> col;

        //Attempt to place the marker
        if(!placeMarker(row - 1, col - 1)) {
            i--;                 //Decrementing i to retry the current player's turn
            continue;            //Skip the rest of the loop and try again
        }
        drawboard();
      
        player_won = winner();
        if(player_won == 1) {
            cout << "Player 1 wins! Congratulations!" << endl;
            break;
        }
        if(player_won == 2) {
            cout << "Player 2 wins! Congratulations!" << endl;
            break;
        }
        swapPlayerMarker();
    }
    if(player_won == 0) {
        cout << "It's a tie!" << endl;
    }
}
int main() {
  //Declaration of the fn
    tictac();
    return 0;
}
//END OF CODE
