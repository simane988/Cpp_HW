#include <iostream>
#include <unordered_map>
#include <string>
#include <set>

using namespace std;

int main()
{
    unordered_map<string,int> data;
    set<string> persons;

    string name;
    int val;

    while (1)
    {
        cout << "Continue? y/n\n";
        cin >> name;
        if (name == "n" || name == "N")
            break;
        cout << "Input data: \n";
        cin >> name >> val;
        data[name] += val;
        persons.insert(name);
    }    
    
    cout << "\nOUTPUT\n" << "##########" << endl;
    for (string t : persons)
    {
        cout << endl << "Name: " << t << " Score: " << data[t] << endl;
    }
    cout << "\n##########" << endl;

    return 0;
}