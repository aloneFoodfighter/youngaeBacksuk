#pragma once

#define RANDOM					RandomSingleton::GetInstance()

class RandomSingleton
{
	SINGLETONE(RandomSingleton)

private:

public:
	inline int GetInt(int num) { return rand() % num; }

	inline int GetFromIntTo(int fromNum, int toNum)
	{
		return rand() % (toNum - fromNum + 1) + fromNum;
	}

	inline float GetFloat(float num)
	{
		return ((float)rand() / (float)RAND_MAX) * num;
	}

	inline float GetFromFloatTo(float fromNum, float toNum)
	{
		float rnd = (float)rand() / (float)RAND_MAX;
		return (rnd * (toNum - fromNum) + fromNum);
	}

};

