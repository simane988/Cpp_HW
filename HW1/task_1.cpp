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

int Min(int a, int b, int c) {
    // write your code here
    if (a < b){
	if (c < a) {
		return c;
	} else {
		return a;
	}
    } else {
	if (c < b) {
		return c;
	} else {
		return b;
	}
    }
    return 0;
}



int main() {
    Check(Min(5, 3, 7), 3);
    Check(Min(-432, -433, -444), -444);
}
