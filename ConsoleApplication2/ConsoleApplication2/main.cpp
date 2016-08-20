#include <SFML\Graphics.hpp>
#include "anim.h"
#include "map.h"
#include "View.h"
using namespace sf;
int main()
{
	RenderWindow window(VideoMode(640, 480), "anus"); //������������� ���� � �����������
	view.reset(FloatRect(0, 0, 300, 300)); //������������� ����

	Image map_image; //������������� �������� �����
	map_image.loadFromFile("images/map.png"); //�������� �������� �����
	Texture map; //������������� �����
	map.loadFromImage(map_image); //�������� �������� �����
	Sprite s_map; //������������� �������
	s_map.setTexture(map); //�������� �������� � ������
	 
	Player p("1.png", 0, 0, 32, 32); //������������� ������

	float CurrentFrame = 0;
	Clock clock; //������������� �������

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();	//������ ��� ������������ ������� � ����
		clock.restart(); //���������� �������, ����� 
		time = time / 60; //�������� ������� �������
		Event event; //����� �������� ����

		while (window.pollEvent(event))   //���
		{
			if (event.type == Event::Closed)//���
				window.close();//� ��� - �������� ����


			//������ ����� ����������//
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
			//����� ����� ����������//

		}
	
		p.update(time); //�������� ������
		window.setView(view); //�������� ���
		window.clear(); //�������� ����� �� ����������� �����
		for (int i = 0; i < HEIGHT_MAP; i++)     //������������� �����
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if ((TileMap[i][j] == ' ')) s_map.setTextureRect(IntRect(0, 0, 32, 32)); // probell - 1 kvadrat
				if ((TileMap[i][j] == 's')) s_map.setTextureRect(IntRect(32, 0, 32, 32)); // s - 2 kvadrat
				if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32)); // 0 - 3 kvadrat

				s_map.setPosition(j * 32, i * 32); //�������� ������� ����� ���� �����
				window.draw(s_map); //������ �����

			}
		window.draw(p.sprite);	//������ ���������
		window.display(); //��������� �����
	}
}