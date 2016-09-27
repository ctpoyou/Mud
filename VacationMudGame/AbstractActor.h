#pragma once

#include "AbstractGameObject.h"
#include "ConsoleGraphics.h"

#include <utility>

namespace mud
{
	namespace actor
	{
		class AbstractActor : public IUpdatable, public IDrawable
		{
		private:
			unsigned int maxTurnPoint;
			unsigned int turnPoint;
			std::pair<int, int> position;

			char icon;

			bool needsDestroy;

		protected:
			virtual void onMyTurn() = 0;

		public:
			AbstractActor(char icon, std::pair<int, int> position, int maxTurnPoint) : icon(icon), needsDestroy(false), maxTurnPoint(maxTurnPoint), turnPoint(maxTurnPoint), position(position) {  }
			virtual ~AbstractActor() { }

			const std::pair<int, int> getPosition() const;
			void setPoisition(const std::pair<int, int>& pos);
			virtual void update() override;
			virtual void draw(mud::graphics::ConsoleGraphics& spriteBatch) override;

			inline void destroyOnNextFrame() { needsDestroy = true; }
		};
	}
}