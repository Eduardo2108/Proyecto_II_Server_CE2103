//
// Created by eduardozumbadog on 5/14/21.
//

#ifndef BACKEND_GAMESETTINGS_H
#define BACKEND_GAMESETTINGS_H

/**
 * @brief Class for grouping parameters for the creation of class Game.
 */
class GameSettings {
public:
    string player1_name;
    string player2_name;

    const string &getPlayer1Name() const {
        return player1_name;
    }

    GameSettings *setPlayer1Name(const string &player1Name) {
        player1_name = player1Name;
        return this;
    }

    const string &getPlayer2Name() const {
        return player2_name;
    }

    GameSettings *setPlayer2Name(const string &player2Name) {
        player2_name = player2Name;
    }

    int getMaxGoals() const {
        return max_goals;
    }

    GameSettings *setMaxGoals(int maxGoals) {
        max_goals = maxGoals;
        return this;

    }

    int getObstacles() const {
        return obstacles;
    }

    GameSettings *setObstacles(int obstacles) {
        GameSettings::obstacles = obstacles;
        return this;

    }

    int max_goals;
    int obstacles;

};


#endif //BACKEND_GAMESETTINGS_H
