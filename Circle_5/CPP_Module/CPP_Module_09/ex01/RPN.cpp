#include "RPN.hpp"

bool	checkOperator(char c) {
	if (c != '+' && c != '-' && c != '/' && c != '*')
		return false;
	else
		return true;
}

static bool	countAndCheck(char *av, int i, int numberCnt, int operatorCnt) {
	while (av[i]) {
		if (isdigit(av[i])) {
			numberCnt++;
			while (av[i] && isdigit(av[i]))
				i++;
		}
		else if (checkOperator(av[i]))
			operatorCnt++;
		i++;
	}
	if (operatorCnt + 1 != numberCnt)
		return true;
	else
		return false;
}

static bool	checkIsOk(char *av, int i, int numberCnt) {
	if (countAndCheck(av, 0, 0, 0) == true)
		return true ;
	while (av[i]) {
		if (isdigit(av[i]))
			numberCnt++;
		if (numberCnt == 2 && checkOperator(av[i]))
			numberCnt = 1;
		else if (numberCnt == 3 && checkOperator(av[i]))
			numberCnt = 2;
		i++;
	}
	if (numberCnt != 1)
		return true;
	else
		return false;
}

static bool	divideError(char *av, int i) {
	while (av[i]) {
		if (atoi(av + i) == 0 && av[i + 2] == '/')
			return true;
		i++;
	}
	return false;
}

void	checkArgumentErrors(int ac, char *av, int i) {
	if (ac != 2)
		throw std::invalid_argument("Error");
	while (av[i]) {
		if ((!isdigit(av[i])) && checkOperator(av[i]) == false && av[i] != ' ')
			throw std::invalid_argument("Error");
		else
			i++;
	}
	if (checkIsOk(av, 0, 0) == true)
		throw std::invalid_argument("Error");
	else if (divideError(av, 0) == true)
		throw std::invalid_argument("Error");
	return ;
}

static int	operator_add(int first, int second) {
	return (first + second);
}

static int	operator_minus(int first, int second) {
	return (first - second);
}

static int	operator_multiply(int first, int second) {
	return (first * second);
}

static int	operator_divide(int first, int second) {
	return (first / second);
}

void	rpn(char *av, int i) {
	std::stack<int>	data;
	int				tmp;
	int				j = 0;
	rpn_s	rpns[4] = {
		{'+', &operator_add},
		{'-', &operator_minus},
		{'*', &operator_multiply},
		{'/', &operator_divide}
	};

	while (av[i]) {
		if (isdigit(av[i]))
			data.push(atoi(av + i));
		else if (checkOperator(av[i])) {
			tmp = data.top();
			data.pop();
			while (rpns[j].op != av[i])
				j++;
			tmp = rpns[j].operate(data.top(), tmp);
			j = 0;
			data.pop();
			data.push(tmp);
		}
		i++;
	}
	std::cout << data.top() << std::endl;
	return ;
}