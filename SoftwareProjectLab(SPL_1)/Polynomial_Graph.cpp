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

    int lineStyle = 3; // Set the line style to thick
    setlinestyle(lineStyle, 0, 1); // Set the line style to thick

    float a, b, ch;
    cout << "Enter the coefficients a, b, and c of the quadratic equation (ax^2 + bx + c): ";
    cin >> a >> b >> ch;

    float discriminant = pow(b, 2) - 4 * a * ch;

    if (discriminant >= 0) {
        float x1 = (-b + sqrt(discriminant)) / (2 * a);
        float x2 = (-b - sqrt(discriminant)) / (2 * a);

        float y1 = 0;
        float y2 = 0;

        if (a != 0) {
            y1 = a * pow(x1, 2) +b * x1 + ch;
            y2 = a * pow(x2, 2) + b * x2 + ch;
        }

        if (y1 >= 0 && y2 >= 0) {
            // Plot the quadratic equation graph with bold lines
            for (int x = -maxX / 2; x <= maxX / 2; ++x) {
                float y = 0.25 * a * pow(x, 2) + 0.25 * b * x + 0.25 * ch;
                putpixel(maxX / 2 + x, maxY / 2 - static_cast<int>(y), YELLOW);
                putpixel(maxX / 2 + x, maxY / 2 - static_cast<int>(y) + 1, YELLOW); // Make the line bold
                putpixel(maxX / 2 + x, maxY / 2 - static_cast<int>(y) - 1, YELLOW); // Make the line bold
                delay(0.25);
            }

            setlinestyle(0, 0, 1); // Reset the line style to default

            // Plot the intersection points on the graphics window
            putpixel(maxX / 2 + static_cast<int>(x1), maxY / 2, RED);
            putpixel(maxX / 2 + static_cast<int>(x2), maxY / 2, RED);

            // Print the intersection points on the graphics window
            char resultStr[100];
            sprintf(resultStr, "Intersection Points: (%.2f, 0) and (%.2f, 0)", x1, x2);
            outtextxy(maxX / 2 + 10, maxY / 2 - 20, resultStr);
        }
    }

    delay(100000);
    closegraph();
    getch();
}
