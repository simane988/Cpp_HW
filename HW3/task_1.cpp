#include <iostream>
#include <vector>
// TASK IS NOT DONE

#include <unordered_map>

using namespace std;

int main ()
{
    int sum;
    int search;
    vector<int> input;

    unordered_map<int,int> val_to_int;

    cout << "Input sequence: \n";
    cout << "If it is end of sequence just input non int value\n";
    while (cin >> sum)
    {
        input.push_back(sum);
    }

    sum = 0;

    for (int i = 0; i < input.size(); i++)
    {
        sum += input[i];
        val_to_int.insert(make_pair(i, sum));
    }

    // cout << val_to_int.find(10);

    for (int i = 0; i < val_to_int.size(); i++)
    {
        cout << i << ' ' << val_to_int[i] << endl;
        // sum -= input[input.size() - 1 - i];
    }

    cout << "What sum do you search for?\n";
    cin >> search;
    cout << search;
}