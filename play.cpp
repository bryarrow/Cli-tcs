#pragma once

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <queue>
#include "getf.cpp"
#include "Map.cpp"
#include "systemset"
#include "losescreen.cpp"
#if SYS==0
#include <conio.h>
#endif
#if SYS==1
#include "kbhit.cpp"
#endif



void clean(bool i){
    if(!i)system("cls");
    else system("clear");
    //printf("\033[2J");
}

void display(Map map){
    clean(SYS);
    for(int j=0;j<y;j++){
        for(int i=0;i<x;i++){
            if(map.is_wall(i,j))
                std::cout<<"#";
            else if(map.is_apple(i,j))
                std::cout<<"$";
            else if(map.is_snake(i,j))
                std::cout<<":";
            else 
                std::cout<<" ";
        }
        std::cout<<std::endl;
    }
}

void play(){
    srand((unsigned int)time(NULL));
    Map map;
    getch();
    while(1){
        display(map);
        while(!kbhit()){
            map.pop();
            map.push();
            display(map);
        }
        bry::getf(3);
        if(move=="\033[A"){
            map.pop();
            map.push(0);
        }else 
        if(move=="\033[B"){
            map.pop();
            map.push(1);
        }else
        if(move=="\033[C"){
            map.pop();
            map.push(3);
        }else
        if(move=="\033[D"){
            map.pop();
            map.push(2);
        }
    }
}