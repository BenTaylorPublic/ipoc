#pragma once
#include <queue>

class Identifiable{
public:
    Identifiable();
    ~Identifiable();
    void registerId();
    void clearId();
    bool matches(const Identifiable* identifiable) const;
private:
    unsigned int id;
    static unsigned int nextIdToAdd;
    static std::queue<unsigned int> idsToGive;
protected:
    unsigned int getId() const;
};