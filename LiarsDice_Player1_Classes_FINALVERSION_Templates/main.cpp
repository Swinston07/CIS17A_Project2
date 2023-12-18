/*
 * File:   main.cpp
 * Author: Sterling Winston 2459130 & Joseph Halman 2821276
 * Created on June 1, 2023, 8:04PM
 *
 * Revise game to utilize structures and a 2d dynamic array passed through a 
 * function
 */

 //System Libraries
#include <iostream> // Input/Output library
#include <iomanip>  // Format library
#include <cmath>    // Math library
#include <fstream>  // File library
#include <cstdlib>  // Time library
#include <ctime>    // Random nuber genreator

using namespace std;

//User Libraries
#include "PlayerLiar.h"

//Global Constants - Math/Physics/Chemistry/Conversions ONLY!!! 
//Structures

//Function Prototypes
void begTtle(int, int);

//Execution Begins Here
int main(int argc, char** argv){
    //Setting Random Number Seed Here
    srand(static_cast<int>(time(0)));

    //Declare All Variables Here
    int plyrs = 2;
    int dice = 3;
    PlayerLiar<int> playrs[plyrs];
    PlayerLiar<char> pLiar;
    
    int title,
        count1,
        count2;
    int *pDce;
    pDce = new int[plyrs];
    fstream dce;
    string p1, p2; // Player 1 and Player2.
    char again, // Play again or not
         choice;
    bool isLiar; // testing whether or not player is a liar.
    unsigned short height; // height of letter
    unsigned short width;  // width of letter
    
    begTtle(height,width);
    
    while(title <= 30){
        cout << "LIARS DICE ";
        title++;
    }
    
        cout << endl << "Do you want to play?" << endl;
        cout << "1 = Yes\n" << "2 = No\n";
            
        cin >> choice;
        switch(choice) {
            case '1': { cout << endl << "Lets Play" << endl;
        
                //Initialize Variables/Input Values
                    do {
                        cout << endl;
                        
                        p1 = "Player 1";
                        p2 = "Player 2";
                        
                        //Write binary file for dice
                        dce.open("dice.bin",ios::out|ios::binary);
                        for(int i = 0; i < plyrs; i++){
                            dce.write(reinterpret_cast<char *>
                                     (playrs[i].getDice()),(dice)*
                                     sizeof(playrs[i].getDice()));
                        }

                        //Display Output
                        cout<<"LAIRS DICE"<<endl;
                        cout<<"Lairs Dice is game where you have to find out "
                              "who is lying about the dice on the board"<<endl
                            <<endl;

                        cout<<"SUPPLIES"<<endl;
                        cout<<"* At least 2 players"<<endl;
                        cout<<"* And at least 3 dices"<<endl;
                        cout<<"* You can add more players before or during the "
                              "game"<<endl;
                        cout<<"* And you can use any type of dice (usually "
                              "D6s) and add how ever"
                            <<"many dice you want"<<endl<<endl;
                        cout<<"CALL"<<endl;
                        cout<<"A call is you saying how many dice of one face "
                              "is on the board"<<endl;
                        cout<<"The next persons call has to either be same "
                              "face but more dice or"
                            <<"different dice and face or raise the face and "
                              "the dice"<<endl<<endl;
                        cout<<"LAIR"<<endl;
                        cout<<"You can only call the pervious person a liar"
                            <<endl;
                        cout<<"A liar is when a call doesn't match the board"
                            <<endl;
                        cout<<"If someone is called a lair then everyone "
                              "reveals their dice"<<endl;
                        cout<<"If the person who called a liar is lying they "
                              "are out/lost"<<endl;
                        cout<<"If they are correct then the person who called "
                              "them a lair is lying"
                            <<"so they are out/lost"<<endl<<endl;
                        cout<<"STEPS"<<endl;
                        cout<<"Step 1: Make your bets"<<endl;
                        cout<<"Step 2: Role your dice and don't show your "
                              "enemy(s)"<<endl;
                        cout<<"Step 3: Player 1 makes a call then moves to "
                              "player 2"<<endl;
                        cout<<"Step 4(Optional): Add in player(s)"<<endl;
                        cout<<"Step 5: Next person calls them a liar or makes "
                              "a call"<<endl;
                        cout<<"Step 6: Repeat step 4/5"<<endl << endl;

                        
                        do{
                            //prntDce(pDce->plyrDce[0], dice);
                            playrs[0].prntDce();
                            cout << "Player 1 make your call:" << endl;
                            pLiar.calls12();
                        }while(pLiar.gCall1() < 1 || pLiar.gCall2() > 6);
                        cout << p1 <<" says " << pLiar.gCall1() << "," << pLiar.gCall2() 
                             << endl;
                        
                        //Players make their  first calls
                        do {
                            //Truth/Liar 
                            cout << p2 << " make your call" << endl;
                            cout << "Use 'L' if you think Player1 is lying and "
                                    "'T' if you think he "
                                 <<  "is telling the truth." << endl;
                            //cin >> chckLr.liar;
                            pLiar.inLiar();
                            

                                // Test to see if Player 1 is a liar
                                if (pLiar.getLiar() == 'l' || pLiar.getLiar() == 'L') {
                                    isLiar = pLiar.tOrF1(playrs[0].getDice(), 
                                                         playrs[1].getDice(),
                                                         dice, pLiar.gCall1(),
                                                         pLiar.gCall2());

                                    cout << "Play again? Y - Yes "
                                            "N - No" << endl;
                                    cin >> again;
                                    
                                }
                            // Code for if Player 2 doesn't call Player 1 a liar
                                else if (pLiar.getLiar() == 't' ||
                                         pLiar.getLiar() == 'T') {
                                    do{
                                        cout << "Player 2 make your call"
                                             << endl;
                                        
                                        //cin >> calls.call3 >> calls.call4;
                                        pLiar.calls34();
                                        
                                    }while(pLiar.gCall3() <= pLiar.gCall1() &&
                                           pLiar.gCall4() <= pLiar.gCall2() || 
                                           pLiar.gCall3() <  pLiar.gCall1()  || 
                                           pLiar.gCall4() > 6);

                                    cout << p2 <<" says " << pLiar.gCall3()<< "," 
                                         << pLiar.gCall4() << endl;

                                        cout << "Player 1 Make your call:" 
                                             << endl;
                                        cout << "Use 'L' if you think Player2 "
                                                "is lying and 'T' if you think "
                                                "he is telling the truth." 
                                             << endl;
                                        //cin >> chckLr.liar;
                                        pLiar.inLiar();

                                        // If Player 1 calls player 2 a liar
                                        if (pLiar.getLiar() == 'l' || pLiar.getLiar() 
                                                        == 'L') {                                            
                                        
                                            isLiar = pLiar.tOrF2(playrs[0].getDice(), 
                                                                 playrs[1].getDice(), 
                                                                 dice, pLiar.gCall3(),
                                                                 pLiar.gCall4());
                                                    
                                            cout << "Play again? Y - Yes "
                                                    "N - No" << endl;
                                            cin >> again;
                                        }
                                        
                                        // If player1 doesnt call player2 a iiar
                                        else if (pLiar.getLiar() == 't' || 
                                                 pLiar.getLiar() == 'T') {
                                            do{
                                                playrs[0].prntDce();
                                                cout << "Player 1 make your call.";
                                                //prntDce(pDce->plyrDce[0], dice);
                                                
                                                pLiar.calls12();                                               
                                                
                                                cout << p1 <<" says " 
                                                     << pLiar.gCall1()
                                                     << "," << pLiar.gCall2() 
                                                     << endl;
                                            }while(pLiar.gCall1() <= pLiar.gCall3() && 
                                                   pLiar.gCall2() <= pLiar.gCall4() ||
                                                   pLiar.gCall1() <  pLiar.gCall3() || 
                                                   pLiar.gCall2() > 6);
                                        }
                                }
                        }while(pLiar.getLiar() == 't' || pLiar.getLiar() == 'T');
                    }while (again == 'y' || again == 'Y');
            } break;
            default: cout << endl <<"Goodbye!" << endl;
        }
        dce.close();  
     
    //Exit Program
    return 0;
}

