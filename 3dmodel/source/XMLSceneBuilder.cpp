#include "../headers/XMLSceneBuilder.h"

#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <GL/gl.h>

//include local headers
#include "../headers/Figure3DNode.h"
#include "../headers/OBJBuilder.h"
#include "../headers/Figure3DNode.h"
#include "../headers/MaterialRenderStrategy.h"
#include "../headers/GLRenderStrategy.h"

using namespace std;

XMLSceneBuilder::XMLSceneBuilder(string filename)
{
	this->filename = filename;
}

Scene* XMLSceneBuilder::buildScene(void)
{
	ifstream t(filename.c_str());
	if(t.eof()) return NULL;
	string str;
	t.seekg(0, std::ios::end);
	str.reserve(t.tellg());
	t.seekg(0, std::ios::beg);

	str.assign((std::istreambuf_iterator<char>(t)),
	            std::istreambuf_iterator<char>());
	rapidxml::xml_document<> doc;
	doc.parse<0>(const_cast<char*>(str.c_str()));

	rapidxml::xml_node<>* scene = doc.first_node("scene");
	Scene* scene_obj = createScene(scene);

	return scene_obj;
}

TreeScene* XMLSceneBuilder::createScene(rapidxml::xml_node<>* node)
{
	node->first_attribute("");
	TreeScene* scene = new TreeScene();
	scene->setRoot(getNode(node));
	return scene;
}

TreeNode* XMLSceneBuilder::getNode(rapidxml::xml_node<>* node)
{
	TreeNode* tree_node = new TreeNode();
	Point position(0,0,0);
	Point rotation(0,0,0);

	rapidxml::xml_node<>* pos_node = node->first_node("position");
	rapidxml::xml_node<>* obj_node = node->first_node("OBJobject");
	rapidxml::xml_node<>* chl_node = node->first_node("childs");
	rapidxml::xml_node<>* rot_node = node->first_node("rotation");

	if(obj_node != NULL)
	{
		delete tree_node;

		string filename(obj_node->first_node("obj_file")->value());
		Figure3D* mesh = findFigure(filename);
		if(mesh == NULL)
		{
			OBJBuilder obj(const_cast<char*>(filename.c_str()));
			mesh = obj.build();
			objects.push_back(pair<string, Figure3D*>(filename, mesh));
			MaterialRenderStrategy* mrs = new MaterialRenderStrategy(0.1, 0.5, 0.1);
			mesh->setRenderStrategy(dynamic_cast<GLRenderStrategy*>(mrs));
		}

		tree_node = new Figure3DNode(mesh);
	}

	if(pos_node != NULL)
		position = getPosition(pos_node);

	if(rot_node != NULL)
		rotation = getRotation(pos_node);

	tree_node->moveObject(position);
	tree_node->rotateObject(rotation);
	if(chl_node != NULL)
	{
		rapidxml::xml_node<>* first_child = chl_node->first_node("TreeNode");
		while(first_child != NULL)
		{
			tree_node->addChild(getNode(first_child));
			first_child = first_child->next_sibling("TreeNode");
		}
	}

	return tree_node;
}

Point XMLSceneBuilder::getPosition(rapidxml::xml_node<>* node)
{
	Point p;

	p.x = atof(node->first_node("x")->value());
	p.y = atof(node->first_node("y")->value());
	p.z = atof(node->first_node("z")->value());

	return p;
}

Point XMLSceneBuilder::getRotation(rapidxml::xml_node<>* node)
{
	Point p;

	p.x = atof(node->first_node("x")->value());
	p.y = atof(node->first_node("y")->value());
	p.z = atof(node->first_node("z")->value());

	return p;
}

Figure3D* XMLSceneBuilder::findFigure(string name)
{
	Figure3D* result = NULL;
	int vector_size = this->objects.size();
	for(int i = 0; i < vector_size; i++)
		if(objects[i].first == name)
			{ result = objects[i].second; break; }
	return result;
}
