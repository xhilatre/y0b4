#ifndef ANIM_H
#define ANIM_H
#include <SFML\Graphics.hpp>
using namespace sf;

class Player {
	float x = 0, y = 0;
public:
	float w, h, dx, dy, speed = 0;
	int dir = 0;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;
	//блок выше - инициализация переменных класса игрока
	Player(String F, int X, int Y, float W, float H) { //конструктор с параметрами для класса игрок
		File = F;
		image.loadFromFile("images/" + File);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = X, y = Y;
		sprite.setTextureRect(IntRect(W, H, W, H));
	}
	void update(float time) //метод обновления персонажа, анимации, направления и скорости движения
	{
		switch (dir)
		{
		case 0: dx = speed; dy = 0; break; //right
		case 1: dx = speed; dy = speed; break; //rught-up
		case 2: dx = 0; dy = speed; break; //up
		case 3: dx = -speed; dy = speed; break;//left-up
		case 4: dx = -speed; dy = 0; break; // left
		case 5: dx = -speed; dy = -speed; break; //left-bot
		case 6: dx = 0; dy = -speed; break; // bot
		case 7: dx = speed; dy = -speed; break;// right-bot
		}
		x += dx*time;
		y += dy*time;

		speed = 0; //обнуляем скорость, чтобы персонаж остановился после отпускания клавиши(если не отпускать - не остановится)
		sprite.setPosition(x, y); //изменение положения спрайта персонажа(игрока)
	}

	float getPlayerX() {	//метод получения координат по иксу
		return x;
	}

	float getPlayerY() {	//метод получения координат по игреку
		return y;
	}
};
#endif // !ANIM_H
