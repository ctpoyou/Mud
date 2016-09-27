
#include "InputHandler.h"

#include "rlutil.h"

namespace mud
{
	namespace input
	{
		InputHandler& InputHandler::getInstance()
		{
			static InputHandler instance;
			return instance;
		}

		InputHandler::InputHandler()
		{
			
		}

		const InputKind InputHandler::getRecentInput()
		{
			if (inputQueue.size() > 0)
			{
				return *(inputQueue.begin());
			}
			else
			{
				return NO_INPUT;
			}
		}

		void InputHandler::clearInputQueue()
		{
			inputQueue.clear();
		}

		const InputKind InputHandler::getInput()
		{
			{
				using namespace rlutil;

				int input = rlutil::getkey();
				switch (input)
				{
				case 72:
				case KEY_UP:
					return UP;
					break;
				case 80:
				case KEY_DOWN:
					return DOWN;
					break;
				case 75:
				case KEY_LEFT:
					return LEFT;
					break;
				case 77:
				case KEY_RIGHT:
					return RIGHT;
					break;
				case KEY_SPACE:
					return SELECT;
					break;
				}
			}

			return NO_INPUT;
		}

		void InputHandler::update()
		{
			{
				using namespace rlutil;

				int input = rlutil::nb_getch();
				switch (input)
				{
				case 72:
				case KEY_UP:
					inputQueue.push_back(UP);
					break;
				case 80:
				case KEY_DOWN:
					inputQueue.push_back(DOWN);
					break;
				case 75:
				case KEY_LEFT:
					inputQueue.push_back(LEFT);
					break;
				case 77:
				case KEY_RIGHT:
					inputQueue.push_back(RIGHT);
					break;
				case KEY_SPACE:
					inputQueue.push_back(SELECT);
					break;
				}
			}
		}
	}
}