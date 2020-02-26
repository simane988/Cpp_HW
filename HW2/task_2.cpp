#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int lin_search(vector<int> vect, int search){
    for (int i = 0; i <= 1000000000; i++){
        if (vect[i] == search){
            cout << endl << "LinSearch: " << search << " Find: " << vect[i] << endl;
            return 0;
        } 
    }
    cout << endl << "LinSearch No elem" << endl;
    return 0;
}

int bin_search(vector<int> vect, int search){
    int left = 0;
    int right = 1000000000;
    int middle;
    bool run = 1;
    while ((left<=right) && (run)){
        middle = (left + right)/2;
        if (vect[middle] == search)
            run = 0;
        else if (vect[middle] > search)
            right = middle - 1;
        else
            left = middle + 1;
    }
    
    if (run == 0)
        cout << endl << "BinSeach: " << search << " Find: " << vect[middle] << endl;
    else
        cout << "BinSearch No elem";
    return 0;
}

int main(){
    vector<int> vect;
    for (int i = 0; i <= 1000000000; i++){
        vect.push_back(i);
    }
    int search_int = rand()%1000000000;

    cout << "Search: " << search_int << endl;

    unsigned int lin_start = clock();
    lin_search(vect, search_int);
    unsigned int lin_end = clock();
    cout << "Lin time: " << lin_end - lin_start << endl;

    unsigned int bin_start = clock();
    bin_search(vect, search_int);
    unsigned int bin_end = clock();
    cout << "Bin time: " << bin_end - bin_start << endl;

    return 0;
}