#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

struct Player {
    int score;
    string name;
};

class Checker{
public:
  	// complete this method
    static int comparator(Player a, Player b)  {
        
        if(a.score < b.score) return -1;
        else if (a.score > b.score) return 1;
        else{
            //a and b has the same score, compare name
            if (a.name == b.name) return 0;
            else if (a.name < b.name) return 1;
            else if (a.name > b.name) return -1;
        }
        return 0;
    }
};




bool compare(Player a, Player b) {
    if(Checker::comparator(a,b) == -1)
        return false;
    return true;
}

int main(){
    
    vector<string> name_list = {"amy", "david", "heraldo", "amy", "aleksa"};
    vector<int> score_list = {100, 100, 50, 75, 150};


    vector<Player> players;
    for(int i = 0; i < name_list.size(); i++){
        Player temp;
        temp.name = name_list[i];
        temp.score = score_list[i];
        players.push_back(temp);
    }
    sort(players.begin(), players.end(), compare);
    for(int i = 0; i < players.size(); i++) {
        cout << players[i].name << " " << players[i].score << endl;
    }
    return 0;
}