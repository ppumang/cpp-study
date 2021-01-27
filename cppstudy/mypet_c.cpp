#include <iostream>

typedef struct Animal {
    char name[30];
    int age, health, food, clean;
} Animal;

void create_animal(Animal* animal) {
    std::cout << "name? ";
    std::cin >> (*animal).name;
    // std::cin >> animal -> name;
    
    std::cout << "age? ";
    std::cin >> (*animal).age;

    (*animal).health = 100;
    (*animal).food = 100;
    (*animal).clean = 100;
}

void play(Animal* animal) {
    animal -> health += 10;
    animal -> food -= 20;
    animal -> clean -= 20;
}

void one_day_pass(Animal* animal) {
    animal -> health -= 10;
    animal -> food -= 30;
    animal -> clean -= 20;
}

void show_stat(Animal* animal) {
    std::cout << animal -> name << "'s status" << std::endl;
    std::cout << "health: " << animal -> health << std::endl;
    std::cout << "food: " << animal -> food << std::endl;
    std::cout << "clean: " << animal -> clean << std::endl;
}

int main()
{   
    Animal* list[10];
    int animal_num = 0;

    for(;;) {
        std::cout << "1. create animal" << std::endl;
        std::cout << "2. play" << std::endl;
        std::cout << "3. status" << std::endl;

        int input;
        std::cin >> input;

        switch (input)
        {
        case 1:
            list[animal_num] = new Animal;
            create_animal(list[animal_num]);
            animal_num++;
            break;
        case 2:
            int play_with;
            std::cout << "which animal?" << std::endl;
            std::cin >> play_with;
            if (play_with < animal_num)
            {
                play(list[play_with]);
            }
            break;
        case 3:
            int status_who;
            std::cout << "which animal?" << std::endl;
            std::cin >> status_who;
            if (status_who < animal_num)
            {
                show_stat(list[status_who]);
            }
            break;
        default:
            break;
        }

        for (int i = 0; i < animal_num; i++)
        {
            one_day_pass(list[i]);
        }
    }
    for (int i = 0; i < animal_num; i++)
    {
        delete list[i];
    }
}