#ifndef BASEBALL_PLAYERS_H
#define BASEBALL_PLAYERS_H

#include <vector>
#include <string>

struct BaseballPlayer {
    std::string name;
    std::string position;
    float battingAverage;
    int homeRuns;
    int RBIs;
};

std::vector<BaseballPlayer> readPlayersFromFile(const std::string& filename);

#endif // BASEBALL_PLAYERS_H

