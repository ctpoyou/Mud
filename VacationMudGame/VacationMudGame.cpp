// VacationMudGame.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.

#include<utility>
#include<functional>

#include "ConsoleGraphics.h"
#include "PlayerCharacter.h"
#include "InputHandler.h"

#include "Projectile.h"

#include "rlutil.h"

int main()
{
	std::function<void(mud::actor::AbstractActor&, mud::actor::AbstractActor&)> noAction = [](mud::actor::AbstractActor& a, mud::actor::AbstractActor& b) {};
	mud::actor::PlayerCharacter player(std::pair<int, int>(10, 10), 5);

	mud::actor::Projectile projectile(noAction, std::pair<int, int>(1, 1), std::pair<int, int>(1, 0), 1);

	int cnt = 0;

	while (true)
	{
		player.draw(mud::graphics::ConsoleGraphics::getInstance());
		projectile.draw(mud::graphics::ConsoleGraphics::getInstance());
		mud::graphics::ConsoleGraphics::getInstance().draw();

		//mud::input::InputHandler::getInstance().update();

		player.update();
		projectile.update();
		//mud::input::InputHandler::getInstance().clearInputQueue();

		/*++cnt;

		if (cnt == 4)
		{
			cnt = 0;
			player.draw(mud::graphics::ConsoleGraphics::getInstance());
			mud::graphics::ConsoleGraphics::getInstance().draw();
		}*/
	}
	
}