#include "baseball_players.h"
#include <iostream>
#include <algorithm>

// Comparator function for sorting players based on the selected stat
bool comparePlayers(const BaseballPlayer& player1, const BaseballPlayer& player2, const std::string& stat) {
    if (stat == "BattingAverage")
        return player1.battingAverage > player2.battingAverage;
    else if (stat == "HomeRuns")
        return player1.homeRuns > player2.homeRuns;
    else if (stat == "RBIs")
        return player1.RBIs > player2.RBIs;
    else
        return false; // Handle invalid stat
}

// Function to calculate total ranking based on weighted sum of stats
double calculateTotalRanking(const BaseballPlayer& player) {
    // Define weights for each stat
    const double battingAverageWeight = 0.4;
    const double homeRunsWeight = 0.3;
    const double RBIsWeight = 0.3;

    // Calculate total ranking
    return (battingAverageWeight * player.battingAverage) + (homeRunsWeight * player.homeRuns) + (RBIsWeight * player.RBIs);
}

int main() {
    std::string filename = "baseball_players.txt";
    std::vector<BaseballPlayer> players = readPlayersFromFile(filename);

    // Calculate total rankings
    std::vector<double> totalRankings;
    for (const auto& player : players) {
        totalRankings.push_back(calculateTotalRanking(player));
    }

    // Output total rankings
    std::cout << "Players:" << std::endl;
    for (size_t i = 0; i < players.size(); ++i) {
        std::cout << i + 1 << ". " << players[i].name << " (" << players[i].position << "): " << totalRankings[i] << std::endl;
    }

    // Prompt user to choose a stat
    std::cout << "\nChoose a stat to rank players (BattingAverage, HomeRuns, RBIs): ";
    std::string chosenStat;
    std::cin >> chosenStat;

    // Sort players based on the chosen stat
    std::sort(players.begin(), players.end(), [chosenStat](const BaseballPlayer& player1, const BaseballPlayer& player2) {
        return comparePlayers(player1, player2, chosenStat);
        });

    // Output the ranked players
    std::cout << "\nRanking of players based on " << chosenStat << ":" << std::endl;
    for (size_t i = 0; i < players.size(); ++i) {
        std::cout << i + 1 << ". " << players[i].name << " (" << players[i].position << "): ";
        if (chosenStat == "BattingAverage")
            std::cout << players[i].battingAverage;
        else if (chosenStat == "HomeRuns")
            std::cout << players[i].homeRuns;
        else if (chosenStat == "RBIs")
            std::cout << players[i].RBIs;
        std::cout << std::endl;
    }

    return 0;
}
