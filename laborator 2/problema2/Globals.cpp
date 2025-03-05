#include "Globals.h"


int CompName(Grades elev1, Grades elev2){
	return strcmp(elev1.getNume(), elev2.getNume());
}

int CompAvg(Grades elev1, Grades elev2) {
	if (elev1.getAvg() > elev2.getAvg())
		return 1;
	else
		if (elev1.getAvg() == elev2.getAvg())
			return 0;
		else
			return -1;
}

int CompHist(Grades elev1, Grades elev2) {
	if (elev1.getHist() > elev2.getHist())
		return 1;
	else
		if (elev1.getHist() == elev2.getHist())
			return 0;
		else
			return -1;
}

int CompMath(Grades elev1, Grades elev2) {
	if (elev1.getMath() > elev2.getMath())
		return 1;
	else
		if (elev1.getMath() == elev2.getMath())
			return 0;
		else
			return -1;
}

int CompEng(Grades elev1, Grades elev2) {
	if (elev1.getEng() > elev2.getEng())
		return 1;
	else
		if (elev1.getEng() == elev2.getEng())
			return 0;
		else
			return -1;
}
