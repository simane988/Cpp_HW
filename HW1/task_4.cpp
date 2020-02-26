#include <iostream>
#include <string>

using namespace std;

void Check(string real, string expected) {
    if (expected != real) {
        cerr << "===================" << endl;
        cerr << "ERROR: expected " << expected << ", got " << real << endl;
        cerr << "===================" << endl;
    } else {
        cerr << "OK" << endl;
    }
}

string DateFromTimestamp(unsigned int time) {
    // write your code here
    // int vis = 1972;
    int secs = time;
    int days = secs/60/60/24;
    int year = 1970;
    int mounths[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int vis_mounths[] = {31,29,31,30,31,30,31,31,30,31,30,31};
    bool run = 1;
    int mounth = 0;

    string str_mounth;
    string str_days;
    string str_hours;
    string str_minutes;
    string str_seconds;


    // Тут считаем год. Всё из-за високосного года, чтоб его.
    while (run) {
        if (year % 4 == 0) {
            if (days > vis_mounths[mounth]) {
                days -= vis_mounths[mounth]; 
            } else {
                run = 0;
            }
            
        } else {
            if (days > mounths[mounth]) {
                days -= mounths[mounth];
            } else {
                run = 0;
            }
        }
        mounth++;
        if (mounth == 12) {
            year++;
            mounth = 0;
        }
    }
    days++;
    if (mounth >= 10)
        str_mounth = to_string(mounth);
    else
        str_mounth = '0' + to_string(mounth);

    if (days >= 10)
        str_days = to_string(days);
    else
        str_days = '0' + to_string(days);

    if (secs/60/60%24 + 3 >= 10)
        str_hours = to_string(secs/60/60%24 + 3);
    else
        str_hours = '0' + to_string(secs/60/60%24 + 3);

    if (secs/60%60 >= 10)
        str_minutes = to_string(secs/60%60);
    else
        str_minutes = '0' + to_string(secs/60%60);

    if (secs%60 >= 10)
        str_seconds = to_string(secs%60);
    else
        str_seconds = '0' + to_string(secs%60);

    return to_string(year) + '-' + str_mounth + '-' + str_days + ' ' + str_hours + ':' + str_minutes + ':' + str_seconds;   
}



int main() {
    Check(DateFromTimestamp(0), "1970-01-01 03:00:00");
    Check(DateFromTimestamp(1500000000), "2017-07-14 05:40:00");
    Check(DateFromTimestamp(2000000000), "2033-05-18 06:33:20");
}