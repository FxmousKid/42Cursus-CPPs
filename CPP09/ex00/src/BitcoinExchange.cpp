/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:42:33 by inazaria          #+#    #+#             */
/*   Updated: 2025/04/04 13:42:49 by inazaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & other)
: _exchangeRates(other._exchangeRates)
{}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        _exchangeRates = other._exchangeRates;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{}

bool isNotSpace(char ch)
{
    return !std::isspace(static_cast<unsigned char>(ch));
}

std::string& ltrim(str&s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), isNotSpace));
    return s;
}

std::string& rtrim(str&s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), isNotSpace).base(), s.end());
    return s;
}

std::string& trim(str&s)
{
    return ltrim(rtrim(s));
}

void BitcoinExchange::loadDatabase(const str& filename)
{
    std::ifstream file(filename.c_str());
    
    if (!file)
        throw std::runtime_error("Error: could not open file.");

    std::string line, date;
    double rate;

    if (std::getline(file, line))
    {
        if (line != "date,exchange_rate")
        {
            std::istringstream ss(line);
            if (std::getline(ss, date, ',') && (ss >> rate))
                _exchangeRates[date] = rate;
        }
    }
    
    while (getline(file, line))
    {
        std::stringstream ss(line);
        if (getline(ss, date, ',') && (ss >> rate))
            _exchangeRates[date] = rate;
    }
}

void BitcoinExchange::processInput(const str& filename)
{
    std::ifstream file(filename.c_str());

    if (!file)
        throw std::runtime_error("Error: could not open file.");

    std::string inputLine, datePart, valuePart;
    double value;
    bool firstLine = true;

    while (getline(file, inputLine))
    {
        trim(inputLine);
        
        if (firstLine && inputLine == "date | value")
        {
            firstLine = false;
            continue;
        }
        
        firstLine = false;
        
        if ((inputLine.size() >= 12) &&  (inputLine[11] != '|' || inputLine[10] != ' ' || inputLine[12] != ' '))
        {
            inputLine = inputLine.empty() ? "empty" : inputLine;
            std::cout << "Error: bad input => " << inputLine << std::endl;
            continue;
        }

        std::stringstream ss(inputLine);
        if (getline(ss, datePart, '|'))
        {
            if (!getline(ss, valuePart))
            {
                std::cout << "Error: bad input => " << inputLine << std::endl;
                continue;
            }

            datePart.erase(datePart.find_last_not_of(" \n\r\t") + 1);
            valuePart.erase(0, valuePart.find_first_not_of(" \n\r\t"));
            
            if (!isValidDate(datePart))
            {
                std::cout << "Error: bad input => " << datePart << std::endl;
                continue;
            }

            if (!isValidValue(valuePart))
            {
                std::cout << "Error: not a positive number." << std::endl;
                continue;
            }

            value = atof(valuePart.c_str());

            if (value > 1000)
            {
                std::cout << "Error: too large a number." << std::endl;
                continue;
            }

            double rate = getExchangeRate(datePart);
            std::cout << datePart << " => " << value << " = " << value * rate << std::endl;
        }
        else
        {
            inputLine = inputLine.empty() ? "empty" : inputLine;
            std::cout << "Error: bad input => " << inputLine << std::endl;
        }
    }
}

double BitcoinExchange::getExchangeRate(const str& date) const
{
    std::map<std::string, double>::const_iterator it = _exchangeRates.lower_bound(date);
    
    if (it == _exchangeRates.end() || it->first != date)
    {
        if (it == _exchangeRates.begin())
            return 0;
        --it;
    }
    return it->second;
}

bool BitcoinExchange::isValidDate(const str& date) const
{
    if (date.size() != DATE_LENGTH || date[YEAR_POSITION] != '-' || date[MONTH_POSITION] != '-')
        return false;

    for (int i = MIN_YEAR_DIGITS; i < MAX_YEAR_DIGITS; ++i)
        if (!isdigit(date[i]))
            return false;

    for (int i = MIN_MONTH_DIGITS; i < MAX_MONTH_DIGITS; ++i)
        if (!isdigit(date[i]))
            return false;

    for (int i = MIN_DAY_DIGITS; i < MAX_DAY_DIGITS; ++i)
        if (!isdigit(date[i]))
            return false;

    int year = atoi(date.substr(MIN_YEAR_DIGITS, YEAR_LENGTH).c_str());
    int month = atoi(date.substr(MIN_MONTH_DIGITS, MONTH_LENGTH).c_str());
    int day = atoi(date.substr(MIN_DAY_DIGITS, DAY_LENGTH).c_str());

    if (month < MIN_MONTH || month > MAX_MONTH)
        return false;

    if (day < MIN_DAY || day > MAX_DAY)
        return false;

    if (month == FEBRUARY)
    {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > 29 || (day == 29 && !isLeap))
            return false;
    }
    else if (month == APRIL || month == JUNE || month == SEPTEMBER || month == NOVEMBER)
    {
        if (day > 30)
            return false;
    }

    return true;
}

bool BitcoinExchange::isValidValue(const str& value) const
{
    char* end;
    double val = strtod(value.c_str(), &end);
    return end != value.c_str() && *end == '\0' && val >= 0;
}
