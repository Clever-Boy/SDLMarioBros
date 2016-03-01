#pragma once

#include <string>
#include <vector>
#include <map>

#include "text.h"

class UIManager {

public:
	UIManager();

	void Draw(Graphics* graph);
	void Update(Graphics* graph);
	void AddText(Graphics* graph,std::string text, int x, int y, std::string label);
	void EditText(std::string text,std::string label);
	void RemoveText(std::string label);

private:
	std::vector<Text> m_text;
	std::map<std::string, int> m_labelText;

};