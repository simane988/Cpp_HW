#include <iostream>

using namespace std;

void Check(int real, int expected) {
    if (expected != real) {
        cerr << "===================" << endl;
        cerr << "ERROR: expected " << expected << ", got " << real << endl;
        cerr << "===================" << endl;
    } else {
        cerr << "OK" << endl;
    }
}

int GCD(int a, int b) {
    // write your code here
    if (a % b == 0)
    	return b;
    if (b % a == 0)
    	return a;
    if (a > b)
    	return GCD(a%b, b);
    return GCD(a, b%a);
}



int main() {
    Check(GCD(25, 30), 5);
    Check(GCD(15929, 17803), 937);
    Check(GCD(15929, 17804), 1);
}