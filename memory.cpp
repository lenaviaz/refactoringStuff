#include "memory.h"
#include <vector>

class memory
{

private:
    int size;
    std::vector<int> capacity;

public:
    memory(int moduleSize)
    {
        size = moduleSize;
        capacity.reserve(size);
    }

    int getSize()
    {
        return size;
    }

    bool checkAddress(int address)
    {
        if (address < capacity[0] || address > capacity[size])
        {
            return false;
        }
        return true;
    }

    bool initialize(int address, std::string word)
    {
        if (checkAddress(address))
        {
            int len = word.length();
            for (int i = 0; i < len; i++)
            {
                char ch = word[i];
                int ascii = (int)ch;
                capacity[address] = ascii;
                address++;
            }
            return true;
        }
        return false;
    }

    int read(int address)
    {
        if (checkAddress(address))
        {
            int readNum = capacity[address];
            return readNum;
        }
        return 0;
    }

    virtual void write(int address, int num)
    {
        if (checkAddress(address))
        {
            capacity[address] = num;
        }
    }
};