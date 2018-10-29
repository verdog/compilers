PROGRAM func;

VAR 
i :INTEGER;
f :FLOAT;
c :CHARACTER;
l: ARRAY [1 .. 8] OF INTEGER;

FUNCTION b (x, y: INTEGER; f: FLOAT): INTEGER;
  VAR
  f: CHARACTER;

  BEGIN
    f := '2';
    RETURN 4 * x
  END;

PROCEDURE p;
  BEGIN
    WRITE('hey.')
  END;

BEGIN
  f := '2';
  f := 2
END
