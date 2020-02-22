#include <iostream>

class ComputerGameObject {
protected:
    std::string name;
public:
    virtual void draw() = 0;
};

class Creature : public ComputerGameObject {
protected:
    int x, y;
public:
    virtual void move(int dx, int dy) = 0;
};

class MythicalAnimal : public Creature {
public:
    MythicalAnimal() {
        this->name = "Мифическое животное";
        this->x = 0;
        this->y = 0;
    }
    MythicalAnimal(const MythicalAnimal& mythicalAnimal) {
        this->x = mythicalAnimal.x;
        this->y = mythicalAnimal.y;
    }
    MythicalAnimal(std::string name) {
        this->name = name;
        this->x = 0;
        this->y = 0;
    }
    MythicalAnimal(std::string name, int x, int y) {
        this->name = name;
        this->x = x;
        this->y = y;
    }
    ~MythicalAnimal() {};
    void move(int dx, int dy) {
        this->x += dx;
        this->y += dy;
        if (dx != 0 && dy != 0)
            std::cout << this->name << " мифически движется на " << abs(dx) <<
                (abs(dx) % 10 == 1 && abs(dx) % 100 / 10 != 1 ? " метр " :
                abs(dx) % 10 >= 2 && abs(dx) % 10 <= 4 && abs(dx) % 100 / 10 != 1 ? " метра " : " метров ") <<
                (dx > 0 ? "вправо" : "влево") << " и на " << abs(dy) << 
                (abs(dy) % 10 == 1 && abs(dy) % 100 / 10 != 1 ? " метр " :
                abs(dy) % 10 >= 2 && abs(dy) % 10 <= 4 && abs(dy) % 100 / 10 != 1 ? " метра " : " метров ") <<
                (dy > 0 ? "вниз" : "вверх") << std::endl;
        else if (dx != 0)
            std::cout << this->name << " мифически движется на " << abs(dx) << 
                (abs(dx) % 10 == 1 && abs(dx) % 100 != 11 ? " метр " :
                abs(dx) % 10 >= 2 && abs(dx) % 10 <= 4 && abs(dx) % 100 / 10 != 1 ? " метра " : " метров ") <<
                (dx > 0 ? "вправо" : "влево") << std::endl;
        else if (dy != 0)
            std::cout << this->name << " мифически движется на " << abs(dy) << 
                (abs(dy) % 10 == 1 && abs(dy) % 100 != 11 ? " метр " :
                abs(dy) % 10 >= 2 && abs(dy) % 10 <= 4 && abs(dy) % 100 / 10 != 1 ? " метра " : " метров ") <<
                (dy > 0 ? "вниз" : "вверх") << std::endl;
        else
            std::cout << this->name << "мифически стоит на месте" << std::endl;
    }
    void draw() {
        std::cout << "Мифическое животное \"" << this->name << "\" находится на позиции с координатами (" <<
            this->x << "; " << this->y << ")" << std::endl;
    }
};

class Human : public Creature {
public:
    Human() {
        this->name = "Человек";
        this->x = 0;
        this->y = 0;
    }
    Human(const Human& human) {
        this->x = human.x;
        this->y = human.y;
    }
    Human(std::string name) {
        this->name = name;
        this->x = 0;
        this->y = 0;
    }
    Human(std::string name, int x, int y) {
        this->name = name;
        this->x = x;
        this->y = y;
    }
    ~Human() {};
    void move(int dx, int dy) {
        this->x += dx;
        this->y += dy;
        if (dx != 0 && dy != 0)
            std::cout << this->name << " по-человечески идет на " << abs(dx) <<
            (abs(dx) % 10 == 1 && abs(dx) % 100 / 10 != 1 ? " метр " :
                abs(dx) % 10 >= 2 && abs(dx) % 10 <= 4 && abs(dx) % 100 / 10 != 1 ? " метра " : " метров ") <<
                (dx > 0 ? "вправо" : "влево") << " и на " << abs(dy) <<
            (abs(dy) % 10 == 1 && abs(dy) % 100 / 10 != 1 ? " метр " :
                abs(dy) % 10 >= 2 && abs(dy) % 10 <= 4 && abs(dy) % 100 / 10 != 1 ? " метра " : " метров ") <<
                (dy > 0 ? "вниз" : "вверх") << std::endl;
        else if (dx != 0)
            std::cout << this->name << " по-человечески идет на " << abs(dx) <<
            (abs(dx) % 10 == 1 && abs(dx) % 100 != 11 ? " метр " :
                abs(dx) % 10 >= 2 && abs(dx) % 10 <= 4 && abs(dx) % 100 / 10 != 1 ? " метра " : " метров ") <<
                (dx > 0 ? "вправо" : "влево") << std::endl;
        else if (dy != 0)
            std::cout << this->name << " по-человечески идет на " << abs(dy) <<
            (abs(dy) % 10 == 1 && abs(dy) % 100 != 11 ? " метр " :
                abs(dy) % 10 >= 2 && abs(dy) % 10 <= 4 && abs(dy) % 100 / 10 != 1 ? " метра " : " метров ") <<
                (dy > 0 ? "вниз" : "вверх") << std::endl;
        else
            std::cout << this->name << "по-человечески стоит на месте" << std::endl;
    }
    void draw() {
        std::cout << "Человек \"" << this->name << "\" находится на позиции с координатами (" <<
            this->x << "; " << this->y << ")" << std::endl;
    }
};

