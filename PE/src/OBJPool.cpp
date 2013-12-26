#include "../headers/OBJPool.h"
#include "../headers/OBJBuilder.h"

OBJPool::~OBJPool()
{
	for(auto ptr : meshes)
	{
		delete ptr.second;
	}
}

Mesh* OBJPool::getMesh(MeshBuildStrategy* mbs, std::string res_name)
{
	OBJMesh m = NULL;
	for(auto item : meshes)
	{
		if(item.first == res_name)
			m = item.second;
	}
	if(m == NULL)
	{
		m = parseOBJ(res_name);
	}

	return mbs->getMesh(m);
}

OBJMesh OBJPool::parseOBJ(std::string res_name)
{
	OBJBuilder b(const_cast<char*>(res_name.c_str()));
	return b.build();
}