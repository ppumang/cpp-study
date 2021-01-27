#include <string.h>
#include <iostream>

class Photon_Cannon {
    int hp, shield;
    int coord_x, coord_y;
    int damage;
    char* cannon_name;

    public:
        Photon_Cannon(int x, int y);
        Photon_Cannon(int x, int y, const char* cannon_name);
        Photon_Cannon(const Photon_Cannon& pc);
        ~Photon_Cannon();

        void show_status();
};

Photon_Cannon::Photon_Cannon(int x, int y) {
    std::cout << "photon constructor" << std::endl;
    hp = shield = 100;
    damage = 20;
    cannon_name = NULL;

    coord_x = x;
    coord_y = y;
}

Photon_Cannon::Photon_Cannon(int x, int y, const char* _name) {
    std::cout << "photon constructor" << std::endl;
    cannon_name = new char[strlen(_name) + 1];
    strcpy(cannon_name, _name);
    hp = shield = 100;
    damage = 20;

    coord_x = x;
    coord_y = y;
}

Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) {
    std::cout << "photon copy constructor" << std::endl;

    hp = pc.hp;
    shield = pc.shield;
    damage = pc.damage;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    cannon_name = new char[strlen(pc.cannon_name) + 1];
    strcpy(cannon_name, pc.cannon_name);
}

Photon_Cannon::~Photon_Cannon() {
    std::cout << cannon_name << "destructor" << std::endl;
    if(cannon_name){
        delete[] cannon_name;
    }
}


void Photon_Cannon::show_status() {
    std::cout << "Photon Cannon " << std::endl;
    std::cout << "Location : (" << coord_x << ", " << coord_y
    << ")" << std::endl;
    std::cout << "hp : " << hp << std::endl;
}

int main() {
    Photon_Cannon pc1(3,3, "cannon1");
    Photon_Cannon pc2 = pc1;

    pc1.show_status();
    pc2.show_status();
}