#include "levelcontent.h"

void UpdateContent(LevelContent* m_content,SDL_Rect camera)
{
	for (unsigned int i = 0; i < m_content->ennemies.size(); ++i)
	{
		m_content->ennemies.at(i).Update(m_content->tileMap);
		for (unsigned int j = 0; j < m_content->bullets.size(); ++j)
		{
			if (CheckCollision(m_content->ennemies.at(i).GetRect(),
				m_content->bullets.at(j).GetRect()))
			{
				m_content->bullets.erase(m_content->bullets.begin() + j);
				m_content->ennemies.erase(m_content->ennemies.begin() + i);
			}
		}

	}
	for (unsigned int i = 0; i < m_content->items.size(); ++i)
	{
		if (isOutScreen(camera, m_content->items.at(i).GetRect()))
			m_content->items.erase(m_content->items.begin() + i);
		else
			m_content->items.at(i).Update(m_content->tileMap);	

	}	
	for (unsigned int j = 0; j < m_content->bullets.size(); ++j)
	{
		m_content->bullets.at(j).Update(m_content->tileMap);
		if (m_content->bullets.at(j).isEnd() || isOutScreen(camera, m_content->bullets.at(j).GetRect()))
			m_content->bullets.erase(m_content->bullets.begin() + j);
	}	
}

void DrawContent(LevelContent* m_content, Graphics* graph, SDL_Rect* camera)
{
	for (int i = 0; i < TOTAL_TILES; ++i) {
		if (m_content->tileMap[i]->CheckCollision(*camera))
			m_content->tileMap[i]->Draw(graph, camera->x, camera->y);
	}
	for (unsigned int i = 0; i < m_content->ennemies.size(); ++i)
	{
		m_content->ennemies.at(i).Draw(graph, camera->x, camera->y);
	}
	for (unsigned int i = 0; i < m_content->items.size(); i++)
	{
		m_content->items.at(i).Draw(graph, camera->x, camera->y);
	}
	for (unsigned int i = 0; i < m_content->bullets.size(); i++)
	{
		m_content->bullets.at(i).Draw(graph, camera->x, camera->y);
	}
}
