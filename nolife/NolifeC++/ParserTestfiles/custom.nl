PROGRAM func;

VAR 
i :INTEGER;
f :FLOAT;
c :CHARACTER;
l: ARRAY [1 .. 10] OF INTEGER;
cl: ARRAY['a' .. 'c'] OF INTEGER;

PROCEDURE b (f: ARRAY[1..10] OF INTEGER);

  BEGIN
    WRITE (f[2])
  END;

BEGIN
  cl['b'] := 2;
  cl['d'] := 2;
  cl['*'] := 2
END
