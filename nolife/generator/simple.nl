{ Extremely simple Oard program }

PROGRAM Flow;
 VAR a:INTEGER;

BEGIN
	a:=1;
	WHILE a <> 10 DO BEGIN
		WRITE(a);
		a:=a+1
	END;
	WRITE(a)
END
