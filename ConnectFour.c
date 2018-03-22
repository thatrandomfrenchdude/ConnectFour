/*
 
 Sample Grid
 
   A B C D E F G
 5 X X X X X X X
 4 X X X X X X X
 3 X X X X X X X
 2 X X X X X X X
 1 X X X X X X X
 0 X X X X X X X
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int play = 0; //used to mark play again
int win = 0; //used to mark a win

//helper function to check a vertical array for 4 in a row
int checkVertical(int arr[6], int ch)
{
    int successive = 0;
    int i;
    for (i = 0; i < 6; i++)
    {
        if (arr[i] == ch)
        {
            successive++;
            if (successive == 4)
                return 1;
        }
        else
            successive = 0;
    }
    return 0;
}

//helper function to check and see if there is a win
int checkWin(int a[6], int b[6], int c[6], int d[6], int e[6], int f[6], int g[6], int ch)
{
    //check verticals
    int win;
    //a
    win = checkVertical(a, ch);
    if (win == 1)
        return win;
    //b
    win = checkVertical(b, ch);
    if (win == 1)
        return win;
    //c
    win = checkVertical(c, ch);
    if (win == 1)
        return win;
    //d
    win = checkVertical(d, ch);
    if (win == 1)
        return win;
    //e
    win = checkVertical(e, ch);
    if (win == 1)
        return win;
    //f
    win = checkVertical(f, ch);
    if (win == 1)
        return win;
    //g
    win = checkVertical(g, ch);
    if (win == 1)
        return win;
    
    //check horizontals
    int i, j;
    for (j = 0; j < 6; j++) //check every row
    {
        int successive = 0;
        for (i = 0; i < 7; i++) //check across the row
        {
            if (i == 0)
            {
                if (a[j] == ch)
                {
                    successive++;
                    if (successive == 4)
                        return 1;
                }
                else
                    successive = 0;
            }
            else if (i == 1)
            {
                if (b[j] == ch)
                {
                    successive++;
                    if (successive == 4)
                        return 1;
                }
                else
                    successive = 0;
            }
            else if (i == 2)
            {
                if (c[j] == ch)
                {
                    successive++;
                    if (successive == 4)
                        return 1;
                }
                else
                    successive = 0;
            }
            else if (i == 3)
            {
                if (d[j] == ch)
                {
                    successive++;
                    if (successive == 4)
                        return 1;
                }
                else
                    successive = 0;
            }
            else if (i == 4)
            {
                if (e[j] == ch)
                {
                    successive++;
                    if (successive == 4)
                        return 1;
                }
                else
                    successive = 0;
            }
            else if (i == 5)
            {
                if (f[j] == ch)
                {
                    successive++;
                    if (successive == 4)
                        return 1;
                }
                else
                    successive = 0;
            }
            else if (i == 6)
            {
                if (g[j] == ch)
                {
                    successive++;
                    if (successive == 4)
                        return 1;
                }
                else
                    successive = 0;
            }
        }
    }
    
    //check right diagonals
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
        {
            //first column
            if (i == 0)
            {
                if (a[j] == ch)
                {
                    if (b[j + 1] == ch)
                        if (c[j + 2] == ch)
                            if (d[j + 3] == ch)
                                return 1;
                }
            }
            //second column
            else if (i == 1)
            {
                if (b[j] == ch)
                    if (c[j + 1] == ch)
                        if (d[j + 2] == ch)
                            if (e[j + 3] == ch)
                                return 1;
            }
            //third column
            else if (i == 2)
            {
                if (c[j] == ch)
                    if (d[j + 1] == ch)
                        if (e[j + 2] == ch)
                            if (f[j + 3] == ch)
                                return 1;
            }
            //fourth column
            else if (i == 3)
            {
                if (d[j] == ch)
                    if (e[j + 1] == ch)
                        if (f[j + 2] == ch)
                            if (g[j + 3] == ch)
                                return 1;
            }
        }
    }
    
    //check left diagonals
    for (i = 0; i < 4; i++)
    {
        for (j = 5; j > 2; j--)
        {
            //first column
            if (i == 0)
            {
                if (a[j] == ch)
                    if (b[j - 1] == ch)
                        if (c[j - 2] == ch)
                            if (d[j - 3] == ch)
                                return 1;
            }
            //second column
            else if (i == 1)
            {
                if (b[j] == ch)
                    if (c[j - 1] == ch)
                        if (d[j - 2] == ch)
                            if (e[j - 3] == ch)
                                return 1;
            }
            //third column
            else if (i == 2)
            {
                if (c[j] == ch)
                    if (d[j - 1] == ch)
                        if (e[j - 2] == ch)
                            if (f[j - 3] == ch)
                                return 1;
            }
            //fourth column
            else if (i == 3)
            {
                if (d[j] == ch)
                    if (e[j - 1] == ch)
                        if (f[j - 2] == ch)
                            if (g[j - 3] == ch)
                                return 1;
            }
        }
    }
    
    return 0;
}

//helper function to check and see if a column is full. If yes, returns -1, else returns number of full spaces
int checkColumn(int column[6])
{
    int i, size = 0;
    for (i = 0; i < 6; i++)
    {
        if (column[i] != 0)
            size++;
    }
    if (size == 6)
        return -1;
    else
        return size;
}

//helper function to flush the input buffer
void flush()
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {}
}

//helper function to print the game board
void printBoard(int a[6], int b[6], int c[6], int d[6], int e[6], int f[6], int g[6])
{
    int i, j, arrayLine;
    arrayLine = 5;
    for (i = 0; i < 14; i++) //loop for every line
    {
        if (i == 0)
        {
            printf("  A   B   C   D   E   F   G  \n");
        }
        else if (i % 2 == 1)
        {
            printf("|---|---|---|---|---|---|---|\n");
        }
        else
        {
            for (j = 0; j < 29; j++)
            {
                //| = 0, 4, 8, 12, 16, 20, 24, 28
                //space = 1, 3, 5, 7, 9, ...
                //letter = 2, 6, 10, 14, 18, 22, 26
                if (j % 2 == 1)
                {
                    printf(" ");
                }
                else if (j % 4 == 0)
                {
                    printf("|");
                }
                else if (j == 2) //a
                {
                    if (a[arrayLine] == 0)
                        printf(" ");
                    else if (a[arrayLine] == 1)
                        printf("X");
                    else if (a[arrayLine] == 2)
                        printf("O");
                }
                else if (j == 6) //b
                {
                    if (b[arrayLine] == 0)
                        printf(" ");
                    else if (b[arrayLine] == 1)
                        printf("X");
                    else if (b[arrayLine] == 2)
                        printf("O");
                }
                else if (j == 10) //c
                {
                    if (c[arrayLine] == 0)
                        printf(" ");
                    else if (c[arrayLine] == 1)
                        printf("X");
                    else if (c[arrayLine] == 2)
                        printf("O");
                }
                else if (j == 14) //d
                {
                    if (d[arrayLine] == 0)
                        printf(" ");
                    else if (d[arrayLine] == 1)
                        printf("X");
                    else if (d[arrayLine] == 2)
                        printf("O");
                }
                else if (j == 18) //e
                {
                    if (e[arrayLine] == 0)
                        printf(" ");
                    else if (e[arrayLine] == 1)
                        printf("X");
                    else if (e[arrayLine] == 2)
                        printf("O");
                }
                else if (j == 22) //f
                {
                    if (f[arrayLine] == 0)
                        printf(" ");
                    else if (f[arrayLine] == 1)
                        printf("X");
                    else if (f[arrayLine] == 2)
                        printf("O");
                }
                else if (j == 26) //g
                {
                    if (g[arrayLine] == 0)
                        printf(" ");
                    else if (g[arrayLine] == 1)
                        printf("X");
                    else if (g[arrayLine] == 2)
                        printf("O");
                }
            }
            arrayLine--;
            printf("\n");
        }
    }
}

int main()
{
    while (play == 0) //loop as many times as they want to play
    {
        //columns for the chart, initialized as int arrays
        //0 means no character has been dropped
        //1 means an X has been dropped
        //2 means an O has been dropped
        int a[6] = {0, 0, 0, 0, 0, 0};
        int b[6] = {0, 0, 0, 0, 0, 0};
        int c[6] = {0, 0, 0, 0, 0, 0};
        int d[6] = {0, 0, 0, 0, 0, 0};
        int e[6] = {0, 0, 0, 0, 0, 0};
        int f[6] = {0, 0, 0, 0, 0, 0};
        int g[6] = {0, 0, 0, 0, 0, 0};
        
        printf("Let's play Connect Four in a line\n");
        printBoard(a, b, c, d, e, f, g);
        
        int count = 0; //used to keep track of turns
        int full; //checks to see if an array is full
        while (win == 0 && count < 42) //loop until someone wins or a tie happens
        {
            if (count % 2 == 0) //player 1
            {
                count++;
                printf("Player 1: Which column would you like to add an 'X' ?\n");
                char column;
                int correctInput = 0;
                while (correctInput == 0) //get a column and check for fullness. If not full, add it
                {
                    column = tolower(getchar()); //get the column
                    flush(); //flush input field
                    if (column == 'a' || column == 'b' || column == 'c' || column == 'd' || column == 'e' || column == 'f' || column == 'g')
                    {
                        if (column == 'a')//check to see if the column is full. If yes, run again. If no, add it
                        {
                            full = checkColumn(a);
                            if (full == -1)
                                printf("That column is full\n");
                            else
                            {
                                correctInput = 1; //we have a correct input
                                a[full] = 1;
                            }
                        }
                        else if (column == 'b')//check to see if the column is full
                        {
                            full = checkColumn(b);
                            if (full == -1)
                                printf("That column is full\n");
                            else
                            {
                                correctInput = 1;
                                b[full] = 1;
                            }
                        }
                        else if (column == 'c')//check to see if the column is full
                        {
                            full = checkColumn(c);
                            if (full == -1)
                                printf("That column is full\n");
                            else
                            {
                                correctInput = 1;
                                c[full] = 1;
                            }
                        }
                        else if (column == 'd')//check to see if the column is full
                        {
                            full = checkColumn(d);
                            if (full == -1)
                                printf("That column is full\n");
                            else
                            {
                                correctInput = 1;
                                d[full] = 1;
                            }
                        }
                        else if (column == 'e')//check to see if the column is full
                        {
                            full = checkColumn(e);
                            if (full == -1)
                                printf("That column is full\n");
                            else
                            {
                                correctInput = 1;
                                e[full] = 1;
                            }
                        }
                        else if (column == 'f')//check to see if the column is full
                        {
                            full = checkColumn(f);
                            if (full == -1)
                                printf("That column is full\n");
                            else
                            {
                                correctInput = 1;
                                f[full] = 1;
                            }
                        }
                        else if (column == 'g')//check to see if the column is full
                        {
                            full = checkColumn(g);
                            if (full == -1)
                                printf("That column is full\n");
                            else
                            {
                                correctInput = 1;
                                g[full] = 1;
                            }
                        }
                    }
                    else
                        printf("Invalid Entry\n");
                }
                //print the board
                printBoard(a, b, c, d, e, f, g);
                //check for win
                win = checkWin(a, b, c, d, e, f, g, 1);
                if (win == 1)
                {
                    printf("Player 1 is a WINNER\n");
                    printf("Player 2 is a LOSER\n");
                }
            }
            else //player 2
            {
                count++;
                printf("Player 2: Which column would you like to add an 'O' ?\n");
                char column;
                int correctInput = 0;
                while (correctInput == 0)
                {
                    column = tolower(getchar()); //get the column
                    flush(); //flush input field
                    if (column == 'a' || column == 'b' || column == 'c' || column == 'd' || column == 'e' || column == 'f' || column == 'g')
                    {
                        if (column == 'a')//check to see if the column is full. If yes, run again. If no, add it
                        {
                            full = checkColumn(a);
                            if (full == -1)
                                printf("That column is full\n");
                            else
                            {
                                correctInput = 1; //we have a correct input
                                a[full] = 2;
                            }
                        }
                        else if (column == 'b')//check to see if the column is full
                        {
                            full = checkColumn(b);
                            if (full == -1)
                                printf("That column is full\n");
                            else
                            {
                                correctInput = 1;
                                b[full] = 2;
                            }
                        }
                        else if (column == 'c')//check to see if the column is full
                        {
                            full = checkColumn(c);
                            if (full == -1)
                                printf("That column is full\n");
                            else
                            {
                                correctInput = 1;
                                c[full] = 2;
                            }
                        }
                        else if (column == 'd')//check to see if the column is full
                        {
                            full = checkColumn(d);
                            if (full == -1)
                                printf("That column is full\n");
                            else
                            {
                                correctInput = 1;
                                d[full] = 2;
                            }
                        }
                        else if (column == 'e')//check to see if the column is full
                        {
                            full = checkColumn(e);
                            if (full == -1)
                                printf("That column is full\n");
                            else
                            {
                                correctInput = 1;
                                e[full] = 2;
                            }
                        }
                        else if (column == 'f')//check to see if the column is full
                        {
                            full = checkColumn(f);
                            if (full == -1)
                                printf("That column is full\n");
                            else
                            {
                                correctInput = 1;
                                f[full] = 2;
                            }
                        }
                        else if (column == 'g')//check to see if the column is full
                        {
                            full = checkColumn(g);
                            if (full == -1)
                                printf("That column is full\n");
                            else
                            {
                                correctInput = 1;
                                g[full] = 2;
                            }
                        }
                    }
                    else
                        printf("Invalid Entry\n");
                }
                //check column and add it if possible
                //print the board
                printBoard(a, b, c, d, e, f, g);
                //check for win
                win = checkWin(a, b, c, d, e, f, g, 2);
                if (win == 1)
                {
                    printf("Player 2 is a WINNER\n");
                    printf("Player 1 is a LOSER\n");
                }
            }
        }
        
        if (count == 42)
            printf("TIE GAME. You should try again\n");
        
        //check if players want to play again
        int answer = 0;
        while (answer == 0)
        {
            printf("Do you want to play again (y/n)?\n");
            char val;
            val = getchar();
            flush();
            if (val == 'y')
                answer = 1;
            else if (val == 'n')
            {
                answer = 1;
                play = 1;
            }
        }
        count = 0; //reset count
        win = 0; //reset win
    }
    return 0;
}
