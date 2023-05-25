/*
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
*/

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

    float a, b, c;
    cout << "Enter the coefficients a, b, and c of the quadratic equation (ax^2 + bx + c): ";
    cin >> a >> b >> c;

    float discriminant = pow(b, 2) - 4 * a * c;

    if (a != 0) {
        if (discriminant > 0) {
            float x1 = (-b + sqrt(discriminant)) / (2 * a);
            float x2 = (-b - sqrt(discriminant)) / (2 * a);

            float y1 = a * pow(x1, 2) + b * x1 + c;
            float y2 = a * pow(x2, 2) + b * x2 + c;

            if (y1 >= 0 && y2 >= 0) {
                // Plot the quadratic equation graph with bold lines
                setlinestyle(lineStyle, 0, 3); // Set the line style to thick
                for (int x = -maxX / 2; x <= maxX / 2; ++x) {
                    float y = a * pow(x, 2) + b * x + c;
                    line(maxX / 2 + x, maxY / 2 - static_cast<int>(y), maxX / 2 + x + 1, maxY / 2 - static_cast<int>(y) + 1);
                    delay(0.25);
                }

                setlinestyle(0, 0, 1); // Reset the line style to default

                // Plot the intersection points on the graphics window
                putpixel(maxX / 2 + static_cast<int>(x1), maxY / 2, RED);
                putpixel(maxX / 2 + static_cast<int>(x2), maxY / 2, RED);

                // Print the intersection points on the graphics window
                char resultStr[100];
                sprintf(resultStr, "Intersection Points: (%.2f, %.2f) and (%.2f, %.2f)", x1, y1, x2, y2);
                outtextxy(maxX / 2 + 10, maxY / 2 - 20, resultStr);
            }
        }
        else if (discriminant == 0) {
            float x = -b / (2 * a);
            float y = a * pow(x, 2) + b * x + c;

            if (y >= 0) {
                // Plot the quadratic equation graph with bold lines
                setlinestyle(lineStyle, 0, 3); // Set the line style to thick
                for (int xi = -maxX / 2; xi <= maxX / 2; ++xi) {
                    float yi = a * pow(xi, 2) + b * xi + c;
                    line(maxX / 2 + xi, maxY / 2 - static_cast<int>(yi), maxX / 2 + xi + 1, maxY / 2 - static_cast<int>(yi) + 1);
                    delay(0.25);
                }

                setlinestyle(0, 0, 1); // Reset the line style to default

                // Plot the intersection point on the graphics window
                putpixel(maxX / 2 + static_cast<int>(x), maxY / 2, RED);

                // Print the intersection point on the graphics window
                char resultStr[100];
                sprintf(resultStr, "Intersection Point: (%.2f, %.2f)", x, y);
                outtextxy(maxX / 2 + 10, maxY / 2 - 20, resultStr);
            }
        }
        else {
            // No real roots, graph doesn't intersect x-axis
            setlinestyle(lineStyle, 0, 3); // Set the line style to thick
            line(0, 0, 0, 0); // Draw a line outside the visible window
            setlinestyle(0, 0, 1); // Reset the line style to default

            outtextxy(maxX / 2 + 10, maxY / 2 - 20, "No intersection with x-axis (Complex roots)");
        }
    }
    else {
        // Invalid input, 'a' coefficient must not be zero
        setlinestyle(lineStyle, 0, 3); // Set the line style to thick
        line(0, 0, 0, 0); // Draw a line outside the visible window
        setlinestyle(0, 0, 1); // Reset the line style to default

        outtextxy(maxX / 2 + 10, maxY / 2 - 20, "Invalid input: 'a' coefficient must not be zero");
    }

    delay(100000);
    closegraph();
    getch();
}

