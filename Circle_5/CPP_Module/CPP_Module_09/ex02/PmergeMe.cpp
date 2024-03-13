#include "PmergeMe.hpp"

static void	checkPositive(char **av, int i, int j) {
	while (av[i]) {
		while (av[i][j]) {
			if (av[i][j] < '0' || av[i][j] > '9')
				throw std::invalid_argument("Error");
			j++;
		}
		j = 0;
		i++;
	}
	return ;
}

static void	checkInt(char **av, int i) {
	unsigned long long	tmp;

	while (av[i]) {
		tmp = atoi(av[i]);
		if (tmp > 2147483647)
			throw std::invalid_argument("Error");
		i++;
	}
	return ;
}

void	checkErrors(int ac, char **av) {
	if (ac < 3)
		throw std::invalid_argument("Error");
	checkPositive(av, 1, 0);
	checkInt(av, 0);
	return ;
}

static void	makePair(std::pair<int, int> fordPair[], char **av, int *tmp) {
	int	count;
	int	i;

	count = 0;
	i = 1;
	while (av[i]) {
		if (av[i + 1] == NULL) {
			*tmp = atoi(av[i]);
			break ;
		}
		fordPair[count].first = atoi(av[i]);
		i++;
		fordPair[count].second = atoi(av[i]);
		i++;
		count++;
	}
	return ;
}

static void	sortPair(std::pair<int, int> fordPair[], int pairCount, int i) {
	int	tmp;

	while (i < pairCount) {
		if (fordPair[i].first > fordPair[i].second) {
			tmp = fordPair[i].first;
			fordPair[i].first = fordPair[i].second;
			fordPair[i].second = tmp;
		}
		i++;
	}
	return ;
}

static bool	allNbPushed(std::pair<int, int> fordPair[], int pairCount, int i) {
	while (i < pairCount) {
		if (fordPair[i].second >= 0)
			return false;
		i++;
	}
	return true;
}

static void	pushV(std::vector<int> **vector, std::pair<int, int> fordPair[], int pairCount, int i) {
	int	tmp;

	if (allNbPushed(fordPair, pairCount, 0) == true)
		return ;
	tmp = fordPair[i].second;
	i++;
	while (i < pairCount) {
		if (fordPair[i].second > tmp)
			tmp = fordPair[i].second;
		i++;
	}
	i = 0;
	while (i < pairCount) {
		if (tmp == fordPair[i].second) {
			fordPair[i].second = -1;
			break ;
		}
		i++;
	}
	(*vector)->insert((*vector)->begin(), tmp);
	pushV(vector, fordPair, pairCount, 0);
	return ;
}

static void	pushMinV(std::vector<int> **vector, std::pair<int, int> fordPair[], int pairCount, int *last) {
	int	i;
	int	tmp;

	i = 0;
	tmp = fordPair[i].first;
	while (i < pairCount) {
		if (fordPair[i].first < tmp)
			tmp = fordPair[i].first;
		i++;
	}
	i = 0;
	while (i < pairCount) {
		if (tmp == fordPair[i].first) {
			if (*last >= 0 && tmp >= *last) {
				tmp = *last;
				*last = -42;
			}
			else
				fordPair[i].first = -1;
			(*vector)->insert((*vector)->begin(), tmp);
			break ;
		}
		i++;
	}
	return ;
}

static void	pushLastV(std::vector<int> **vector, std::pair<int, int> fordPair[], int pairCount, int last) {
	std::vector<int>::iterator	it;
	int							i;

	i = 0;
	while (i < pairCount) {
		if (fordPair[i].first > 0) {
			it = std::lower_bound((*vector)->begin(), (*vector)->end(), fordPair[i].first);
			(*vector)->insert(it, fordPair[i].first);
		}
		i++;
	}
	if (last > 0) {
		it = std::lower_bound((*vector)->begin(), (*vector)->end(), last);
		(*vector)->insert(it, last);
	}
	return ;
}

