#include "commission.h"

// Returns the commission
float Commission(int locks, int stocks, int barrels)
{
	float commission;

	if (locks == -1) {
		commission = 0.0f;	// terminated
	}
	else if ((locks < 1) || (locks > 70) ||
			(stocks < 1) || (stocks > 80) ||
			(barrels < 1) || (barrels > 90))
	{
		commission = -1.0f;	// invalid
	}
	else {
		float sales = (lockPrice * locks) +
					(stockPrice * stocks) +
					(barrelPrice * barrels);
		if (sales <= 1000) {
			commission = sales * 0.1f;
		}
		else if (sales <= 1800) {
			commission = 1000 * 0.1f;
			commission += (sales-1000) * 0.15f;
		}
		else {
			commission = 1000 * 0.1f;
			commission += 800 * 0.15f;
			commission += (sales-1800) * 0.2f;
		}
	}

	return commission;
}