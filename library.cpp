#include "library.h"
#include "character.h"
#include "game.h"

using namespace std;
int main() {

    srand((unsigned)time(NULL));


    Game game;

    game.get_dim();     //prende dimensione per array personaggi
    game.init_characters();        //inizializza i personaggi
    game.game_loop();
    game.get_winner();

    return 0;   //fottiti marco

}