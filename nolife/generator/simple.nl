{ Extremely simple Oard program }

PROGRAM Simple;
	VAR
	a: ARRAY [1..3] OF INTEGER;
	b: INTEGER;
	BEGIN
		b := 2;
		a[b] := 2;
		WRITE(a[2])
	END