#include "memory.cpp"
#include <map>

class mmu
{
public:
    std::map<int, memory *> mmuMap;
    std::vector<int> memIndex;

    bool checkAddressBounds(int address, memory &mem)
    {
        if (mmuMap.empty())
            return true;

        memIndex.clear();
        int prevKey = 0;
        int prevSize = 0;
        for (std::pair<const int, memory *> pair : mmuMap)
        {
            int key = pair.first;
            int size = pair.second->getSize();

            if (address < (key) && (address > (prevKey + prevSize)))
            {
                if ((address + mem.getSize() < key))
                {
                    return true;
                }
            }
            prevKey = key;
            prevSize = size;
        }

        if (address > (prevKey + prevSize))
        {
            return true;
        }

        return false;
    }

    bool checkMap(int address, memory &mem)
    {
        return checkAddressBounds(address, mem);
    }

    void attach(int address, memory &mem)
    {
    }
};