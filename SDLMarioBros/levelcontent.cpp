#include "levelcontent.h"

void UpdateContent(LevelContent* m_content,SDL_Rect camera)
{
	for (unsigned int i = 0; i < m_content->ennemies.size(); ++i)
	{
		m_content->ennemies.at(i).Update(m_content->tileMap);
	}

	for (unsigned int i = 0; i < m_content->items.size(); ++i)
	{
		m_content->items.at(i).Update(m_content->tileMap);
	}
	for (unsigned int i = 0; i < m_content->bullets.size(); ++i)
	{
		m_content->bullets.at(i).Update(m_content->tileMap);
		if (m_content->bullets.at(i).isEnd() || isOutScreen(camera, m_content->bullets.at(i).GetRect()))
			m_content->bullets.erase(m_content->bullets.begin() + i);
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
