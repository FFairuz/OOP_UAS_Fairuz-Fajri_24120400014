#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Player {
public:
    string name;
    int age;
    
    Player(string n, int a) : name(n), age(a) {}
};

class Coach {
public:
    string name;
    string type;
    Coach(string n, string t) : name(n), type(t) {}
};

class Team {
public:
    string name;
    vector<Player> players;
    
    Team(string n) : name(n) {}
    
    void addPlayer(Player p) {
        players.push_back(p);
    }
};

class Club {
public:
    string name;
    vector<Team> teams;

    Club(string n) : name(n) {}
    
    void addTeam(Team t) {
        teams.push_back(t);
    }
};

int main() {
    Club fcCakrawala("FC Cakrawala");
    Team u23("FC Cakrawala Muda");

    // Menambahkan pemain
    u23.addPlayer(Player("Ali", 21));
    u23.addPlayer(Player("Budi", 22));

    // Menambahkan tim ke klub
    fcCakrawala.addTeam(u23);

    cout << "Klub: " << fcCakrawala.name << endl;
    return 0;
}
