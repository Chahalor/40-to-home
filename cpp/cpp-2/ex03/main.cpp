#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

#define PART(title) std::cout << YELLOW << title << RESET << "\n";

bool bsp(Point const &a,Point const &b,Point const &c,Point const &point);

struct t_triangle {
	Point peak1;
	Point peak2;
	Point peak3;

	t_triangle(const Point& a, const Point& b, const Point& c)
		: peak1(a), peak2(b), peak3(c) {}
};

std::ostream& operator<<(std::ostream &os, const t_triangle &tri)
{
	os << "{" << tri.peak1 << ", " << tri.peak2 << ", " << tri.peak3 << "}";
	return (os);
}

#ifndef VISUAL

int	main(void)
{
	t_triangle	triangle(
		Point(100, 100),
		Point(700, 150),
		Point(400, 500)
	);

	Point	tests[] = {
		Point(400, 450),	// inside
		Point(150, 200),	// edge
		Point(50, 50),		// outside
		Point(400, 1000)	// far away
	};	//test clearly not made by chat-gpt

	std::cout << "Triangle: " << triangle << "\n\n";

	for (size_t i = 0; i < sizeof(tests) / sizeof(*tests); ++i)
	{
		bool inside = bsp(triangle.peak1, triangle.peak2, triangle.peak3, tests[i]);
		std::cout
			<< "Point " << tests[i]
			<< " → " << (inside ? "\033[32mINSIDE\033[0m" : "\033[31mOUTSIDE\033[0m")
			<< std::endl;
	}
	return (0);
}

#else

#include <SDL2/SDL.h>

int main()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cerr << "SDL_Init error: " << SDL_GetError() << "\n";
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow(
		"BSP",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		800, 600,
		SDL_WINDOW_SHOWN
	);

	if (!window)
	{
		std::cerr << "SDL_CreateWindow error: " << SDL_GetError() << "\n";
		SDL_Quit();
		return 1;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer)
	{
		std::cerr << "SDL_CreateRenderer error: " << SDL_GetError() << "\n";
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}

	// --- Data ---
	t_triangle	tri(Point(100, 100), Point(700, 150), Point(400, 500));
	Point		pt(400, 450);
	bool		running = true;

	std::cout << "Triangle: " << tri << "\n";
	std::cout << "Initial point: " << pt << "\n\n";

	SDL_Event event;

	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				running = false;
			else if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						running = false;
						break;
				}
			}
		}

		// Check if point is inside triangle
		bool	inside = bsp(tri.peak1, tri.peak2, tri.peak3, pt);

		// --- Render ---
		SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
		SDL_RenderClear(renderer);

		// Draw triangle (green)
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		SDL_RenderDrawLine(renderer,
			tri.peak1.getX().toInt(), tri.peak1.getY().toInt(),
			tri.peak2.getX().toInt(), tri.peak2.getY().toInt());
		SDL_RenderDrawLine(renderer,
			tri.peak2.getX().toInt(), tri.peak2.getY().toInt(),
			tri.peak3.getX().toInt(), tri.peak3.getY().toInt());
		SDL_RenderDrawLine(renderer,
			tri.peak3.getX().toInt(), tri.peak3.getY().toInt(),
			tri.peak1.getX().toInt(), tri.peak1.getY().toInt());

		// Draw point (red or green)
		if (inside)
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		else
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

		SDL_Rect	rect = { pt.getX().toInt() - 3, pt.getY().toInt() - 3, 6, 6 };
		SDL_RenderFillRect(renderer, &rect);

		SDL_RenderPresent(renderer);

		// Optional: print position and status
		std::cout << "\rPoint: " << pt
				  << (inside ? " \033[32mINSIDE\033[0m" : " \033[31mOUTSIDE\033[0m")
				  << "          " << std::flush;

		SDL_Delay(16); // ~60fps
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

#endif	/* !VISUAL */