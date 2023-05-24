#include <bits/stdc++.h>
#include <graphics.h>
#include "HEADER.h"

using namespace std;

void Polynomial_Graph()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int maxX = getmaxx();
    int maxY = getmaxy();

    // Draw the x and y axes
    line(0, maxY / 2, maxX, maxY / 2);
    line(maxX / 2, 0, maxX / 2, maxY);

    float a, b, c;
    std::cout << "Enter the coefficients a, b, and c of the quadratic equation (ax^2 + bx + c): ";
    std::cin >> a >> b >> c;

    for (int x = -maxX / 2; x <= maxX / 2; ++x) {
        float y = 0.25*a * pow(x, 2) + 0.25*b * x + 0.25*c;
        putpixel(maxX / 2 + x, maxY / 2 - static_cast<int>(y), YELLOW);
        delay(0.0025);
    }

    delay(100000);
    closegraph();
    getch();
}
