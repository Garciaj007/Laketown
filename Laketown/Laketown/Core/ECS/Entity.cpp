#include "Entity.h"
#include "../Components/TransformComponent.h"

Entity::Entity(TransformComponent transform) {

}

Entity::~Entity() {

}

void Entity::RegisterComponent(ISystem* system) {

}

void Entity::AddComponent(IComponent* component) {
	
}	

bool Entity::RemoveComponent(int componentID) {
	 
}	 
void Entity::RemoveAllComponents() {
	 
}	

void Entity::Destroy() {

}

