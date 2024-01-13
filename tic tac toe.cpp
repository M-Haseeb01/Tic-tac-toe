#include <iostream>
using namespace std;
// Function to display 3x3 grid for game
void gamegrid(char arr3[3][3])
{
    cout  << "0" << "  " << "1" << "  " << "2" << endl;
   cout << arr3[0][0] << " | " << arr3[0][1] << " | " << arr3[0][2] << endl;
    cout << "----------" << endl;
    cout << arr3[1][0] << " | " << arr3[1][1] << " | " << arr3[1][2] << endl;  
    
    cout << "----------" << endl;
   cout << arr3[2][0] << " | " << arr3[2][1] << " | " << arr3[2][2] << endl;
}
// Bool function to check win or lose
bool win(char arr3[3][3]) {
    // For loop for checking rows
    for (int i = 0; i <= 2; i++) {
        if (arr3[i][0] == arr3[i][1] && arr3[i][1] == arr3[i][2] && arr3[i][0] == 'X') {
            return true;
        }
    }
    //For loop for checking coloumns
    for (int j = 0; j <= 2; j++) {
        if (arr3[0][j] == arr3[1][j] && arr3[2][j] == arr3[0][j] && arr3[0][j] == 'X')
            return true; 
    }
    
   
       //IF condition  for checking  diagonals with and or conditions
    if ((arr3[0][0] == arr3[1][1] && arr3[2][2] == arr3[0][0] && arr3[0][0] == 'X') ||
        (arr3[0][2] == arr3[1][1] && arr3[2][0] == arr3[0][2] && arr3[0][2] == 'X'))
        return true;
    // For loop for checking rows
    for (int i = 0; i < 3; i++) {
        if (arr3[i][0] == arr3[i][1] && arr3[i][1] == arr3[i][2] && arr3[i][0] =='O') {
            return true;
        }
    }
    // For loop for checking col
    for (int j = 0; j < 3; j++) {
        if (arr3[0][j] == arr3[1][j] && arr3[1][j] == arr3[2][j] && arr3[0][j] == 'O') {
            return true;
        }
    }
    //IF condition  for checking  diagonals with and or conditions
    if ((arr3[0][0] == arr3[1][1] && arr3[1][1] == arr3[2][2] && arr3[0][0] == 'O') ||
        (arr3[0][2] == arr3[1][1] && arr3[1][1] == arr3[2][0] && arr3[0][2] == 'O')) {
        return true; 
    }

    return false;
}
int toss()
{
    int t1 = rand() % 2;
  
    return t1;
}


void placing(char arr3[3][3],int p)
{
    int row, col;
    cout << "Enter Row:Col";
    cin >> row >> col;
    //checking invalid entry 
    if (arr3[row][col] != 0) {
        cout << "Invalid entry" << endl;
    }
    // placing for p1 X
    else if (p == 1)
    {
        //placing row and col for p1 at 0 row
        if (row == 0) {
            arr3[row][col] = 'X';
        }
        //placing row and col for p1 at 1 row
        else if (row == 1) {
            arr3[row][col] = 'X';
        }
        //placing row and col for p1 at 2 row
        else if (row == 2) {
            arr3[row][col] = 'X';
        }
    }
    else
    {
        //placing row and col for p2 at 0 row
        if (row == 0) {
            arr3[row][col] = 'O';
        }
        //placing row and col for p2 at 1 row
        else if (row == 1) {
            arr3[row][col] = 'O';
        }
        //placing row and col for p2 at 2 row
        else if (row == 2) {
            arr3[row][col] = 'O';
        }
    }

}
void displayname(char a[], char  b[])
{
 //for couting(displaying name)
    cout << "Player1:" << a << endl;
    cout << "Player2:" << b << endl;

}
bool tie(char arr3[][3])
{
    int check = 1;
   
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr3[i][j] == 0)
            {
                check = 0;
                break;
            }
        }
        if (!check) {
            break;
        }
    }
   
    if (check && !win(arr3))
    {
        return true;
    }
    return false;
}


