#ifndef VIEW_H
#define VIEW_H
#include <SFML/Graphics.hpp>
using namespace sf;

View view;

View getPlayerCoordsForView(float x, float y) {	//функция получения координат для камеры
	view.setCenter(x, y);	//центрирование камеры
	return view;
}

#endif VIEW_H
