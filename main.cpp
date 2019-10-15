#include <iostream>

using namespace std;


//
class StrategyInterface
{
public:
    virtual void suma(int a, int b) = 0;
};

class SumaSimple: public StrategyInterface
{
public:
    virtual void suma(int a, int b)
    {
        cout << a+b << endl;
    }
};

class SumaAvanzada: public StrategyInterface
{
public:
    virtual void suma(int a, int b)
    {
        cout << "the addition of a and b is: " << a+b << endl;
    }
};


class Context
{
private:
    StrategyInterface *_strategy;

public:
    Context(StrategyInterface *strategy):_strategy(strategy)
    {
    }

    void set_strategy(StrategyInterface *strategy)
    {
        _strategy = strategy;
    }

    void Suma()
    {
        //numbers used for the addition
        _strategy->suma(1,3);
    }
};

int main(int argc, char *argv[])
{
    SumaSimple sumaSimple;
    SumaAvanzada sumaAvanzada;


    Context context(&sumaSimple);

    context.set_strategy(&sumaAvanzada);
    context.Suma();

    return 0;
}