void cpuMove(char arr[][3], int& p) {
   
    int t = 0; int check = 0;
    if (check == 0)
    {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {

                if (arr[1][1] == 0)
                {
                    arr[1][1] = 'O';
                }

                if (arr[i][j] == 0) {
                    arr[i][j] = 'O';

                    return;
                }
               // break;
            }
        }
    }
    
    int row, col;
    cout << "Enter Row:Col ";
    cin >> row >> col;
    if (arr[row][col] != 0) {
        check = 1;
        cout << "Invalid entry" << endl;
    }
    if (row == 0) {
        arr[row][col] = 'X';
    }
    else if (row == 1) {
        arr[row][col] = 'X';
    }
    else if (row == 2) {
        arr[row][col] = 'X';
    }
   
   
}
int winner(char arr3[][3])
{
    for (int i = 0; i < 3; i++) {
        if (arr3[i][0] == arr3[i][1] && arr3[i][1] == arr3[i][2] && arr3[i][0] == 'X') {
            return 2;
        }
    }

    for (int j = 0; j < 3; j++) {
        if (arr3[0][j] == arr3[1][j] && arr3[1][j] == arr3[2][j] && arr3[0][j] == 'X') {
            return 2;
        }
    }

    if ((arr3[0][0] == arr3[1][1] && arr3[1][1] == arr3[2][2] && arr3[0][0] == 'X') ||
        (arr3[0][2] == arr3[1][1] && arr3[1][1] == arr3[2][0] && arr3[0][2] == 'X')) {
        return 2;
    }
    for (int i = 0; i < 3; i++) {
        if (arr3[i][0] == arr3[i][1] && arr3[i][1] == arr3[i][2] && arr3[i][0] == 'O') {
            return 1;

        }
    }

    for (int j = 0; j < 3; j++) {
        if (arr3[0][j] == arr3[1][j] && arr3[1][j] == arr3[2][j] && arr3[0][j] == 'O') {
            return 1;

        }
    }

    if ((arr3[0][0] == arr3[1][1] && arr3[1][1] == arr3[2][2] && arr3[0][0] == 'O') ||
        (arr3[0][2] == arr3[1][1] && arr3[1][1] == arr3[2][0] && arr3[0][2] == 'O')) {
        return 1;

    }
}
int main() {
    cout << "************Welcome to tic tac toe*************" <<  endl;
    cout << "Press 1 for Player vs Player"<<endl;
    cout << "Press 2 for Player vs CPU" << endl;
    char arr[3][3] = { 0 };
    int choice;
    cin >> choice;
    if (choice == 1)
    {
       
        char arr[3][3] = { 0 };
        char p1[100], p2[100];
        cout << "Enter Name1:" << endl;
        cin >> p1;
        cout << endl << "Enter Name2:" << endl;
        cin >> p2;
        int t1;
        cout << "Enter any number to toss" << endl;
        cin >> t1;
        int turn = toss();
        if (turn == 1) {
            cout << p1 << " won the toss" << endl;
        }
        else {
            cout << p2 << " won the toss" << endl;
        }

        bool check = false;
        int p;
        while (!win(arr)&&!tie(arr))
        {
            system("cls");

            displayname(p1, p2);
            gamegrid(arr);
            cout << "Turn for ";
            if (turn == 1) {
                cout << p1 << endl;
            }
            else {
                cout << p2 << endl;
            }
            p = turn;
            placing(arr, p);
            gamegrid(arr);
            if (turn == 1) {
                turn = 2;
            }
            else {
                turn = 1;
            }
        }
        int w = winner(arr);
       
        if (win(arr))
        {
            if (w == 1)
            {
                cout << "Player 2 won" << endl;
            }
            else if (w == 2)
            {
                cout << "Player 1 won" << endl;
            }
        }
        if (tie(arr))
        {
            cout << "Its a tie" << endl;
        }
       


    }
    
    if (choice == 2)
    {
      
        char p1[100], p2[100];
        cout << "Enter Name1:" << endl;
        cin >> p1;

        char cpu[10] = "CPU";
        while (!win(arr))
        { 
            system("cls");
            displayname(p1, cpu);
            gamegrid(arr);
            cout << "Turn for " << p1 << endl;
            int p = 1;
            placing(arr, p);
            gamegrid(arr);

            if (!win(arr))
            {
                displayname(p1, cpu);
                cout << "CPU's turn" << endl;
                 cpuMove(arr, p);
                gamegrid(arr);
            }
        }

        int w = winner(arr);
        if (w == 2)
        {
            cout << p1 << " won" << endl;
        }
        else if (w == 1)
        {
            cout << "CPU won" << endl;
        }
        else if(tie(arr))
        {
            cout << "It's a tie!" << endl;
        }
    }



    return 0;
}
