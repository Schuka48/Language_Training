#include <iostream>
#include <string>


class Dollars {
    int m_dollars;
public:
    Dollars(int dollars = 0): m_dollars{dollars} {}
    int getDollars() const {
        return m_dollars;
    }
    friend Dollars operator+ (const Dollars& d1, const Dollars& d2);
    friend Dollars operator- (const Dollars& d1, const Dollars& d2);

    friend std::ostream& operator<< (std::ostream& out, const Dollars& d);
    friend std::istream& operator>> (std::istream& in, Dollars& d);
};

Dollars operator+ (const Dollars& d1, const Dollars& d2) {
    return Dollars(d1.getDollars() + d2.getDollars());
}

Dollars operator- (const Dollars& d1, const Dollars& d2) {
    return Dollars(d1.getDollars() - d2.getDollars());
}

std::ostream& operator<< (std::ostream& out, const Dollars& d) {
    return out << d.getDollars() << " dollars";
}

std::istream& operator>> (std::istream& in, Dollars& d) {
   std::cout << "input dollar count: ";
    return in >> d.m_dollars;
}

class Fraction {
    int m_numerator;
    int m_denominator;

public:
    Fraction(int numerator = 0, int denominator = 1):
        m_numerator{numerator},
        m_denominator{denominator} { reduce(); }

    void print() {
        std::cout << m_numerator << "/" << m_denominator << std::endl;
    }
    static int nod(int a, int b) {
        return (b == 0) ? (a > 0 ? a : -a) : nod(b, a % b);
    }
    void reduce() {
        int nod = Fraction::nod(m_numerator, m_denominator);
        m_numerator /= nod;
        m_denominator /= nod;
    }

    friend Fraction operator* (const Fraction& f, int value);
    friend Fraction operator* (int value, const Fraction& f);
    friend Fraction operator* (const Fraction& f1, const Fraction& f2);

    friend std::istream& operator>> (std::istream& in, Fraction& f);
};

Fraction operator* (const Fraction& f, int value) {
    int m_nod = Fraction::nod(f.m_numerator, f.m_denominator);
    return Fraction((f.m_numerator / m_nod) * value, f.m_denominator / m_nod);
}

Fraction operator* (int value, const Fraction& f) {
    return f * value;
}

Fraction operator* (const Fraction& f1, const Fraction& f2) {
    int new_numerator = f1.m_numerator * f2.m_numerator;
    int new_denominator = f1.m_denominator * f2.m_denominator;
    int m_nod = Fraction::nod(new_numerator, new_denominator);
    return Fraction(new_numerator / m_nod, new_denominator / m_nod);
}

std::istream& operator>> (std::istream& in, Fraction& f) {
       std::string str;
       in >> str;
       f.m_numerator = std::stoi(str.substr(0, str.find('/')));
       f.m_denominator = std::stoi(str.substr(str.find('/') + 1, str.length()));

       return in;
}

int main()
{
    Fraction f1;
    std::cout << "Enter fraction 1: ";
    std::cin >> f1;

    return 0;
}
