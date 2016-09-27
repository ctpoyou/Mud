#pragma once

#include "AbstractActor.h"

namespace mud
{
	namespace actor
	{
		namespace action
		{
			class MoveImpl
			{
			private:
				AbstractActor& actor;
			private:
				MoveImpl(const MoveImpl& value);
				//MoveImpl(MoveImpl&& value);

			public:
				MoveImpl(AbstractActor& actor) :actor(actor) { }
				void move(int dirX, int dirY) const;
			};
		}
	}
}
