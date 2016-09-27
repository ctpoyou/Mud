#pragma once

#include "AbstractActor.h"

namespace mud
{
	namespace actor
	{
		namespace projectile
		{
			class IProjectileFunctor
			{
			public:
				virtual ~IProjectileFunctor() = 0 { }
				virtual void operator() (const AbstractActor& projectile, const AbstractActor& collidedActor) = 0;
			};
		}
	}
}