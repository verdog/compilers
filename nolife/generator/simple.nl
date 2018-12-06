{ An uninteresting case of recursion, by Dan Kirkpatrick }

{ Note that since the procedure's call to decls() passes a }
{ constant, the final assignment (a := 0) should NOT change the }
{global value of a }


PROGRAM foo;
  VAR a:INTEGER;

PROCEDURE decls(a,b:INTEGER);
BEGIN
  WRITE(a);
  WRITE(b);
  IF (a > 0) THEN
    decls(a - 1, b MOD 2)
  ELSE
    a := 0
END;

PROCEDURE foo(a, b:INTEGER);
BEGIN
  WRITE(a);
  WRITE(b)
END;

BEGIN
  READ(a);
  decls(a, 100);
  foo(a, 10)
END
