#pragma once

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <queue>
#include "getf.cpp"
#include "data.h"
#include "systemset"
#include "losescreen.cpp"

void clean(bool i){
    i=0?system("cls"):
    system("clear");
    //printf("\033[2J");
}

bool find(int i,int j){
    std::queue<Body> temp;
    while(!snake.empty()){
        if(snake.front().y==i && snake.front().x==j)return true;
        temp.push(snake.front());
        snake.pop();
    }
    while(!temp.empty()){
        snake.push(temp.front());
        temp.pop();
    }
    return false;
}

bool find_eh(int i,int j){
    std::queue<Body> temp;
    for(int i=0;!snake.empty();i++){
        if(snake.front().y==i && snake.front().x==j&&i<snake.size())return true;
        temp.push(snake.front());
        snake.pop();
    }
    while(!temp.empty()){
        snake.push(temp.front());
        temp.pop();
    }
    return false;
}

void start(){
    Body bo_start[4];
    bo_start[0].x=4;
    bo_start[1].x=3;
    bo_start[2].x=2;
    bo_start[3].x=1;
    position=3;
    snake.push(bo_start[3]);
    snake.push(bo_start[2]);
    snake.push(bo_start[1]);
    snake.push(bo_start[0]);
}

void display(){
    clean(SYS);
    int px=x;
    int py=y;
    for(int i=0;i<px;i++)std::cout<<"#";
    std::cout<<std::endl;
    for(int i=0;i<py-2;i++){
        std::cout<<"#";
        for(int j=1;j<px;j++){
            if(find(i,j))
                std::cout<<"\"";
            else
                std::cout<<" ";
        }
        std::cout<<"#"<<std::endl;
    }
    for(int i=0;i<px;i++)std::cout<<"#";
}

void freshapple(){
    applex=rand()%x;
    appley=rand()%y;
}

bool if_lose(){
    if(((snake.back().x==x||snake.back().x==0)&&(snake.back().y==y||snake.back().y==0))||find_eh(snake.back().y,snake.back().x))
        return true;
    return false;
}

bool ate(){

}



void play(){
    start();
    getch();
    while(1){
        display();
        move="   ";
        bry::get(3);
        Body add;
        if(move=="\033[A"){
            snake.pop();
            add=snake.back();
            add.y--;
            snake.push(add);
            position=0;
            if(if_lose())losescreen();
            if(ate())freshapple();
        }else 
        if(move=="\033[B"){
            snake.pop();
            add=snake.back();
            add.y++;
            snake.push(add);
            position=1;
            if(if_lose())losescreen();
            if(ate())freshapple();
        }else
        if(move=="\033[C"){
            snake.pop();
            add=snake.back();
            add.x++;
            snake.push(add);
            position=3;
            if(if_lose())losescreen();
            if(ate())freshapple();
        }else
        if(move=="\033[D"){
            snake.pop();
            add=snake.back();
            add.x--;
            snake.push(add);
            position=2;
            if(if_lose())losescreen();
            if(ate())freshapple();
        }else{
            snake.pop();
            add=snake.back();
            switch (position)
            {
            case 0:
                add.y--;
                break;
            case 1:
                add.y++;
                break;
            case 2:
                add.x--;
                break;
            case 3:
                add.x++;
                break;
            default:
                std::cerr<<"position error";
                exit(-10);
                break;
            }
            snake.push(add);
            if(if_lose())losescreen();
            if(ate())freshapple();
        }
    }
}