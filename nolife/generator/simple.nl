{ Extremely simple Oard program }

PROGRAM Flow;
 VAR x: INTEGER;

PROCEDURE myread (a: INTEGER);
BEGIN
	READ(a);
	myread(a)
END;

BEGIN
	myread(x);
	WRITE(x)
END
