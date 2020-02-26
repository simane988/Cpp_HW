#include <iostream>
#include <cmath>

using namespace std;

int sort(int* input_arr, int* output_arr){

    int left = 0;
    int right = 9;

    for (int i = 0; i < 10; i++){
        if (left > right)
            break;
        if (abs(input_arr[left]) >= abs(input_arr[right])){
            output_arr[i] = pow(input_arr[left], 2.0);
            left++;
        } else if (abs(input_arr[left]) < abs(input_arr[right])){
            output_arr[i] = pow(input_arr[right], 2.0);
            right--;
        } 
    }
    return 0;
}

int main(){

    int unsorted_array[10] = {-11, -7, -5, -4, 1, 2, 5, 6, 9, 10};
    int out_array[10];

    sort(unsorted_array, out_array);

    cout << endl << "Unsorted array:" << endl;
    for (int i = 0; i < 10; i++)
        cout << unsorted_array[i] << ' ';

    cout << endl;

    cout << endl << "Sorted powered array:" << endl;
    for (int i = 0; i < 10; i++)
        cout << out_array[i] << ' ';

    cout << endl << endl;
    return 0;
}
