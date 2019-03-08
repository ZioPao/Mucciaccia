#include "game.h"

void Game::init_characters() {
    for (int i = 1; i <= dim; i++)
        characters.emplace_back(i);
}

void Game::game_loop(){

    Condition tmp;
    for (int i=0; i < dim; i++){
        for (int j=0; j < dim; j++){
            if ((i !=j) && (characters[i].get_status() && characters[j].get_status())){                       //non devono essere lo stesso elemento
                tmp = characters[i].fight(characters[j]);       //salva la condition

                switch (tmp){
                    case WIN:
                        characters[i].set_status(WIN);
                        characters[j].set_status(LOSE);
                        break;
                    case LOSE:
                        characters[i].set_status(LOSE);
                        characters[j].set_status(WIN);
                        break;
                    case TIE:
                        //todo combattimento con oggetti
                        characters[i].set_status(LOSE);
                        characters[j].set_status(LOSE);
                        break;
                }
            }

        }
    }


}

//getters
void Game::get_dim(){
    cout << "Inserire dimensione" << endl;
    cin >> this->dim;
}

void Game::get_winner(){

    for (int i=0; i < dim; i++)
        if (characters[i].get_status())
            cout << characters[i].get_name() << " ha vinto con la sua nerchia di " << characters[i].get_penis() <<"cm" << endl;
}
