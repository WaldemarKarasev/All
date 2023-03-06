#include <cmath>

bool isAlmostEqual(double a, double b, double epsilon)
{
	
	return fabs(a - b) <= epsilon;;
}

bool approximatelyEqual(double a, double b, double epsilon)
{
	return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon) //absEpsilon - абсолютное значение близкое к 0, relEpsilon - разница в процентах, для алгоритма Кнута
{
	if (fabs(a - b) <= absEpsilon)
		return true;
	else
		return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * relEpsilon);
}