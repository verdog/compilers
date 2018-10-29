PROGRAM func;

VAR 
i :INTEGER;
f :FLOAT;
c :CHARACTER;
l: ARRAY [10 .. 15] OF INTEGER;
cl: ARRAY['a' .. 'c'] OF INTEGER;

FUNCTION b (x, y: INTEGER; f: FLOAT): INTEGER;
  VAR
  f: CHARACTER;

  BEGIN
    f := '2';
    g := h + 2;
    RETURN 4 * x
  END;

PROCEDURE p;
  BEGIN
    WRITE('hey.')
  END;

BEGIN
  f := '2';
  f := 2;

  l[1] := 'c';
  l[1] := 2;
  l[1] := 2 + l[2];
  l[2] := 2.0;
  l[9] := 2;
  l[i] := 2;

  x[9] := y;
  f[2] := 2.0;

  cl['a'] := 5;
  cl['d'] := 4;
  cl['a'] := 'a';
  cl[2] := 2
END
