{ Extremely simple Oard program }

PROGRAM Flow;
 VAR x: ARRAY [1..3] OF INTEGER;

PROCEDURE xd (a: ARRAY [1..3] OF INTEGER);
BEGIN
	a[1] := 1;
	READ(a[2]);
	x[3] := 3;
	WRITE(x[3])
END;

BEGIN
	xd(x);
	WRITE(x[1]);
	WRITE(x[2]);
	WRITE(x[3])
END
