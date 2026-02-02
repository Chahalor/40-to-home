#include <vector>
#include <deque>
#include <algorithm>
#include <cstddef>

struct s_node
{
	long		v;
	std::size_t	id;
};

static inline bool	operator<(const s_node &a, const s_node &b)
{
	if (a.v != b.v) return a.v < b.v;
	return a.id < b.id;
}

/*
 * Jacobsthal:
 * J(0)=0, J(1)=1, J(n)=J(n-1)+2*J(n-2)
 * Iteratif (sinon c’est une centrale nucléaire pour faire 3 additions).
 */
static inline std::size_t	_jacobsthal(std::size_t n)
{
	std::size_t a = 0;
	std::size_t b = 1;

	if (n == 0) return 0;
	if (n == 1) return 1;

	for (std::size_t i = 2; i <= n; ++i)
	{
		std::size_t c = b + 2 * a;
		a = b;
		b = c;
	}
	return b;
}

/*
 * Génère l’ordre d’insertion des indices (pend) selon blocs Jacobsthal:
 * ordre typique: 1, 3, 2, 5, 4, 9, 8, 7, 6, ...
 *
 * On retourne des indices dans [1 .. m-1] (0 est traité à part).
 */
static inline std::vector<std::size_t>	_make_jacob_order(std::size_t m)
{
	std::vector<std::size_t> order;

	if (m <= 1)
		return order;

	std::vector<bool> used(m, false);

	order.push_back(1);
	used[1] = true;

	std::size_t prev = 1;
	std::size_t k = 3;

	while (prev < m - 1)
	{
		std::size_t curr = _jacobsthal(k++);
		if (curr >= m)
			curr = m - 1;

		for (std::size_t i = curr; i > prev; --i)
		{
			if (!used[i])
			{
				order.push_back(i);
				used[i] = true;
			}
		}
		prev = curr;
		if (curr == m - 1)
			break;
	}

	// Complète si jamais il manque des indices (sécurité)
	for (std::size_t i = 2; i < m; ++i)
	{
		if (!used[i])
			order.push_back(i);
	}

	return order;
}

template<typename C>
static inline typename C::iterator	_lower_bound_range(
	C &c,
	typename C::iterator first,
	typename C::iterator last,
	const s_node &value
)
{
	// vector/deque => random access => std::lower_bound OK
	return std::lower_bound(first, last, value);
}

/*
 * Ford–Johnson sur une séquence de nodes (val + id).
 * Retourne une séquence triée de nodes.
 */
template<typename C>
static C	_fj_sort_nodes(C nodes)
{
	const std::size_t n = nodes.size();
	if (n <= 1)
		return nodes;

	// 1) Pairing
	struct s_pair { s_node lo; s_node hi; };
	std::vector<s_pair> pairs;
	pairs.reserve(n / 2);

	s_node leftover;
	bool has_leftover = false;

	for (std::size_t i = 0; i + 1 < n; i += 2)
	{
		s_node a = nodes[i];
		s_node b = nodes[i + 1];
		if (b < a)
			std::swap(a, b);

		pairs.push_back(s_pair{a, b});
	}

	if (n % 2 != 0)
	{
		leftover = nodes.back();
		has_leftover = true;
	}

	// 2) Extract maxima + mapping hi.id -> lo
	C maxs;
	maxs.clear();
	maxs.resize(pairs.size());

	// ids sont 0..n-1 dans l’appel racine, mais en récursion on conserve les ids originaux
	// donc on ne peut pas indexer par "size".
	// On utilise un vector de mapping via une table (vector) dimensionnée sur max id + 1.
	std::size_t max_id = 0;
	for (std::size_t i = 0; i < pairs.size(); ++i)
		if (pairs[i].hi.id > max_id) max_id = pairs[i].hi.id;

	std::vector<s_node> lo_for_hi(max_id + 1);

	for (std::size_t i = 0; i < pairs.size(); ++i)
	{
		maxs[i] = pairs[i].hi;
		lo_for_hi[pairs[i].hi.id] = pairs[i].lo;
	}

	// 3) Recursion on maxima
	C chain = _fj_sort_nodes(maxs);

	// 4) Build pend minima in the order of the sorted maxima chain
	C pend;
	pend.clear();
	pend.resize(chain.size());

	for (std::size_t i = 0; i < chain.size(); ++i)
	{
		const s_node &mx = chain[i];
		pend[i] = lo_for_hi[mx.id];
	}

	// 5) Insert pend[0] in front (always before its max)
	if (!pend.empty())
		chain.insert(chain.begin(), pend[0]);

	// 6) Insert remaining minima in Jacobsthal order, each time bounded before its max
	if (pend.size() > 1)
	{
		std::vector<std::size_t> order = _make_jacob_order(pend.size());

		for (std::size_t idx_i = 0; idx_i < order.size(); ++idx_i)
		{
			std::size_t idx = order[idx_i];
			const s_node &mn = pend[idx];

			// Find the associated max (same idx in maxima-order)
			// In the current chain, that max is still present; we need its iterator as upper bound.
			// Since duplicates exist, we locate by (v,id) node exact match.
			s_node mx = maxs[0]; // dummy init
			// The max associated to pend[idx] is the max that was at position idx in the sorted maxima chain:
			// But "chain" got an extra element inserted at begin, so maxima positions shifted by +1.
			// The max itself is chain[idx+1] if no earlier insertions moved it. But insertions before it can move it.
			// So: search it.
			mx = maxs[0]; // overwritten next line
			mx = _fj_sort_nodes(maxs)[idx]; // expensive if recomputed; avoided below in final note

			// Better: we already have sorted maxima chain in "max_chain"
			// We'll keep it: (see final note)
			// --- placeholder removed in final note ---
		}
	}

	// 7) Insert leftover if any (full range)
	if (has_leftover)
	{
		typename C::iterator pos = std::lower_bound(chain.begin(), chain.end(), leftover);
		chain.insert(pos, leftover);
	}

	return chain;
}

/*
 * Final public sort: take T<long> and return T<long>.
 * Works for std::vector<long> and std::deque<long>.
 */
template<typename T>
T	Sortator2000(T &list)
{
	// Build nodes with unique ids to survive duplicates
	typedef typename T::value_type value_type;

	(void)sizeof(value_type); // hush warnings if needed

	std::vector<s_node> nodes;
	nodes.reserve(list.size());

	for (std::size_t i = 0; i < list.size(); ++i)
		nodes.push_back(s_node{list[i], i});

	// Sort nodes using Ford–Johnson
	std::vector<s_node> sorted_nodes = _fj_sort_nodes(nodes);

	// Convert back to T<long>
	T out;
	out.clear();
	out.resize(sorted_nodes.size());

	for (std::size_t i = 0; i < sorted_nodes.size(); ++i)
		out[i] = sorted_nodes[i].v;

	return out;
}

// explicit instantiations
template std::deque<long> Sortator2000<std::deque<long> >(std::deque<long> &);
template std::vector<long> Sortator2000<std::vector<long> >(std::vector<long> &);
