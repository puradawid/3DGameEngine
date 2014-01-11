#include "../headers/SceneIterator.h"
#include <stdlib.h>

bool SceneIterator::hasNext(){
	SceneNode* lastElement = this->end();
	if (current == NULL || path[0].first == NULL || lastElement == current){ // obvious
		return false;
	}
	else{
		return true;
	}	
}

SceneNode* SceneIterator::end(){
	if (current == NULL || path[0].first == NULL){ // obvious
		return NULL;
	}
	SceneNode* check = path[0].first;
	bool found = false;
	while (!found){ // find last element of the tree. 
		if (check->childs.size() != 0){
			check = check->childs[check->childs.size() - 1];
		}
		else {
			found = true;
		}
	}
	return check;
}
SceneNode* SceneIterator::next(){ // if path size is 0 we know we're starting from the root
	if (path.size() == 0){   
		if (current->childs.size() > 0){
			path.push_back(std::make_pair(current,0)); // add root to path
			current = current->childs[0];
			path.push_back(std::make_pair(current,0)); // add root's child to path
			return current;
		}
	}
	else {
		bool found = false;
		while (!found){ // indeed looks ugly but only idea that comes into my mind
			if (current->childs.size() > 0){
				if (path[path.size() - 1].second == current->childs.size()){ // visited every child? go up
					path.erase(path.end());
					current = path[path.size() - 1].first;
					path[path.size() - 1].second++; // lets tell the above node that this child has been visited
				}
				else if (path[path.size() - 1].second != current->childs.size()){ // not all children have been visited
					current = current->childs[path[path.size() - 1].second];
					path.push_back(std::make_pair(current, 0));
					found = true;
				}
			}
			else { // no children? remove last element from path and set current to the new last element in path
				if (path[path.size() - 1].second == 0){ // so if its the a node without children and the int value is 0 means we havent returned it yet so lets... go
					found = true;
					path[path.size() - 1].second++;
				}
				else { // second value is not 0 we've been there already... lets go back to the previous node
					path.erase(path.end());
					current = path[path.size() - 1].first;
					path[path.size() - 1].second++; // lets tell the above node that this child has been visited
				}
			}
		}
		return current;
	}
} 
