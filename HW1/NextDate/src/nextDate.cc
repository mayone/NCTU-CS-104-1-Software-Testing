#include "nextDate.h"

// Returns next date of the date
Date NextDate(const Date &today)
{
	Date tomorrow;

	int yy = today.year;
	yy += yy;

	return tomorrow;
}