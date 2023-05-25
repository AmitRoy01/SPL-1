#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;

void Linear_Graph()
{
    int gd = DETECT, gm;
    initwindow(800, 600); // Set the window size to 800x600
    setbkcolor(LIGHTGRAY); // Set the background color of the graphics window

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

    float m1 = -(0.25 * a1) / (0.25 * b1);
    float t1 = 20 * (c1 / b1);
    float m2 = -(0.25 * a2) / (0.25 * b2);
    float t2 = 20 * (c2 / b2);

    // Plot the linear equation graphs
    setcolor(YELLOW); // Set the color for the first line
    setlinestyle(lineStyle, 0, 3); // Set the line style to thick for the first line
    for (int x = -midX; x < midX; ++x) {
        int y1 = m1 * x + t1;
        line(midX + x, midY - y1, midX + x + 1, midY - y1 + 1);
        delay(0.5);
    }

    setcolor(GREEN); // Set the color for the second line
    setlinestyle(lineStyle, 0, 3); // Set the line style to thick for the second line
    for (int x = -midX; x < midX; ++x) {
        int y2 = m2 * x + t2;
        line(midX + x, midY - y2, midX + x + 1, midY - y2 + 1);
        delay(0.5);
    }

    setlinestyle(0, 0, 1); // Reset the line style to default

    // Calculate the intersection point
    float x = (c1 * b2 - c2 * b1) / (a1 * b2 - a2 * b1);
    float y = (a1 * c2 - a2 * c1) / (a1 * b2 - a2 * b1);

    // Check if lines intersect or not
    if (isfinite(x) && isfinite(y)) {
        // Set the font size and style for "Intersection Point"
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);

        // Calculate the position to display the text at the middle of the graphics window
        int textWidth = textwidth("Intersection Point");
        int textHeight = textheight("Intersection Point");
        int textX = midX - textWidth / 2;
        int textY = midY - textHeight / 2;

        // Print "Intersection Point"
        outtextxy(textX, textY, "Intersection Point");

        // Set the font size and style for the intersection point coordinates
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);

        // Calculate the position to display the coordinates below the "Intersection Point" text
        int coordY = textY + textHeight + 10;

        // Print the intersection point coordinates
        char resultStr[100];
        sprintf(resultStr, "(x = %.2f, y = %.2f)", x, y);
        outtextxy(textX, coordY, resultStr);
    }
    else {
        // Set the font size and style for "No intersection point"
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);

        // Calculate the position to display the text at the middle of the graphics window
        int textWidth = textwidth("No intersection point");
        int textHeight = textheight("No intersection point");
        int textX = midX - textWidth / 2;
        int textY = midY - textHeight / 2;

        // Print "No intersection point"
        outtextxy(textX, textY, "No intersection point");
    }

    delay(100000); // Wait for 10 seconds before closing the window
    closegraph();
    getch();
}