template<class T>
bool PlayerLiar<T>::tOrF2(int *a, int *b, int dice, int c1, int c2){
    int count = 0;
    
    for(int i = 0; i < dice; i++){
        if(a[i] == c2 || b[i] == c2){
            count++;
        }
    }
    
    count >= c1 ? isLiar = false : isLiar = true;
    
    (isLiar) ?  cout << "Player 2 is a liar. "
                       "Player "
                        "2 loses\n" :
                cout << "Player 2 is not a "
                        "liar. Player 1 loses\n";
        
    return isLiar;
}

template<class T>
bool PlayerLiar<T>::tOrF1(int *a, int *b, int dice, int c1, int c2){
    int count = 0;
    
    for(int i = 0; i < dice; i++){
        if(a[i] == c2 || b[i] == c2){
            count++;
        }
    }
    
    count >= c1 ? isLiar = false : isLiar = true;
    
    (isLiar) ?  cout << "Player 1 is a liar. "
                       "Player "
                        "1 loses\n" :
                cout << "Player 1 is not a "
                        "liar. Player 2 loses\n";
        
    return isLiar;
}

template<class T>
char PlayerLiar<T>::getLiar(){
    return liar;
}

template<class T>
void PlayerLiar<T>::inLiar(){
        cin >> liar;
}

int PlayerCalls::gCall4(){
    return call4;
}

int PlayerCalls::gCall3(){
    return call3;
}

void PlayerCalls::calls34(){
    cin >> call3 >> call4;
}

int PlayerCalls::gCall2(){
    return call2;
}

int PlayerCalls::gCall1(){
    return call1;
}

void PlayerCalls::calls12(){
    cin >> call1 >> call2;
}

template<class T>
void Player<T>::prntDce(){
    sortDce();
    for(int i = 0; i < NUMDCE; i++){
        cout << plyrDce[i] << endl;
    }
}

