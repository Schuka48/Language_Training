#include <iostream>

class Dollars {
    int m_dollars;
public:
    Dollars(int dollars): m_dollars{dollars} {}
    int getDollars() const {
        return m_dollars;
    }
    friend Dollars operator+ (const Dollars& d1, const Dollars& d2);
    friend Dollars operator- (const Dollars& d1, const Dollars& d2);
};

Dollars operator+ (const Dollars& d1, const Dollars& d2) {
    return Dollars(d1.getDollars() + d2.getDollars());
}

Dollars operator- (const Dollars& d1, const Dollars& d2) {
    return Dollars(d1.getDollars() - d2.getDollars());
}


int main()
{
    Dollars result = Dollars(4) + (Dollars(7) - Dollars(3));
    std::cout << "I have " << result.getDollars() << " dollars!" << "\n";
    return 0;
}
