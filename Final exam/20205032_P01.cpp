#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool no_wrong_trip_code = true;
map<string, ll> trip_code;
map<string, ll> customer_code;
ll total_qty, qty_custommer, total_trips;
int qty;

void check(string trip_code) {
    if(inp.trip_code == "TR0000000\*") {
        no_wrong_trip_code = true;
    } else no_wrong_trip_code = false;
}


ll total_time(string from_time, string to_time) {
    ll from_y, from_mo, from_d, to_y, to_mo, to_d;
    ll from_h, from_m, from_s, to_h, to_m, to_s;
    from_y = (from_time[0] - '0') * 1000 + (from_time[1] - '0') * 100 + (from_time[2] - '0') * 10 +(from_time[3] - '0'); 
    from_mo = (from_time[5] - '0') * 10 + (from_time[6] - '0'); 
    from_d = (from_time[8] - '0') * 10 + (from_time[9] - '0'); 
    to_y = (to_time[0] - '0') * 1000 + (to_time[1] - '0') * 100 + (to_time[2] - '0') * 10 +(to_time[3] - '0'); 
    to_mo = (to_time[5] - '0') * 10 + (to_time[6] - '0'); 
    to_d = (to_time[8] - '0') * 10 + (to_time[9] - '0');
    from_h = (from_time[0] - '0') * 10 + (from_time[1] - '0'); //hour
    from_m = (from_time[3] - '0') * 10 + (from_time[4] - '0'); //minute
    from_s = (from_time[6] - '0') * 10 + (from_time[7] - '0'); //second
    to_h = (to_time[0] - '0') * 10 + (to_time[1] - '0');
    to_m = (to_time[3] - '0') * 10 + (to_time[4] - '0');
    to_s = (to_time[6] - '0') * 10 + (to_time[7] - '0');
    return (to_y - from_y) * 365 * 3600 + (to_mo - from_mo) * 30 * 3600 + (to_d - from_d) * 3600 + (to_h - from_h) * 3600 + (to_m - from_m) * 60 + (to_s - from_s);
}

int main() {
    int S = 0;
    string inp;
    cin >> inp;
    while(inp != "*") {
        string date;
        cin >> date;
        cin >> inp;
    }
    cin >> inp;
    while(inp != "*") {
        string trip_code, customer_code, date, time, qty;
        cin >> trip_code >> customer_code >> date >> time >> qty;
        if(no_wrong_trip_code) {
            check(trip_code);
        }
        
        


        cin >> inp;
    }
    cin >> inp;
    while(inp != "***") {
        if(inp == "TOTAL_QTY") {
            cout << int(S) << endl;
        } else if(inp == "QTY_CUSTOMER") {
            string customer_code;
            cin >> customer_code;
            cout << qty.customer_code << endl;
        } else if(inp == "QTY_MAX_PERIOR") {
            string date, time;

        } else if(inp == "TOTAL_TRIPS") {
            string num;
            cin >> num;
        } else if(inp == "TRAVEL_TIME_TRIP") {
            string trip_code, total_time_s;
            cout << total_time_s;
        } else if(inp == "MAX_CONFLICT_TRIPS") {

        }
        cin >> inp;
    }
}
