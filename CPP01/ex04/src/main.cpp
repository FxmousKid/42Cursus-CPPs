/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:00:38 by inazaria          #+#    #+#             */
/*   Updated: 2025/02/26 00:44:18 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>

typedef std::string str;
typedef std::ifstream ifs;
typedef std::ofstream ofs;

/* replaces all instances of s1 with s2 in line, and returns the new std::string */
str	homemade_replace_in_line(str line, str s1, str s2)
{
	str		res = str("");
	size_t	idx = 0;
	size_t	pos = 0;
	int		len_s1 = s1.length();

	while (idx < line.length()) {
		if (line.find(s1) == pos || line.find(s1) == str::npos) {
			res += line.substr(idx, line.length());
			return (res);
		}
		pos = line.find(s1);
		res += line.substr(idx, pos);
		idx += pos + len_s1;
		res += s2;
	}
	return res;
}


void	rpl(ifs &fin, ofs &fout, str s1, str s2)
{
	str line;

	std::getline(fin, line);
	while (!line.empty()) {
		fout << homemade_replace_in_line(line, s1, s2);
		std::getline(fin, line);
	}
}

int main(int argc, char *argv[])
{
	if (argc != 4) {
		std::cout << "Wrong Arg count, use ./a.out <file> <s1> <s2>" << std::endl;
		return (1);
	}

	ifs	fin;
	ofs fout;

	fin.open(argv[1]);
	if (fin.fail()) {
		std::cerr << "Failed to open " << argv[1] << std::endl;
		perror("");
		return (1);
	}
	fout.open((str(argv[1]) + ".replace").c_str());
	if (fout.fail()) {
		std::cerr << "Failed to create " << str(argv[1]) + ".replace" << std::endl;
		perror("");
		return (1);
	}
	rpl(fin, fout, str(argv[2]), str(argv[3]));
	fin.close();
	fout.close();
}
