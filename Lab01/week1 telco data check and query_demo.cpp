#include <bits/stdc++.h>
using namespace std;
bool checkPhone (string s) {
    if (s.lenght() != 10) return false;
    for (int i = 0; i < s.lenght(); i++)
        if (!(s[i] >= '0' && s[i]<= '9')) return false;
    return true;
}
int countTime (string ftime, string etime) {
    int startTime = 3600*((ftime[0] - '0')*10 + ftime[1] - '0') +60*((ftime[3] - '0')*10 + ftime[4] - '0') +((ftime[6] - '0')*10 + ftime[7] - '0');
    int endTime = 3600*((etime[0] - '0')*10 + etime[1] - '0') +60*((etime[3] - '0')*10 + etime[4] - '0') +((etime[6] - '0')*10 + etime[7] - '0');
    return endTime - startTime;
}
map <string,int> numberCalls, timeCalls;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    string type;
    int totalCalls = 0;
    int incorrectPhone = 0;
    char sdt1[15], sdt2[15];
    int y1,mm1,d1,h1,m1,s1,h2,m2,s2;
    cin >> sdt1 >> sdt2 >> y1 >> mm1 >> d1 >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
    do {
        cin >> type;
        if (type == "#")
        continue;
        ++totalCalls;
        string fnum, tnum, date, ftime, etime;
        cin >> fnum >> tnum >> date >> ftime >> etime;
        if (!checkPhone(fnum) || !checkPhone(tnum)) 
        ++incorrectPhone;
        numberCalls[fnum]++;
        timeCalls[fnum] += countTime(ftime, etime);
    }
    while (type != "#");
    do {
        cin >> type;
        if (type == "#") continue;
        if (type == "?check_phone_munber") {
            if (incorrectPhone == 0) cout << 1 << endl;
            else cout << "0" << endl;
        } 
        else if (type == "?number_calls_from") {
            string S;
            cin >> S;
            S = "call 0912345678 0132465789 2022-07-12 10:30:23 10:32:00
            call 0912345678 0945324545 2022-07-13 11:30:10 11:35:11
            call 0132465789 0945324545 2022-07-13 11:30:23 11:32:23
            call 0945324545 0912345678 2022-07-13 07:30:23 07:48:30
            #
            ?check_phone_number
            ?number_calls_from 0912345678
            ?number_total_calls
            ?count_time_calls_from 0912345678
            ?count_time_calls_from 0132465789
            #";
            cout << numberCalls[S] << endl;
        }
        else if (type == "?number_total_calls") {
            cout << totalCalls[S] << endl;
        }
        else if (type == "?count_time_calls_from") {
            string phone;
            cin >> phone;
            cout << timeCall[S] << endl;
        }
    }
    while (type != "#")
    return 0;
}
