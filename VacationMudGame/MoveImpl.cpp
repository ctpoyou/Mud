
#include "MoveImpl.h"
#include <utility>

namespace mud
{
	namespace actor
	{
		namespace action
		{
			void MoveImpl::move(int dirX, int dirY) const
			{
				std::pair<int, int> pos = actor.getPosition();

				pos.first += dirX;
				pos.second += dirY;

				actor.setPoisition(pos);
			}
		}
	}
}