static void	vectorSort(std::vector<int> *vector, int ac, char **av) {
	std::pair<int, int>		fordPair[ac / 2];
	int	last;

	last = -42;
	makePair(fordPair, av, &last);
	sortPair(fordPair, ac/2, 0);
	pushV(&vector, fordPair, ac/2, 0);
	pushMinV(&vector, fordPair, ac/2, &last);
	pushLastV(&vector, fordPair, ac/2, last);
	return ;
}

static void	pushD(std::deque<int> **deque, std::pair<int, int> fordPair[], int pairCount, int i) {
	int	tmp;

	if (allNbPushed(fordPair, pairCount, 0) == true)
		return ;
	tmp = fordPair[i].second;
	i++;
	while (i < pairCount) {
		if (fordPair[i].second > tmp)
			tmp = fordPair[i].second;
		i++;
	}
	i = 0;
	while (i < pairCount) {
		if (tmp == fordPair[i].second) {
			fordPair[i].second = -1;
			break ;
		}
		i++;
	}
	pushD(deque, fordPair, pairCount, 0);
	(*deque)->insert((*deque)->begin(), 1, tmp);
	return ;
}

static void	pushMinD(std::deque<int> **deque, std::pair<int, int> fordPair[], int pairCount, int *last) {
	int	i;
	int	tmp;

	i = 0;
	tmp = fordPair[i].first;
	while (i < pairCount) {
		if (fordPair[i].first < tmp)
			tmp = fordPair[i].first;
		i++;
	}
	i = 0;
	while (i < pairCount) {
		if (tmp == fordPair[i].first) {
			if (*last >= 0 && tmp >= *last) {
				tmp = *last;
				*last = -42;
			}
			else
				fordPair[i].first = -1;
			(*deque)->insert((*deque)->begin(), tmp);
			break ;
		}
		i++;
	}
	return ;
}

static void	pushLastD(std::deque<int> **deque, std::pair<int, int> fordPair[], int pairCount, int last) {
	std::deque<int>::iterator	it;
	int							i;

	i = 0;
	while (i < pairCount) {
		if (fordPair[i].first > 0) {
			it = std::lower_bound((*deque)->begin(), (*deque)->end(), fordPair[i].first);
			(*deque)->insert(it, fordPair[i].first);
		}
		i++;
	}
	if (last > 0) {
		it = std::lower_bound((*deque)->begin(), (*deque)->end(), last);
		(*deque)->insert(it, last);
	}
	return ;
}

static void	dequeSort(std::deque<int> *deque, int ac, char **av) {
	std::pair<int, int>		fordPair[ac / 2];
	int	last;

	last = -42;
	makePair(fordPair, av, &last);
	sortPair(fordPair, ac/2, 0);
	pushD(&deque, fordPair, ac/2, 0);
	pushMinD(&deque, fordPair, ac/2, &last);
	pushLastD(&deque, fordPair, ac/2, last);
	return ;
}

static void	display(char **av, std::vector<int>	vector, std::deque<int>deque, timer t) {
	std::vector<int>::iterator	it;
	int							i;

	i = 1;
	std::cout << "Before: ";
	while (av[i]) {
		std::cout << atoi(av[i]) << " ";
		i++;
	}
	std::cout << std::endl;
	it = vector.begin();
	std::cout << "After: ";
	while (it != vector.end()) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " <<
	vector.size() << " elements with std::vector : " <<
	((((long double)t.v_time)/CLOCKS_PER_SEC) * 1000)
	<< " ms" << std::endl;
	std::cout << "Time to process a range of " <<
	deque.size() << " elements with std::deque : " <<
	((((long double)t.d_time)/CLOCKS_PER_SEC) * 1000)
	<< " ms" << std::endl;
	return ;
}

void	sort(int ac, char **av) {
	std::vector<int>		vector;
	std::deque<int>			deque;
	timer					time;

	time.start = std::clock();
	vectorSort(&vector, ac, av);
	time.v_time = std::clock() - time.start;
	time.start = std::clock();
	dequeSort(&deque, ac, av);
	time.d_time = std::clock() - time.start;
	display(av, vector, deque, time);
	return ;
}