class MagicCharacter : public Creature {
public:
    MagicCharacter() {
        this->name = "Волшебный персонаж";
        this->x = 0;
        this->y = 0;
    }
    MagicCharacter(const MagicCharacter& magicCharacter) {
        this->x = magicCharacter.x;
        this->y = magicCharacter.y;
    }
    MagicCharacter(std::string name) {
        this->name = name;
        this->x = 0;
        this->y = 0;
    }
    MagicCharacter(std::string name, int x, int y) {
        this->name = name;
        this->x = x;
        this->y = y;
    }
    ~MagicCharacter() {};
    void move(int dx, int dy) {
        this->x += dx;
        this->y += dy;
        if (dx != 0 && dy != 0)
            std::cout << this->name << " волшебно перемещается на " << abs(dx) <<
            (abs(dx) % 10 == 1 && abs(dx) % 100 / 10 != 1 ? " метр " :
                abs(dx) % 10 >= 2 && abs(dx) % 10 <= 4 && abs(dx) % 100 / 10 != 1 ? " метра " : " метров ") <<
                (dx > 0 ? "вправо" : "влево") << " и на " << abs(dy) <<
            (abs(dy) % 10 == 1 && abs(dy) % 100 / 10 != 1 ? " метр " :
                abs(dy) % 10 >= 2 && abs(dy) % 10 <= 4 && abs(dy) % 100 / 10 != 1 ? " метра " : " метров ") <<
                (dy > 0 ? "вниз" : "вверх") << std::endl;
        else if (dx != 0)
            std::cout << this->name << " волшебно перемещается на " << abs(dx) <<
            (abs(dx) % 10 == 1 && abs(dx) % 100 != 11 ? " метр " :
                abs(dx) % 10 >= 2 && abs(dx) % 10 <= 4 && abs(dx) % 100 / 10 != 1 ? " метра " : " метров ") <<
                (dx > 0 ? "вправо" : "влево") << std::endl;
        else if (dy != 0)
            std::cout << this->name << " волшебно перемещается на " << abs(dy) <<
            (abs(dy) % 10 == 1 && abs(dy) % 100 != 11 ? " метр " :
                abs(dy) % 10 >= 2 && abs(dy) % 10 <= 4 && abs(dy) % 100 / 10 != 1 ? " метра " : " метров ") <<
                (dy > 0 ? "вниз" : "вверх") << std::endl;
        else
            std::cout << this->name << "волшебно стоит на месте" << std::endl;
    }
    void draw() {
        std::cout << "Волшебный персонаж \"" << this->name << "\" находится на позиции с координатами (" <<
            this->x << "; " << this->y << ")" << std::endl;
    }
};

class MagicThing : public ComputerGameObject {
protected:
    int x, y;
    int power;
public:
    MagicThing() {
        this->name = "Волшебный предмет";
        this->x = 0;
        this->y = 0;
        this->power = 0;
    }
    MagicThing(const MagicThing& magicThing) {
        this->name = magicThing.name;
        this->x = magicThing.x;
        this->y = magicThing.y;
        this->power = magicThing.power;
    }
    MagicThing(std::string name, int power) {
        this->name = name;
        this->x = 0;
        this->y = 0;
        this->power = power;
    }
    MagicThing(std::string name, int x, int y, int power) {
        this->name = name;
        this->x = x;
        this->y = y;
        this->power = power;
    }
    ~MagicThing() {};
    void draw() {
        std::cout << "Волшебный предмет \"" << this->name << "\" находится на позиции с координатами (" <<
            this->x << "; " << this->y << ")" << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    MythicalAnimal flyingFishWithBlueEyes = MythicalAnimal("Летающая рыба с голубыми глазами");
    flyingFishWithBlueEyes.draw();
    flyingFishWithBlueEyes.move(12, -23);
    flyingFishWithBlueEyes.draw();
    Human knightBoris = Human("Рыцарь Борис", 10, -4);
    knightBoris.draw();
    knightBoris.move(-6, 0);
    knightBoris.draw();
    MagicCharacter clownWizard = MagicCharacter("Клоун-волшебник", 1, 1);
    clownWizard.draw();
    clownWizard.move(0, 124);
    clownWizard.draw();
    MagicThing greenMushroom = MagicThing("Зеленый гриб", 10, 25, 100);
    greenMushroom.draw();
    return 0;
}