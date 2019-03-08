//
// Created by aless on 08/03/2019.
//

#ifndef PAIL_GAME_H
#define PAIL_GAME_H

#include "library.h"
#include "character.h"

class Game{

private:
    int dim = 0;                    //numero dei characters, da definire dopo
    vector<character> characters;

public:


    ///logica gioco
    void init_characters();
    void game_loop();

    //getters
    void get_dim();
    void get_winner();

};




#endif //PAIL_GAME_H
