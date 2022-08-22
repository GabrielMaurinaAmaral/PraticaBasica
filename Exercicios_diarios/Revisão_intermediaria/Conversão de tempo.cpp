#include <bits/stdc++.h>

using namespace std;

string timeConversion(string s)
{
    int pos = s.find(":");
    int hora = stoi(s.substr(0, pos));

    string formato = s.substr(8, 2);
    
    if (hora == 12 && formato == "AM")
        return "00" + s.substr(pos, 6);
    else if (hora < 12 && formato == "PM")
        return to_string((hora + 12)) + s.substr(pos, 6);
    else
        return s.substr(0, 8);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
