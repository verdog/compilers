PROGRAM func;

VAR 
a, c, d :INTEGER;
f :FLOAT;
l: ARRAY ['a'..'z'] OF CHARACTER;

FUNCTION b(x: INTEGER): INTEGER;
  BEGIN
    RETURN 4 * x
  END;

PROCEDURE p;
  BEGIN
    WRITE('hey.')
  END;

BEGIN
  c := b(4);
  p()
END
