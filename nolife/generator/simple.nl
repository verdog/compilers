{ Extremely simple Oard program }

PROGRAM Simple;
	VAR
	a: ARRAY [1..3] OF FLOAT;
	b: INTEGER;
	BEGIN
		b := 2;
		a[b] := 2.0;
		WRITE(a[2])
	END