PROGRAM func;

VAR 
i :INTEGER;
f :FLOAT;
c :CHARACTER;
l: ARRAY [1 .. 8] OF INTEGER;

FUNCTION b (x: INTEGER): INTEGER;
  BEGIN
    RETURN 4 * x
  END;

PROCEDURE p;
  BEGIN
    WRITE('hey.')
  END;

BEGIN
  {*
  i := 6 + b(4);
  f := 4.5;
  c := 'j';
  *}
  
  c := 2.0 + ('e' + 'c');

  c := b(2);

  p()
END
