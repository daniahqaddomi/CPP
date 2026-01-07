/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniah <daniah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 09:32:09 by daniah            #+#    #+#             */
/*   Updated: 2026/01/07 11:33:41 by daniah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(std::string str, std::string s1, std::string s2)
{
	std::string 	result;
	size_t			pos;
	size_t			lastPos;
	
	if (s1.empty())
		return str;
	
	result = "";
	lastPos = 0;
	pos = str.find(s1);
	
	while (pos != std::string::npos)
	{
		result.append(str, lastPos, pos - lastPos);
		result.append(s2);
		lastPos = pos + s1.length();
		pos = str.find(s1, lastPos);
	}
	
	result.append(str, lastPos, str.length() - lastPos);
	
	return result;
}

int main(int argc, char **argv)
{
	std::ifstream inFile;
	std::ofstream outFile;
	std::string filename;
	std::string s1;
	std::string s2;
	std::string line;
	std::string content;
	std::string result;
	
	if (argc != 4)
	{
		std::cout << "Usage: ./sed filename s1 s2" << std::endl;
		return 1;
	}
	
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	
	inFile.open(filename.c_str());
	if (!inFile.is_open())
	{
		std::cout << "Error: cannot open file " << filename << std::endl;
		return 1;
	}
	
	content = "";
	while (std::getline(inFile, line))
	{
		content += line;
		if (!inFile.eof())
			content += "\n";
	}
	inFile.close();
	
	result = replaceAll(content, s1, s2);
	
	outFile.open((filename + ".replace").c_str());
	if (!outFile.is_open())
	{
		std::cout << "Error:cannot create output file" << std::endl;
		return 1;
	}
	
	outFile << result;
	outFile.close();
	
	std::cout << "Replacement complete. Output written to " << filename << ".replace" << std::endl;
	
	return 0;
}
