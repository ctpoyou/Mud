
#include "AbstractActor.h"

namespace mud
{
	namespace actor
	{
		const std::pair<int, int> AbstractActor::getPosition() const
		{
			return position;
		}

		void AbstractActor::setPoisition(const std::pair<int, int>& pos)
		{
			position = pos;
		}

		void AbstractActor::update()
		{
			--turnPoint;

			if (turnPoint <= 0)
			{
				onMyTurn();
				turnPoint = maxTurnPoint;
			}
		}

		void AbstractActor::draw(mud::graphics::ConsoleGraphics& spriteBatch)
		{
			std::pair<int, int> position = getPosition();
			spriteBatch.write(position.first, position.second, icon);
		}
	}
}