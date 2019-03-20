#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include "../ECS/IComponent.h"
#include "../../Vector.h"

class TransformComponent {

public:
	Math::Vec2 position;
	float angle;
};

#endif // !TRANSFORMCOMPONENT_H

