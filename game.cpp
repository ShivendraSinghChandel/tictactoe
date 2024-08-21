#include<iostream>
using namespace std;
class tictactoe{
    public:char board[3][3]={'1','2','3','4','5','6','7','8','9'};
void displayBoard()
{
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
        {
            cout<<board[i][j]<<"    ";
        }
        cout<<"\n\n";
    }

}
void playerMove(char Player)
{
    int move;
    cout<<Player <<" - enter your move : ";
    cin>>move;

    int row=(move-1)/3;
    int col=(move-1)%3;

    if(board[row][col]!='X' && board[row][col]!='O'){
        board[row][col]=Player;
    }
    else{
        cout<<"invalid move,please enter again";
        playerMove(Player);
    }
}
int checkWinner(char Player)
{
    for(int i=0;i<3;i++){
        if(board[i][0]==Player && board[i][1]==Player && board[i][2]==Player ||
           board[0][i]==Player && board[1][i]==Player && board[2][i]==Player){
            return true;
           }
        if(board[0][0]==Player && board[1][1]==Player && board[2][2]==Player ||
           board[0][2]==Player && board[1][1]==Player && board[2][0]==Player){
            return true;
           }
    }
    return false;
}
};
int main(){
    tictactoe t;
    char currentPlayer='X';
    int moves=0;
    while(moves<9)
    {
        t.displayBoard();
        t.playerMove(currentPlayer);
        moves++;
        if(t.checkWinner(currentPlayer)){
            cout<<currentPlayer<<" is the winner\n";
            t.displayBoard();
            return 0;
        }
        if(currentPlayer=='X'){
            currentPlayer='O';
        }
        else{
            currentPlayer='X';
        }
    }
    cout<<"It's a draw !";
    t.displayBoard();
    return 0;
}