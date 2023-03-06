#include <iostream>
#include <string>
#include <map>


template<class Key, class Value>
class dictionary
{
public:
    virtual ~dictionary() = default;

    virtual const Value& get(const Key& key) const = 0;
    virtual void set(const Key& key, const Value& value) = 0;
    virtual bool is_set(const Key& key) const = 0;
};

template<class Key>
class not_found_exception : public std::exception
{//map.at(key)!!!!!
public:
    virtual const Key& get_key() const noexcept = 0;
};


template<class Key, class Value>
class Container : public dictionary<Key, Value>
{
public:

    Container()
    {
        std::cout << "HELLO" << std::endl;
    }

    const Value& get(const Key& key)const override
    {
        return myMap.at(key);
    }

    void set(const Key& key, const Value& value) override
    {
        myMap.emplace(key, value);
    }

    bool is_set(const Key& key)const override
    {
        if (myMap.find(key) != myMap.end())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

private:

    std::map<Key, Value> myMap;
};


int main()
{
    Container<int, std::string> dict;
    dict.set(2, "hello2");
    dict.set(1, "hello1");
    dict.set(3, "hello3");
    dict.set(5, "hello5");

    std::cout << dict.get(1) << std::endl;
    std::cout << dict.is_set(1) << std::endl;


}
