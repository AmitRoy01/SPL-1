#include <bits/stdc++.h>
#include <graphics.h>
#include "HEADER.h"

using namespace std;

void Linear_Graph()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Define the linear equation coefficients
    float a1, b1, c1, a2, b2, c2;
    int lineStyle = 3; // Set the line style to thick

    int maxX = getmaxx();
    int maxY = getmaxy();
    int midX = maxX / 2;
    int midY = maxY / 2;

    cout << "Enter the coefficients a, b, and c of the first linear equation (ax + by = c): ";
    cin >> a1 >> b1 >> c1;
    cout << "Enter the coefficients a, b, and c of the second linear equation (ax + by = c): ";
    cin >> a2 >> b2 >> c2;

    // Draw the x and y axes
    line(0, midY, maxX, midY);
    line(midX, 0, midX, maxY);

    setlinestyle(lineStyle, 0, 1); // Set the line style to thick

    float m1 = (-(0.5*a1) /(0.5* b1));
    float t1 = 10*(c1 / b1);
    float m2 = (-(0.5*a2) /(0.5* b2));
    float t2 = 10*(c2 / b2);

    // Plot the linear equation graphs
    for (int x = -midX; x < midX; ++x) {
        int y1 = (m1 * x + t1);
        int y2 = (m2 * x + t2);
        putpixel(midX + x, midY - y1, YELLOW);
        putpixel(midX + x, midY - y2, GREEN);
        delay(0.5);
    }

    setlinestyle(0, 0, 1); // Reset the line style to default

    // Calculate the intersection point
    float x = (c1 * b2 - c2 * b1) / (a1 * b2 - a2 * b1);
    float y = (a1 * c2 - a2 * c1) / (a1 * b2 - a2 * b1);

    // Print the intersection point
    char resultStr[100];
    sprintf(resultStr, "Intersection Point: (x = %.2f, y = %.2f)", x, y);
    outtextxy(midX + 10, midY + 10, resultStr);

    delay(100000);  // Wait for 10 seconds before closing the window
    closegraph();
    getch();
}
