#include <bits/stdc++.h>
#include <graphics.h>
#include "HEADER.h"

using namespace std;

void Linear_Graph()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Define the linear equation coefficients
    float a, b,c;
    //std::cout << "Enter the coefficients m and c of the linear equation (y = mx + c): ";
//    std::cin >> m >> c;

    int maxX = getmaxx();
    int maxY = getmaxy();
    int midX = maxX / 2;
    int midY = maxY / 2;

    for(int i=0;i<2;i++){
    cout << "Enter the coefficients a,b & c of  "<<i+1<<" th linear equation (ax + by = c): ";
    cin >> a >> b>>c;

    // Draw the x and y axes
    line(0, midY, maxX, midY);
    line(midX, 0, midX, maxY);

    float m = (-0.25*a/(0.25*b));
    float t =10*(c/b);
    // Plot the linear equation graph
    for (int x = -midX; x < midX; ++x)
    {
        int y = (m * x + t);
        putpixel(midX + x, midY - y, YELLOW);
        delay(0.5);
    }
    }
    delay(10000);  // Wait for 10 seconds before closing the window
    closegraph();
    getch();
}
