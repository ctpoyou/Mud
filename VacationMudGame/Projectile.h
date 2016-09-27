#pragma once

#include <utility>
#include <functional>
#include "AbstractActor.h"
#include "MoveImpl.h"

namespace mud
{
	namespace actor
	{
		typedef std::function<void(AbstractActor&, AbstractActor&)>& _OnHitHandler;

		class Projectile : public AbstractActor
		{
		private:
			_OnHitHandler onHitHandler;
			std::pair<int, int> moveDirection;
			const action::MoveImpl moveImpl;

		private:

		public:
			Projectile(_OnHitHandler onHitHandler, std::pair<int, int> position, std::pair<int, int> direction, int maxTurnPoint) :
				AbstractActor('*', position, maxTurnPoint),
				moveDirection(direction),
				onHitHandler(onHitHandler),
				moveImpl(action::MoveImpl(*this))
			{ }
			~Projectile() { }

			inline virtual void onMyTurn() override
			{
				moveImpl.move(1, 0);
			}
			
			inline void onProjectileHit(const AbstractActor& actor) const
			{
				//onHitHandler(*this, actor);
			}
		};
	}
}