#include <iostream>
#include <cstdlib>
#include <windows.h>
#include<stdlib.h>


using namespace std;

char board[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int check_win();
void board_status();
void gameplay(char, int, int);

/*
 * Driver Function.
 */
int main()
{
    int player = 1;
    int i, box_no;

    char mark_x_o;
    //gameplay();
    cout << endl << " \t\t\t\t\t\tEmpieza el juego " << endl << endl;

    do
    {
        board_status();
        player = player % 2 ? 1 : 2;
        gameplay(mark_x_o,box_no,player);
        i = check_win();
        player++;

    }
    while (i == -1);

    board_status();

    if (i == 1)
        cout << "~~~Jugador " << --player << " Won" << endl;
    else
        cout << "~~~Empate!" << endl;
    return 0;
}

void gameplay(char mark_x_o, int box_no,int player)
{
    cout<<endl<<endl;

    cout << "Jugador " << player << ", ingrese numero: ";
    cin >> box_no;


    while (cin.fail() || box_no < 1 || box_no > 9 || box_no!= (int)board[box_no]-'0')
    {
        cin.clear();
        cin.ignore();
        cout << "Movimiento invalido!" << endl;
        cout << "Jugador " << player << ", ingrese numero: ";
        cin >> box_no;
    }

    system("cls");

    mark_x_o = player == 1 ? 'X' : 'O';


    if (box_no == 1 && board[1] == '1')
    {
        board[1] = mark_x_o;
    }
    else if (box_no == 2 && board[2] == '2')
    {
        board[2] = mark_x_o;
    }
    else if (box_no == 3 && board[3] == '3')
    {
        board[3] = mark_x_o;
    }
    else if (box_no == 4 && board[4] == '4')
    {
        board[4] = mark_x_o;
    }
    else if (box_no == 5 && board[5] == '5')
    {
        board[5] = mark_x_o;
    }
    else if (box_no == 6 && board[6] == '6')
    {
        board[6] = mark_x_o;
    }
    else if (box_no == 7 && board[7] == '7')
    {
        board[7] = mark_x_o;
    }
    else if (box_no == 8 && board[8] == '8')
    {
        board[8] = mark_x_o;
    }
    else if (box_no == 9 && board[9] == '9')
    {
        board[9] = mark_x_o;
    }
}


/* -1 : Game in progress.
 *  0 : Game over. No result.
 *  1 : Game over. with result.
 */
int check_win ()
{
    if (board[1] == board[2] && board[2] == board[3])
        return 1;

    else if (board[4] == board[5] && board[5] == board[6])
        return 1;

    else if (board[7] == board[8] && board[8] == board[9])
        return 1;

    else if (board[1] == board[4] && board[4] == board[7])
        return 1;

    else if (board[2] == board[5] && board[5] == board[8])
        return 1;

    else if (board[3] == board[6] && board[6] == board[9])
        return 1;

    else if (board[1] == board[5] && board[5] == board[9])
        return 1;

    else if (board[3] == board[5] && board[5] == board[7])
        return 1;

    else
    {
        bool done = true;
        for (int i=1; i<9; i++)
        {
            if (i==(int)board[i]-'0')
            {
                done = false;
                break;
            }

        }

        if (done) return 0;
    }

    return -1;
}

/*
 * Drawing the board.
 */
void board_status ()
{

    cout << endl;
    cout << "Jugador 1 (X)  -  Jugador 2 (O)" << endl << endl;

    for(int i = 1; i < 10; i++)
    {
        cout << "       |       |       " << endl;
        Sleep(50);
        cout << "      " << board[i] << "|      " << board[i+1] << "|     " << board[i+2] << endl;
        Sleep(50);
        cout << "_______|_______|________" << endl;
        Sleep(50);

        i+= 2;

        if(i == 9)
        {
            cout << "       |       |       " << endl;
        }
    }

}


