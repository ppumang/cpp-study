#include <iostream>

class Marine {
    static int total_marine_num;
    const static int i = 0;

    int hp;
    int coord_x, coord_y;
    int damage;
    bool is_dead;
    char* name;
    const int default_damage;

    public:
        Marine();
        Marine(int x, int y);
        Marine(int x, int y, const char* name);
        Marine(int x, int y, int default_damage);
        ~Marine();

        int attack();
        Marine& be_attacked(int damage_earn);
        void move(int x, int y);
        void show_status();

        static void show_total_marine();
};
int Marine::total_marine_num = 0;
void Marine::show_total_marine() {
    std::cout << "total_marines : " << total_marine_num << std::endl;
}

Marine::Marine() : name(NULL), hp(50), coord_x(0), coord_y(0), damage(5), is_dead(false), default_damage(5) {
    total_marine_num++;
    }
Marine::Marine(int x, int y) : name(NULL), hp(50), coord_x(x), coord_y(y), damage(5), is_dead(false), default_damage(5) {
    total_marine_num++;
    }
Marine::Marine(int x, int y, const char* marine_name) : hp(50), coord_x(x), coord_y(y),damage(5), is_dead(false), default_damage(5){
    name = new char[strlen(marine_name) + 1];
    strcpy(name, marine_name);
    total_marine_num++;
}
Marine::Marine(int x, int y, int default_damage) : coord_x(x), coord_y(y), hp(50), damage(default_damage), default_damage(default_damage), is_dead(false) {
    total_marine_num++;
    name = new char[20];
    strcpy(name, "default marine");
    }
Marine::~Marine() {
    std::cout << name << "'s destructor" << std::endl;
    if (name && name != NULL)
    {
        delete[] name;
    }
    total_marine_num --;
}
void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
int Marine::attack() {return damage;}
Marine& Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if(hp <= 0) is_dead = true;

    return *this;
}
void Marine::show_status() {
    std::cout << "*** Marine : " << name << " ***" << std::endl;
    std::cout << " Location : (" << coord_x << ", " << coord_y
    << ") " << std::endl;
    std::cout << " hp : " << hp << std::endl;
}

int main() {
    Marine marine1(2,3,5);
    std::cout << "main" << std::endl;

    marine1.show_status();

    Marine marine2(3,5,10);
    marine2.show_status();

    std::cout << std::endl << "marine1 attackes marine2 2 times!" << std::endl;
    marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
}