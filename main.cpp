/*
    Hello Guys im RedMad :$, this my secund C++ Project!

    Simple Tic Tac Toe Game with many features!

    
    Features:

        1- Player vs Player Mode!
        2- Player vs Computer Mode!
        3- Simple UI Menu!


    i hope this code help some people!


    - RedMad :$
*/

#include <iostream>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <conio.h>

using namespace std;

using namespace this_thread;

#define clear system("clear");



// some Global Variabels ! 

const int LIMIT_SIZE = 3;

char board[LIMIT_SIZE][LIMIT_SIZE] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

char player = 'X';

//################################################################################//

class Tic{


    public:
        
        // This Function Generate Random Number!
        int gen_random(int max, bool computer=false) {

            if(!computer) {

                srand(time(0));

                int random_number = 1 + rand() % max;


                return random_number;

            }


            else{


                srand(time(0));

                int random_number = rand() % max;


                return random_number;


            }


        }

        // This Function reset the board and the player to defult values!
        void setup(bool computer = false) {

            if(computer == false) {

                player = 'X';

                board[0][0] = '1';
                board[0][1] = '2';
                board[0][2] = '3';

                board[1][0] = '4';
                board[1][1] = '5';
                board[1][2] = '6';

                board[2][0] = '7';
                board[2][1] = '8';
                board[2][2] = '9';

            }


            else {


                board[0][0] = '1';
                board[0][1] = '2';
                board[0][2] = '3';

                board[1][0] = '4';
                board[1][1] = '5';
                board[1][2] = '6';

                board[2][0] = '7';
                board[2][1] = '8';
                board[2][2] = '9';


            }

        }


        // This Function Draw The board!
        void draw_board() {
            clear;

            banner();

            cout << "\t -------------\n";
            for (int i = 0; i < LIMIT_SIZE; i++){
                cout << "\t | ";
                for(int j = 0; j < LIMIT_SIZE; j++){

                    cout << board[i][j];
                    cout << " | ";

                }

                cout << endl;
                cout << "\t -------------\n";
            }

            cout << "\n\n";

        }

        // print the banner!
        void banner() {

            cout << "╔╦╗┬┌─┐  ╔╦╗┌─┐┌─┐  ╔╦╗┌─┐┌─┐\n";
            cout << " ║ ││     ║ ├─┤│     ║ │ │├┤ \n";
            cout << " ╩ ┴└─┘   ╩ ┴ ┴└─┘   ╩ └─┘└─┘\n";
            cout << "                      By RedMad :$ v1.0\n";

            cout << "\n\n";

        }


        // The Main Menu function!
        void menu() {

            clear;

            banner();

            cout << "Choose Game Mode: \n\n";

            cout << "[1] - Player vs Player\n\n";
            cout << "[2] - Player vs Computer\n\n";
            cout << "[0] - Exit\n\n";

            char c = getch();

            while(true) {


                switch(c) {

                    case '1': 
                        draw_board(), play(); 
                        break;


                    case '2': 
                        draw_board(), play_computer(); 
                        break;

                    case '0': exit(1);


                    }


                }


        }

        // Change The Player Symbol every Turn!
        void change_player() {

            if(player == 'X')

                player = 'O';

            else
                player = 'X';

        }


