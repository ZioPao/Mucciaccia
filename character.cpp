#include "character.h"

///Status getters
string Character::get_name(){
    return name;
}
int Character::get_penis() {
    return penis;
}
Objects Character::get_object() {
    return this->object;
}
bool Character::get_status(){
    return this -> alive;
}

///setters
void Character::set_status(Condition cnd){

    if (cnd == LOSE){
        //cout << this -> name << " muore" << endl;
        this -> alive = false;
    }
}

///FIGHTS
Condition Character::fight(Character enemy) {

    if (this->penis > enemy.penis){
        this->print_fight(enemy, PENI);
        return WIN;}

    else if (this->penis < enemy.penis){
        enemy.print_fight(*this, PENI);
        return LOSE;}
    else{
        //cout << "Sia " << this -> name << " che " << enemy.name <<" muoiono strangolati coi propri peni" << endl;
        this->print_fight(enemy,OGGETTI);
        return TIE;}
}
Condition Character::fight_with_obj(Character enemy) {

    switch (this->object) {
        ///COLLA MAIN
        case COLLA:
            switch (enemy.get_object()) {
                case COLLA:
                    if (this->glue_quant > enemy.glue_quant) {     //vince this
                        glue_quant -= 10;           //diminuisce la quantità di colla del vincitore
                        return WIN;
                    }
                    if (this->glue_quant < enemy.glue_quant) {
                        enemy.glue_quant -= 10;     //bugia, può tornare e servire per ulteriori combattimenti
                        return LOSE;
                    } else {
                        glue_quant -= random() % 5;      //diminuisce di un tot
                        glue_quant -= random() % 5;
                        fight_with_obj(enemy);      //again fino a che qualcuno non vince a colpi di colla
                    }
                    break;
                case FORBICI:
                    //la colla cade randomicamente su due punti, punta o ingranaggio a seconda della precisione di mucciaccia
                    break;
                case CARTA:
                    break;
                case MALATTIE:
                    break;

                default:
                    break;
            }
            ///FORBICI MAIN
        case FORBICI:
            break;
            ///CARTA MAIN
        case CARTA:
            break;
            ///MALATTIE MAIN
        case MALATTIE:
            break;
        default:
            break;
    }
}

///PRINTING
void Character::print_fight(Character other, bool obj) {
    int rand_phrase[2];

    rand_phrase[0] = (int) random() % 3;
    rand_phrase[1] = (int) random() % 3;

    if (!obj){
        switch (rand_phrase[0]) {
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
        cout << this->name;

        switch (rand_phrase[1]) {
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
        cout << other.name << endl;
    }
}