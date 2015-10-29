#ifndef __NEXTDATE_H__
#define __NEXTDATE_H__

inline bool isLeapYear(int year);

const int YEAR_LOWER = 1812;
const int YEAR_VALID = 1993;
const int YEAR_UPPER = 2012;
const int MONTH_LOWER = 1;
const int MONTH_UPPER = 12;
const int DAY_LOWER = 1;
inline int DAY_UPPER(int year, int month);


class Date {
public:
	Date(int year = 0, int month = 0, int day = 0)
	: year(year), month(month), day(day)
	{}
	bool operator==(const Date &rhs) const
	{
		return (year == rhs.year) &&
				(month == rhs.month) &&
				(day == rhs.day);
	}
	int year;
	int month;
	int day;
};
const Date invalidDate;

// Returns next date of the date
Date NextDate(const Date &date);

#endif  // __NEXTDATE_H__
