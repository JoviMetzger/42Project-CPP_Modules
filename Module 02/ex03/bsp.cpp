#include "Point.hpp"

/* bsp();
 *	Checks if the given point/cordinaten are inside the triangle.
 *	First we calculate the area of the main triangle and then the area of the 3 sub-triangles.
 *
 * Calculation:
 *	Formula:
 *		Area = 1/2 * |x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)|
 *	In simple:
 *		A = x1(y2 - y3)
 *		B = x2(y3 - y1)
 *		C = x3(y1 - y2)
 *		ABC = 1/2 * (A + B + C);
 */
bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	// Main triangle (ABC)
	Fixed	A = a.getValueX() * (b.getValueY() - c.getValueY());		// A = x1(y2 - y3)
	Fixed	B = b.getValueX() * (c.getValueY() - a.getValueY());		// B = x2(y3 - y1)
	Fixed	C = c.getValueX() * (a.getValueY() - b.getValueY());		// C = x3(y1 - y2)
	Fixed	ABC = Fixed(0.5f) * (A + B  + C);				// 1/2 * (A + B + C);

	// Sub-triangle one: PBC
	Fixed	one_P = point.getValueX() * (b.getValueY() - c.getValueY());	// one_P = xP(y2 - y3)
	Fixed	one_B = b.getValueX() * (c.getValueY() - point.getValueY());	// one_B = x2(y3 - yP)
	Fixed	one_C = c.getValueX() * (point.getValueY() - b.getValueY());	// one_C = x3(yP - y2)
	Fixed	PBC = Fixed(0.5f) * (one_P + one_B + one_C);			// 1/2 * (P + B + C);

	// Sub-triangle two: APC
	Fixed	two_A = a.getValueX() * (point.getValueY() - c.getValueY());	// two_A = x1(yP -y3)
	Fixed	two_P = point.getValueX() * (c.getValueY() - a.getValueY());	// two_P = xP(y3 -y1)
	Fixed	two_C = c.getValueX() * (a.getValueY() - point.getValueY());	// two_C = x3(y1 -yP)
	Fixed	APC = Fixed(0.5f) * (two_A + two_P + two_C);			// 1/2 * (A + P + C);

	// Sub-triangle three: ABP
	Fixed	three_A = a.getValueX() * (b.getValueY() - point.getValueY());	// three_A = x1(y2 - yP)
	Fixed	three_B = b.getValueX() * (point.getValueY() - a.getValueY());	// three_B = x2(yP - y1)
	Fixed	three_P = point.getValueX() * (a.getValueY() - b.getValueY());	// three_P = xP(y1 - y2)
	Fixed	ABP = Fixed(0.5f) * (three_A + three_B + three_P);		// 1/2 * (A + B + P);

	if (ABC > 0 && (PBC > 0) && (APC > 0) && (ABP > 0))
		return true;
	else
		return false;
}
