/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Players.h
 * Author: sterl
 *
 * Created on December 17, 2023, 1:15 PM
 */

#ifndef PLAYERS_H
#define PLAYERS_H

template<class T>
class Player{
private:
    T *plyrDce;
    const T NUMDCE = 3;
public:
    Player();
    ~Player(){
        delete [] plyrDce;
    };
    
    T *getDice();
    void sortDce();
    void prntDce();
};

#endif /* PLAYERS_H */

