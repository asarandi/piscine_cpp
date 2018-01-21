/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:37:59 by asarandi          #+#    #+#             */
/*   Updated: 2018/01/19 21:23:04 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdio.h>

class	Instruction
{
	protected:
		static int							_dataPtr;
		static char							*_data;
	public:
		Instruction();
		~Instruction();
		Instruction( const Instruction& other );
		Instruction& operator=( const Instruction& rhs );

		void init(char *data);
		char getData();
		virtual char getLiteral() = 0;
		virtual int execute() = 0;

};

int		Instruction::_dataPtr = 0;
char*	Instruction::_data = NULL;

char	Instruction::getData()
{
	return this->_data[_dataPtr];
}

void	Instruction::init(char *data)
{
	this->_dataPtr = 0;
	this->_data = data;
}

Instruction::Instruction()
{
	return ;
}

Instruction::~Instruction(void)
{
	return ;
}

Instruction::Instruction( const Instruction& other)
{
	*this = other;
	return ;
}

Instruction &Instruction::operator=(const Instruction& rhs)
{
	(void)rhs;
	return *this;
}

/////////////////////////////////////////
class iGreater	: public Instruction
{
	char getLiteral();
	int execute();
};

char iGreater::getLiteral()
{
	return '>';
}

int iGreater::execute()
{
	Instruction::_dataPtr += 1;
	return (0);
}

/////////////////////////////////////////
class iLess	: public Instruction
{
	char getLiteral();
	int execute();
};

char iLess::getLiteral()
{
	return '<';
}

int iLess::execute()
{
	Instruction::_dataPtr -= 1;
	return (0);
}

/////////////////////////////////////////
class iPlus	: public Instruction
{
	char getLiteral();
	int execute();
};

char iPlus::getLiteral()
{
	return '+';
}

int iPlus::execute()
{
	Instruction::_data[Instruction::_dataPtr] += 1;
	return (0);
}

/////////////////////////////////////////
class iMinus	: public Instruction
{
	char getLiteral();
	int execute();
};

char iMinus::getLiteral()
{
	return '-';
}

int iMinus::execute()
{
	Instruction::_data[Instruction::_dataPtr] -= 1;
	return (0);
}

/////////////////////////////////////////
class iDot	: public Instruction
{
	char getLiteral();
	int execute();
};

char iDot::getLiteral()
{
	return '.';
}

int iDot::execute()
{
	std::cout << Instruction::_data[Instruction::_dataPtr] ;
	return (0);
}

/////////////////////////////////////////
class iComa	: public Instruction
{
	char getLiteral();
	int execute();
};

char iComa::getLiteral()
{
	return ',';
}

int iComa::execute()
{
	int c;
	c = getchar();
	Instruction::_data[Instruction::_dataPtr] = static_cast<char>(c);
	return (0);
}

/////////////////////////////////////////
class iOpen	: public Instruction
{
	char getLiteral();
	int execute();

};

char iOpen::getLiteral()
{
	return '[';
}

int iOpen::execute()
{
	return (1);
}

/////////////////////////////////////////
class iClose	: public Instruction
{
	char getLiteral();
	int execute();
};

char iClose::getLiteral()
{
	return ']';
}

int iClose::execute()
{
	return (2);
}






int main(int ac, char **av)
{
	if (ac == 2)
	{
		std::streampos	size;
		char *memblock;

		std::ifstream file (av[1], std::ios::in|std::ios::binary|std::ios::ate);
		if (file.is_open())
		{
			size = file.tellg();
			memblock = new char [size];
			file.seekg (0, std::ios::beg);
			file.read (memblock, size);
			file.close();
			std::cout << memblock  << std::endl;

			iGreater	*greater	= new iGreater();
			iLess		*less		= new iLess();
			iPlus		*plus		= new iPlus();
			iMinus		*minus		= new iMinus();
			iDot		*dot		= new iDot();
			iComa		*coma		= new iComa();
			iOpen		*open		= new iOpen();
			iClose		*close		= new iClose();

			std::vector<Instruction*>	bf;

			int	i = 0;
			while (i < size)
			{
				if (memblock[i] == '>')
					bf.push_back(greater);
				else if (memblock[i] == '<')
					bf.push_back(less);
				else if (memblock[i] == '+')
					bf.push_back(plus);
				else if (memblock[i] == '-')
					bf.push_back(minus);
				else if (memblock[i] == '.')
					bf.push_back(dot);
				else if (memblock[i] == ',')
					bf.push_back(coma);
				else if (memblock[i] == '[')
					bf.push_back(open);
				else if (memblock[i] == ']')
					bf.push_back(close);
				i++;
			}


			char	*data	= new char[100000];


			std::cout << "---[ open mind interpreter ]-----------------------------------------" << std::endl;
			greater->init(data);

			i = 0;
			int brackets = 0;
			char c;
			while (i < static_cast<int>(bf.size())  )
			{
				int res = bf[i]->execute();
				if (res == 1)
				{
					if (bf[i]->getData() == 0)
					{
						while (i < size)
						{
							c = bf[i]->getLiteral();
							if (c == '[')
								brackets += 1;
							else if (c == ']')
								brackets -= 1;
							if ((c == ']') && (brackets == 0))
								break ;
							i++;
						}
					}
				}
				else if (res == 2)
				{
					if (bf[i]->getData() != 0)
					{
						while (i >= 0)
						{				
							c = bf[i]->getLiteral();
							if (c == '[')
								brackets += 1;
							else if (c == ']')
								brackets -= 1;
							if ((c == '[') && (brackets == 0))
								break ;				
							i--;						
						}
					}
				}
				i++;
			}

			

			delete [] memblock;
			delete [] data;
		}
		else
			std::cout << "could not open file" << std::endl;
	}
	else
		std::cout << "please provide a file name" << std::endl;
	return 0;
}
