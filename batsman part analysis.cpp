#include <iostream>
#include <string.h>
#include <iomanip>


using namespace std;

class cricket{
public:
string name;
int runs;
int balls;
int six;
int four;
float strikerate;

cricket(string a,int b,int c,int d,int e){
name=a;
runs=b;
balls=c;
six=d;
four=e;


}

};

class batsman:public cricket{
public:
    int *runsperover;
    int oversplayed;



public:

    batsman(string a,int b,int c ,int d,int e,int g):cricket(a,b,c,d,e){

        name=a;
        oversplayed=g;
        cout<<"enter the run per over of player "<<name<<":"<<endl;
        runsperover = new int[oversplayed];

for(int i=0;i<oversplayed;i++){
    cin>>runsperover[i];
}



    }

    float strikerate(){
        return (float(runs)/balls)*100;

    }
    float runrate(){
    return float(runs)/oversplayed;


    }

   void display() {

    cout << left;

    cout << setw(25) << "Player Name"
         << setw(15) << name << endl;

    cout << setw(25) << "Total Runs"
         << setw(15) << runs << endl;

    cout << setw(25) << "Total Balls"
         << setw(15) << balls << endl;

    cout << setw(25) << "Total Sixes"
         << setw(15) << six << endl;

    cout << setw(25) << "Total Fours"
         << setw(15) << four << endl;

    cout << setw(25) << "Strike Rate"
         << setw(15) << strikerate() << endl;

    cout << setw(25) << "Run Rate"
         << setw(15) << runrate() << endl;

    cout << endl;
}
    void show(string a,int oversplayed){
    cout<<"the runs per over of player"<<name<<":";
    cout<<endl;
    for(int i=0;i<oversplayed;i++){
            cout<<runsperover[i];
    cout<<endl;

    }
    cout<<endl;
    }


};

int main(){
int n;
cout<<"enter the number of players"<<":";
cin>>n;
cout<<endl;
string j;
cout<<"enter the batting team name"<<":";
cin>>j;
cout<<endl;
cout<<"enter the players name"<<":";
cout<<endl;
string s[n];
for(int i=0;i<n;i++){
    cin>>s[i];
}


cricket *e[n];
int b[n];
int c[n];
int d[n];
int e2[n];
cout<<"enter the total runs scored by each batsman"<<":"<<endl;
for(int i=0;i<n;i++){

    cin>>b[i];
}
cout<<"enter total balls played by each player "<<":"<<endl;
for(int i=0;i<n;i++){
        cin>>c[i];


}
cout<<"enter the six played by each player"<<":"<<endl;
for(int i=0;i<n;i++){

    cin>>d[i];
}
cout<<"enter the four played by each player"<<":"<<endl;
for(int i=0;i<n;i++){
    cin>>e2[i];
}



for(int i=0;i<n;i++){

    e[i]=new cricket(s[i],b[i],c[i],d[i],e2[i]);
}
cout<<"enter the over played by each player"<<":"<<endl;
int f[n];
for(int i=0;i<n;i++){
    cin>>f[i];
}

batsman *e1[n];


for(int i=0;i<n;i++){

    e1[i]=new batsman(s[i],b[i],c[i],d[i],e2[i],f[i]);
}


for(int i=0;i<n;i++){
    e1[i]->display();

    cout<<endl;
}

for(int i=0;i<n;i++){
    e1[i]->show(s[i],f[i]);
}

}









