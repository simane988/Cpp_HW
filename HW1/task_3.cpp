#include <iostream>

using namespace std;

void Check(int expected, int real)
{
    if (expected != real)
    {
        cerr << "===================" << endl;
        cerr << "ERROR: expected " << expected << ", got " << real << endl;
        cerr << "===================" << endl;
    }
    else
    {
        cerr << "OK" << endl;
    }
}

int ToInt(string val)
{
    // write your code here
    int len = val.length();
    int out = 0;
    char ch;
    int d = 1;
    for (int i = 1; i <= len; i++)
    {
        ch = val[len - i];
        if (ch >= '0' && ch <= '9')
        {
            out += (ch - 48) * d;
            d *= 10;
        }
        else if (ch < '0' || ch > '9')
        {
            return 0;
        }
    }
    return out;
}

int main()
{
    Check(ToInt("123"), 123);
    Check(ToInt("00000001"), 1);
    Check(ToInt(""), 0);
    Check(ToInt("100078001"), 100078001);
    Check(ToInt("1OOO78001"), 0);
}