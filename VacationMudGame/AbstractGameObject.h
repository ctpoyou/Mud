#pragma once

#include "IUpdatable.h"
#include "IDrawable.h"

namespace mud
{
	class AbstractGameObject : public IUpdatable, public IDrawable
	{
	public:
		AbstractGameObject() { }
		virtual ~AbstractGameObject() = 0;
	};
}