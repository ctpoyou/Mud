#pragma once

#include <vector>
#include <algorithm>

#include "AbstractActor.h"
#include "PlayerCharacter.h"
#include "IDrawable.h"
#include "IUpdatable.h"

#include "ConsoleGraphics.h"

namespace mud
{
	namespace manager
	{
		namespace map
		{
			using namespace mud::actor;

			class GameMap : 
				public IUpdatable,
				public IDrawable
			{
			private:
				std::vector<AbstractActor> actors;
				PlayerCharacter player;

				GameMap(const GameMap& value);
				GameMap(GameMap&& value);

			public:
				
				inline void addActor(const AbstractActor& newActor_)
				{
					actors.push_back(newActor_);
				}

				inline void removeActor(const AbstractActor& actor_)
				{
					actors.erase(std::find(actors.begin(), actors.end(), actor_));
				}

				void draw(graphics::ConsoleGraphics& console) override;
				void update() override;
				void showFogOfWar();
			};
		}
	}
}