{ Extremely simple Oard program }

PROGRAM Simple;
	VAR
	a: ARRAY [1..3] OF INTEGER;
	BEGIN
		a[1] := 5;
		WRITE(a[1])
	END