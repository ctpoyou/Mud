#pragma once

#include <utility>

#include "AbstractActor.h"
#include "MoveImpl.h"

namespace mud
{
	namespace actor
	{
		class PlayerCharacter :
			public AbstractActor
		{
		private:
			const action::MoveImpl moveImpl;

		public:
			PlayerCharacter(std::pair<int, int> position, int maxTurnPoint) : AbstractActor('@', position, maxTurnPoint), moveImpl(action::MoveImpl(*this)) { }
			~PlayerCharacter() { }

			void onMyTurn() override;
		};

	}
}

