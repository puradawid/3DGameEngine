#ifndef ANIMATION_H
#define ANIMATION_H

#include "TreeNode.h"
#include "Frame.h"

#include <vector>

class Animation
{
protected:
	TreeNode* object;
	std::vector<Frame*> frames;
	GLboolean playing;
public:
	Animation()
	{
		object = NULL;
		playing = false;
	}
	void assignNode(TreeNode* object)
	{
		this->object = object;
	}
	void setNextFrame(Frame* frame)
	{
		this->frames.push_back(frame);
	}
	void tick(GLint ms)
	{
		Point new_position;
		Point new_angle;
		Point new_scale;

		int frames_count = frames.size() - 1; // Je¿eli i = ostatnia klatka to koniec animacji
		for (int i = 0; i < frames_count; i++)
		{
			if (frames[i]->elapsed_time <= ms && frames[i + 1]->elapsed_time >= ms)
			{
				GLfloat alpha = (((GLfloat)frames[i + 1]->elapsed_time - ms) / (GLfloat)(frames[i + 1]->elapsed_time - frames[i]->elapsed_time)); // Rzutowanie na float?

				new_position.x = alpha * frames[i]->translation.x + (1.0f - alpha) * frames[i + 1]->translation.x;
				new_position.y = alpha * frames[i]->translation.y + (1.0f - alpha) * frames[i + 1]->translation.y;
				new_position.z = alpha * frames[i]->translation.z + (1.0f - alpha) * frames[i + 1]->translation.z;

				new_angle.x = alpha * frames[i]->rotation.x + (1.0f - alpha) * frames[i + 1]->rotation.x;
				new_angle.y = alpha * frames[i]->rotation.y + (1.0f - alpha) * frames[i + 1]->rotation.y;
				new_angle.z = alpha * frames[i]->rotation.z + (1.0f - alpha) * frames[i + 1]->rotation.z;

				new_scale.x = alpha * frames[i]->scale.x + (1.0f - alpha) * frames[i + 1]->scale.x;
				new_scale.y = alpha * frames[i]->scale.y + (1.0f - alpha) * frames[i + 1]->scale.y;
				new_scale.z = alpha * frames[i]->scale.z + (1.0f - alpha) * frames[i + 1]->scale.z;

				object->moveObject(new_position);
				object->rotateObject(new_angle);
				// scale ?

				// Przejscie po dzieciach

				break;
			}
		}
	}
	GLboolean is_playing()
	{
		if (playing)
			return true;
		else
			return false;
	}
	void start_playing()
	{
		playing = true;
	}
	void stop_playing()
	{
		playing = false;
	}
};

#endif
