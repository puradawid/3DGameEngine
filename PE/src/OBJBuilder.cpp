
#include "../headers/OBJBuilder.h"

#include <iostream>
#include <fstream>
#include <string>
#include <GL/gl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

OBJBuilder::IndexedPoint getIndexedPoint(string);

OBJBuilder::OBJBuilder(char* filename)
{
	//phase first load elements
	std::string line;
	ifstream file(filename);
	if (file.is_open())
	{
		while(getline(file, line))
		{
			if(line.find("vn") == 0)
			{
				istringstream s(line.substr(2));
				GLdouble x,y,z;
				s >> x >> y >> z;
				normals.push_back(SimplePoint(x,y,z));
				continue;
			}
			if(line.find("vt") == 0)
			{
				istringstream s(line.substr(2));
				GLdouble x,y,z;
				s >> x >> y >> z;
				textures.push_back(SimplePoint(x,y,z));
				continue;
			}
			if(line.find("v") == 0)
			{
				istringstream s(line.substr(1));
				GLdouble x,y,z;
				s >> x >> y >> z;
				vertexes.push_back(SimplePoint(x,y,z));
				continue;
			}
			if(line.find("f") == 0)
			{
				line = line.substr(line.find(" ") + 1); //forward trim space
				if(line[line.length() - 1] == ' ' )
					line = line.substr(0, line.find_last_of(" ")); //trim backward space
				string a_str = line.substr(0, line.find(" "));
				line = line.substr(line.find(" ") + 1);
				string b_str = line.substr(0, line.find(" "));
				string c_str = line.substr(line.find(" ") + 1);
				IndexedPoint a = getIndexedPoint(a_str);
				IndexedPoint b = getIndexedPoint(b_str);
				IndexedPoint c = getIndexedPoint(c_str);
				triangles.push_back(Triangle(a,b,c));
				continue;
			}
		}
		file.close();
	}

	//second phase - build points
	int facessize = triangles.size();
	for(int i = 0; i < facessize; i++)
	{
		//create new vector
		vector<Point>* vect = new vector<Point>(3);
		Triangle triangle = triangles[i];
		IndexedPoint indexes[3];

		indexes[0] = triangle.a;
		indexes[1] = triangle.b;
		indexes[2] = triangle.c;

		for(int j = 0; j < 3; j++)
		{
			Point p_ptr = Point();

			p_ptr.x = vertexes[indexes[j].v - 1].x;
			p_ptr.y = vertexes[indexes[j].v - 1].y;
			p_ptr.z = vertexes[indexes[j].v - 1].z;

			p_ptr.normal.x = normals[indexes[j].n - 1].x;
			p_ptr.normal.y = normals[indexes[j].n - 1].y;
			p_ptr.normal.z = normals[indexes[j].n - 1].z;

			if(textures.size() != 0)
			{
				p_ptr.texture.x = textures[indexes[j].t].x;
				p_ptr.texture.y = textures[indexes[j].t].y;
				p_ptr.texture.z = textures[indexes[j].t].z;
			}

			(*vect)[j] = p_ptr;
		}
		meshes.push_back(vect);
	}

}

std::vector<std::vector<Point>*>* OBJBuilder::build()
{
	/*
	Figure3D* figure = new Figure3D();
	int triangles_size = meshes.size();
	for(int i = 0; i < triangles_size; i++)
		figure->addPolygon(meshes[i]->data(), meshes[i]->size());

	return figure;
	*/
	std::vector<std::vector<Point>*>* mesh = new std::vector<std::vector<Point>*>();
	int triangles_size = meshes.size();
	std::vector<std::vector<Point>*>* v = new std::vector<std::vector<Point>*>();
	for(std::vector<Point>* item : meshes)
	{
		v->push_back(item);
	}

	return v;
}

OBJBuilder::IndexedPoint getIndexedPoint(string phrase)
{
	GLint v,t,n;
	v = atoi(phrase.substr(0, phrase.find("/")).c_str());
	phrase = phrase.substr(phrase.find("/") + 1);
	t = atoi(phrase.substr(0, phrase.find("/")).c_str());
	phrase = phrase.substr(phrase.find("/") + 1);
	n = atoi(phrase.c_str());

	return OBJBuilder::IndexedPoint(v,t,n);
}
