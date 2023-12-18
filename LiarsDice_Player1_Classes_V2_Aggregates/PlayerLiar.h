/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   PlayerLiar.h
 * Author: sterl
 *
 * Created on December 17, 2023, 2:26 PM
 */

#ifndef PLAYERLIAR_H
#define PLAYERLIAR_H

class PlayerLiar{
private:
    char liar;
    bool isLiar;
public:
    void inLiar();
    char getLiar();
    bool tOrF1(int *, int*, int, int, int);
    bool tOrF2(int *, int *, int, int, int);
};

#endif /* PLAYERLIAR_H */

