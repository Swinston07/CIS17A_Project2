/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   PlayCall.h
 * Author: sterl
 *
 * Created on December 17, 2023, 6:53 PM
 */

#ifndef PLAYCALL_H
#define PLAYCALL_H

#include "Player.h"
#include "PlayerCalls.h"

template<class T>
class PlayCall{
private:
    Player<T> *player;
    PlayerCalls *plyrCls;
public:
    int *getDice(){
        return player->getDice();
    }
    
    int gCall1(){
        return plyrCls->gCall1();
    }
    
    int gCall2(){
        return plyrCls->gCall2();
    }
    
    int gCall3(){
        return plyrCls->gCall3();
    }
    
    int gCall4(){
        return plyrCls->gCall4();
    }
    
    void prntDce(){
        player->prntDce();
    }
    
    void calls12(){
        plyrCls->calls12();
    }
    
    void calls34(){
        plyrCls->calls34();
    }
    
    PlayCall(){
        player = new T;
        plyrCls - new PlayerCalls;
    }
};

#endif /* PLAYCALL_H */

