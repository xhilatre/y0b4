#include <SFML\Graphics.hpp>
#include "anim.h"
#include "map.h"
#include "View.h"
using namespace sf;
int main()
{
	RenderWindow window(VideoMode(640, 480), "anus"); //инициализация окна с разрешением
	view.reset(FloatRect(0, 0, 300, 300)); //инициализация вида

	Image map_image; //инициализация картинки карты
	map_image.loadFromFile("images/map.png"); //загрузка картинки карты
	Texture map; //текстуризация карты
	map.loadFromImage(map_image); //загрузка текстуры карты
	Sprite s_map; //инициализация спрайта
	s_map.setTexture(map); //загрузка текстуры в спрайт
	 
	Player p("1.png", 0, 0, 32, 32); //инициализация игрока

	float CurrentFrame = 0;
	Clock clock; //инициализация таймера

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();	//таймер для стабилизации времени в игре
		clock.restart(); //перезапуск таймера, чтобы 
		time = time / 60; //скорость течения времени
		Event event; //ивент закрытия окна

		while (window.pollEvent(event))   //это
		{
			if (event.type == Event::Closed)//это
				window.close();//и это - закрытие окна


			//начало блока управления//
			if ((Keyboard::isKeyPressed(Keyboard::Left))) {
				p.dir = 4;	p.speed = 0.2;
				CurrentFrame += 0.01*time;
				if (CurrentFrame > 3) CurrentFrame -= 3;
				p.sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 96, 32, 32));
				getPlayerCoordsForView(p.getPlayerX(), p.getPlayerY());
			}

			if ((Keyboard::isKeyPressed(Keyboard::Right))) {
				p.dir = 0; p.speed = 0.2;
				CurrentFrame += 0.01*time;
				if (CurrentFrame > 3) CurrentFrame -= 3;
				p.sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 32, 32, 32));
				getPlayerCoordsForView(p.getPlayerX(), p.getPlayerY());
			}

			if ((Keyboard::isKeyPressed(Keyboard::Up))) {
				p.dir = 6; p.speed = 0.2;
				CurrentFrame += 0.01*time;
				if (CurrentFrame > 3) CurrentFrame -= 3;
				p.sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 64, 32, 32));
				getPlayerCoordsForView(p.getPlayerX(), p.getPlayerY());
			}

			if ((Keyboard::isKeyPressed(Keyboard::Down))) {
				p.dir = 2; p.speed = 0.2;
				CurrentFrame += 0.01*time;
				if (CurrentFrame > 3) CurrentFrame -= 3;
				p.sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 0, 32, 32));
				getPlayerCoordsForView(p.getPlayerX(), p.getPlayerY());
			}
			//конец блока управления//

		}
	
		p.update(time); //обновлям игрока
		window.setView(view); //оживляем вид
		window.clear(); //отчищаем экран от предыдущего кадра
		for (int i = 0; i < HEIGHT_MAP; i++)     //инициализация карты
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if ((TileMap[i][j] == ' ')) s_map.setTextureRect(IntRect(0, 0, 32, 32)); // probell - 1 kvadrat
				if ((TileMap[i][j] == 's')) s_map.setTextureRect(IntRect(32, 0, 32, 32)); // s - 2 kvadrat
				if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32)); // 0 - 3 kvadrat

				s_map.setPosition(j * 32, i * 32); //выделяем каждому блоку свое место
				window.draw(s_map); //рисуем карту

			}
		window.draw(p.sprite);	//рисуем персонажа
		window.display(); //обновляем экран
	}
}