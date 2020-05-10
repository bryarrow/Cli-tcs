#pragma once

#include <queue>
#include <vector>
#include <string>

bool nosetted=true;
int x=80,y=40;// wide,high of the map

int applex,appley;

struct Body{
    int x=0;
    int y=0;
};

std::queue<Body> snake;
int position=0;

std::string move;