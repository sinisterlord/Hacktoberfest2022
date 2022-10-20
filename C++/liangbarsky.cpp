#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Initialization
    int x1, y1, x2, y2;
    cout << "Enter start pt: ";
    cin >> x1 >> y1;
    cout << "Enter end pt: ";
    cin >> x2 >> y2;

    // Calculating Δx and Δy
    int dx = (x2 - x1);
    int dy = (y2 - y1);

    // Calculation Pk values
    float p[4] = {(float)-dx, (float)dx, (float)-dy, (float)dy};

    // Initialization
    int xmin, xmax, ymin, ymax;
    cout << "Enter xmax, xmin: ";
    cin >> xmax >> xmin;
    cout << "Enter ymax, ymin: ";
    cin >> ymax >> ymin;

    // Calculation Qk values
    float q[4] = {(float)x1 - xmin, (float)xmax - x1, (float)y1 - ymin, (float)ymax - y1};

    // For any Pk = 0 and Qk < 0 ---> Line Rejected
    if ((p[0] == 0 && q[0] < 0) || (p[1] == 0 && q[1] < 0) || (p[2] == 0 && q[2] < 0) || (p[3] == 0 && q[3] < 0))
    {
        cout << "Line Rejected";
        return 0;
    }

    vector<float> r1, r2;
    r1.push_back(0);
    r2.push_back(1);

    // For Pk < 0, Calculating Qk/Pk
    for (int i = 0; i < 4; i++)
        if (p[i] < 0)
            r1.push_back(q[i] / p[i]);

    // Calculating t1
    float t1 = *max_element(r1.begin(), r1.end());

    // For Pk > 0, Calculating Qk/Pk
    for (int i = 0; i < 4; i++)
        if (p[i] > 0)
            r2.push_back(q[i] / p[i]);

    // Calculating t2
    float t2 = *min_element(r2.begin(), r2.end());

    cout << "t1: " << t1 << ", t2: " << t2 << endl;
    if (t1 > t2)
    {
        cout << "Line Rejected";
        return 0;
    }
    else
    {
        cout << "Clipped Line Coordinates: "
             << "(" << x1 + dx * t1 << ", " << y1 + dy * t1 << ")"
             << " and "
             << "(" << x1 + dx * t2 << ", " << y1 + dy * t2 << ")";
    }

    return 0;
}