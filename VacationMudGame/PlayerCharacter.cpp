#include "PlayerCharacter.h"

#include "InputHandler.h"

namespace mud
{
	namespace actor
	{
		void PlayerCharacter::onMyTurn()
		{
			input::InputKind kind = input::InputHandler::getInstance().getInput();

			switch (kind)
			{
			case input::UP:
				moveImpl.move(0, -1);
				break;
			case input::DOWN:
				moveImpl.move(0, 1);
				break;
			case input::LEFT:
				moveImpl.move(-1, 0);
				break;
			case input::RIGHT:
				moveImpl.move(1, 0);
				break;
			case input::SELECT:
				break;
			}
		}
	}
}

