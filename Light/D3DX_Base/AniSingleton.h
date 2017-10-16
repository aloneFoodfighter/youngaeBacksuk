#pragma once

#define ANIMATION_CLASS		AniSingleton::GetInstance()
#define G_ANIMATION			AniSingleton::GetInstance()->getDirection()

enum Direction
{
	STAY,
	FIRST, SECOND, THIRD, FOURTH, FIFTH,
	ROCK,
	HEAD
};

class AniSingleton
{
	SINGLETONE(AniSingleton)

private:
	Direction direction;

	bool first;
	bool second;
	bool third;
	bool fourth;
	bool fifth;
	bool head;

	bool light;

public:
	Direction getDirection()
	{
		return direction;
	}
	void setDirection(Direction direc)
	{
		direction = direc;
	}

	bool getLight() { return light; }

	void setLight(bool _light) { light = _light; }

	bool getFirst() { return first; }
	bool getSecond() { return second; }
	bool getThird() { return third; }
	bool getFourth() { return fourth; }
	bool getFifth() { return fifth; }
	bool getHead() { return head; }

	void setFirst(bool _first) { first = _first; }
	void setSecond(bool _second) { second = _second; }
	void setThird(bool _third) { third = _third; }
	void setFourth(bool _fourth) { fourth = _fourth; }
	void setFifth(bool _fifth) { fifth = _fifth; }
	void setHead(bool _head) { head = _head; }

};

