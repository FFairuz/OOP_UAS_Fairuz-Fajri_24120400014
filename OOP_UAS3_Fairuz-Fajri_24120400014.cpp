#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Kelas Player
class Player {
private:
    string name;
    int age;

public:
    Player(string playerName, int playerAge) : name(playerName), age(playerAge) {}

    void displayInfo() {
        cout << "Player Name: " << name << ", Age: " << age << endl;
    }
};

// Kelas Coach
class Coach {
protected:
    string name;

public:
    Coach(string coachName) : name(coachName) {}

    virtual void displayInfo() {
        cout << "Coach Name: " << name << endl;
    }
};

// Kelas HeadCoach yang merupakan subclass dari Coach
class HeadCoach : public Coach {
public:
    HeadCoach(string coachName) : Coach(coachName) {}

    void displayInfo() override {
        cout << "Head Coach Name: " << name << endl;
    }
};

// Kelas AssistantCoach yang merupakan subclass dari Coach
class AssistantCoach : public Coach {
public:
    AssistantCoach(string coachName) : Coach(coachName) {}

    void displayInfo() override {
        cout << "Assistant Coach Name: " << name << endl;
    }
};

// Kelas Team
class Team {
private:
    string teamName;
    HeadCoach headCoach;
    AssistantCoach assistantCoach;
    vector<Player> players;

public:
    Team(string name, HeadCoach hc, AssistantCoach ac) 
        : teamName(name), headCoach(hc), assistantCoach(ac) {}

    void addPlayer(Player player) {
        players.push_back(player);
    }

    void displayTeamInfo() {
        cout << "Team Name: " << teamName << endl;
        headCoach.displayInfo();
        assistantCoach.displayInfo();
        cout << "Players: " << endl;
        for (auto& player : players) {
            player.displayInfo();
        }
    }
};

// Kelas Club
class Club {
private:
    string clubName;
    Team* team;

public:
    Club(string name, Team* t) : clubName(name), team(t) {}

    void displayClubInfo() {
        cout << "Club Name: " << clubName << endl;
        team->displayTeamInfo();
    }
};

// Fungsi Main
int main() {
    HeadCoach hc("John Doe");
    AssistantCoach ac("Jane Smith");

    Team youngTeam("FC Cakrawala Muda", hc, ac);

    // Menambahkan pemain
    youngTeam.addPlayer(Player("Alyssa", 21));
    youngTeam.addPlayer(Player("Budi", 22));

    Club fcCakrawala("FC Cakrawala", &youngTeam);
    
    // Menampilkan informasi club
    fcCakrawala.displayClubInfo();

    return 0;
}
