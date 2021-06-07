//
// Created by eduardozumbadog on 5/15/21.
//

#ifndef PROYECTO_II_SERVER_CE2103_BPMANAGER_H
#define PROYECTO_II_SERVER_CE2103_BPMANAGER_H

#include "Components/Ball.h"
#include "Components/Player.h"
#include "Components/Field.h"
#include "Components/GameSettings.h"
#include "Pathfinding/Route.h"
#include "Pathfinding/Pathfinding.h"
#include <mutex>

/**
 * @brief This class provides an API to the logics of BP Game.
 */
class BPManager {
private:
    Player *player_1;
    Player *player_2;
    Ball *ball;
    int max_goals;
    Field *field;
    static BPManager *instance;
    static std::mutex mutex_;


    BPManager() = default;

    explicit BPManager(GameSettings *settings) {
        //Initialize variables.
        this->field = new Field();
        this->ball = new Ball();
        this->player_1 = new Player();
        this->player_2 = new Player();
        //Configure game with user's choices.
        this->max_goals = settings->getMaxGoals();
        this->field->generateField();
        //set ball position in the Field.
        this->field->setBall(true, ball->getRow(), ball->getColumn());
    }

public:
/**
 * @brief Method for calculating a shot from the user or the AI
 * @param shoot information with the strength and direction of the shot.
 * @return The path of the ball.
 */
    Route *shoot(Shoot *shoot) {
        return Pathfinding::calculateShoot(shoot, this->field, this->ball);

    }


    Field *getField() {
        return this->field;
    }

    static BPManager *getInstance(GameSettings *settings = nullptr);
};


#endif //PROYECTO_II_SERVER_CE2103_BPMANAGER_H
