/*
  Copyright 2011 Mats Sjöberg
  
  This file is part of the Heebo programme.
  
  Heebo is free software: you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  Heebo is distributed in the hope that it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
  or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
  License for more details.
  
  You should have received a copy of the GNU General Public License
  along with Heebo.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "mapwidget.h"

//------------------------------------------------------------------------------

MapWidget::MapWidget(GameMap* map, QWidget* parent) :
  QGraphicsView(parent),
  m_map(map)
{
  m_scene = new QGraphicsScene(this);
  populateScene();
  setScene(m_scene);
  show();
}

//------------------------------------------------------------------------------

void MapWidget::populateScene() {
  int w = 60, h = 60;

  QBrush wall(Qt::lightGray);
  QBrush floor(Qt::black);

  for (int j=0; j<m_map->height(); j++) {
    for (int i=0; i<m_map->width(); i++) {
      QChar ch = m_map->at(j, i);
      m_scene->addRect(QRectF(i*w, j*h, w, h), QPen(),  ch == 'W' ? wall : floor); 
    }
  }
      
}
