#ifndef ICOMPONENT_H
#define ICOMPONENT_H

class IComponent {
protected:
	int componentID;
	int id;
	bool active;

public:
	virtual void Create() = 0;
	virtual void Destroy() = 0;
};

#endif // !ICOMPONENT_H

