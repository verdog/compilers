{ Extremely simple Oard program }

PROGRAM Flow;
 VAR x, y:INTEGER;

PROCEDURE mywrite (a,b: INTEGER);
BEGIN
	WRITE(a);
	WRITE(b);
	WRITE(x)
END;

BEGIN
	x := 9;
	y := 10;
	mywrite(x, y)
END
