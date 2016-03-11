#include "levelcontent.h"

void UpdateContent(LevelContent* m_content)
{
	for (unsigned int i = 0; i < m_content->ennemies.size(); ++i)
	{
		m_content->ennemies.at(i).Update(m_content->tileMap);
	}

	for (unsigned int i = 0; i < m_content->items.size(); ++i)
	{
		m_content->items.at(i).Update(m_content->tileMap);
	}
}
