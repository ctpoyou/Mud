#pragma once

namespace mud
{
	class IUpdatable
	{
	public:
		virtual ~IUpdatable() = 0 { };
		virtual void update() = 0;
	};
}