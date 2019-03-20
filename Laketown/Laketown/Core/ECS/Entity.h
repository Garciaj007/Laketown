#ifndef ENTITY_H
#define ENTITY_H

#include "IComponent.h"
#include "ISystem.h"
#include <vector>

//Forward Declarations
class TransformComponent;

class Entity {
	//Members
	int entityID;
	std::vector<IComponent> components;
public:
	//Constructor Destructor
	Entity(TransformComponent transform);
	~Entity();

	//Methods
	void AddComponent(IComponent* component);
	bool RemoveComponent(int componentID);
	void Destroy();

private:
	void RegisterComponent(ISystem* system);
	void RemoveAllComponents();
	
};

#endif // !ENTITY_H