template<class T>
void Player<T>::sortDce(){
    for(int i = 0; i < NUMDCE - 1; i++){
        for(int j = 0; j < NUMDCE; j++){
            if(plyrDce[i] > plyrDce[j]){
                plyrDce[i] = plyrDce[i]^plyrDce[j];
                plyrDce[j] = plyrDce[i]^plyrDce[j];
                plyrDce[i] = plyrDce[i]^plyrDce[j];
            }
        }
    }
}

template<class T>
T *Player<T>::getDice(){
    return plyrDce;
}

template<class T>
Player<T>::Player(){
    plyrDce = new T[NUMDCE];
    
    for(int i = 0; i < NUMDCE; i++){
        plyrDce[i] = rand()%6+1;
    }
    
}

// Function Execution

void begTtle(int height, int width){
    //Title
    //Letter L
    height=7;
    //vertical line
    for (int i = 0; i < height - 1; i++) {
        cout<<"*"<<endl;
    }
    //horizontal line
    for (int i = 0; i < height; i++) {
        cout<<"*";
    }cout<<endl<<endl;
    
    //Letter I
    height=7;
    width=3;
    // top horizontal line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl;
    //vertical lines
    for (int i = 0; i < height; i++) {
        cout<<" ";
        cout<<"*"<<endl;
    }
    //bottom horizontal line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl<<endl;
    
    //Letter A
    height=7;
    width=7;
     //top line
    for (int i = 0; i < width; i++) {
        if (i == width / 2) {
           cout<<"*";
        } else {
           cout<<" ";
        }
    }cout<<endl;
    //top half of A
    for (int i = 0; i < height / 2 - 1; i++) {
        for (int j = 0; j < width; j++) {
            if (j == width / 2 - i - 1 || j == width / 2 + i + 1) {
                cout<<"*";
            } else {
                cout<<" ";
            }
        }cout<<endl;
    }
    //middle line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl;
    //bottom half of A
    for (int i = 0; i < height / 2 - 1; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1) {
                cout<<"*";
            } else {
                cout<<" ";
            }
        }cout<<endl<<endl;
    }
    //Letter R
    height=7;
    width=6;
     //top horizontal line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl;
    //top half of R
    for (int i = 0; i < height / 2 - 1; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1 || j == i + 1) {
               cout<<"*";
            } else {
               cout<<" ";
            }
        }cout<<endl;
    }
    //middle horizontal line
    for (int i = 0; i < width; i++) {
        if (i == 0 || i == width - 1) {
           cout<<"*";
        } else {
           cout<<" ";
        }
    }cout<<endl;
    //bottom half of R
    for (int i = height / 2; i < height - 1; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1 || j == height - i) {
              cout<<"*";
            } else {
               cout<<" ";
            }
        }cout<<endl;
    }
    //bottom horizontal line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl<<endl;
    
    //Letter S
    height=7;
    width=6;
     //top horizontal line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl;
    //top half of S
    for (int i = 0; i < height / 2 - 1; i++) {
        cout<<"*";
        for (int j = 0; j < width - 1; j++) {
            cout<<" ";
        }cout<<"*"<<endl;
    }
    //middle horizontal line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl;
    
    // bottom half of S
    for (int i = height / 2 + 1; i < height - 1; i++) {
        cout<<" ";
        for (int j = 0; j < width - 1; j++) {
            cout<<" ";
        }cout<<"*"<<endl;
    }
    //bottom horizontal line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl<<endl;
    
    //Letter D
    height=7;
    width=6;
    //top horizontal line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl;
    // top half of D
    for (int i = 0; i < height / 2 - 1; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1) {
                cout<<"*";
            } else {
                cout<<" ";
            }
        }cout<<endl;
    }
    //printing bottom half of D
    for (int i = height / 2; i < height - 1; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1) {
                cout<<"*";
            } else {
               cout<<" ";
            }
        }cout<<endl;
    }
    //bottom horizontal line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl<<endl;
    
    //Letter I
    height=7;
    width=3;
    // top horizontal line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl;
    //vertical lines
    for (int i = 0; i < height; i++) {
        cout<<" ";
        cout<<"*"<<endl;
    }
    //bottom horizontal line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl<<endl;
    
    //Letter C
    height=7;
    width=5;
    //top horizontal line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl;
    //top half of C
    for (int i = 0; i < height ; i++) {
        cout<<"*";
        for (int j = 0; j < width - 2; j++) {
            cout<<" ";
        }cout<<"*"<<endl;
    }
    
    // bottom horizontal line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl<<endl;
    
    //Letter E
    height=7;
    width=4;
    //top horizontal line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl;
    //top vertical line
    for (int i = 0; i < height / 2 - 1; i++) {
        cout<<"*"<<endl;
    }
    //middle horizontal line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl;
    // bottom vertical line
    for (int i = 0; i < height / 2 - 1; i++) {
        cout<<"*"<<endl;
    }
    //bottom horizontal line
    for (int i = 0; i < width; i++) {
        cout<<"*";
    }cout<<endl<<endl;
}