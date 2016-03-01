#include "uimanager.h"

UIManager::UIManager()
{
}

void UIManager::Draw(Graphics * graph)
{
	for (unsigned int i = 0; i < this->m_text.size(); i++)
	{
		this->m_text.at(i).Draw(graph);
	}
}

void UIManager::Update(Graphics * graph)
{
	for (unsigned int i = 0; i < this->m_text.size(); i++)
	{
		this->m_text.at(i).Update(graph);
	}
}

void UIManager::AddText(Graphics* graph,std::string text,int x, int y, std::string label)
{
	m_text.emplace_back(text, graph, x, y);
	m_labelText[label] = m_text.size() - 1;
}

void UIManager::EditText(std::string text,std::string label)
{
	m_text.at(m_labelText[label]).EditText(text);
}

void UIManager::RemoveText(std::string label)
{
	m_text.erase(m_text.begin() + m_labelText.at(label));
	m_labelText.erase(label);
}
