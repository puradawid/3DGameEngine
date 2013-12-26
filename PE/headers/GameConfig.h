#ifndef GAMECONFIG_H
#define GAMECONFIG_H

#include <vector>
#include <utility>
#include <string>
#include <cstdlib>

class GameConfig
{
protected:
	std::vector<std::pair<std::string, std::string> > config;
public:
	GameConfig() {}
	std::string getAttribute(std::string attr_name) 
	{
		for(int i = 0 ; i < config.size(); i++)
			if(config[i].first == attr_name)
				return config[i].second;
		return NULL;
	}
	int getIntAttribute(std::string attr_name)
	{
		std::string res;
		for(int i = 0 ; i < config.size(); i++)
			if(config[i].first == attr_name)
				res = config[i].second;
		if(res == "") return 0;
		return atoi(res.c_str());
	}
};

class TypicalConfig : public GameConfig
{
public:
	TypicalConfig() : GameConfig()
	{
		config.push_back(std::pair<std::string, std::string>("h_resolution", "800"));
		config.push_back(std::pair<std::string, std::string>("v_resolution", "600"));
		config.push_back(std::pair<std::string, std::string>("window_name", "Powered by PenetrationEngine - Pura&Rewucki Development"));
	}
};

#endif
