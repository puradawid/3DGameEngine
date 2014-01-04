#ifndef ANIMATIONBUILDER_H
#define ANIMATION_BUILDER

#include "Animation.h"
#include "Frame.h"
#include "../utils/rapidxml/rapidxml.hpp"
#include "Point.h"

#include <string>

class AnimationBuilder
{
protected: 
	static Point getPoint(rapidxml::xml_node<>* node)
	{
		Point p;
		p.x = atof(node->first_node("x")->value());
		p.y = atof(node->first_node("y")->value());
		p.z = atof(node->first_node("z")->value());
		return p;
	};

	static rapidxml::xml_node<>* getAnimationNode(std::string source)
	{
		rapidxml::xml_document<> doc;
		doc.parse<0>(const_cast<char*>(source.c_str()));

		rapidxml::xml_node<>* animation = doc.first_node("animation");
		rapidxml::xml_node<>* frame = animation->first_node("frame");
		return animation;
	};

	static Frame* getFrameFromNode(rapidxml::xml_node<>* frame_node)
	{
		Point rotation = AnimationBuilder::getPoint(frame_node->first_node("rotation"));
		Point translation = AnimationBuilder::getPoint(frame_node->first_node("translation"));
		Point scale = AnimationBuilder::getPoint(frame_node->first_node("scale"));
		int elapsed_time = atoi(frame_node->first_node("elapsed_time")->value());
		Frame* returned = new Frame(rotation, scale, translation, elapsed_time);
		return returned;
	};

public:
	static Animation* parseAnimation(std::string resource_path)
	{
		Animation* anim = new Animation();

		ifstream t(resource_path.c_str());
		if(t.eof()) return NULL;
		string str;
		t.seekg(0, std::ios::end);
		str.reserve(t.tellg());
		t.seekg(0, std::ios::beg);

		str.assign((std::istreambuf_iterator<char>(t)),
		            std::istreambuf_iterator<char>());

		rapidxml::xml_node<>* animation = AnimationBuilder::getAnimationNode(str);
		rapidxml::xml_node<>* first_frame = animation->first_node("frame");
		while(first_frame != NULL)
		{
			anim->setNextFrame(getFrameFromNode(first_frame));
			first_frame = first_frame->next_sibling("frame");
		}
		return anim;
	}

};

#endif