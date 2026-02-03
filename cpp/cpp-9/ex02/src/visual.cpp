/* ************************************************************************** */
/*                                   Printer                                  */
/* ************************************************************************** */
// made by: ugwentzi <3

#include "all.hpp"

#include <vector>

void print_duration(clock_t start, clock_t end, const char* label, size_t n_elem)
{
	double sec = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	if (sec >= 1.0)
		outl(label << " sort time (" << n_elem << " nb): " << sec << " seconds")
	else if (sec >= 0.001)
		outl(label << " sort time (" << n_elem << " nb): " << sec * 1000.0 << " ms")
	else
		outl(label << " sort time (" << n_elem << " nb): " << sec * 1000000.0 << " µs")
}

void color_shade(int value, int max_value, int &r, int &g, int &b)
{
	const int r_start = 0, g_start = 255, b_start = 0;
	const int r_end   = 255, g_end = 0, b_end     = 0;

	const double t = (max_value > 0) ? (double)value / max_value : 0.0;

	r = r_start + int(t * (r_end - r_start));
	g = g_start + int(t * (g_end - g_start));
	b = b_start + int(t * (b_end - b_start));
}

void print_array(const char *label, const std::vector<uint> &v)
{
	out(BOLD << label);

	uint max_value = 0;
	for (size_t i = 0; i < v.size(); ++i)
	{
		if (v[i] > max_value)
			max_value = v[i];
	}

	for (size_t i = 0; i < v.size(); ++i)
	{
		int r, g, b;
		color_shade(v[i], max_value, r, g, b);
		out(rgb(r, g, b) << BOLD << static_cast<uint>(v[i]) << " ")
	}
	outl("" RESET);
}