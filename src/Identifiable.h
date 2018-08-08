#pragma once

#include <queue>

#define ID_MAX 2

#define ID_DRAWABLE 0
#define ID_ONSCREEN_BUTTON 1
#define ID_DECIMATED_PROCESS 0

class Identifiable
{
public:
	Identifiable();
	~Identifiable();
	void registerId(const unsigned int& idIndex);
	void clearId(const unsigned int& idIndex);
	bool matches(const Identifiable* identifiable,
				 const unsigned int& idIndex) const;
private:
	unsigned int id[ID_MAX];
	static unsigned int nextIdToAdd;
	static std::queue<unsigned int> idsToGive;
protected:
	unsigned int getId(const unsigned int& idIndex) const;
};