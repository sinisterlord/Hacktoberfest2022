#include <bits/stdc++.h>
using namespace std;
void ellipse(int r1, int r2, vector<int> x_co, vector<int> y_co)
{
    int x = 0;
    int y = r2;
    int d1 = r2 * r2 + 0.25 * r1 * r1 - r1 * r1 * r2;
    int dx = 2 * r2 * r2 * x;
    int dy = 2 * r1 * r1 * y;
    do
    {
        x_co.push_back(x);
        y_co.push_back(y);
        if (d1 < 0)
        {
            x++;
            dx = dx + 2 * r2 * r2;
            d1 = d1 + dx + r2 * r2;
        }
        else
        {
            x++;
            y--;
            dx = dx + 2 * r2 * r2;
            dy = dy - 2 * r1 * r1;
            d1 = d1 + dx - dy + r2 * r2;
        }
    } while (dx < dy);
    int d2 = r2 * r2 * (x + 0.5) * (x + 0.5) + r1 * r1 * (y - 1) * (y - 1) - r1 * r1 * r2 * r2;
    do
    {
        x_co.push_back(x);
        y_co.push_back(y);
        if (d2 < 0)
        {
            y--;
            dy = dy - 2 * r1 * r1;
            d2 = d2 - dy + r1 * r1;
        }
        else
        {
            x++;
            y--;
            dy = dy - 2 * r1 * r1;
            dx = dx + 2 * r2 * r2;
            d2 = d2 + dx - dy + r1 * r1;
        }
    } while (y > 0);
    for (int i = 0; i < x_co.size(); i++)
        cout << "[" << x_co[i] << ", " << y_co[i] << "], ";
    for (int i = 0; i < x_co.size(); i++)
        cout << "[" << -1 * x_co[i] << ", " << y_co[i] << "], ";
    for (int i = 0; i < x_co.size(); i++)
        cout << "[" << -1 * x_co[i] << ", " << -1 * y_co[i] << "], ";
    for (int i = 0; i < x_co.size(); i++)
        cout << "[" << x_co[i] << ", " << -1 * y_co[i] << "], ";
}
int main()
{
    int x, y, r1, r2;
    vector<int> x_co;
    vector<int> y_co;
    cout << "Enter r1 and r2: ";
    cin >> r1 >> r2;
    ellipse(r1, r2, x_co, y_co);
    return 0;
}