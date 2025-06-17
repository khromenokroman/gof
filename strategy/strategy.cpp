#include <iostream>
#include <memory>

class Icounter
{
public:
    virtual ~Icounter() = default;
    virtual void add() = 0;
};

class Counter : public Icounter
{
public:
    Counter() = default;
    ~Counter() = default;

    void add() override
    {
        std::cout << "Counter add" << std::endl;
    }
};

class FakeCounter : public Icounter
{
public:
    FakeCounter() = default;
    ~FakeCounter() = default;

    void add() override
    {
        std::cout << "Fake counter add" << std::endl;
    }
};

class Test
{
public:
    Test(std::unique_ptr<Icounter> &&counter) : m_counter{std::move(counter)}
    {
    }
    ~Test() = default;

    void process()
    {
        std::cout << "process... " << std::endl;
        m_counter->add();
    }

private:
    std::unique_ptr<Icounter> m_counter;
};

int main()
{

    {
        Test test{std::make_unique<Counter>()};
        test.process();
    }

    {
        Test test{std::make_unique<FakeCounter>()};
        test.process();
    }

    return 0;
}
