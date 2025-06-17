#include <iostream>

template <typename Type>
class Vector
{
public:
    Vector() : m_data{new Type[M_DEFAULT_SIZE]}, m_capacity{M_DEFAULT_SIZE} {}
    ~Vector()
    {
        delete[] m_data;
    }

    void push_back(Type const &value)
    {
        if (m_size == m_capacity)
        {
            replace_data();
        }
        m_data[m_size++] = value;
    }

    std::size_t size() { return m_size; };
    std::size_t capacity() { return m_capacity; };

    Type operator[](std::size_t index) { return m_data[index]; };

private:

    void replace_data()
    {
        auto new_arr = new Type[m_capacity * 2];
        for (std::size_t i = 0; i < m_size; ++i)
        {
            new_arr[i] = m_data[i];
        }
        delete[] m_data;
        m_data = new_arr;
        m_capacity = m_capacity * 2;
    }

    Type *m_data = nullptr;                          // 8
    static constexpr std::size_t M_DEFAULT_SIZE = 2; // 8
    std::size_t m_size = 0;                          // 8
    std::size_t m_capacity = 0;                      // 8
};

int main()
{
    Vector<int> vec;
    vec.push_back(10);
    std::cout << "size: " << vec.size() << " capacity: " << vec.capacity() << std::endl;
    vec.push_back(10);
    std::cout << "size: " << vec.size() << " capacity: " << vec.capacity() << std::endl;
    vec.push_back(10);
    std::cout << "size: " << vec.size() << " capacity: " << vec.capacity() << std::endl;

    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << std::endl;
    }
}
