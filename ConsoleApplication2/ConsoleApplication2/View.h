#ifndef VIEW_H
#define VIEW_H
#include <SFML/Graphics.hpp>
using namespace sf;

View view;

View getPlayerCoordsForView(float x, float y) {	//������� ��������� ��������� ��� ������
	view.setCenter(x, y);	//������������� ������
	return view;
}

#endif VIEW_H
