#pragma once

#include "IUpdatable.h"

#include <list>

namespace mud
{
	namespace input
	{
		enum InputKind { UP, DOWN, LEFT, RIGHT, SELECT, NO_INPUT };
		class InputHandler : public IUpdatable
		{
		private:
			std::list<InputKind> inputQueue;

		private:
			InputHandler();
			
			InputHandler(const InputHandler& value);
			InputHandler(InputHandler&& value);

			InputHandler& operator=(const InputHandler& rhs);
			
		public:
			static InputHandler& getInstance();
			const InputKind getRecentInput();
			const InputKind getInput();

			virtual void update() override;

			void clearInputQueue();
		};
	}
}
