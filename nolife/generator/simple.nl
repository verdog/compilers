{ Extremely simple Oard program }

PROGRAM Simple;
	VAR
	a: INTEGER;
	BEGIN
		a := 7;
		a := a MOD 4;
		WRITE(a)
	END