#pragma once

#include <string>
#include <vector>

namespace mud
{
	namespace graphics
	{
		class ConsoleGraphics
		{
		private:
			const int INIT_SIZE_X = 120;
			const int INIT_SIZE_Y = 40;

			const int FONT_SIZE_X = 9;
			const int FONT_SIZE_Y = 20;

			const int MARGIN_X = 30;
			const int MARGIN_Y = 80;

			const char BLANK_CHARACTER = '.';
		private:
			std::vector<std::string> backbuffer;
			std::vector<std::string> frontbuffer;

			int xSize, ySize;

		private:
			ConsoleGraphics();
			ConsoleGraphics(const ConsoleGraphics& value);
			ConsoleGraphics(ConsoleGraphics&& value);

			ConsoleGraphics& operator=(const ConsoleGraphics& rhs);

			void fill(std::vector<std::string>& buffer, const char value);
			void firstDraw();

		public:
			static ConsoleGraphics& getInstance();

			void resize(const int x, const int y);

			void write(int x, int y, const std::string& value);
			void write(int x, int y, const char value);

			void draw();
			void clear();
		};

	}
}