        // This Function Check The winner or Loser or Equals!
        char check_winner() {

            int counter = 0;

            // Checking Rows player < X > !

            if(board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') return 'X';
            else if(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') return 'X';
            else if(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') return 'X';


            //Checking Columns player < X > !
            if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') return 'X';
            else if(board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') return 'X';
            else if(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') return 'X';


            //Checking Dialogs player < X > !
            if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') return 'X';
            else if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') return 'X';


            // Checking Rows player < O > !

            if(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') return 'O';
            else if(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') return 'O';
            else if(board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') return 'O';


            //Checking Columns player < O > !
            if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') return 'O';
            else if(board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') return 'O';
            else if(board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') return 'O';


            //Checking Dialogs player < O > !
            if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') return 'O';
            else if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') return 'O';
            

            for(int i = 0; i < LIMIT_SIZE; i++) {

                for(int j = 0; j < LIMIT_SIZE; j++) {

                    if(board[i][j] == 'X' || board[i][j] == 'O')
                        counter++;

                }

            }

            if (counter == 9) return 'E';

            return '0';
            
        }


        // This Function choose the computer choice randomly!
        void computer_choice(){

            char computer_sympol = 'O';
            bool run = true;
            int counter = 0;


            for(int i = 0; i < LIMIT_SIZE; i++){

                for(int j = 0; j < LIMIT_SIZE; j++){

                    if(board[i][j] == 'X' || board[i][j] == 'O') counter++;

                }

            }


            if (check_winner() == '0'){


                while(run){

                    int computer_input_R = gen_random(LIMIT_SIZE, true);
                    int computer_input_C = gen_random(LIMIT_SIZE, true);
                    

                    if(counter != 9){


                        if(board[computer_input_R][computer_input_C] != 'X' && board[computer_input_R][computer_input_C] != 'O'){
                                
                            board[computer_input_R][computer_input_C] = computer_sympol;
                            run = false;
                            

                        }

                        else {
                            computer_input_R = gen_random(LIMIT_SIZE, true);
                            computer_input_C = gen_random(LIMIT_SIZE, true);

                        }


                    }


                    }


            }
            
           

            
        }

        // This Function for < Player vs Computer > Mode!
        void play_computer() {

            player = 'X';  

            while(check_winner() == '0'){


                cout << "Enter position ( " << player << " )";

                char c = getch();

                for(int i = 0; i < LIMIT_SIZE; i++) {

                    for(int j = 0; j < LIMIT_SIZE; j++) {

                        if(board[i][j] == c && board[i][j] != 'X' && board[i][j] != 'O') board[i][j] = player;
                    }

                }

                draw_board();

                cout << "Computer Turn (O) !\n\n";

                computer_choice();

                sleep_for(2s);

                draw_board();
     
            }

            if(check_winner() == 'E') cout << "No Winner (Equals) !" << endl, again_play(true);
            else cout << "Winner is ( " << check_winner() << " ) !" << endl, again_play(true);

        }

        
        // This Function for < Player vs Player > Mode !
        void play() {

            

            while(check_winner() == '0'){

                cout << "Enter position ( " << player << " )";

                char c = getch();                


                for(int i = 0; i < LIMIT_SIZE; i++) {

                    for(int j = 0; j < LIMIT_SIZE; j++) {

                        if(board[i][j] == c && board[i][j] != 'X' && board[i][j] != 'O')
                            board[i][j] = player;
 

                    }

                }
                
                draw_board();
                change_player();

                
            }

            if(check_winner() == 'E') cout << "No Winner (Equals) !" << endl, again_play(false);
            else cout << "Winner is ( " << check_winner() << " ) !" << endl, again_play(false);

        }


        // This Function ask the player for play again or not && reset the defult values! 
        void again_play(bool computer=false) {

            if(computer == false) {

                cout << "\n\nPlay Again? (y/n)";

                char c = getch();


                while(true) {


                    switch(c) {

                        case 'y':
                            setup(false);
                            draw_board(),play();
                            break;

                        case 'n':
                            setup(false);
                            menu();
                            break;

                    }

                }  


            }

            else {

                cout << "\n\nPlay Again? (y/n)";

                char c = getch();


                while(true) {


                    switch(c) {

                        case 'y':
                            setup(true);
                            draw_board(),play_computer();
                            break;

                        case 'n':
                            setup(true);
                            menu();
                            break;


                    }

                }   
                

            }


        }
};




int main(int argc, char *argv[]){
    
 
    Tic tic_obj;

    tic_obj.menu();

    return 0;
}
