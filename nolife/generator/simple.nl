{ Extremely simple Oard program }

PROGRAM Flow;
 VAR a:INTEGER;

BEGIN
	READ(a);
	CASE a OF
	    1,2: WRITE(0);
	    5  : WRITE(1) 
	END
END
