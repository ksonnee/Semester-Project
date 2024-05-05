#include "baseball_players.h"
#include <iostream>
#include <fstream>
#include <sstream>

std::vector<BaseballPlayer> readPlayersFromFile(const std::string& filename) {
    std::vector<BaseballPlayer> players;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return players;
    }

    std::string line;
    while (std::getline(file, line)) {
        BaseballPlayer player;
        std::stringstream ss(line);
        ss >> player.name >> player.position >> player.battingAverage >> player.homeRuns >> player.RBIs;
        players.push_back(player);
    }

    file.close();
    return players;
}

