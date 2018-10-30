PROGRAM func;

VAR 
j :INTEGER;
i :INTEGER;
f :FLOAT;
c :CHARACTER;
l: ARRAY [1 .. 10] OF INTEGER;
cl: ARRAY['a' .. 'c'] OF INTEGER;

PROCEDURE b (f: ARRAY[1..10] OF INTEGER);

  BEGIN
    WRITE('an array.')
  END;

PROCEDURE c (g: INTEGER);

  BEGIN
    WRITE('not an array.')
  END;

BEGIN
  b(l); {ok}
  c(l); {not ok}
  b(i); {not ok}
  c(i); {ok}

  i := l
END
