PROGRAM func;

VAR 
a, c, d :INTEGER;
f :FLOAT;
l: ARRAY [1..10] OF INTEGER;

PROCEDURE b;

  BEGIN
    RETURN 4
  END;

BEGIN
  c := b()
END
