#include "BitcoinExchange.hpp"

static void	getData(std::map<std::string, long double> *data, const char *dataBase) {
	std::fstream						file;
	std::string							temp;
	std::string							date;
	long double							value;

	file.open(dataBase, std::fstream::in);
	while (file) {
		file >> temp;
		if (temp.find("-") != std::string::npos) {
			date = temp.substr(0, temp.find(","));
			value = atof(temp.c_str() + strlen(date.c_str()) + 1);
			(*data)[date] = value;
		}
	}
	file.close();
	return ;
}

static void	processData(std::map<std::string, long double> data, std::string string) {
	std::map<std::string, long double>::iterator		it;
	std::string											date;
	long double											val;

	date = string.substr(0, string.find(" "));
	val = atof(string.c_str() + string.find("|") + 2);
	it = data.find(date);
	if (it != data.end())
		std::cout << date << " => " << val << " = " << val * data.at(date) << std::endl;
	else {
		data[date] = val;
		it = data.find(date);
		it--;
		std::cout << date << " => " << val << " = " << val * it->second << std::endl;
		data.erase(date);
	}
	return ;
}

static bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;  // 400으로 나누어떨어지는 연도는 윤년
            }
            return false;  // 100으로 나누어떨어지는 연도는 윤년이 아님
        }
        return true;  // 4로 나누어떨어지는 연도는 윤년
    }
    return false;  // 나머지 연도는 윤년이 아님
}

static void	checkData(std::map<std::string, long double> data, std::string string) {
	int		year;
	int		month;
	int		day;
	long	val;

	year = atoi(string.c_str());
	if (year < 2009) {
		std::cout << "bad input => " << string << std::endl;
		return ;
	}
	month = atoi(string.c_str() + 5);
	if (month < 1 || month > 12) {
		std::cout << "bad input => " << string << std::endl;
		return ;
	}
	day = atoi(string.c_str() + 8);
	if (day < 1 || day > 31) {
		std::cout << "bad input => " << string << std::endl;
		return ;
	}
	val = atol(string.c_str() + 13);
	if (val < 0 || val > 1000) {
		if (val < 0)
			std::cout << "not a positive number." << std::endl;
		else if (val > 1000)
			std::cout << "too large a number." << std::endl;
		return ;
	}
	if (year == 2009 && month == 1 && day < 2) {
		std::cout << "bad input => " << string << std::endl;
		return ;
	}
	bool isLeap = isLeapYear(year);
    if (month == 2 && day > 28) {
        if (isLeap && day == 29) {
            // 윤년이면 2월 29일까지 유효
            processData(data, string);
            return;
        } else {
            std::cout << "bad input => " << string << std::endl;
            return;
        }
    }

	processData(data, string);
	return ;
}

static void	readInput(std::map<std::string, long double> data, const char *input) {
	std::fstream	ifs;
	std::string		temp;

	ifs.open(input, std::fstream::in);
	while (std::getline(ifs, temp)) {
		if (temp.find("date | value") == std::string::npos) {
			checkData(data, temp);
		}
	}
	return ;
}

void	btc(const char *dataBase, const char *input) {
	std::map<std::string, long double>	data; //map을 쓴이유는 key값을 통해 value값을 찾기 쉽게 하기 위함
	getData(&data, dataBase);
	readInput(data, input);
	return ;
}

void	checkArg(int ac, char **av) {
	std::fstream	ifs;
	struct stat		info;

	if (ac >= 3)
		throw std::invalid_argument("인자 두개만 넣어라~");
	ifs.open(av[1], std::fstream::in);
	if (!(ifs.is_open()))
		throw std::invalid_argument("파일 안열린다~");
	else
		ifs.close();
	lstat(av[1], &info); //stat info에 저장
	if (S_ISDIR(info.st_mode) || S_ISLNK(info.st_mode))  // S_ISDIR() 매크로는 디렉토리인지 확인하는 매크로이다. S_ISLNK() 매크로는 심볼릭 링크 파일인지 확인하는 매크로이다.
		throw std::invalid_argument("파일이 아니다~");
	return ;
}