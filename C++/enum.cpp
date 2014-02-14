#include <iostream>
using namespace std;
class EnumType
{
    public:
        enum Color
        {
            RED,
            BLUE
        };

        enum Fruit
        {
            BANANA,
            APPLE
        };

    private:
    protected:
};

int main()
{
    EnumType::Color a = EnumType::RED;
    EnumType::Fruit b = EnumType::BANANA;
 
    if (a == b) // The compiler will compare a and b as integers
        cout << "a and b are equal" << endl; // and find they are equal!
    else
        cout << "a and b are not equal" << endl;
 
    return 0;
}
