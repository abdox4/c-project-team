#include "my_plane.h"
#include "Game.h"
my_plane::my_plane(Game* pGame2):GameObject(pGame2, RefPoint, width, height, RED, RED),
pWind1(pGame2->getWind()){
}

void my_plane::draw() const {
    pWind1->SetBrush(Maincolor);
    pWind1->SetPen(Maincolor);
    //main body
    const double xbody = 0.125;
    pWind1->DrawRectangle(RefPoint.x - (xbody * size), RefPoint.y - size, RefPoint.x + (xbody * size), RefPoint.y + size, FILLED);
    //wings
    const double ywing = 0.65;
    pWind1->DrawTriangle(RefPoint.x, RefPoint.y - ywing * size, RefPoint.x, RefPoint.y, RefPoint.x + size, RefPoint.y);
    pWind1->DrawTriangle(RefPoint.x, RefPoint.y - ywing * size, RefPoint.x, RefPoint.y, RefPoint.x - size, RefPoint.y);
    //tail wing
    const double tailfactor = 0.5;
    pWind1->DrawTriangle(RefPoint.x, RefPoint.y + size, RefPoint.x + tailfactor * size, RefPoint.y + size, RefPoint.x, RefPoint.y + tailfactor * size);
    pWind1->DrawTriangle(RefPoint.x, RefPoint.y + size, RefPoint.x - tailfactor * size, RefPoint.y + size, RefPoint.x, RefPoint.y + tailfactor * size);
}

void my_plane::move(){
    pWind1->GetKeyPress(key);
    if (fuel > 0) {
        if (key == 'a') {
            RefPoint.x -= 40;
            fuel -= 2;
        }
        if (key == 'd') {
            RefPoint.x += 40;
            fuel -= 2;
        }
        if (key == 'w') {
            RefPoint.y -= 30;
            fuel -= 2;
        }
        if (key == 's') {
            RefPoint.y += 30;
            fuel -= 2;
        }
    }
    draw();
}
