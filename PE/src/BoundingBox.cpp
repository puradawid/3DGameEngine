#include "../headers/BoundingBox.h"

#include <GL/gl.h>
#include <limits>

#include "../headers/Game.h"

using namespace std;

BoundingBox::BoundingBox(Mesh* mesh)
{
	translation_vector = SimplePoint(0,0,0);
	scale_vector = SimplePoint(1,1,1);
	rotation_vector = SimplePoint(0,0,0);

	generateFrom(mesh);
}

void BoundingBox::generateFrom(Mesh* mesh)
{
	int mesh_size = mesh->getSize();
	vector<SimplePoint> points;
	for(int i = 0; i < mesh_size; i++)
	{
		Point p = mesh->getPoint(i);
		SimplePoint sp(p.x, p.y, p.z);
		points.push_back(sp);
	}
	
	pair<SimplePoint, SimplePoint> calc_points = getVectorFromPoints(points);
	
	rel_min = calc_points.first;
	rel_max = calc_points.second;
}

void drawLine(vector<SimplePoint> points, int i, int j)
{
	glBegin(GL_LINES);
	glVertex3f(points[i].x, points[i].y, points[i].z);
	glVertex3f(points[j].x, points[j].y, points[j].z);
	glEnd();
}


void BoundingBox::render()
{
	vector<SimplePoint> points = getAllPoints(min, max);
	
	glPushMatrix();

	glLoadIdentity();

	Game::getGameInstance()->getScene()->getCurrentCamera()->updateWorld();

	drawLine(points, 0, 1);
	drawLine(points, 1, 2);
	drawLine(points, 2, 3);
	drawLine(points, 3, 4);
	drawLine(points, 4, 5);
	drawLine(points, 5, 6);
	drawLine(points, 6, 7);
	drawLine(points, 7, 4);
	drawLine(points, 0, 3);
	drawLine(points, 5, 0);
	drawLine(points, 1, 6);
	drawLine(points, 2, 7);

	glPopMatrix();
}

void BoundingBox::recalculate()
{
	//get all points from min and max
	//check min and max from points
	vector <SimplePoint> cube = getAllPoints(rel_min, rel_max);
	for(int i = 0 ; i < 8; i++)
		cube[i] = cube[i].rotate(rotation_vector).translate(translation_vector).scale(scale_vector);
	pair<SimplePoint, SimplePoint> corners = getVectorFromPoints(cube);
	min = corners.first;
	max = corners.second;
}

void BoundingBox::translate(SimplePoint p)
{
	this->translation_vector = p;
	recalculate();
}

void BoundingBox::scale(SimplePoint p)
{
	this->scale_vector = p;
	recalculate();
}

void BoundingBox::rotate(SimplePoint p)
{
	this->rotation_vector = p;
	recalculate();
}

vector<SimplePoint> BoundingBox::getAllPoints(SimplePoint min, SimplePoint max)
{
	vector<SimplePoint> bb(8);

	double width = max.x - min.x;
	double height = max.y - min.y;
	double depth = max.z - min.z;

	bb[0] = min;
	bb[1] = SimplePoint(min.x, min.y, min.z + depth);
	bb[2] = SimplePoint(min.x + width, min.y, min.z + depth);
	bb[3] = SimplePoint(min.x + width, min.y, min.z);
	bb[4] = SimplePoint(min.x + width, min.y + height, min.z);
	bb[5] = SimplePoint(min.x, min.y + height, min.z);
	bb[6] = SimplePoint(min.x, min.y + height, min.z + depth);
	bb[7] = max;

	return bb;
}

pair<SimplePoint, SimplePoint> BoundingBox::getVectorFromPoints(vector<SimplePoint> points)
{
	double dbl_min = -std::numeric_limits<double>::max();
	double dbl_max = std::numeric_limits<double>::max();
	SimplePoint min(dbl_max, dbl_max, dbl_max), max(dbl_min, dbl_min, dbl_min);
	int points_size = points.size();
	for(int i = 0; i < points_size; i++)
	{
		if(min.x > points[i].x) min.x = points[i].x;
		if(max.x < points[i].x) max.x = points[i].x;

		if(min.y > points[i].y) min.y = points[i].y;
		if(max.y < points[i].y) max.y = points[i].y;

		if(min.z > points[i].z) min.z = points[i].z;
		if(max.z < points[i].z) max.z = points[i].z;
	}

	return pair<SimplePoint, SimplePoint>(min, max);
}

bool BoundingBox::collision(BoundingBox* collisioned)
{
	SimplePoint b_min = collisioned->min;
	SimplePoint b_max = collisioned->max;
	return b_max.x > min.x  &&
		b_max.y > min.y  &&
		b_max.z > min.z  && 
		b_min.x < max.x  &&
		b_min.y < max.y  &&
		b_min.z < max.z;
}