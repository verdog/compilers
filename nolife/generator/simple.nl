{ Extremely simple Oard program }

PROGRAM Simple;
	VAR
	a: INTEGER;
	BEGIN
		a := 1;
		WRITE(a <= 1);
		WRITE(a < 1);
		WRITE(a >= 1);
		WRITE(a > 1);
		WRITE(a = 1);
		WRITE(a <> 1)
	END