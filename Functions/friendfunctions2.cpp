// friend keyword is usually used for overload << and >>
// one of the advantages of friend functions: can be used to increase the versatility of overloaded operators

#include <iostream>
#include <iomanip> // stream manipulators

class Money {
    private:
        long long cents_;
    public:
        Money(long long dollars = 0) { cents_ = dollars * 100; }

        // operator<< left operand is std::ostream, which you don't own, so it can't be a member of Money class
        // printing needs the private data, and if we don't want to expose the getter -> use friend
        friend std::ostream& operator<<(std::ostream& os, const Money& m){
            long long d = m.cents_ / 100;
            long long c = std::llabs(m.cents_ % 100);
            os << (m.cents_ < 0 ? "-" : "") << "$" << std::llabs(d)
               << "." << std::setw(2) << std::setfill('0') << c; 
            // std::setw(n) set field width(next insertion only), stream manipulators
            // std::setfill(ch) fill character for padding, stream manipulators
            // std::llabs() returns the absolute value of a long long, declared in <cstdlib>
            return os;
        }

        // if making operator+ a member, the left operand must be Money type
        // don't have to use friend here, but we use it for 1. access cents_ 2.keep the oprator a non-member
        friend Money operator+(const Money& lhs, const Money& rhs) {
            Money out;
            out.cents_ = lhs.cents_ + rhs.cents_;
            return out;
        }

        friend Money operator+(const Money& lhs, int dollars) {
            Money out;
            out.cents_ = lhs.cents_ + dollars * 100;
            return out;
        }

        friend Money operator+(int dollars, const Money& rhs) {
            Money out;
            out.cents_ = dollars * 100 + rhs.cents_;
            return out;
        }

};

int main() {
    Money rent(1600);
    Money uitilities(80);

    Money total1 = rent + uitilities;
    Money total2 = rent + 80;
    Money total3 = 1500 + uitilities;

    std::cout << "Total1: " << total1 << "\n";
    std::cout << "Total2: " << total2 << "\n";
    std::cout << "Total3: " << total3 << "\n";

    return 0;
}