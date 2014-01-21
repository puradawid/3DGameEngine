
#include "..\headers\EnemyObject.h"
#include <math.h>
class SpiralEnemyStrategy : public EnemyObject
{
private:
	std::vector<std::pair<double,double>> points;
	std::vector<std::pair<double, double>>::iterator pointsIterator;
	int centerX = 0, centerY = 0, radius = 100;
	double angleStep = .01;
	double pi = 2 * 2 * M_PI;
	double x = 0, y = 0, currentX,currentY;
	int count = 0;
	int current = 0;
	bool firstRun = true;
	void calculate(){
		for (double currentAngle = 0; currentAngle < -1; currentAngle -= angleStep){
			x = centerX + cos(currentAngle * pi) * radius;
			y = centerY + sin(currentAngle * pi) * radius;
			count++;
			points.push_back(std::make_pair(x, y));
		}
	};

public:

	virtual void nextMove()
	{
		if (firstRun == true){
			calculate();
			firstRun = false;
			pointsIterator = points.begin();
			currentX = pointsIterator->first;
			currentY = pointsIterator->second;
			pointsIterator++;
		}
		else {
			if (pointsIterator != points.end()){
				this->move(SimplePoint(currentX - pointsIterator->first, 0, currentY - pointsIterator->second));
				currentX = pointsIterator->first;
				currentY = pointsIterator->second;
				pointsIterator++;
			}
			else {
				pointsIterator = points.begin();
			}
		}
		
	}

};