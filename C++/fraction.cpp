#include <iostream>
using namespace std;

class fraction
{
private:
    int numerator;
    int denominator;

public:
    fraction(int numerator, int denominator)
    {
        this->denominator = denominator;
        this->numerator = numerator;
    }

    void print()
    {
        cout << this->numerator << "/" << this->denominator << endl;
    }

    void simplify()
    {
        int gcd = 1;
        int j = min(this->numerator, this->denominator);
        for (int i = 1; i <= j; i++)
        {
            if (this->numerator % i == 0 && this->denominator % i == 0)
                gcd = i;
        }
        this->numerator = this->numerator / gcd;
        this->denominator = this->denominator / gcd;
    }

    void add(fraction const &f)
    {
        int lcm = this->denominator * f.denominator;
        int x = lcm / this->denominator;
        int y = lcm / this->numerator;
        int num = x * this->numerator + (y * f.numerator);
        this->numerator = num;
        this->denominator = lcm;
        simplify();
        print();
    }
    void multiply(fraction const &f)
    {
        this->numerator = this->numerator * f.numerator;
        this->denominator = this->denominator * f.denominator;
        print();
    }
};

int main()
{
    fraction f1(10, 3);
    fraction f2(15, 4);
    f1.print();
    f2.print();
    f1.add(f2);
    f1.multiply(f2);
    return 0;
}