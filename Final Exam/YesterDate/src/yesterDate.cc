#include "yesterDate.h"

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

// Returns yester date of the date
Date YesterDate(const Date &date)
{
	Date yesterDate;

	if ((date.year < YEAR_LOWER) || (date.year > YEAR_UPPER) ||
		(date.month < MONTH_LOWER) || (date.month > MONTH_UPPER) ||
		(date.day < DAY_LOWER) || (date.day > DAY_UPPER(date.year, date.month)))
	{	// Date out of range
		yesterDate = invalidDate;
	}
	else if (date.day == DAY_LOWER) {
		if (date.month == MONTH_LOWER) {
			if (date.year == YEAR_LOWER) {	// Yester date out of range
				yesterDate = invalidDate;
			}
			else {							// Yester year
				yesterDate.year = date.year - 1;
				yesterDate.month = 12;
				yesterDate.day = 31;
			}
		}
		else {								// Yester month
			yesterDate.year = date.year;
			yesterDate.month = date.month - 1;
			yesterDate.day = DAY_UPPER(yesterDate.year, yesterDate.month);
		}
	}
	else {									// Yester day
		yesterDate.year = date.year;
		yesterDate.month = date.month;
		yesterDate.day = date.day - 1;
	}

	return yesterDate;
}