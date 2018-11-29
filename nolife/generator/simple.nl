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
		WRITE(a <> 1);
		WRITE(a AND 2);
		WRITE(a OR 2)
	END