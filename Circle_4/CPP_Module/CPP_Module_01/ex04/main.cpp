/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:24:52 by gsong             #+#    #+#             */
/*   Updated: 2023/08/15 15:55:33 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
int main(int argc, char **argv)
{
	try
	{
		if (argc != 4)
			throw "input invalid";

		std::string filename;
		std::string s1;
		std::string s2;
		std::string line;
		std::ifstream inputFile;
		std::ofstream outputFile;

		filename = argv[1];
		s1 = argv[2];
		s2 = argv[3];
		if (!filename.length() || !s1.length())
		{
			throw "Error: argument should not be blank.";
		}
		inputFile.open(argv[1]);
		if (inputFile.fail())
			throw "Error: Unable to open input file.";
		outputFile.open(filename.append(".replace").c_str());
		if (outputFile.fail())
			throw "Error: Unable to open output file.";

		while (std::getline(inputFile, line))
		{
			std::string resultLine;
			size_t startPos = 0;
			size_t foundPos = line.find(s1, startPos);

			while (foundPos != std::string::npos) // find 가 못찾으면 npos foundPos가 npos임
			{
				resultLine += line.substr(startPos, foundPos - startPos);
				resultLine += s2;
				startPos = foundPos + s1.length();
				foundPos = line.find(s1, startPos);
			}

			resultLine += line.substr(startPos);
			outputFile << resultLine << std::endl;
		}

		inputFile.close();
		outputFile.close();
	}
	catch (const char *e)
	{
		std::cout << e << std::endl;
		return 1;
	}

	return 0;
}
