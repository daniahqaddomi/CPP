/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dqaddomi <dqaddomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 09:32:09 by daniah            #+#    #+#             */
/*   Updated: 2026/01/15 18:14:47 by dqaddomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(std::string str, std::string s1, std::string s2)
{
	std::string 	result;
	size_t			pos;
	size_t			last_pos;
	
	if (s1.empty())
		return (str);
	
	result = "";
	last_pos = 0;
	pos = str.find(s1);
	
	while (pos != std::string::npos)
	{
		result.append(str, last_pos, pos - last_pos);
		result.append(s2);
		last_pos = pos + s1.length();
		pos = str.find(s1, last_pos);
	}
	
	result.append(str, last_pos, str.length() - last_pos);
	
	return (result);
}

int main(int argc, char **argv)
{
	std::ifstream in_file;
	std::ofstream out_file;
	std::string filename;
	std::string s1;
	std::string s2;
	std::string line;
	std::string content;
	std::string result;
	
	if (argc != 4)
	{
		std::cout << "Usage: ./sed filename s1 s2" << std::endl;
		return (1);
	}
	
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	
	if (s1.empty())
	{
		std::cout << "Error: s1 cannot be empty" << std::endl;
		return (1);
	}
	
	in_file.open(filename.c_str());
	if (!in_file.is_open())
	{
		std::cout << "Error: cannot open file " << filename << std::endl;
		return (1);
	}
	
	content = "";
	while (std::getline(in_file, line))
	{
		content += line;
		if (!in_file.eof())
			content += "\n";
	}
	in_file.close();
	
	result = replaceAll(content, s1, s2);
	
	out_file.open((filename + ".replace").c_str());
	if (!out_file.is_open())
	{
		std::cout << "Error:cannot create output file" << std::endl;
		return (1);
	}
	
	out_file << result;
	out_file.close();
	
	std::cout << "Replacement complete. Output written to " << filename << ".replace" << std::endl;
	
	return (0);
}
