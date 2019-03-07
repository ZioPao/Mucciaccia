#include "library.h"
using namespace std;
class Character {

private:
    string name;
    int penis;
    int objects;

    //stati del singolo personaggio
    bool alive = true;

public:

    explicit Character(int id) {         //todo non so cosa faccia
        this->name = "Mucciaccia " + to_string(id);
        this->penis = rand() % MAX_PENIS;
        this->objects = rand() % NUM_OBJECTS;
    }

    ///Status getters
    string print_name(){
        return name;
    }
    int get_penis() {
        return penis;
    }

    int get_objects() {
        return objects;
    }

    bool get_status(){
        return this -> alive;
    }


    ///setters

    void set_status(Condition cnd){

        if (cnd == LOSE){
            //cout << this -> name << " muore" << endl;
            this -> alive = false;
        }
    }
    ///Check vari
    Condition fight(Character enemy) {

        if (this->penis > enemy.penis){
            this->print_fight(enemy);
            return WIN;}

        else if (this->penis < enemy.penis){
           enemy.print_fight(*this);
            return LOSE;}
        else{
            cout << "Sia " << this -> name << " che " << enemy.name <<" muoiono strangolati coi propri peni" << endl;
            return TIE;}
    }
    void print_fight(Character other){

        int rand_phrase[2];

        rand_phrase[0] = rand()%3;
        rand_phrase[1] = rand()%3;

        switch(rand_phrase[0]){
            case 0:
                cout << PRE_PHRASE1;
                break;
            case 1:
                cout << PRE_PHRASE2;
                break;
            case 2:
                cout << PRE_PHRASE3;
                break;
            default:
                break;
        }
        //printa in mezzo il nome
        cout << this->print_name();

        switch(rand_phrase[1]){
            case 0:
                cout << POST_PHRASE1;
                break;
            case 1:
                cout << POST_PHRASE2;
                break;
            case 2:
                cout << POST_PHRASE3;
                break;
            default:
                break;
        }
        cout << other.print_name() << endl;

    }


};

class Game{

private:
    int dim = 0;                    //numero dei characters, da definire dopo
    vector<Character> characters;

public:


    void init_characters() {
        for (int i = 1; i <= dim; i++)
            characters.emplace_back(i);
    }

    void game_loop(){

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
                            characters[i].set_status(LOSE);
                            characters[j].set_status(LOSE);
                            break;
                    }
                }

            }
        }


    }

    //getters
    void get_dim(){
        cout << "Inserire dimensione" << endl;
        cin >> this->dim;
    }

    void get_winner(){

        for (int i=0; i < dim; i++)
            if (characters[i].get_status())
                cout << characters[i].print_name() << " ha vinto con la sua nerchia di " << characters[i].get_penis() <<"cm" << endl;
    }

};


int main() {

    srand((unsigned)time(NULL));


    Game game;

    game.get_dim();     //prende dimensione per array personaggi
    game.init_characters();        //inizializza i personaggi
    game.game_loop();
    game.get_winner();

}