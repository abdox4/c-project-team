#pragma once
#include <iostream>
#include "CMUgraphicsLib\CMUgraphics.h"
#include "GameObject.h"
class Game;
class my_plane :public GameObject{
protected:
	window* pWind1;
	int size = 100;
	color Maincolor = RED;
	int fuel = 100;
	char key = '`';
public:
	my_plane(Game* pGame2);
	virtual void draw() const override;
	virtual void move()override;
};
