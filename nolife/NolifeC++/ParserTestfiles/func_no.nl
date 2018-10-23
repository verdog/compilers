PROGRAM func;

VAR 
a, c, d :INTEGER;
f :FLOAT;

FUNCTION b : INTEGER;

  BEGIN
    RETURN 4
  END;

BEGIN
  c := b()
END
