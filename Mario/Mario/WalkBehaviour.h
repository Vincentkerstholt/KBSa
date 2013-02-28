
class WalkBehaviour 
{
private:

public:
	virtual void Walk() = 0;
};


class NormalWalk : public WalkBehaviour 
{
private:

public:

	void Walk(){}
};
