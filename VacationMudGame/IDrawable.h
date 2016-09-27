#pragma once

#include "ConsoleGraphics.h"

namespace mud
{
	class IDrawable
	{
	public:
		virtual ~IDrawable() = 0 { };
		virtual void draw(mud::graphics::ConsoleGraphics& spriteBatch) = 0;
	};
}