#pragma once

#include "AbstractActor.h"

namespace mud
{
	namespace actor
	{
		namespace projectile
		{
			class ProjectileNoAction
			{
			public:
				virtual void operator() (const AbstractActor& projectile, const AbstractActor& collidedActor)
				{

				}
			};
		}
		
	}
}