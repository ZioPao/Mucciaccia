#ifndef PAIL_CHARACTER_H
#define PAIL_CHARACTER_H

#include "library.h"
using namespace std;

    class character {

    private:
        string name;
        int hp;
        int penis;
        int objects;

        //Int che servono nel caso di combattimenti con oggetti
        int glue_quant;

        //stati del singolo personaggio
        bool alive = true;

    public:

        explicit character(int id) {
            this->name = "Mucciaccia " + to_string(id);
            this->hp = MAX_HP;           //parte sempre da 100
            this->penis = (int) random() % MAX_PENIS;
            this->objects = (int) random() % NUM_OBJECTS;

            ///todo fai switch case per tutti i vari oggetti
            if (this->objects == COLLA)
                glue_quant = (int) random() % 100;
        }

        ///Status getters

        string get_name();
        int get_penis();
        int get_objects();
        bool get_status();

        ///setters
        void set_status(Condition cnd);

        ///FIGHTS
        Condition fight(character enemy);

        Condition fight_with_obj(character enemy);

        ///PRINTING
        void print_fight(character other);


    };



#endif //PAIL_CHARACTER_H
