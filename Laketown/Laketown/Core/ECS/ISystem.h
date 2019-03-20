#ifndef ISYSTEM_H
#define ISYSTEM_H

#include <vector>
#include "IComponent.h"

class ISystem {
protected:
	std::vector<const IComponent> components;

public:
	virtual void RegisterComponents(const IComponent*) = 0;
	virtual void UpdateComponents() = 0;
	virtual bool RefreshComponents() = 0;
};

#endif 

