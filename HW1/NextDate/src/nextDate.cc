#include "nextDate.h"

inline bool isLeapYear(int year)
{
	if (((year % 4 == 0) && (year % 100 != 0)) ||
		(year % 400 == 0))
	{
		return true;
	}
	else
		return false;
}

inline int DAY_UPPER(int year, int month)
{
	if (month <= 7) {
		if (month & 1) {
			return 31;
		}
		else {
			if (month == 2) {
				if (isLeapYear(year)) {
					return 29;
				}
				else {
					return 28;
				}
			}
			else {
				return 30;
			}
		}
	}
	else {
		if (month & 1) {
			return 30;
		}
		else {
			return 31;
		}
	}
}

// Returns next date of the date
Date NextDate(const Date &date)
{
	Date nextDate;

	if ((date.year < YEAR_LOWER) || (date.year > YEAR_UPPER) ||
		(date.month < MONTH_LOWER) || (date.month > MONTH_UPPER) ||
		(date.day < DAY_LOWER) || (date.day > DAY_UPPER(date.year, date.month)))
	{
		nextDate = invalidDate;
	}
	else if (date.day == DAY_UPPER(date.year, date.month)) {
		if (date.month == MONTH_UPPER) {
			if (date.year == YEAR_UPPER) {
				nextDate = invalidDate;
			}
			else {
				nextDate.year = date.year + 1;
				nextDate.month = 1;
				nextDate.day = 1;
			}
		}
		else {
			nextDate.year = date.year;
			nextDate.month = date.month + 1;
			nextDate.day = 1;
		}
	}
	else {
		nextDate.year = date.year;
		nextDate.month = date.month + 1;
		nextDate.day = date.day + 1;
	}


	return nextDate;
}