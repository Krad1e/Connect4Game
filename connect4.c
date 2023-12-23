//Alex Brousse
//Connect 4

#include <stdio.h>

char getCounter( void );
char game( char, char );
void printBoard( void );
int turn( char, int );
int victory( char, int );

char board[6][7] = {{'-','-','-','-','-','-','-'},

    {'-','-','-','-','-','-','-'},

    {'-','-','-','-','-','-','-'},

    {'-','-','-','-','-','-','-'},

    {'-','-','-','-','-','-','-'},

    {'-','-','-','-','-','-','-'}}; 

int main( void )
{

    printf( "\nPlayer 1, enter your letter(A-Z): " ); //accepts player 1 letter
    char store1 = getCounter(); //sends letter to getCounter for errorcheck
    getchar(); 

    printf( "\nPlayer 2, enter your letter(A-Z): " ); //accepts player 2 letter
    char store2 = getCounter(); //sends letter to getCounter for errorcheck
    getchar();  


    char victory = game(store1, store2);
    printf( "\n\nPlayer %c won the game\n", victory );  

    return 0; 
} //end function main 

//function getCounter begins 
char getCounter( void ) // function proto accepts and error checks player 1&2 input
{

    char p1;  

    scanf( "%c", &p1 );
    while ( p1 > 90 || p1 < 65 ) 
    {
        printf( "\nError! Must be uppcase A-Z." );
        scanf( "%c", &p1 );
    } //end while 

    return p1; 
} // end function getCounter

// function game begins
char game( char store1, char store2 )
{
    int returnval = 0;
    int choice;
    char temp; 
    char currentplayer; 

    while(1)
    {
        printf( "\n\n%c, your turn. Enter a column to drop into: ", store1 );  // asks player 1 for move
        scanf( "%d", &choice );
        getchar();
        while( choice < -1 || choice > 6 ) //error checks move 
        {
            printf( "\nError! Column does not exist. %c, re-enter a column: ", store1 ); //asks for re-entry
            scanf( "%d", &choice ); 
        }

        while( board[0][choice] != '-' ) { //ensures  entry is  on a tile with a hyphen
            printf( "\nInvalid entry, please re-enter your choice" ); //asks for re-entry
            scanf( "%d", &choice );  
        }

        temp  = store1; 
        returnval = turn( temp, choice ); //calls function turn 
        printBoard(); //calls printBoard
        if( returnval == 1 )
        {
            return currentplayer = store1;
        }


        printf( "\n\n%c, your turn. Enter a column to drop into: ", store2 ); //asks player 2 for move
        scanf( "%d", &choice ); 
        while( choice < -1 || choice > 6 ) //error checks move
        {
            printf( "\nError! Column does not exist. %c, re-enter a column: ", store2 ); //asks for re-entry
            scanf( "%d", &choice ); 
        }

        while( board[0][choice] != '-' ) { //ensures entry is not on a tile with a hyphen
            printf( "\nInvalid entry, please re-enter your choice" ); //asks for re-entry
            scanf( "%d", &choice );  
        }

        temp = store2; 
        returnval = turn( temp, choice );  //calls function turn
        printBoard(); //calls printBoard
        if( returnval == 1 )
        {
            return currentplayer = store2;
        }
    }

    return currentplayer;
}

// function printBoard begins
void printBoard( void )
{

    int r = 0;
    int c = 0; 

    for ( r = 0; r < 6; r++ )
    {

        printf( "\n" ); 
        printf( "[" );
        for ( c = 0; c < 7; c++ ) 
        {
            printf ( " %c ", board[r][c] );
        }     
        printf("]\n" );
    }          
}         

//functon turn begins 
int turn( char playerpos, int column )
{
    int row = 5; 

    while ( row >= 0 )
    { 
        if (board[row][column] == '-' )
        {
            board[row][column] = playerpos;

            return victory( playerpos, column );
        } 
        else
        {
            row--;
        }

    } 

    return victory( playerpos, column );
    // return 0; 
} 

//function victory begins
int victory( char player, int column )
{

    int i, row;
    int count = 0;

    for ( i = 0; i < 6; i++ ) //checks up and down column
    {

        if( board[i][column] == player )  //player letter matches 
        {
            count++;
        }

        if( count == 4 ) 
        {  

            return 1;      //return win condition if player hits 4 
        }
        if ( board[i][column] != player )
        {
            count = 0; 
        } 
    }

    count = 0;
    i = 0; 

    while( board[i][column] == '-' )
    {
        i++;
    }

    row = i; 

    for ( i = 0; i < 6; i++ ) //this loop will check down column value passed to the function to ID which row being verified
    {

        if ( board[row][i] == player ) //player letter matches
        {
            count++;
        }
        if ( count == 4 )
        {
            return 1;
        }
        if ( board[row][i] != player )
        {
            count = 0;
        }
    }
    return 0;
} // end of victory 

