#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

class bowler {
public:
    string name;
    int overs;
    int wickets;

    bowler(string a, int b, int d) {
        name = a;
        overs = b;
        wickets = d;
    }

//Virtual Destructor
    virtual ~bowler() {}
};

bool operator<(const bowler &o, const bowler &o1) {
    return o.wickets < o1.wickets;
}

class type : public bowler {
public:
    string bowlingtype;
    int runs;
    int *wicketsperover1;
    int *runsperover1;

public:
    type(string t, string a, int b, int d, int k, int l) : bowler(a, b, d) {
        bowlingtype = t;
        runs = k;
        overs = l;
        wicketsperover1 = new int[l];
        runsperover1 = new int[l];

        cout << "\n\n>>> Data Entry for " << name << " <<<" << endl;
        cout << "\n";
        for (int i = 0; i < l; i++) {
            cout << "Enter wickets in Over " << i + 1 << ": ";
            cin >> wicketsperover1[i];
        }
        cout << "\n";
        for (int i = 0; i < l; i++) {
            cout << "Enter runs in Over " << i + 1 << ": ";
            cin >> runsperover1[i];
        }
    }
//Destructor
    ~type() {
        delete[] wicketsperover1;
        delete[] runsperover1;
    }

    int strikerate() {
        if (wickets == 0) return 0;
        return (6 * overs) / wickets;
    }

    int rate() {
        if (overs == 0) return 0;
        return runs / overs;
    }

    void show() {
        cout << setw(15) << name << setw(10) << wickets << setw(15) << bowlingtype << setw(10) << runs << setw(15) << rate() << setw(10) << strikerate() << endl;
    }

    void save(bool overwrite) {
        ofstream f;
        if (overwrite) f.open("ipl_database.txt", ios::out);
        else f.open("ipl_database.txt", ios::app);
        if (f.is_open()) {
            f << "INSERT INTO Scoreboard VALUES ('" << name << "'," << wickets << ",'" << bowlingtype << "'," << runs << "," << rate() << ");" << endl;
            f.close();
        }
    }

//Maiden Over Logic
    void maiden() {
        for (int i = 0; i < overs; i++) {
            if (runsperover1[i] == 0) {
                cout << "[MAIDEN OVER] Bowler: " << name << " bowled a maiden in Over " << i + 1 << "!" << endl;
            }
        }
    }
};

class hatrick : public type {
public:
    hatrick(string t, string a, int b, int d, int k, int l) : type(t, a, b, d, k, l) {}

    bool h1() {
        for (int i = 0; i < overs; i++) {
            if (wicketsperover1[i] >= 3) return true;
        }
        return false;
    }
};

int main() {
    int choice;
    cout << "*****************************************************" << endl;
    cout << "* IPL CRICKET MANAGEMENT SYSTEM           *" << endl;
    cout << "*****************************************************" << endl;
    cout << "* [1] Create New Match Record (Overwrite File)     *" << endl;
    cout << "* [2] View Historical Scoreboard (Database)       *" << endl;
    cout << "*****************************************************" << endl;
    cout << "Please select an option (1-2): ";
    cin >> choice;

    if (choice == 2) {
        ifstream f("ipl_database.txt");
        string line;
        if (f.is_open()) {
            cout << "\n" << setfill('=') << setw(70) << "" << setfill(' ') << endl;
            cout << "                 HISTORICAL SCOREBOARD DATA                 " << endl;
            cout << setfill('=') << setw(70) << "" << setfill(' ') << endl;
            cout << setw(15) << "NAME" << setw(10) << "WICKETS" << setw(15) << "TYPE" << setw(10) << "RUNS" << setw(10) << "ECO" << endl;
            cout << setfill('-') << setw(70) << "" << setfill(' ') << endl;

            while (getline(f, line)) {
                if (line.find("VALUES") == string::npos) continue;
                size_t s = line.find("("), e = line.find(")");
                string data = line.substr(s + 1, e - s - 1);
                for (int i = 0; i < data.length(); i++) if (data[i] == ',' || data[i] == '\'') data[i] = ' ';
                stringstream ss(data);
                string n1, w1, t1, r1, ec1;
                if (ss >> n1 >> w1 >> t1 >> r1 >> ec1)
                    cout << setw(15) << n1 << setw(10) << w1 << setw(15) << t1 << setw(10) << r1 << setw(10) << ec1 << endl;
            }
            cout << setfill('=') << setw(70) << "" << setfill(' ') << endl;
            f.close();
            return 0;
        } else {
            cout << "\n[!] Database file not found. Create a record first." << endl;
            return 0;
        }
    }

    int n;
    cout << "\n[SYSTEM] Enter the number of bowlers: ";
    cin >> n;

    string j;
    cout << "Enter the Bowling Team name: ";
    cin >> j;

    string a[n];
    int b[n], d[n];
    string o;

    cout << "\nEnter opening bowler name: ";
    cin >> o;

    cout << "\nEnter names of all " << n << " bowlers in order(Separated By Space):" << endl;
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << "\nEnter overs played by each bowler:" << endl;
    for (int i = 0; i < n; i++) cin >> b[i];

    cout << "\nEnter total wickets for each bowler:" << endl;
    for (int i = 0; i < n; i++) cin >> d[i];

    bowler *e[n];
    for (int i = 0; i < n; i++) e[i] = new bowler(a[i], b[i], d[i]);

    string typebow[n];
    int m[n];

    cout << "\nEnter bowling type (Fast/Spin):" << endl;
    for (int i = 0; i < n; i++) cin >> typebow[i];

    cout << "\nEnter total runs conceded:" << endl;
    for (int i = 0; i < n; i++) cin >> m[i];

    hatrick *e2[n];
    for (int i = 0; i < n; i++) {
        e2[i] = new hatrick(typebow[i], a[i], b[i], d[i], m[i], b[i]);
    }

    cout << "\n" << setfill('*') << setw(80) << "" << setfill(' ') << endl;
    cout << "                        CURRENT MATCH SCORECARD                       " << endl;
    cout << setfill('*') << setw(80) << "" << setfill(' ') << endl;
    cout << setw(15) << "NAME" << setw(10) << "WKTS" << setw(15) << "TYPE" << setw(10) << "RUNS" << setw(15) << "ECO" << setw(10) << "SR" << endl;

    for (int i = 0; i < n; i++) {
        e2[i]->show();
        e2[i]->save(i == 0 && choice == 1);
    }

    cout << "\n--- Performance Analysis ---" << endl;
    for (int i = 0; i < n; i++) {
        e2[i]->maiden();
        if (e2[i]->h1()) cout << "!!! HAT-TRICK ALERT: " << e2[i]->name << " took 3+ wickets in an over!" << endl;
    }

    cout << "\n--- Wicket Comparison ---" << endl;
    for (int i = 0; i < n - 1; i++) {
        if (*e[i] < *e[i + 1]) {
            cout << e[i + 1]->name << " > " << e[i]->name << " (More wickets)" << endl;
        } else {
            cout << e[i]->name << " >= " << e[i + 1]->name << " (More/Equal wickets)" << endl;
        }
    }

    for (int i = 0; i < n; i++) {
        delete e[i];
        delete e2[i];
    }

    return 0;
}
