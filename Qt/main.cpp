#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <array>
#include <clocale>
#include <windows.h>
#include <cmath>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string_view>

const int arraySize = 10000;
const int MAX_MONSTER_COUNT = 10;

struct Student {
    std::string name {};
    int ball;
};

struct Season {
    std::string name{};
    double averageTemperature {};
};

static std::array<Student, 8> arr {
      { { "Albert", 3 },
        { "Ben", 5 },
        { "Christine", 2 },
        {  "Dan", 8 },
        { "Enchilada", 4 },
        {  "Francis", 1 },
        { "Greg", 3 },
        { "Hagrid", 5 }
      }
};

static std::array<Season, 4> seasons {
    {
        { "Spring", 285.0 },
        { "Summer", 296.0 },
        { "Fall", 288.0 },
        { "Winter", 263.0 }
    }
};

static auto func { [](const Season& a, const Season& b) {
        return a.averageTemperature < b.averageTemperature;
    }};

class Vector3D;

class Point3D {
    double m_x, m_y, m_z;

public:
    Point3D(double x = 0.0, double y = 0.0, double z = 0.0): m_x(x), m_y(y), m_z(z) {}
    void print() {
        std::cout << "Point (" << m_x << ", " << m_y << ", " << m_z << ")" << std::endl;
    }

    void moveByVector(const Vector3D& v);
};

class Vector3D {
    double m_x, m_y, m_z;

public:
    Vector3D(double x = 0.0, double y = 0.0, double z = 0.0): m_x(x), m_y(y), m_z(z) {}
    void print() {
        std::cout << "Vector (" << m_x << ", " << m_y << ", " << m_z << ")" << std::endl;
    }
    friend void Point3D::moveByVector(const Vector3D& v);
};

void Point3D::moveByVector(const Vector3D &v) {
    this->m_x = this->m_x + v.m_x;
    this->m_y = this->m_y + v.m_y;
    this->m_z = this->m_z + v.m_z;
}

class Dollars {
    int m_dollars;
public:
    Dollars(int dollars): m_dollars{dollars} {}
    int get_dollars () const {return m_dollars;}
};

Dollars add (const Dollars& d1, const Dollars &d2) {
    return Dollars(d1.get_dollars() + d2.get_dollars());
}

class Fruit {
public:
    enum FruitList {
        AVOCADO,
        BLACKBERRY,
        LEMON
    };
private:
    FruitList m_type;
public:
    Fruit(FruitList type): m_type(type) {}

    FruitList getFruitType() {return m_type;}
};

class Timer {
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1>>;

    std::chrono::time_point<clock_t> m_beg;

public:
    Timer(): m_beg(clock_t::now()) {}
    void reset() {
        m_beg = clock_t::now();
    }
    double elapsed() const {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};

void mySort(std::array<int, arraySize>& array) {
    for(int startIndex = 0; startIndex < arraySize - 1; ++startIndex) {
        int smallestIndex = startIndex;

        for(int currentIndex = startIndex + 1; currentIndex < arraySize; ++currentIndex) {
            if(array[currentIndex] < array[smallestIndex])
                smallestIndex = currentIndex;
        }

        std::swap(array[startIndex], array[smallestIndex]);
    }
}

class Point {
    double m_a = 0.0;
    double m_b = 0.0;
public:
    Point(double a = 0.0, double b = 0.0): m_a{a}, m_b{b} {}
    void print() const {
        std::cout << "Point(" << m_a << ", " << m_b << ")" << std::endl;
    }
    friend double distanceFrom(const Point& pointA, const Point& pointB);
};

double distanceFrom(const Point& pointA, const Point& pointB) {
    return sqrt(pow(pointA.m_a - pointB.m_a, 2) + pow(pointA.m_b - pointB.m_b, 2));
}

class Welcome {
private:
    char* m_data;
public:
    Welcome() {
        m_data = new char[14];
        const char* init = "Hello, World!";
        for(int i = 0; i < 14; i++) {
            m_data[i] = init[i];
        }
    }
    ~Welcome() {
        delete [] m_data;
//        std::cout << "Реализация деструктора для класса Welcome!" << std::endl;
    }
    void print() { std::cout << m_data << std::endl;}
};

// ----------------------- ZAD N 3 -----------------------------------

class Monster {
public:
    enum MonsterType {
        Dragon,
        Goblin,
        Ogre,
        Orc,
        Skeleton,
        Troll,
        Vampire,
        Zombie,
        MAX_MONSTER_TYPES = 8
    };
private:
    MonsterType m_type;
    std::string m_name;
    int m_health;
public:
    Monster(Monster::MonsterType type, std::string name, int health = 100):
        m_type{type}, m_name{name}, m_health{health} {}
    std::string getTypeString() const {
        switch (m_type) {
        case 0: return "dragon ";
        case 1: return "goblin ";
        case 2: return "ogre ";
        case 3: return "orc ";
        case 4: return "skeleton ";
        case 5: return "troll ";
        case 6: return "vampire ";
        case 7: return "zombie ";
        case 8: return " ";
        }
        return "indefined type";
    }
    void print() const {
        std::cout << m_name << " is the " << getTypeString() <<  "that has "
                  << m_health << " health points." << std::endl;
    }

};

class MonsterGenerator {
public:
    static int getRandomNumber(int min, int max) {
        static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
        return static_cast<int>(rand() * fraction * (max - min +1) + min);
    }
    static Monster generateMonster() {
        static const std::string s_names[] = {"Jack", "John", "Nick", "Keij", "Lilo", "Bobby"};
        int rand_int = getRandomNumber(0, Monster::MAX_MONSTER_TYPES - 1);
        int rand_health = getRandomNumber(0, 100);
        int rand_name_id = getRandomNumber(0, 5);

        return Monster(static_cast<Monster::MonsterType>(rand_int), s_names[rand_name_id], rand_health);
    }
};

//----------------------------------------------------------------------------------------

int main()
{

    using namespace std;
    srand(static_cast<unsigned int>(time(nullptr)));
    setlocale(LC_ALL, "PL_pl.UTF-8");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    /*Point3D p(3.0, 4.0, 5.0);
    Vector3D v(3.0, 3.0, -3.0);

    p.print();
    p.moveByVector(v);
    p.print();*/

    Timer timer;

    std::array<int, arraySize> myArray;

    for(int i = 0; i < arraySize; ++i) {
        myArray[i] = arraySize - i;
    }

//    mySort(myArray);
//    std::sort(myArray.begin(), myArray.end());

    Point first;
    Point second(2.0, 5.0);
    first.print();
    second.print();
    cout << "Дистанция между двумя точками: " << distanceFrom(first, second) << endl;

    Welcome hello;
    hello.print();

    cout << "Время выполнения кода: " << timer.elapsed() << endl;
    cout << endl;

    rand();

    vector<Monster> TargetList;
    for(int i = 0; i < MonsterGenerator::getRandomNumber(0, MAX_MONSTER_COUNT); i++) {
        TargetList.push_back(MonsterGenerator::generateMonster());
    }
    for(const auto& monster: TargetList)
        monster.print();


    auto bestStudent {std::max_element(arr.begin(), arr.end(), [](const Student& a, const Student& b) {
        return a.ball < b.ball;
    })
    };
    cout << "Best Student: " << bestStudent->name << " with "
         << bestStudent->ball << " points" << endl;



    std::sort(seasons.begin(), seasons.end(), func);

    for (const auto& season: seasons)
        std::cout << season.name << '\n';

    return 0;
}
