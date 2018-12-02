{ Extremely simple Oard program }

PROGRAM Simple;
	VAR
	a, b: INTEGER;
	BEGIN
		READ(a);
		READ(b);
		IF b THEN
			IF a THEN
				WRITE(0)
			ELSE
				WRITE(1)
		ELSE
			WRITE(2)
	END
