#ifndef XMLSCENEBUILDER_H

#define XMLSCENEBUILDER_H

#include <vector>
#include <string>

#include "../utils/rapidxml/rapidxml.hpp"
#include "../utils/rapidxml/rapidxml_utils.hpp"

#include "../headers/Scene.h"
#include "../headers/Figure3D.h"
#include "../headers/TreeNode.h"
#include "../headers/TreeScene.h"

class XMLSceneBuilder
{
protected:
	std::vector<std::pair<std::string, Figure3D*> > objects; //3D objects for scene
	std::string filename; //filename of XML file

	//functionalities
	TreeNode* addOBJObject(TreeNode*, rapidxml::xml_node<>*);
	TreeScene* createScene(rapidxml::xml_node<>*);
	Point getPosition(rapidxml::xml_node<>*);
	Point getRotation(rapidxml::xml_node<>*);
	TreeNode* getNode(rapidxml::xml_node<>* node);
	TreeNode* getOBJObject(rapidxml::xml_node<>*);
	Figure3D* findFigure(string); //finds figure and return pointer to it

public:
	XMLSceneBuilder(std::string); //load objects
	Scene* buildScene();

};

#endif
