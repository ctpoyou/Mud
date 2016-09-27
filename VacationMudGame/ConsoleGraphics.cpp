
#include "ConsoleGraphics.h"

#include "rlutil.h"

#include <iostream>
#include <algorithm>

namespace mud
{
	namespace graphics
	{
		ConsoleGraphics::ConsoleGraphics() : backbuffer(), xSize(INIT_SIZE_X), ySize(INIT_SIZE_Y)
		{
			resize(xSize, ySize);

			rlutil::hidecursor();
			firstDraw();
		}

		ConsoleGraphics& ConsoleGraphics::getInstance()
		{
			static ConsoleGraphics instance = ConsoleGraphics();
			return instance;
		}

		void ConsoleGraphics::resize(const int x, const int y)
		{
			HWND console = GetConsoleWindow();
			RECT r;
			GetWindowRect(console, &r); //stores the console's current dimensions
			MoveWindow(console, r.left, r.top, FONT_SIZE_X * x + MARGIN_X, FONT_SIZE_Y * y + MARGIN_Y, TRUE);
			auto i = backbuffer.begin();

			while (i != backbuffer.end())
			{
				i->resize(x);
			}

			i = frontbuffer.begin();

			while (i != frontbuffer.end())
			{
				i->resize(x);
			}

			fill(backbuffer, BLANK_CHARACTER);
			fill(frontbuffer, BLANK_CHARACTER);
			
			backbuffer.resize(y, std::string(x, BLANK_CHARACTER));
			frontbuffer.resize(y, std::string(x, BLANK_CHARACTER));
			
			xSize = x;
			ySize = y;
		}

		void ConsoleGraphics::fill(std::vector<std::string>& buffer, const char value)
		{
			auto i = backbuffer.begin();

			while (i != backbuffer.end())
			{
				std::fill(i->begin(), i->end(), BLANK_CHARACTER);
				++i;
			}
		}

		void ConsoleGraphics::firstDraw()
		{
			rlutil::locate(1, 1);

			int i;
			for (i = 0; i < ySize; ++i)
			{
				std::cout << frontbuffer[i] << std::endl;
			}
		}

		void ConsoleGraphics::write(int x, int y, const std::string& value)
		{
			if (0 <= y && y < ySize && 0 <= x + value.length() && x < xSize)
			{
				std::string& line = backbuffer[y];
				auto lineStartIter = line.begin() + x;
				int endIdx = std::min<int>(value.length(), xSize - x);

				for (int i = 0; i < endIdx; ++i)
				{
					*(lineStartIter + i) = value[i];
				}
			}
		}

		void ConsoleGraphics::write(int x, int y, char value)
		{
			if (0 <= y && y < ySize && 0 <= x && x < xSize)
			{
				std::string& line = backbuffer[y];
				line[x] = value;
			}
		}

		void ConsoleGraphics::draw()
		{
			int i, j;
			for (i = 0; i < ySize; ++i)
			{
				for (j = 0; j < xSize; ++j)
				{
					if (backbuffer[i][j] != frontbuffer[i][j])
					{
						rlutil::locate(j + 1, i + 1);
						std::cout << backbuffer[i][j];
					}
				}
			}

			frontbuffer = backbuffer;
			fill(backbuffer, BLANK_CHARACTER);
		}

		void ConsoleGraphics::clear()
		{
			//fill(frontbuffer, BLANK_CHARACTER);
			//rlutil::cls();
		}
	}
}