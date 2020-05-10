#pragma once

#include <queue>
#include <vector>
#include <string>
#include <time.h>
#include <cstdlib>
#include "losescreen.cpp"


int x=80,y=30;// wide,high of the map
std::string move;

struct Body{
    int x=0;
    int y=0;
};//to store the first and latest snake position

struct Block{
    bool is_snake=false;
    bool is_apple=false;
    bool is_wall=false;
    int nextx=-1,nexty=-1;
};//Block of map

class Map{
    Block Blocks[200][200];
    Body back,frount;
    int position=3;
    public:
    //judgeing functions
    bool is_snake(int x,int y){
        return Blocks[x][y].is_snake;
    }
    bool is_apple(int x,int y){
        return Blocks[x][y].is_apple;
    }
    bool is_wall(int x,int y){
        return Blocks[x][y].is_wall;
    }


    //setting functions
    int set_apple(int fx,int fy){
        if(is_wall(fx,fy)||is_snake(fx,fy)||is_apple(fx,fy))set_apple(fx+1,fy-1);
        Blocks[fx][fy].is_apple=true;
        return 0;
    }
    
    int set_snake(int fx,int fy){
        if(is_snake(fx,fy)||is_wall(fx,fy))losescreen();
        if(is_apple(fx,fy)){
            set_air(fx,fy);
            push();
            if(set_apple(rand()%x,rand()%y))return -100;
        }
        Blocks[fx][fy].is_snake=true;
        return 0;
    }

    int set_air(int x,int y){
        if(is_wall(x,y))return -50;
        if(is_snake(x,y)){
            Blocks[x][y].is_snake=false;
            Blocks[x][y].nextx=-1;
            Blocks[x][y].nexty=-1;
        }
        Blocks[x][y].is_apple=false;
        return 0;
    }
    //search next snake
    Body search(int x,int y){
        Body bod;
        bod.x=Blocks[x][y].nextx;
        bod.y=Blocks[x][y].nexty;
        return bod;
    }


    //snake ctrl
    Map(){
        for(int i=0;i<x;i++){
            Blocks[i][0].is_wall=true;
            Blocks[i][y-1].is_wall=true;
        }
        for(int i=0;i<y;i++){
            Blocks[0][i].is_wall=true;
            Blocks[x-1][i].is_wall=true;
        }
        for(int i=1;i<4;i++){
            set_snake(i,1);
            Blocks[i][1].nextx=i+1;
            Blocks[i][1].nexty=1;
        }
        set_snake(4,1);
        back.x=1;
        back.y=1;
        frount.x=4;
        frount.y=1;
        set_apple(rand()%x,rand()%y);
    }

    void pop(){
        int tx=back.x;
        int ty=back.y;
        back=search(back.x,back.y);
        set_air(tx,ty);
    }

    void push(){
        push(position);
    }

    void push(int pos){
        switch (pos){
            case 0:
                set_snake(frount.x,frount.y-1);
                Blocks[frount.x][frount.y].nextx=frount.x;
                Blocks[frount.x][frount.y].nexty=frount.y-1;
                frount.y--;
                position=0;
                break;
            case 1:
                set_snake(frount.x,frount.y+1);
                Blocks[frount.x][frount.y].nextx=frount.x;
                Blocks[frount.x][frount.y].nexty=frount.y+1;
                frount.y++;
                position=1;
                break;
            case 2:
                set_snake(frount.x-1,frount.y);
                Blocks[frount.x][frount.y].nextx=frount.x-1;
                Blocks[frount.x][frount.y].nexty=frount.y;
                frount.x--;
                position=2;
                break;
            case 3:
                set_snake(frount.x+1,frount.y);
                Blocks[frount.x][frount.y].nextx=frount.x+1;
                Blocks[frount.x][frount.y].nexty=frount.y;
                frount.x++;
                position=3;
                break;
            default:
                std::cerr<<"position error";
                exit(-10);
                break;
        }
    }
};