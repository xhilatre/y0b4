#ifndef MAP_H
#define MAP_H
#include <SFML\Graphics.hpp>
using namespace sf;
const int HEIGHT_MAP = 25;	//высота
const int WIDTH_MAP = 40;	//ширина

String TileMap[HEIGHT_MAP] = {	//карта
	"0000000000000000000000000000000000000000",
	"0    s                                 0",
	"0     s                                0",
	"0      s                               0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                  s                   0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0000000000000000000000000000000000000000",
};

#endif