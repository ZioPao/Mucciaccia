#ifndef PAIL_CHARACTER_H
#define PAIL_CHARACTER_H

#include "library.h"
using namespace std;

    class Character {

    private:
        string name;
        int hp;             //per tutti i combattimenti
        int force;          //forza per gli oggetti
        int precision;      //precisione da usare nei combattimenti con gli oggetti
        int penis;         //todo necessario finire combattimenti con oggetti per evitare che ci siano più vincitori
        Objects object;

        //Int che servono nel caso di combattimenti con oggetti
        int glue_quant;
        int glue_pressure;      //pressione da calcolare con la forza e la quantita di colla rimasta


        //stati del singolo personaggio
        bool alive = true;

    public:

        explicit Character(int id) {
            this->name = "Mucciaccia " + to_string(id);
            this->hp = MAX_HP;           //parte sempre da 100
            this->penis = (int)random()%MAX_PENIS;
            // this->penis = static_cast <float> (rand()) / static_cast <float> (RAND_MAX/27);

            this->object = static_cast<Objects>(random() % NUM_OBJECTS);
            this->force = (int) random() % MAX_HP;
            this->precision=(int)random()%50;           //todo rivedi

            ///todo fai switch case per tutti i vari oggetti
            switch (this->get_object()) {
                case COLLA:
                    //glue_quant = (int) random() % 100;
                    glue_quant = 100;
                    glue_pressure = (glue_quant*precision)/2;   //todo rivedi
                    break;
                case FORBICI:
                    break;
                default:
                    break;

            }
        }

        ///Status getters

        string get_name();
        int get_penis();
        Objects get_object();
        bool get_status();

        ///setters
        void set_status(Condition cnd);

        ///FIGHTS
        Condition fight(Character enemy);

        Condition fight_with_obj(Character enemy);

        ///PRINTING
        void print_fight(Character other, bool obj);


    };



#endif //PAIL_CHARACTER_H
