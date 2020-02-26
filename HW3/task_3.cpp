#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

void create_all_cases(int n, int opened, int closed, string ans, unordered_set<string>& all_cases)
{
    if (opened < n/2)
    {
        ans += '(';
        create_all_cases(n, ++opened, closed, ans, all_cases);
    }

    if (closed < opened)
    {
        ans += ')';
        create_all_cases(n, opened, ++closed, ans, all_cases);
    }

    if (opened + closed == n)
    {
        all_cases.insert(ans);
        return;
    }
}

int main()
{
    int n;
    cin >> n;
    if (n % 2 == 1)
    {
        cout << "Creating valid cases is not possible\n";
        return 0;
    }

    int opened = 0;
    int closed = 0;
    string ans;
    unordered_set<string> all_cases;

    create_all_cases(n, opened, closed, ans, all_cases);

    for (string t : all_cases)
        cout << t << endl;
    
    return 0;
}