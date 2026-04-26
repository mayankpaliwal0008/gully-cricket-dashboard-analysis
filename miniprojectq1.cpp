#include <iostream>
#include <string.h>

using namespace std;



class cricket{
public:
string name;
int runs;
int balls;
int six;
int four;
float strikerate;

public:

    cricket(string a){

    name=a;

    }



    void show(){

    cout<<name;

    }


};

int main(){
    string j[2];

    for(int i=0;i<2;i++){
cout<<"enter the name of team"<<i+1<<":";
cin>>j[i];
cout<<endl;
}
    int n;
cout<<"enter the number of players in each team"<<":";
cin>>n;
cout<<endl;

cricket *e[n];
cricket *e1[n];

string a[n];//input names of team1
string g[n];//input names of team2





cout<<"-------team1-------------"<<endl;
cout<<"enter the names of team"<<1<<" players"<<endl;
for(int i=0;i<n;i++){
        cin>>a[i];

}
cout<<"--------team2--------------"<<endl;
cout<<"enter the name of team"<<2<<"players"<<endl;
for(int i=0;i<n;i++){

    cin>>g[i];
}
string win;
string opener[2];
cout<<"enter the team who won the toss"<<":";
cin>>win;
cout<<endl;
if(win=="masterblaster")
cout<<"----master blaster want to go for batting first---- "<<endl;
else{
    cout<<"----hustlers want to go for batting first----"<<endl;
}
cout<<endl;
cout<<"enter the names of player which will do opening of team "<< win<<endl;
for(int i=0;i<2;i++){

    cin>>opener[i];
}
cout<<endl;
for(int i=0;i<n;i++){

    e[i]=new cricket(a[i]);
    e1[i]=new cricket(g[i]);
}
cout<<j[0]<<"\t\t"<<j[1]<<endl;;
for(int i=0;i<n;i++){
  e[i]->show();
  cout<<"\t\t\t";
  e1[i]->show();

  cout<<endl;
}




}

